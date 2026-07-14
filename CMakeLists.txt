cmake_minimum_required(VERSION 3.20)

project(LogosRoboticsSDK
    VERSION 0.0.1
    DESCRIPTION "Educational Open-Source Robotics Motion Control SDK"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------
# SDK Library
# -------------------------------------------------------

add_library(LogosRoboticsSDK

    sdk/kinematics/CoreXYKinematics.cpp
)

target_include_directories(LogosRoboticsSDK PUBLIC
    ${PROJECT_SOURCE_DIR}/sdk
)

# -------------------------------------------------------
# Tests
# -------------------------------------------------------

add_executable(CoreXYKinematics_Test

    tests/CoreXYKinematics_Test.cpp
)

target_link_libraries(CoreXYKinematics_Test
    LogosRoboticsSDK
)