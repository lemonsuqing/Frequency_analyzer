cmake_minimum_required(VERSION 3.5)
project(Frequency_analyzer LANGUAGES CXX)

# 基本配置
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/selfworlk/tool/C_Tool/QT/6.5.3/mingw_64")  # 修改为你的Qt安装路径
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt组件
find_package(Qt6 COMPONENTS Widgets SerialPort REQUIRED)

# 源代码文件
set(SOURCES
    src/Frequency_analyzer.h
    src/Frequency_analyzer.cpp
    src/main.cpp
)

# UI文件
set(FORMS
    src/Frequency_analyzer.ui
)

# 编译选项
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# 创建可执行文件
add_executable(${PROJECT_NAME}
    WIN32
    ${SOURCES}
    ${FORMS}
)

# 链接库
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::SerialPort
)

# Windows平台需要额外的库
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE setupapi)
endif()