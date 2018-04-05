# Add binaries
add_executable(dbi_main "dbi_main.c")

# Add libraries
add_library(example000 SHARED "example000.c")
add_library(example001 SHARED "example001.c")
add_library(example002 SHARED "example002.c")

# Find DynamoRIO
find_package(DynamoRIO)
if(NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "Cannot find DynamoRIO")
endif(NOT DynamoRIO_FOUND)

# Configure clients
