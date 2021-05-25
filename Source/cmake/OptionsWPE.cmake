include(GNUInstallDirs)
include(VersioningUtils)

SET_PROJECT_VERSION(2 32 1)

set(USER_AGENT_BRANDING "" CACHE STRING "Branding to add to user agent string")

find_package(Cairo 1.14.0 REQUIRED)
find_package(Fontconfig 2.8.0 REQUIRED)
find_package(Freetype 2.4.2 REQUIRED)
find_package(GLIB 2.44.0 REQUIRED COMPONENTS gio gio-unix gobject gthread gmodule)
find_package(HarfBuzz 0.9.18 REQUIRED COMPONENTS ICU)
find_package(ICU 60.2 REQUIRED COMPONENTS data i18n uc)
find_package(JPEG REQUIRED)
find_package(LibEpoxy 1.4.0 REQUIRED)
find_package(LibGcrypt 1.6.0 REQUIRED)
find_package(LibXml2 2.8.0 REQUIRED)
find_package(PNG REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(Threads REQUIRED)
find_package(WebP REQUIRED COMPONENTS demux)
find_package(WPE REQUIRED)
find_package(ZLIB REQUIRED)

WEBKIT_OPTION_BEGIN()

SET_AND_EXPOSE_TO_BUILD(ENABLE_DEVELOPER_MODE ${DEVELOPER_MODE})

include(GStreamerDefinitions)

# Public options shared with other WebKit ports. Do not add any options here
# without approval from a WPE reviewer. There must be strong reason to support
# changing the value of the option.
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ACCESSIBILITY PUBLIC ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ENCRYPTED_MEDIA PUBLIC ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_THUNDER PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBDRIVER PUBLIC ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_CRYPTO PUBLIC ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_XSLT PUBLIC ON)

# Private options shared with other WebKit ports. Add options here only if
# we need a value different from the default defined in WebKitFeatures.cmake.
# Changing these options is completely unsupported.
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_ASYNC_SCROLLING PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_AUTOCAPITALIZE PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CONTENT_EXTENSIONS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_CONIC_GRADIENTS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_PAINTING_API PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_SCROLL_SNAP PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_CSS_TYPED_OM PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_FILTERS_LEVEL_2 PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_GPU_PROCESS PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_LAYOUT_FORMATTING_CONTEXT PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEDIA_STREAM PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MHTML PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NETSCAPE_PLUGIN_API PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NOTIFICATIONS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_NETWORK_CACHE_STALE_WHILE_REVALIDATE PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_OFFSCREEN_CANVAS PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_PERIODIC_MEMORY_MONITOR PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_RESOURCE_LOAD_STATISTICS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SERVICE_WORKER PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SHAREABLE_RESOURCE PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_SMOOTH_SCROLLING PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_TOUCH_EVENTS PRIVATE ON)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBGL2 PRIVATE OFF)
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEB_RTC PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})
WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_WEBXR PRIVATE ${ENABLE_EXPERIMENTAL_FEATURES})

# Public options specific to the WPE port. Do not add any options here unless
# there is a strong reason we should support changing the value of the option,
# and the option is not relevant to any other WebKit ports.
WEBKIT_OPTION_DEFINE(ENABLE_GTKDOC "Whether or not to use generate gtkdoc." PUBLIC OFF)
WEBKIT_OPTION_DEFINE(USE_OPENJPEG "Whether to enable support for JPEG2000 images." PUBLIC ON)
WEBKIT_OPTION_DEFINE(USE_WOFF2 "Whether to enable support for WOFF2 Web Fonts." PUBLIC ON)
WEBKIT_OPTION_DEFINE(ENABLE_WPE_QT_API "Whether to enable support for the Qt5/QML plugin" PUBLIC ${ENABLE_DEVELOPER_MODE})
WEBKIT_OPTION_DEFINE(USE_SYSTEMD "Whether to enable journald logging" PUBLIC ON)
WEBKIT_OPTION_DEFINE(USE_SOUP2 "Whether to enable usage of Soup 2 instead of Soup 3." PUBLIC ON)

# Private options specific to the WPE port.
WEBKIT_OPTION_DEFINE(USE_GSTREAMER_HOLEPUNCH "Whether to enable GStreamer holepunch" PRIVATE OFF)
WEBKIT_OPTION_DEFINE(USE_EXTERNAL_HOLEPUNCH "Whether to enable external holepunch" PRIVATE OFF)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEMORY_SAMPLER PRIVATE ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_RESOURCE_USAGE PRIVATE ON)
else ()
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MEMORY_SAMPLER PRIVATE OFF)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_RESOURCE_USAGE PRIVATE OFF)
endif ()

if (ENABLE_DEVELOPER_MODE)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_API_TESTS PRIVATE ON)
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_MINIBROWSER PUBLIC ON)
endif ()

if (CMAKE_SYSTEM_NAME MATCHES "Linux" AND NOT EXISTS "/.flatpak-info")
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_BUBBLEWRAP_SANDBOX PUBLIC ON)
else ()
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_BUBBLEWRAP_SANDBOX PUBLIC OFF)
endif ()

# Enable variation fonts when cairo >= 1.16, fontconfig >= 2.13.0, freetype >= 2.9.0 and harfbuzz >= 1.4.2.
if (("${PC_CAIRO_VERSION}" VERSION_GREATER "1.16.0" OR "${PC_CAIRO_VERSION}" STREQUAL "1.16.0")
    AND ("${PC_FONTCONFIG_VERSION}" VERSION_GREATER "2.13.0" OR "${PC_FONTCONFIG_VERSION}" STREQUAL "2.13.0")
    AND ("${FREETYPE_VERSION_STRING}" VERSION_GREATER "2.9.0" OR "${FREETYPE_VERSION_STRING}" STREQUAL "2.9.0")
    AND ("${PC_HARFBUZZ_VERSION}" VERSION_GREATER "1.4.2" OR "${PC_HARFBUZZ_VERSION}" STREQUAL "1.4.2"))
    WEBKIT_OPTION_DEFAULT_PORT_VALUE(ENABLE_VARIATION_FONTS PRIVATE ON)
endif ()

WEBKIT_OPTION_DEPEND(USE_GSTREAMER_HOLEPUNCH ENABLE_VIDEO)
WEBKIT_OPTION_DEPEND(USE_EXTERNAL_HOLEPUNCH ENABLE_VIDEO)

include(GStreamerDependencies)

WEBKIT_OPTION_END()

if (USE_SOUP2)
    set(SOUP_MINIMUM_VERSION 2.54.0)
    set(SOUP_API_VERSION 2.4)
    set(WPE_API_VERSION 1.0)
    set(WPE_API_DOC_VERSION 1.0)
else ()
    set(SOUP_MINIMUM_VERSION 2.99.4)
    set(SOUP_API_VERSION 3.0)
    set(WPE_API_VERSION 1.1)
    # No API changes in 1.1, so keep using the same API documentation.
    set(WPE_API_DOC_VERSION 1.0)
endif ()
find_package(LibSoup ${SOUP_MINIMUM_VERSION} REQUIRED)

if (WPE_API_VERSION VERSION_EQUAL "1.0")
    CALCULATE_LIBRARY_VERSIONS_FROM_LIBTOOL_TRIPLE(WEBKIT 18 0 15)
else ()
    CALCULATE_LIBRARY_VERSIONS_FROM_LIBTOOL_TRIPLE(WEBKIT 0 0 0)
endif ()

# These are shared variables, but we special case their definition so that we can use the
# CMAKE_INSTALL_* variables that are populated by the GNUInstallDirs macro.
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBDIR}" CACHE PATH "Absolute path to library installation directory")
set(EXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_BINDIR}" CACHE PATH "Absolute path to executable installation directory")
set(LIBEXEC_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBEXECDIR}/wpe-webkit-${WPE_API_VERSION}" CACHE PATH "Absolute path to install executables executed by the library")

if (ENABLE_ACCESSIBILITY)
    find_package(ATK 2.16.0)
    if (NOT ATK_FOUND)
        message(FATAL_ERROR "atk is needed for ENABLE_ACCESSIBILITY")
    endif ()
    find_package(ATKBridge)
    if (NOT ATKBridge_FOUND)
        message(FATAL_ERROR "at-spi2-atk is needed for ENABLE_ACCESSIBILITY")
    endif ()
endif ()

if (USE_OPENJPEG)
    find_package(OpenJPEG 2.2.0)
    if (NOT OpenJPEG_FOUND)
        message(FATAL_ERROR "libopenjpeg 2.2.0 is required for USE_OPENJPEG.")
    endif ()
endif ()

if (USE_WOFF2)
    find_package(WOFF2 1.0.2 COMPONENTS dec)
    if (NOT WOFF2_FOUND)
        message(FATAL_ERROR "liwoff2dec is needed for USE_WOFF2.")
    endif ()
endif ()

if (ENABLE_WEB_CRYPTO)
    find_package(Libtasn1 REQUIRED)
    if (NOT LIBTASN1_FOUND)
        message(FATAL_ERROR "libtasn1 is required to enable Web Crypto API support.")
    endif ()
    if (LIBGCRYPT_VERSION VERSION_LESS 1.7.0)
        message(FATAL_ERROR "libgcrypt 1.7.0 is required to enable Web Crypto API support.")
    endif ()
endif ()

if (ENABLE_WEBDRIVER)
    SET_AND_EXPOSE_TO_BUILD(ENABLE_WEBDRIVER_KEYBOARD_INTERACTIONS ON)
    SET_AND_EXPOSE_TO_BUILD(ENABLE_WEBDRIVER_MOUSE_INTERACTIONS ON)
    SET_AND_EXPOSE_TO_BUILD(ENABLE_WEBDRIVER_TOUCH_INTERACTIONS OFF)
    SET_AND_EXPOSE_TO_BUILD(ENABLE_WEBDRIVER_WHEEL_INTERACTIONS ON)
endif ()

if (ENABLE_XSLT)
    find_package(LibXslt 1.1.7 REQUIRED)
endif ()

if (ENABLE_WPE_QT_API)
    find_package(Qt5 REQUIRED COMPONENTS Core Quick Gui)
    find_package(Qt5Test REQUIRED)
endif ()

if (ENABLE_WPE_QT_API OR USE_WPE_VIDEO_PLANE_DISPLAY_DMABUF)
    find_package(WPEBackend_fdo 1.5.0 REQUIRED)
endif ()


if (ENABLE_WEBXR)
    find_package(OpenXR 1.0.9)
    if (NOT OPENXR_FOUND)
        message(FATAL_ERROR "OpenXR is required to enable WebXR support.")
    endif ()
    SET_AND_EXPOSE_TO_BUILD(USE_OPENXR ${OpenXR_FOUND})
endif ()

if (USE_SYSTEMD)
    find_package(Systemd)
    if (Systemd_FOUND)
        message(STATUS "Release logs will be sent to the Systemd journal")
        SET_AND_EXPOSE_TO_BUILD(USE_JOURNALD TRUE)
    else ()
        message(FATAL_ERROR "libsystemd is needed for USE_SYSTEMD")
    endif ()
endif ()

if (ENABLE_ENCRYPTED_MEDIA AND ENABLE_THUNDER)
  find_package(Thunder REQUIRED)
endif ()

add_definitions(-DBUILDING_WPE__=1)
add_definitions(-DGETTEXT_PACKAGE="WPE")
add_definitions(-DJSC_GLIB_API_ENABLED)

if (USER_AGENT_BRANDING)
    add_definitions(-DUSER_AGENT_BRANDING=${USER_AGENT_BRANDING})
endif ()

if (EXISTS "${TOOLS_DIR}/glib/svn-revision")
    execute_process(COMMAND ${TOOLS_DIR}/glib/svn-revision ERROR_QUIET OUTPUT_VARIABLE SVN_REVISION OUTPUT_STRIP_TRAILING_WHITESPACE)
else ()
    set(SVN_REVISION "tarball")
endif ()
add_definitions(-DSVN_REVISION="${SVN_REVISION}")

SET_AND_EXPOSE_TO_BUILD(HAVE_ACCESSIBILITY ${ENABLE_ACCESSIBILITY})
SET_AND_EXPOSE_TO_BUILD(USE_ATK ${ENABLE_ACCESSIBILITY})
SET_AND_EXPOSE_TO_BUILD(USE_CAIRO TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_EGL TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_GCRYPT TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_LIBEPOXY TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_LIBWPE TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_OPENGL_ES TRUE)
SET_AND_EXPOSE_TO_BUILD(HAVE_OPENGL_ES_3 TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_WPE_RENDERER TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_XDGMIME TRUE)

if (WTF_CPU_ARM OR WTF_CPU_MIPS)
    SET_AND_EXPOSE_TO_BUILD(USE_CAPSTONE ${ENABLE_DEVELOPER_MODE})
endif ()

SET_AND_EXPOSE_TO_BUILD(USE_TEXTURE_MAPPER TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_TEXTURE_MAPPER_GL TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_TILED_BACKING_STORE TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_COORDINATED_GRAPHICS TRUE)
SET_AND_EXPOSE_TO_BUILD(USE_NICOSIA TRUE)

# GUri is available in GLib since version 2.66, but we only want to use it if version is >= 2.67.1.
if (PC_GLIB_VERSION VERSION_GREATER "2.67.1" OR PC_GLIB_VERSION STREQUAL "2.67.1")
    SET_AND_EXPOSE_TO_BUILD(HAVE_GURI 1)
endif ()

# Override the cached variable, gtk-doc does not really work when cross-building or building on Mac.
if (CMAKE_CROSSCOMPILING OR APPLE)
    set(ENABLE_GTKDOC OFF)
endif ()

set(FORWARDING_HEADERS_DIR ${DERIVED_SOURCES_DIR}/ForwardingHeaders)
set(FORWARDING_HEADERS_WPE_DIR ${FORWARDING_HEADERS_DIR}/wpe)
set(FORWARDING_HEADERS_WPE_EXTENSION_DIR ${FORWARDING_HEADERS_DIR}/wpe-webextension)
set(FORWARDING_HEADERS_WPE_DOM_DIR ${FORWARDING_HEADERS_DIR}/wpe-dom)
set(FORWARDING_HEADERS_WPE_JSC_DIR ${FORWARDING_HEADERS_DIR}/wpe-jsc)
set(DERIVED_SOURCES_JAVASCRIPCOREWPE_DIR ${DERIVED_SOURCES_JAVASCRIPTCORE_DIR}/javascriptcorewpe)
set(DERIVED_SOURCES_JAVASCRIPCORE_GLIB_API_DIR ${DERIVED_SOURCES_JAVASCRIPTCORE_DIR}/javascriptcorewpe/jsc)
set(DERIVED_SOURCES_WPE_API_DIR ${DERIVED_SOURCES_WEBKIT_DIR}/wpe)

set(WPE_PKGCONFIG_FILE ${CMAKE_BINARY_DIR}/wpe-webkit-${WPE_API_VERSION}.pc)
set(WPEWebExtension_PKGCONFIG_FILE ${CMAKE_BINARY_DIR}/wpe-web-extension-${WPE_API_VERSION}.pc)

include(BubblewrapSandboxChecks)
include(GStreamerChecks)
