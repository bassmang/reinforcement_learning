set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework filesystem system program_options thread REQUIRED)

set(TEST_SOURCES
  test_vw_external_parser.cc
  test_vw_binary_parser.cc
  test_example_joiner.cc
  test_reward_functions.cc
  main.cc
  test_common.cc
  test_lru_dedup_cache.cc
  test_timestamp_helper.cc
  test_log_converter.cc
  test_skip_learn.cc
  test_metrics.cc
  test_client_and_enqueued_time.cc
)

add_executable(binary_parser_unit_tests ${TEST_SOURCES})

# Add the include directories from vw target for testing
target_include_directories(binary_parser_unit_tests
  PRIVATE
    $<TARGET_PROPERTY:vw_core,INCLUDE_DIRECTORIES>
)

target_link_libraries(binary_parser_unit_tests
  PRIVATE
    rl_binary_parser
    Boost::unit_test_framework
    Boost::system
    Boost::filesystem
)

add_test(NAME binary_parser_unit_tests COMMAND binary_parser_unit_tests -- ${CMAKE_CURRENT_LIST_DIR}/test_files/)
