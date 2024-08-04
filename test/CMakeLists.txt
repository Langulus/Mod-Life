file(GLOB_RECURSE
	LANGULUS_MOD_LIFE_TEST_SOURCES 
	LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
	*.cpp
)

add_executable(LangulusModLifeTest ${LANGULUS_MOD_LIFE_TEST_SOURCES})

target_link_libraries(LangulusModLifeTest
	PRIVATE		Langulus
				Catch2
)

add_dependencies(LangulusModLifeTest
	LangulusModLife
)

add_test(
	NAME		LangulusModLifeTest
	COMMAND		LangulusModLifeTest
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)