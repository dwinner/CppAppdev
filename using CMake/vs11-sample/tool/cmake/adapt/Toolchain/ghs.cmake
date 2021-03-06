include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME "ghs")
set(CMAKE_SYSTEM_VERSION "2013.5.5")
set(CMAKE_SYSTEM_PROCESSOR "rh850")

set(GHS_PATH "$ENV{DIR_MULTI}" CACHE PATH "Path to the Green Hills Multi2000 installation")

set(CMAKE_C_COMPILER    ${GHS_PATH}/ccv850.exe)
set(CMAKE_CXX_COMPILER  ${GHS_PATH}/cxv850.exe)
set(CMAKE_AR            ${GHS_PATH}/ax.exe)
set(CMAKE_LINKER        ${GHS_PATH}/cxv850.exe)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
