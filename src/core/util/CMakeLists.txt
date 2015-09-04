set(util_SRCS  Entity.cpp EntityManager.cpp)

add_library(util SHARED ${util_SRCS})

target_include_directories(util PUBLIC ${CMAKE_SOURCE_DIR}/include)
