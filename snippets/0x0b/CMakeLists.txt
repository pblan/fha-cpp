cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 20)
add_executable(a_threads_01_two a_threads_01_two)
add_executable(a_threads_02_simple a_threads_02_simple)
add_executable(a_threads_03_multiple a_threads_03_multiple)
add_executable(a_threads_04_array a_threads_04_array)
add_executable(a_threads_05_ref a_threads_05_ref)
add_executable(b_mutex_01_lock b_mutex_01_lock)
add_executable(b_mutex_02_condition_var_nok b_mutex_02_condition_var_nok)
add_executable(b_mutex_03_condition_var_ok b_mutex_03_condition_var_ok)
add_executable(c_stream_01_file_io c_stream_01_file_io)
add_executable(c_stream_02_string_io c_stream_02_string_io)
add_executable(d_link_01_main d_link_01_main)

add_executable(work_fileptr_io work_fileptr_io)
add_executable(work_rlvalue work_rlvalue)

add_executable(sol_coldwall sol_coldwall)
add_executable(sol_deepbutter sol_deepbutter)
add_executable(sol_westwheat sol_westwheat)
add_executable(sol_smoothrock sol_smoothrock)
