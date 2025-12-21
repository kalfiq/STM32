############################################################################################
# Handle the user argument
############################################################################################
if ("${VARIANT}" STREQUAL "")
    set(LOWER_VARIANT "stm32f722")
else ()
    string(TOLOWER ${VARIANT} LOWER_VARIANT)
endif ()

############################################################################################
# Handle the variant files - Possible to abstract this out in an external utilities file?
############################################################################################
if (${LOWER_VARIANT} STREQUAL "stm32f722")
    set(SOURCE_FILES
        STM32F722/Startup/Startup.s
    )

    get_filename_component(LINKER
        STM32F722/Linker/linker.ld
        ABSOLUTE
    )

    get_filename_component(TOOLCHAIN
        CMake/STM32F722.cmake
        ABSOLUTE
    )
elseif (${LOWER_VARIANT} STREQUAL "atmel328p")
    message(FATAL_ERROR "Variant not yet supported: ${VARIANT}")
else ()
    message(FATAL_ERROR "Invalid variant provided: ${VARIANT}")
endif ()

foreach(FILE ${SOURCE_FILES})
    get_filename_component(SOURCE ${FILE} ABSOLUTE)
    list(APPEND SOURCES ${SOURCE})
endforeach ()

############################################################################################
# Set the parent variables for final compilation and linking
############################################################################################
set(PLATFORM_SOURCES ${SOURCES} PARENT_SCOPE)
set(LINKER_SCRIPT ${LINKER} PARENT_SCOPE)
set(PLATFORM_TOOLCHAIN ${TOOLCHAIN} PARENT_SCOPE)
