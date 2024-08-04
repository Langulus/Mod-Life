cmake_minimum_required(VERSION 3.28)
project(LangulusModLife
    VERSION         1.0.0
    DESCRIPTION     "Langulus plug-in module for simulating organisms and ecosystems"
    HOMEPAGE_URL    https://langulus.com
)

file(GLOB_RECURSE
    LANGULUS_MOD_LIFE_SOURCES 
    LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
    source/*.cpp
)

# Build the module                                                              
add_library(LangulusModLife SHARED ${LANGULUS_MOD_LIFE_SOURCES})

target_link_libraries(LangulusModLife
    PRIVATE     Langulus
)

if(LANGULUS_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()