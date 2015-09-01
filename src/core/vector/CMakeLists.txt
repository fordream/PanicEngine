set(vector_SRCS Vector2D.cpp)

add_library(vector SHARED ${vector_SRCS})

target_include_directories(vector PUBLIC ${CMAKE_SOURCE_DIR}/include)
