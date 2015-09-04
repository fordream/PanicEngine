set(event_SRCS EventDispatcher.cpp)

add_library(event SHARED ${event_SRCS})

target_include_directories(event PUBLIC ${CMAKE_SOURCE_DIR}/include)
