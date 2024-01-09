cmake_minimum_required(VERSION 3.20)
project(abseil_status_macros VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)  # To allow pulling packages directly from GIT-repositories.

# Load external dependencies to make it available for quberry internals.

# Avoid building/adding Eigen unit tests to the list of CMake targets (especially, since it  triggers CMake warning.
option(BUILD_TESTING OFF)

# GoogleTest (unit tests).
FetchContent_Declare(
        gtest
        SYSTEM
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(gtest)
include(GoogleTest)

# Abseil (advanced C++ language primitives, statuses, etc.)
FetchContent_Declare(
        absl
        SYSTEM
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG 20230802.1
)
set(ABSL_BUILD_TESTING OFF)
set(ABSL_PROPAGATE_CXX_STD ON)
set(CMAKE_INCLUDE_CURRENT_DIR OFF)  # toggle on/off to handle absl-related warnings.
FetchContent_MakeAvailable(absl)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create library
set(SOURCES_ABSL_STATUS_MACROS
        "status.cc"
        "status_builder.cc"
)

set(PUBLIC_HEADERS_STATUS_MACROS
        "canonical_errors.h"
        "source_location.h"
        "status.h"
        "status_builder.h"
        "status_macros.h"
)

add_library(absl_status_macros STATIC ${SOURCES_ABSL_STATUS_MACROS})
target_link_libraries(absl_status_macros PUBLIC absl::memory absl::status absl::strings)
set_target_properties(absl_status_macros PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS_STATUS_MACROS})
INSTALL(TARGETS absl_status_macros
        LIBRARY DESTINATION "lib"
        PUBLIC_HEADER DESTINATION "include"
)
