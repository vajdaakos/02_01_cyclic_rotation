cmake_minimum_required(VERSION 3.5)

project(02_01_cyclic_rotation LANGUAGES C)

add_executable(02_01_cyclic_rotation main.c)

include(GNUInstallDirs)
target_link_libraries(${PROJECT_NAME} -lunity)
install(TARGETS 02_01_cyclic_rotation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
