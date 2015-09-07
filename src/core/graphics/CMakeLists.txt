set(graphics_SRCS Window.cpp)

add_library(graphics SHARED ${graphics_SRCS})
target_link_libraries(graphics GL)

target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/include)
