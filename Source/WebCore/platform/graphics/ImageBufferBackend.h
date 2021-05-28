/*
 * Copyright (C) 2020 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "AlphaPremultiplication.h"
#include "ColorSpace.h"
#include "FloatRect.h"
#include "GraphicsTypesGL.h"
#include "ImagePaintingOptions.h"
#include "IntRect.h"
#include "PlatformLayer.h"
#include "RenderingMode.h"
#include <wtf/RefPtr.h>
#include <wtf/Vector.h>

namespace WebCore {

class GraphicsContext;
class GraphicsContextGL;
class HostWindow;
class Image;
class ImageData;
class NativeImage;

enum BackingStoreCopy {
    CopyBackingStore, // Guarantee subsequent draws don't affect the copy.
    DontCopyBackingStore // Subsequent draws may affect the copy.
};

enum class PreserveResolution : uint8_t {
    No,
    Yes,
};

enum class PixelFormat : uint8_t {
    RGBA8,
    BGRA8,
#if CPU(BIG_ENDIAN)
    ARGB8 = BGRA8, // BGRA will actually be ARGB on BIG_ENDIAN
#endif
    RGB10,
    RGB10A8,
};

enum class VolatilityState : uint8_t {
    Valid,
    Empty
};

class ThreadSafeImageBufferFlusher {
    WTF_MAKE_FAST_ALLOCATED;
    WTF_MAKE_NONCOPYABLE(ThreadSafeImageBufferFlusher);
public:
    ThreadSafeImageBufferFlusher() = default;
    virtual ~ThreadSafeImageBufferFlusher() = default;
    virtual void flush() = 0;
};

class ImageBufferBackend {
public:
    struct Parameters {
        FloatSize logicalSize;
        float resolutionScale;
        DestinationColorSpace colorSpace;
        PixelFormat pixelFormat;
    };

    WEBCORE_EXPORT virtual ~ImageBufferBackend() = default;

    WEBCORE_EXPORT static IntSize calculateBackendSize(const FloatSize&, float resolutionScale);

    virtual GraphicsContext& context() const = 0;
    virtual void flushContext() { }

    virtual IntSize backendSize() const { return { }; }

    virtual size_t memoryCost() const { return 4 * backendSize().area().unsafeGet(); }
    virtual size_t externalMemoryCost() const { return 0; }

    virtual RefPtr<NativeImage> copyNativeImage(BackingStoreCopy) const = 0;
    virtual RefPtr<Image> copyImage(BackingStoreCopy, PreserveResolution) const = 0;

    WEBCORE_EXPORT virtual void draw(GraphicsContext&, const FloatRect& destRect, const FloatRect& srcRect, const ImagePaintingOptions&) = 0;
    WEBCORE_EXPORT virtual void drawPattern(GraphicsContext&, const FloatRect& destRect, const FloatRect& srcRect, const AffineTransform& patternTransform, const FloatPoint& phase, const FloatSize& spacing, const ImagePaintingOptions&) = 0;

    WEBCORE_EXPORT virtual RefPtr<NativeImage> sinkIntoNativeImage();
    WEBCORE_EXPORT virtual RefPtr<Image> sinkIntoImage(PreserveResolution);
    WEBCORE_EXPORT virtual void drawConsuming(GraphicsContext& destContext, const FloatRect& destRect, const FloatRect& srcRect, const ImagePaintingOptions&);

    virtual void clipToMask(GraphicsContext&, const FloatRect&) { }

    WEBCORE_EXPORT void convertToLuminanceMask();
    virtual void transformColorSpace(DestinationColorSpace, DestinationColorSpace) { }

    virtual String toDataURL(const String& mimeType, Optional<double> quality, PreserveResolution) const = 0;
    virtual Vector<uint8_t> toData(const String& mimeType, Optional<double> quality) const = 0;
    virtual Vector<uint8_t> toBGRAData() const = 0;

    virtual RefPtr<ImageData> getImageData(AlphaPremultiplication outputFormat, const IntRect&) const = 0;
    virtual void putImageData(AlphaPremultiplication inputFormat, const ImageData&, const IntRect& srcRect, const IntPoint& destPoint, AlphaPremultiplication destFormat) = 0;

    virtual PlatformLayer* platformLayer() const { return nullptr; }
    virtual bool copyToPlatformTexture(GraphicsContextGL&, GCGLenum, PlatformGLObject, GCGLenum, bool, bool) const { return false; }

    virtual bool isInUse() const { return false; }
    virtual void releaseGraphicsContext() { ASSERT_NOT_REACHED(); }
    virtual VolatilityState setVolatile(bool) { return VolatilityState::Valid; }
    virtual void releaseBufferToPool() { }

    virtual std::unique_ptr<ThreadSafeImageBufferFlusher> createFlusher() { return nullptr; }

    static constexpr bool isOriginAtUpperLeftCorner = false;
    static constexpr bool canMapBackingStore = true;
    static constexpr RenderingMode renderingMode = RenderingMode::Unaccelerated;

protected:
    WEBCORE_EXPORT ImageBufferBackend(const Parameters&);

    virtual unsigned bytesPerRow() const { return 4 * backendSize().width(); }

    template<typename T>
    T toBackendCoordinates(T t) const
    {
        static_assert(std::is_same<T, IntPoint>::value || std::is_same<T, IntSize>::value || std::is_same<T, IntRect>::value);
        if (resolutionScale() != 1)
            t.scale(resolutionScale());
        return t;
    }

    IntSize logicalSize() const { return IntSize(m_parameters.logicalSize); }
    float resolutionScale() const { return m_parameters.resolutionScale; }
    DestinationColorSpace colorSpace() const { return m_parameters.colorSpace; }
    PixelFormat pixelFormat() const { return m_parameters.pixelFormat; }

    IntRect logicalRect() const { return IntRect(IntPoint::zero(), logicalSize()); };
    IntRect backendRect() const { return IntRect(IntPoint::zero(), backendSize()); };

    WEBCORE_EXPORT virtual void copyImagePixels(
        AlphaPremultiplication srcAlphaFormat, PixelFormat srcPixelFormat, unsigned srcBytesPerRow, uint8_t* srcRows,
        AlphaPremultiplication destAlphaFormat, PixelFormat destPixelFormat, unsigned destBytesPerRow, uint8_t* destRows, const IntSize&) const;

    WEBCORE_EXPORT Vector<uint8_t> toBGRAData(void* data) const;

    WEBCORE_EXPORT RefPtr<ImageData> getImageData(AlphaPremultiplication outputFormat, const IntRect& srcRect, void* data) const;
    WEBCORE_EXPORT void putImageData(AlphaPremultiplication inputFormat, const ImageData&, const IntRect& srcRect, const IntPoint& destPoint, AlphaPremultiplication destFormat, void* data);

    Parameters m_parameters;
};

} // namespace WebCore

namespace WTF {

template<> struct EnumTraits<WebCore::PixelFormat> {
    using values = EnumValues<
    WebCore::PixelFormat,
    WebCore::PixelFormat::RGBA8,
    WebCore::PixelFormat::BGRA8,
    WebCore::PixelFormat::RGB10,
    WebCore::PixelFormat::RGB10A8
    >;
};

template<> struct EnumTraits<WebCore::PreserveResolution> {
    using values = EnumValues<
    WebCore::PreserveResolution,
    WebCore::PreserveResolution::No,
    WebCore::PreserveResolution::Yes
    >;
};

} // namespace WTF
