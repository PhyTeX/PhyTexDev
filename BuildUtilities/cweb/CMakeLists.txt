## CMakeLists.txt                                       -*- CMake -*-
##
## Copyright (C) 2006-2017 Christian Schenk
## 
## This file is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published
## by the Free Software Foundation; either version 2, or (at your
## option) any later version.
## 
## This file is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this file; if not, write to the Free Software
## Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
## USA.

set(MIKTEX_CURRENT_FOLDER "${MIKTEX_IDE_BUILD_UTILITIES_FOLDER}/CWeb")

include_directories(BEFORE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_definitions(
  -DUSE_MIKTEX_EXIT
)

set(initctangle_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/initcommon.c
  ${CMAKE_CURRENT_SOURCE_DIR}/initctangle.c
  ${CMAKE_CURRENT_SOURCE_DIR}/initcweb.h
  ${MIKTEX_LIBRARY_WRAPPER}
  ctangle-version.h
)

set_source_files_properties(
  ${CMAKE_CURRENT_SOURCE_DIR}/initcommon.c
  ${CMAKE_CURRENT_SOURCE_DIR}/initctangle.c
  PROPERTIES LANGUAGE CXX
)

if(MIKTEX_NATIVE_WINDOWS)
  list(APPEND initctangle_sources
    ${MIKTEX_COMMON_MANIFEST}
    ctangle.rc
  )
endif()

set_source_files_properties(
  ${MIKTEX_LIBRARY_WRAPPER}
  PROPERTIES COMPILE_FLAGS "-DCPLUSPLUSMAIN"
)

add_executable(${MIKTEX_PREFIX}ctangle ${initctangle_sources})

set_property(TARGET ${MIKTEX_PREFIX}ctangle PROPERTY FOLDER ${MIKTEX_CURRENT_FOLDER})

target_link_libraries(${MIKTEX_PREFIX}ctangle
  ${app_dll_name}
  ${core_dll_name}
  ${kpsemu_dll_name}
  ${w2cemu_dll_name}
)

install(
  TARGETS
    ${MIKTEX_PREFIX}ctangle
 DESTINATION
   "${MIKTEX_BINARY_DESTINATION_DIR}"
)
