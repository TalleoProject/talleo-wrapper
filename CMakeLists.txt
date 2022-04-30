cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0048 NEW)

set(VERSION "0.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cryptonote/cmake")

# parse project version from cryptonote/src/version.h.in
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/cryptonote/src/version.h.in" VERSION_FILE)
string(REGEX REPLACE ".*APP_VER_MAJOR ([0-9]+).*" "" DUMMY ${VERSION_FILE})
set(VER_MAJOR ${CMAKE_MATCH_1})
string(REGEX REPLACE "APP_VER_MINOR ([0-9]+)" "" DUMMY ${VERSION_FILE})
set(VER_MINOR ${CMAKE_MATCH_1})
string(REGEX REPLACE "APP_VER_REV ([0-9]+)" "" DUMMY ${VERSION_FILE})
set(VER_PATCH ${CMAKE_MATCH_1})
string(REGEX REPLACE "APP_VER_BUILD ([0-9]+)" "" DUMMY ${VERSION_FILE})
set(VER_TWEAK ${CMAKE_MATCH_1})
unset(DUMMY)
message("Version: ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}.${VER_TWEAK}")
project(TalleoWrapper VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}.${VER_TWEAK} LANGUAGES C CXX)

if(CMAKE_TOOLCHAIN_FILE)
  message("Toolchain: ${CMAKE_TOOLCHAIN_FILE}")
endif()
message("System: ${CMAKE_SYSTEM_NAME}")
message("Processor: ${CMAKE_SYSTEM_PROCESSOR}")

if(CMAKE_SYSTEM_NAME MATCHES "kFreeBSD.*|FreeBSD")
  set(FREEBSD TRUE)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "DragonFly.*")
  set(DRAGONFLY TRUE)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "kOpenBSD.*|OpenBSD.*")
  set(OPENBSD TRUE)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
  set(NETBSD TRUE)
endif()

if(MSVC)
  add_definitions("-EHsc" "-DWIN32" "-DBUILD_DLL")
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions("-MTd")
  else()
    add_definitions("-MT")
  endif()
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Windows)
elseif(APPLE)
  add_definitions("-DOSX" "-DPOSIX" "-DBUILD_DLL")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fvisibility=hidden")
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/OSX)
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Posix)
elseif(FREEBSD OR NETBSD OR OPENBSD)
  add_definitions("-DBSD" "-DPOSIX" "-DBUILD_DLL")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fvisibility=hidden")
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/FreeBSD)
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Posix)
elseif(ANDROID)
  add_definitions("-DANDROID" "-DPOSIX" "-DBUILD_DLL")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fvisibility=hidden")
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Android)
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Posix)
else()
  add_definitions("-DLINUX" "-DPOSIX" "-DBUILD_DLL")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -fvisibility=hidden")
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Linux)
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/src/Platform/Posix)
endif()

find_package(RocksDB)
if(ROCKSDB_FOUND)
  include_directories(SYSTEM ${ROCKSDB_INCLUDE_DIRS})
else()
  include_directories(${CMAKE_SOURCE_DIR}/cryptonote/external/rocksdb/include)
endif()

# Force find_package(OpenSSL) to search the static library
if(STATIC)
  set(OPENSSL_USE_STATIC_LIBS ON)
endif()
if(MSVC)
  set(OPENSSL_MSVC_STATIC_RT ON)
endif()

# We have to look for Homebrew OpenSSL a bit differently
# Borrowed from https://github.com/tarantool/tarantool/commit/6eab201af1843f53a833c8928dc58fceffa08147
if(APPLE)
  find_program(HOMEBREW_EXECUTABLE brew)
  execute_process(COMMAND ${HOMEBREW_EXECUTABLE} --prefix openssl
    OUTPUT_VARIABLE HOMEBREW_OPENSSL
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(DEFINED HOMEBREW_OPENSSL)
    if(NOT DEFINED OPENSSL_ROOT_DIR)
      message(STATUS "Setting OpenSSL root to ${HOMEBREW_OPENSSL}")
      set(OPENSSL_ROOT_DIR "${HOMEBREW_OPENSSL}")
    endif()
  endif()
endif()

find_package(OpenSSL)

if(NOT OPENSSL_FOUND)
    find_package(PkgConfig)

    if(PKG_CONFIG_FOUND)
        pkg_search_module(OPENSSL openssl)
    endif()
endif()

add_subdirectory(cryptonote EXCLUDE_FROM_ALL)

include_directories(include cryptonote cryptonote/include cryptonote/src ${Boost_INCLUDE_DIR})

file(GLOB_RECURSE Wrapper src/*)

add_library(TalleoWrapper SHARED ${Wrapper})

if(ANDROID)
target_link_libraries(TalleoWrapper Common CryptoNoteCore Http Logging Mnemonics NodeRpcProxy Rpc System Wallet Transfers AndroidCompat)
else()
target_link_libraries(TalleoWrapper Common CryptoNoteCore Http Logging Mnemonics NodeRpcProxy Rpc System Wallet Transfers)
endif()

target_link_libraries(TalleoWrapper ${OPENSSL_LIBRARIES})
if(OPENSSL_FOUND)
  if(NOT MSVC AND NOT NETBSD)
    set(OPENSSL_LIBRARIES "${OPENSSL_LIBRARIES};dl")
  endif()

  target_link_libraries(TalleoWrapper ${OPENSSL_LIBRARIES})
  # prevent error LNK2019: unresolved external symbol _vsnprintf
  if(MSVC AND NOT (MSVC_VERSION LESS 1900))
    target_link_libraries(TalleoWrapper "legacy_stdio_definitions.lib")
  endif()
endif()
