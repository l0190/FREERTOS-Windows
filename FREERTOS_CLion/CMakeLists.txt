cmake_minimum_required(VERSION 3.5)
project(FREERTOS_Project)

# 设置 CMake 构建类型
set(CMAKE_BUILD_TYPE Debug)

# 添加源文件
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

# 添加 FreeRTOS 源文件
set(FREERTOS_DIR "D:/tools/code/c/FreeRTOSv202012.00/FreeRTOS")
message("Value of FREERTOS_DIR: ${FREERTOS_DIR}")
FILE(GLOB FREERTOS_SOURCES ${FREERTOS_DIR}/Source/*.c)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/)

list(APPEND FREERTOS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/tasks.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/queue.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/timers.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/list.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/queue.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/portable/MemMang/heap_3.c")
list(APPEND FREERTOS_SOURCES "${FREERTOS_DIR}/Source/portable/MSVC-MingW/port.c")

# 添加头文件目录
include_directories(
        include
        ${FREERTOS_DIR}/Source/include
        ${FREERTOS_DIR}/Source/portable/MSVC-MingW
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# 创建可执行文件
add_executable(FREERTOS_Project ${SOURCE_FILES} ${FREERTOS_SOURCES})

# 链接 FreeRTOS 静态库和 pthread 库
target_link_libraries(FREERTOS_Project)
