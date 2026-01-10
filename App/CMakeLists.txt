set(SOURCE_FILES
    logger/logger.c
    logger/ring_buffer.c
    utilities/converter.c
    main.c
)

set(HEADER_PATHS
    logger
    utilities
)

############################################################################################
# Get the absolute paths for the source files
############################################################################################
foreach(FILE ${SOURCE_FILES})
    get_filename_component(SOURCE ${FILE} ABSOLUTE)
    list(APPEND SOURCES ${SOURCE})
endforeach()

foreach(PATH ${HEADER_PATHS})
    get_filename_component(HEADER ${PATH} ABSOLUTE)
    list(APPEND HEADERS ${HEADER})
endforeach()

############################################################################################
# Set the parent variables for final compilation and linking
############################################################################################
set(APP_SOURCES ${SOURCES} PARENT_SCOPE)
set(APP_HEADERS ${HEADERS} PARENT_SCOPE)

