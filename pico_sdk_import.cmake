echo 'if (NOT PICO_SDK_PATH)
    set(PICO_SDK_PATH "$ENV{PICO_SDK_PATH}" CACHE PATH "Path to the PICO SDK")
endif ()
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
' > pico_sdk_import.cmake
