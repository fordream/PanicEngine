project(PanicEngine)
cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0042 NEW)


# Qt specific instructions
# Tell CMake to run moc when necessary:
# set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "-fPIC -g -Wall")

add_subdirectory(src)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} vector graphics ${Qt5Widgets_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Qt5Widgets_INCLUDE_DIRS})


qt5_use_modules(${PROJECT_NAME} Widgets)
