/*
 * Copyright (C) 2020 Jacek Piszczek
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "Pasteboard.h"
#include "DragData.h"
#include "SelectionData.h"

#include "NotImplemented.h"
#include "PasteboardStrategy.h"

#include <cairo.h>

#include <proto/exec.h>
#include <proto/clipboard.h>
#include <proto/intuition.h>

#include <libraries/charsets.h>
#include <libraries/clipboard.h>

namespace WebCore {

enum ClipboardDataType {
    ClipboardDataTypeText,
    ClipboardDataTypeMarkup,
    ClipboardDataTypeURIList,
    ClipboardDataTypeURL,
    ClipboardDataTypeImage,
    ClipboardDataTypeUnknown
};

std::unique_ptr<Pasteboard> Pasteboard::createForCopyAndPaste()
{
    return std::make_unique<Pasteboard>();
}

Pasteboard::Pasteboard(SelectionData& selectionData)
    : m_selectionData(selectionData)
{
}

Pasteboard::Pasteboard(const String& name)
    : m_selectionData(SelectionData::create())
    , m_name(name)
{
}

Pasteboard::Pasteboard()
    : m_selectionData(SelectionData::create())
{
}

Pasteboard::~Pasteboard() = default;

bool Pasteboard::hasData()
{
     notImplemented();
    return false;
}

Vector<String> Pasteboard::typesSafeForBindings(const String&)
{
    notImplemented();
    return { };
}

Vector<String> Pasteboard::typesForLegacyUnsafeBindings()
{
    Vector<String> types;
//    platformStrategies()->pasteboardStrategy()->getTypes(types);
     notImplemented();
    return types;
}

String Pasteboard::readOrigin()
{
    notImplemented(); // webkit.org/b/177633: [GTK] Move to new Pasteboard API
    return { };
}

static ClipboardDataType selectionDataTypeFromHTMLClipboardType(const String& type)
{
    if (type == "text/plain")
        return ClipboardDataTypeText;
    if (type == "text/html")
        return ClipboardDataTypeMarkup;
    if (type == "Files" || type == "text/uri-list")
        return ClipboardDataTypeURIList;
    return ClipboardDataTypeUnknown;
}

String Pasteboard::readString(const String& type)
{
	(void)type;
//    return platformStrategies()->pasteboardStrategy()->readStringFromPasteboard(0, type);
     notImplemented();
    return { };
}

String Pasteboard::readStringInCustomData(const String&)
{
    notImplemented();
    return { };
}

void Pasteboard::writeString(const String& type, const String& text)
{
	auto ctype = selectionDataTypeFromHTMLClipboardType(type);
	
	if (ctype == ClipboardDataTypeText || ctype == ClipboardDataTypeUnknown)
	{
		struct Library *ClipboardBase;
		if ((ClipboardBase = OpenLibrary("clipboard.library", 53)))
        {
        	auto utext = text.utf8();
			struct TagItem tags[] = { {CLP_Charset, MIBENUM_UTF_8}, { TAG_DONE, 0 }};
			WriteClipTextA(utext.data(), tags);
			CloseLibrary(ClipboardBase);
		}
	}
	else if (ctype == ClipboardDataTypeMarkup)
	{
		struct Library *ClipboardBase;
		if ((ClipboardBase = OpenLibrary("clipboard.library", 53)))
        {
        	auto utext = text.utf8();
			struct TagItem tags[] = { {CLP_Charset, MIBENUM_UTF_8}, {CLP_ClipUnit, 1}, { TAG_DONE, 0 }};
			WriteClipTextA(utext.data(), tags);
			CloseLibrary(ClipboardBase);
		}
	}
}

void Pasteboard::clear()
{
}

void Pasteboard::clear(const String&)
{
}

void Pasteboard::read(PasteboardPlainText& text, PlainTextURLReadingPolicy, Optional<size_t>)
{
	const char *clipcontents;

	struct Library *ClipboardBase;
	if ((ClipboardBase = OpenLibrary("clipboard.library", 53)))
	{
		struct TagItem tags[] = { {CLP_Charset, MIBENUM_UTF_8}, { TAG_DONE, 0 }};
		clipcontents = (const char *)ReadClipTextA(tags);
		if (nullptr != clipcontents)
		{
			text.text = String::fromUTF8(clipcontents);
			FreeClipText(clipcontents);
		}
		
		CloseLibrary(ClipboardBase);
	}
}

void Pasteboard::read(PasteboardWebContentReader&, WebContentReadingPolicy, Optional<size_t>)
{
    notImplemented();
}

void Pasteboard::read(PasteboardFileReader&, Optional<size_t>)
{
     notImplemented();
}

void Pasteboard::write(const PasteboardURL& url)
{
     writePlainText(url.url.string(), CanSmartReplace);
}

void Pasteboard::writeTrustworthyWebURLsPboardType(const PasteboardURL&)
{
    notImplemented();
}

void Pasteboard::write(const PasteboardImage& image)
{
	RefPtr<cairo_surface_t> surface = image.image->nativeImageForCurrentFrame();
	if (surface.get())
	{
		// Create a copy of the data since it'll take time to write it
		unsigned char *data;
		int width, height, stride;

		cairo_surface_flush (surface.get());

		data = cairo_image_surface_get_data (surface.get());
		width = cairo_image_surface_get_width (surface.get());
		height = cairo_image_surface_get_height (surface.get());
		stride = cairo_image_surface_get_stride (surface.get());
		
		// should cairo use a different stride, we'd be in trouble with this routine
		if (stride > 0 && height > 0 && data && (stride == width * 4))
		{
			void *copiedData = fastMalloc(stride * height);
			
			memcpy(copiedData, data, stride * height);
			
			if (copiedData)
			{
				Thread::create("Clipboard Writer", [copiedData, width, height] {
					struct Library *ClipboardBase;
					if ((ClipboardBase = OpenLibrary("clipboard.library", 53)))
					{
						struct TagItem tags[] = {
							{CLP_Width, ULONG(width)}, {CLP_Height, ULONG(height)},
							{CLP_Data, (IPTR)copiedData}, {CLP_Format, CLIPPIXFMT_ARGB32 },
							{ TAG_DONE, 0 }
						};
						
						WriteClipImageA(tags);
						CloseLibrary(ClipboardBase);
					}
					fastFree(copiedData);
				});
			}
			else
			{
				DisplayBeep(0);
			}
		}
		else
		{
			DisplayBeep(0);
		}
	}
	else
	{
		DisplayBeep(0);
	}
}

void Pasteboard::write(const PasteboardWebContent& content)
{
    if (!content.text.isEmpty())
    {
	     writePlainText(content.text, CanSmartReplace);
	}
	
	if (!content.markup.isEmpty())
	{
		// will go into Unit1
		writeString("text/html", content.markup);
	}
}

Pasteboard::FileContentState Pasteboard::fileContentState()
{
    notImplemented();
    return FileContentState::NoFileOrImageData;
}

bool Pasteboard::canSmartReplace()
{
     notImplemented();
    return false;
}

void Pasteboard::writeMarkup(const String&)
{
     notImplemented();
}

void Pasteboard::writePlainText(const String& text, SmartReplaceOption)
{
    writeString("text/plain;charset=utf-8", text);
}

void Pasteboard::writeCustomData(const Vector<PasteboardCustomData>&)
{
     notImplemented();
}

void Pasteboard::write(const Color&)
{
     notImplemented();
}

#if ENABLE(DRAG_SUPPORT)
void Pasteboard::setDragImage(DragImage, const IntPoint&)
{
}

std::unique_ptr<Pasteboard> Pasteboard::createForDragAndDrop()
{
    return std::make_unique<Pasteboard>(SelectionData::create());
}

std::unique_ptr<Pasteboard> Pasteboard::createForDragAndDrop(const DragData& dragData)
{
    ASSERT(dragData.platformData());
    return std::make_unique<Pasteboard>(*dragData.platformData());
}

#endif

} // namespace WebCore
