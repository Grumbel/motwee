# motwee - Easing functions for C++
# Copyright (C) Ingo Ruhnke <grumbel@gmail.com>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
#
# * Neither the name of the author nor the names of contributors may
#   be used to endorse or promote products derived from this software
#   without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

cmake_minimum_required(VERSION 3.15)
project(motwee VERSION 0.0.0)

set(TINYCMMC_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/tinycmmc/modules/")
find_package(tinycmmc CONFIG)
message(STATUS "tinycmmc module path: ${TINYCMMC_MODULE_PATH}")
list(APPEND CMAKE_MODULE_PATH ${TINYCMMC_MODULE_PATH})

include(MaximumWarnings)
include(GNUInstallDirs)

file(GLOB MOTWEE_HEADERS "include/motwee/*.hpp")

add_library(motwee INTERFACE)
target_include_directories(motwee INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
set_target_properties(motwee PROPERTIES
  PUBLIC_HEADER "${MOTWEE_HEADERS}")

if(BUILD_EXTRA)
  add_executable(motwee_exe src/main.cpp)
  target_compile_options(motwee_exe PRIVATE ${WARNINGS_CXX_FLAGS})
  set_target_properties(motwee_exe PROPERTIES
    OUTPUT_NAME "motwee"
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)
  target_link_libraries(motwee_exe motwee)

  install(TARGETS motwee_exe
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
endif()

install(TARGETS motwee
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

include(ExportAndInstallLibrary)

# EOF #
