cmake_minimum_required(VERSION 3.10)
project(WasmMultiThreadExample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 Emscripten 编译器
set(CMAKE_C_COMPILER emcc)
set(CMAKE_CXX_COMPILER em++)

# 添加源文件
add_executable(wasm_multi_thread main.cpp)

# 设置 Emscripten 链接标志
set_target_properties(wasm_multi_thread PROPERTIES
    LINK_FLAGS "-s WASM=1 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=4 -s EXPORTED_RUNTIME_METHODS=['ccall']"
)