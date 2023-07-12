cmake_minimum_required(VERSION 3.0)
project(main LANGUAGES CXX)

find_package(OpenCV REQUIRED)

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR} ${sourcefile})
    string( REPLACE ".cpp" "" file ${filename} )
    add_executable( ${file} ${sourcefile} )
    target_link_libraries( ${file} ${OpenCV_LIBS} )
endforeach( sourcefile ${APP_SOURCES} )

# add_executable(basicFunc  2basicFunc.cpp)
# target_include_directories(basicFunc PRIVATE include)
# target_link_libraries(basicFunc ${OpenCV_LIBS})
