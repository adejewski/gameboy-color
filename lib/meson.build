gameboy_lib = static_library('gameboy',
  sources : [],
  include_directories : include_directories('.')
)

gameboy_dep = declare_dependency(
  link_with : gameboy_lib,
  include_directories : include_directories('.')
)

gtest_dep = dependency('gtest', main : true,
  fallback : ['gtest', 'gtest_main_dep'])

test_exe = executable('test_gameboy',
  sources : ['cpu/registers_test.cc'],
  dependencies : [gameboy_dep, gtest_dep]
)

test('gameboy tests', test_exe)
