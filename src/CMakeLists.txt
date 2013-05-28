#CMAKE_CXX_FLAGS will be used for any build type
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -std=c++11")

message("Using Build Type: " ${CMAKE_BUILD_TYPE})

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DBConnector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SimpleLowPass.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/DBConnector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Node.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SimpleLowPass.h
)

#This cmake config file is missing sqlite3 incudes.be carefull when you are using it!

add_executable(lowPassFilter ${HEADERS} ${SOURCE})

