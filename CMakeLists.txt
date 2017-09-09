
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library ( c_prop_tree STATIC c_prop_tree.cpp )

add_executable ( propcpp main.cpp )
target_link_libraries ( propcpp c_prop_tree )

add_executable ( propc   main.c   )
target_link_libraries ( propc c_prop_tree )
