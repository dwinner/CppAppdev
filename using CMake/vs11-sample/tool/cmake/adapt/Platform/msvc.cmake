set(CMAKE_BUILD_TYPE_INIT Debug)

# ---------- default libraries to link ----------
set(CMAKE_C_STANDARD_LIBRARIES_INIT) # kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib
set(CMAKE_CXX_STANDARD_LIBRARIES_INIT) # kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib

# ---------- compiler flags ----------
set(CMAKE_FLAGS_INIT)
set(CMAKE_FLAGS_INIT "${CMAKE_FLAGS_INIT} /wd4068")
set(CMAKE_C_FLAGS "/Gy")
set(CMAKE_CXX_FLAGS "/Gy")

set(CMAKE_C_FLAGS_INIT) # default: /DWIN32 /D_WINDOWS /W3
set(CMAKE_C_FLAGS_INIT "${CMAKE_FLAGS_INIT}")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} /MP")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} /analyze")

set(CMAKE_CXX_FLAGS_INIT) # default: /DWIN32 /D_WINDOWS /W3 /GR /EHsc
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_FLAGS_INIT}")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} /MP")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} /analyze")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} /EHsc")

# ---------- linker flags ----------
set(CMAKE_LINKER_FLAGS_INIT)
set(CMAKE_LINKER_FLAGS_INIT "${CMAKE_LINKER_FLAGS_INIT} /SUBSYSTEM:WINDOWS")

set(CMAKE_EXE_LINKER_FLAGS_INIT) # default: /machine:X86
set(CMAKE_EXE_LINKER_FLAGS_INIT "${CMAKE_EXE_LINKER_FLAGS_INIT} ${CMAKE_LINKER_FLAGS_INIT}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${CMAKE_EXE_LINKER_FLAGS_INIT} /machine:X86")

set(CMAKE_SHARED_LINKER_FLAGS_INIT) # default: /machine:X86
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${CMAKE_SHARED_LINKER_FLAGS_INIT} ${CMAKE_LINKER_FLAGS_INIT}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${CMAKE_SHARED_LINKER_FLAGS_INIT} /machine:X86")

set(CMAKE_MODULE_LINKER_FLAGS_INIT) # default: /machine:X86
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${CMAKE_MODULE_LINKER_FLAGS_INIT} ${CMAKE_LINKER_FLAGS_INIT}")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${CMAKE_MODULE_LINKER_FLAGS_INIT} /machine:X86")

set(CMAKE_STATIC_LINKER_FLAGS_INIT)
set(CMAKE_STATIC_LINKER_FLAGS_INIT "${CMAKE_STATIC_LINKER_FLAGS_INIT} ${CMAKE_LINKER_FLAGS_INIT}")

# ---------- debug configuration ----------
#
#   MP     Build with Multiple Processes
#   Od     optimization disable; Because /Od suppresses code movement, it simplifies the debugging process
#   MTd    /MT causes the application to use the multithread, static version of the run-time library, /MTd Defines _DEBUG and _MT.
#   RTC1   run time checks: 1 ^= su; s == Enables stack frame run-time error checking; u == Reports when a variable is used without having been initialized
#   Fp     Specifies a precompiled header file name
#   fp     Specify floating-point behavior.
#   ZI     Includes debug information in a program database compatible with Edit and Continue.
#   GR     Enable Runtime type information
#
set(CMAKE_C_FLAGS_DEBUG_INIT) # default: /D_DEBUG /MDd /Zi /Ob0 /Od /RTC1
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /W0")
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /MDd")
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /ZI")
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /Ob0")
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /Od")
set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_C_FLAGS_DEBUG_INIT} /RTC1")

set(CMAKE_CXX_FLAGS_DEBUG_INIT) # default: /D_DEBUG /MDd /Zi /Ob0 /Od /RTC1
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /W0")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /MDd")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /ZI")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /Ob0")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /Od")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} /RTC1")

set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT) # default: /debug /INCREMENTAL
set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT "${CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT} /DEBUG")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT "${CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT} /INCREMENTAL")

set(CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT) # default: /debug /INCREMENTAL
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT "${CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT} /DEBUG")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT "${CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT} /INCREMENTAL")

set(CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT) # default: /debug /INCREMENTAL
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT "${CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT} /DEBUG")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT "${CMAKE_MODULE_LINKER_FLAGS_DEBUG_INIT} /INCREMENTAL")

set(CMAKE_STATIC_LINKER_FLAGS_DEBUG_INIT)

# ---------- release configuration ----------
set(CMAKE_C_FLAGS_RELEASE_INIT) # default: /MD /O2 /Ob2 /D NDEBUG
set(CMAKE_C_FLAGS_RELEASE_INIT "${CMAKE_C_FLAGS_RELEASE_INIT} /W4")
set(CMAKE_C_FLAGS_RELEASE_INIT "${CMAKE_C_FLAGS_RELEASE_INIT} /MT")
set(CMAKE_C_FLAGS_RELEASE_INIT "${CMAKE_C_FLAGS_RELEASE_INIT} /O2")
set(CMAKE_C_FLAGS_RELEASE_INIT "${CMAKE_C_FLAGS_RELEASE_INIT} /Ob2")

set(CMAKE_CXX_FLAGS_RELEASE_INIT) # default: /MD /O2 /Ob2 /D NDEBUG
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /W4")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /MT")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /O2")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /Ob2")

set(CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT) # default: /INCREMENTAL:NO
set(CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT "${CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT} /INCREMENTAL:NO")

set(CMAKE_SHARED_LINKER_FLAGS_RELEASE_INIT) # default: /INCREMENTAL:NO
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE_INIT "${CMAKE_SHARED_LINKER_FLAGS_RELEASE_INIT} /INCREMENTAL:NO")

set(CMAKE_MODULE_LINKER_FLAGS_RELEASE_INIT) # default: /INCREMENTAL:NO
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE_INIT "${CMAKE_MODULE_LINKER_FLAGS_RELEASE_INIT} /INCREMENTAL:NO")

set(CMAKE_STATIC_LINKER_FLAGS_RELEASE_INIT)
