set(SOURCE_FILES
    Logger/Logger.c
    Logger/RingBuffer.c
    Utilities/Converter.c
    Main.c
)

set(HEADER_PATHS
    Logger
    Utilities
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

