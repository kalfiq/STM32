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
        stm32f722/startup/startup.s
        stm32f722/startup/system_init.c

        stm32f722/drivers/gpio/gpio.c
        stm32f722/drivers/clock/clock_config.c
    )

    set(INCLUDE_DIRS
        stm32f722/
        stm32f722/drivers
    )

    get_filename_component(LINKER
        stm32f722/linker/linker.ld
        ABSOLUTE
    )

    get_filename_component(TOOLCHAIN
        cmake/stm32f722.cmake
        ABSOLUTE
    )
elseif (${LOWER_VARIANT} STREQUAL "atmel328p")
    message(FATAL_ERROR "Variant not yet supported: ${VARIANT}")
else ()
    message(FATAL_ERROR "Invalid variant provided: ${VARIANT}")
endif ()

foreach (FILE ${SOURCE_FILES})
    get_filename_component(SOURCE ${FILE} ABSOLUTE)
    list(APPEND SOURCES ${SOURCE})
endforeach ()

foreach (DIR ${INCLUDE_DIRS})
    get_filename_component(HEADER ${DIR} ABSOLUTE)
    list(APPEND HEADERS ${HEADER})
endforeach()

############################################################################################
# Set the parent variables for final compilation and linking
############################################################################################
set(PLATFORM_SOURCES ${SOURCES} PARENT_SCOPE)
set(PLATFORM_HEADERS ${HEADERS} PARENT_SCOPE)
set(LINKER_SCRIPT ${LINKER} PARENT_SCOPE)
set(PLATFORM_TOOLCHAIN ${TOOLCHAIN} PARENT_SCOPE)
