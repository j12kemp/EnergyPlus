project(ExpandObjects Fortran)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../../Products" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../../Products" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../../Products" )

SET(SRC epfilter.f90) 

ADD_EXECUTABLE( ExpandObjects ${SRC} )

SET_TARGET_PROPERTIES(ExpandObjects PROPERTIES
  COMPILE_FLAGS "-std=legacy -ffree-line-length-200 ${SHARED_FLAGS}"
)

# the Fortran apps require a DEF for proper path handling on Windows
if( WIN32 ) 
  add_definitions(-D_WIN32) 
  if( CMAKE_Fortran_COMPILER MATCHES "ifort" )
    add_definitions( "/fpp" )
  else() # assume mingw gfortran if not intel fortran
    add_definitions( "-x f95-cpp-input" )
  endif()  
else()
  if( CMAKE_Fortran_COMPILER MATCHES "ifort" )
    add_definitions( "-fpp" )
  elseif( CMAKE_Fortran_COMPILER_ID MATCHES "GNU" ) # could use this above in WIN32 block to be more specific
    add_definitions( "-cpp" )
  endif()
endif()
  
install(TARGETS ExpandObjects DESTINATION ./)
