set(PORT MorphOS)

if (NOT DEFINED MORPHOS_MINIMAL)
	message( FATAL_ERROR "MORPHOS_MINIMAL not set!")
elseif(MORPHOS_MINIMAL)
	message(STATUS ">>>>>>>>>>>> Building Minimal! <<<<<<<<<<<<<<")
else()
	message(STATUS ">>>>>>>>>>>> Building Full! <<<<<<<<<<<<<<")
endif()

cmake_policy(SET CMP0074 NEW)

WEBKIT_OPTION_BEGIN()

WEBKIT_OPTION_DEFINE(USE_LIBHYPHEN "" PUBLIC ON)

# Marking text and co
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DRAG_SUPPORT PRIVATE ON)

WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_DARK_MODE_CSS PRIVATE ON)

# Filtering, JS injections and other crap
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CONTENT_EXTENSIONS PRIVATE ON)

WEBKIT_OPTION_DEFINE(USE_OPENJPEG "Whether to enable support for JPEG2000 images." PUBLIC ON)

if (NOT MORPHOS_MINIMAL)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_APPLICATION_MANIFEST PRIVATE ON)

	# Video & Audio support
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIDEO PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_AUDIO PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_CONTROLS_SCRIPT PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_SOURCE PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FULLSCREEN_API PUBLIC ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_STATISTICS PUBLIC ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_LEGACY_ENCRYPTED_MEDIA PRIVATE ON)
# incomplete
#	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_STREAM PRIVATE ON)

	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_XSLT PUBLIC ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MHTML PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_CONIC_GRADIENTS PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_PAINTING_API PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_TYPED_OM PRIVATE ON)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_GAMEPAD PUBLIC OFF)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NOTIFICATIONS PRIVATE ON)
	WEBKIT_OPTION_DEFINE(USE_WOFF2 "Whether to enable support for WOFF2 Web Fonts." PUBLIC ON)
#	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VARIATION_FONTS PRIVATE ON)
endif()

if (MORPHOS_MINIMAL)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_CRYPTO PRIVATE OFF)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VIDEO PRIVATE OFF)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_AUDIO PRIVATE OFF)
	WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_CONTROLS_SCRIPT PRIVATE OFF)
endif()

WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SERVICE_WORKER PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_TOUCH_EVENTS PUBLIC ON)

WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_OFFSCREEN_CANVAS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_OFFSCREEN_CANVAS_IN_WORKERS PRIVATE ON)

WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_TOUCH_EVENTS PUBLIC ON)

# Doesn't work with curl backend
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FTPDIR PRIVATE OFF)

### Things that'll stay off:
# Payment things
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_APPLE_PAY PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_PAYMENT_REQUEST PRIVATE OFF)
# WebGL
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL2 PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(USE_SYSTEM_MALLOC PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SMOOTH_SCROLLING PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_REMOTE_INSPECTOR PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_RESOURCE_USAGE PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FTL_JIT PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ACCESSIBILITY PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_GEOLOCATION PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_3D_TRANSFORMS PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NETSCAPE_PLUGIN_API PRIVATE OFF)

WEBKIT_OPTION_END()

find_package(Threads REQUIRED)
find_package(Cairo REQUIRED)
find_package(Freetype REQUIRED)
find_package(Fontconfig REQUIRED)
find_package(CURL 7.60.0 REQUIRED)
find_package(ICU REQUIRED COMPONENTS uc i18n data)
find_package(HarfBuzz REQUIRED)
find_package(JPEG 1.5.2 REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(OpenSSL 1.1.1 REQUIRED)
find_package(ZLIB 1.2.11 REQUIRED)
find_package(PNG REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(Nghttp2 REQUIRED)
find_package(Hyphen REQUIRED)
find_package(LibPSL REQUIRED)
find_package(WebP REQUIRED)
find_package(OpenJPEG 2.2.0 REQUIRED)
find_package(LibXslt 1.1.32 REQUIRED)
find_package(WOFF2 1.0.2 COMPONENTS dec common)

if (NOT MORPHOS_MINIMAL)
	find_package(ffmpeg REQUIRED)
	find_package(LibGcrypt 1.6.0 REQUIRED)
	find_package(Libtasn1 REQUIRED)
endif()

SET_AND_EXPOSE_TO_BUILD(USE_CAIRO ON)
SET_AND_EXPOSE_TO_BUILD(USE_CURL ON)
SET_AND_EXPOSE_TO_BUILD(USE_FREETYPE ON)
SET_AND_EXPOSE_TO_BUILD(USE_HARFBUZZ ON)
SET_AND_EXPOSE_TO_BUILD(USE_EXPORT_MACROS ON)
SET_AND_EXPOSE_TO_BUILD(USE_LD_GOLD OFF)

if (NOT MORPHOS_MINIMAL)
	SET_AND_EXPOSE_TO_BUILD(USE_GCRYPT TRUE)
endif()

set(bmalloc_LIBRARY_TYPE STATIC)
set(WTF_LIBRARY_TYPE STATIC)
set(JavaScriptCore_LIBRARY_TYPE STATIC)
set(PAL_LIBRARY_TYPE STATIC)
set(WebCore_LIBRARY_TYPE STATIC)
set(WebKitLegacy_LIBRARY_TYPE STATIC)
set(WebKit_LIBRARY_TYPE STATIC)
set(WebCoreTestSupport_LIBRARY_TYPE STATIC)

set(CMAKE_POSITION_INDEPENDENT_CODE False)

set(ENABLE_API_TESTS OFF)
set(ENABLE_WEBCORE ON)
set(ENABLE_WEBKIT OFF)
set(ENABLE_WEBKIT_LEGACY ON)
set(ENABLE_GRAPHICS_CONTEXT_3D OFF)
