#设定Cmake的最低版本要求
cmake_minimum_required(VERSION 3.0.0)
#项目名称，可以和文件夹名称不同
project(VERSION 0.1.0)
#命令指定 SOURE_TEST变量（自己定义就行）来表示多个源文件
set(SOURCE_TEST 43file1.cpp 43file2.cpp coordin.h)
#例如：set(SOURCE_TEST main.cpp test.cpp test1.cpp)
#将生成的可执行文件保存至bin文件夹中
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#生成可执行文件main.exe(可执行文件名 自己定义就行)，用${var_name}获取变量的值。
add_executable(main ${SOURCE_TEST})