include(platform/Cairo.cmake)
include(platform/Curl.cmake)
include(platform/FreeType.cmake)
include(platform/ImageDecoders.cmake)

if (NOT MORPHOS_MINIMAL)
	include(platform/GCrypt.cmake)
endif()

list(APPEND WebCore_PRIVATE_INCLUDE_DIRECTORIES
    "${WEBKIT_LIBRARIES_DIR}/include"
)

list(APPEND WebCore_PRIVATE_INCLUDE_DIRECTORIES
    ${WEBCORE_DIR}/platform
    ${WEBCORE_DIR}/platform/morphos
    ${WEBCORE_DIR}/platform/generic
    ${WEBCORE_DIR}/platform/graphics/morphos
    ${WEBCORE_DIR}/platform/mediacapabilities
)

list(APPEND WebCore_SYSTEM_INCLUDE_DIRECTORIES
    ${ICU_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIR}
    ${SQLITE_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIRS}
    ${WPE_INCLUDE_DIRS}
    ${HYPHEN_INCLUDE_DIRS}
    ${AVCODEC_INCLUDE_DIR}
)

list(APPEND WebCore_LIBRARIES
    ${ICU_LIBRARIES}
    ${LIBXML2_LIBRARIES}
    ${SQLITE_LIBRARIES}
    ${ZLIB_LIBRARIES}
    ${WPE_LIBRARIES}
    ${HYPHEN_LIBRARIES}
)

list(APPEND WebCore_SOURCES
    editing/morphos/EditorMorphOS.cpp
    editing/morphos/AutofillElements.cpp
    platform/morphos/PasteboardMorphOS.cpp
    platform/morphos/CursorMorphOS.cpp
    platform/morphos/PlatformKeyboardEvent.cpp
    platform/morphos/PlatformScreenMorphOS.cpp
    platform/morphos/ScrollbarThemeMorphOS.cpp
    platform/morphos/MIMETypeRegistryMorphOS.cpp
    platform/morphos/DragDataMorphOS.cpp
    platform/morphos/SelectionData.cpp
    platform/generic/KeyedDecoderGeneric.cpp
    platform/generic/KeyedEncoderGeneric.cpp
    platform/graphics/morphos/GraphicsLayerMorphOS.cpp
    platform/graphics/morphos/ImageMorphOS.cpp
    platform/network/morphos/CurlSSLHandleMorphOS.cpp
    platform/network/morphos/NetworkStateNotifierMorphOS.cpp
    platform/posix/SharedBufferPOSIX.cpp
    platform/text/LocaleICU.cpp
    platform/text/hyphen/HyphenationLibHyphen.cpp
    rendering/RenderThemeMorphOS.cpp
    page/morphos/DragControllerMorphOS.cpp
)

list(APPEND WebCore_PRIVATE_FRAMEWORK_HEADERS
    platform/graphics/morphos/MediaPlayerMorphOS.h
)

if (NOT MORPHOS_MINIMAL)
	list(APPEND WebCore_SOURCES
		platform/audio/morphos/AudioDestinationMorphOS.cpp
		platform/audio/morphos/AudioBusMorphOS.cpp
		platform/audio/morphos/AudioFileReaderMorphOS.cpp
		platform/audio/morphos/FFTFrameMorphOS.cpp
		platform/graphics/morphos/acinerella.c
		platform/graphics/morphos/AcinerellaPointer.cpp
		platform/graphics/morphos/AcinerellaBuffer.cpp
		platform/graphics/morphos/AcinerellaMuxer.cpp
		platform/graphics/morphos/AcinerellaHLS.cpp
		platform/graphics/morphos/AcinerellaDecoder.cpp
		platform/graphics/morphos/AcinerellaAudioDecoder.cpp
		platform/graphics/morphos/AcinerellaVideoDecoder.cpp
		platform/graphics/morphos/AcinerellaContainer.cpp
		platform/graphics/morphos/MediaPlayerPrivateMorphOS.cpp
		platform/graphics/morphos/MediaSourcePrivateMorphOS.cpp
		platform/graphics/morphos/MediaSourceBufferPrivateMorphOS.cpp
		platform/graphics/morphos/AudioTrackPrivateMorphOS.cpp
		platform/graphics/morphos/VideoTrackPrivateMorphOS.cpp
		platform/graphics/morphos/MediaDescriptionMorphOS.cpp
		platform/graphics/morphos/MediaSampleMorphOS.cpp
	)

	list(APPEND WebCore_USER_AGENT_STYLE_SHEETS
		${WEBCORE_DIR}/Modules/mediacontrols/mediaControlsApple.css
	)

	set(WebCore_USER_AGENT_SCRIPTS
		${WEBCORE_DIR}/en.lproj/mediaControlsLocalizedStrings.js
		${WEBCORE_DIR}/Modules/mediacontrols/mediaControlsApple.js
	)

	set(WebCore_USER_AGENT_SCRIPTS_DEPENDENCIES ${WEBCORE_DIR}/platform/rendering/RenderThemeMorphOS.cpp)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -DMORPHOS_MINIMAL=${MORPHOS_MINIMAL}")
