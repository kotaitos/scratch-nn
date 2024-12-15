cmake_minimum_required(VERSION 3.16)

# プロジェクト名とバージョン
project(NeuralNetworkProject VERSION 1.0 LANGUAGES CXX)

# C++の標準設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ビルドの種類
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# オプション設定
option(ENABLE_TESTS "Enable building tests" ON)

# ヘッダーファイル用のインクルードディレクトリを設定
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/domain
    ${CMAKE_SOURCE_DIR}/implementation
    ${CMAKE_SOURCE_DIR}/data
    ${CMAKE_SOURCE_DIR}/utils
    ${PROJECT_SOURCE_DIR}
)

# ソースファイルとヘッダーファイルを収集
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/domain/*.cpp
    ${CMAKE_SOURCE_DIR}/implementation/*.cpp
    ${CMAKE_SOURCE_DIR}/data/*.cpp
    ${CMAKE_SOURCE_DIR}/utils/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/domain/*.hpp
    ${CMAKE_SOURCE_DIR}/implementation/*.hpp
    ${CMAKE_SOURCE_DIR}/data/*.hpp
    ${CMAKE_SOURCE_DIR}/utils/*.hpp
)

# 実行ファイルを作成
add_executable(neural_network main.cpp ${SOURCES} ${HEADERS})

# テストの設定（GoogleTestを使用）
if(ENABLE_TESTS)
    # GoogleTestを取得
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
    )
    FetchContent_MakeAvailable(googletest)

    # テスト用のターゲットを作成
    add_executable(test_suite
        tests/test_main.cpp
        tests/test_Layer.cpp
        tests/test_Network.cpp
        tests/test_SigmoidNeuron.cpp
        ${SOURCES}
    )
    target_link_libraries(test_suite gtest gtest_main)
    add_test(NAME neural_network_tests COMMAND test_suite)
endif()

# 最適化オプション
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(neural_network PRIVATE -Wall -Wextra -g)
else()
    target_compile_options(neural_network PRIVATE -O2)
endif()

# テストの有効化
enable_testing()

# テストの追加
add_test(NAME SigmoidNeuronTest COMMAND test_suite)

# テスト実行時の詳細出力を有効化
set(CTEST_OUTPUT_ON_FAILURE TRUE)
