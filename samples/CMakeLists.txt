set(sampleScene_SRCS sampleScene.cpp main.cpp)

add_executable(sampleScene ${sampleScene_SRCS})

target_link_libraries(sampleScene graphics vector ${Qt5Widgets_LIBRARIES})
target_include_directories(sampleScene PUBLIC ${CMAKE_SOURCE_DIR}/include)

