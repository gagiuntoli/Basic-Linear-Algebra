
file(GLOB testsources *.cpp)

message( "${testsources}" )

foreach (testfile ${testsources})

	# Delete File extensions (test_i.cpp -> test_i)
	get_filename_component(testname ${testfile} NAME_WE)

	# Create the executable test_i and link.
	add_executable(${testname} ${testfile})
	target_link_libraries(${testname} bla cblas)

endforeach ()
