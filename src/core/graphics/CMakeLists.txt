set(graphics_SRCS QGLWindow.cpp)

add_library(graphics SHARED ${graphics_SRCS})
# link Qt OpenGL libraries
# target_link_libraries(graphics GL)

target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(graphics PUBLIC ${Qt5Widgets_INCLUDE_DIRS})

