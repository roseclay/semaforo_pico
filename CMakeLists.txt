echo 'cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(semaforo_pico)
pico_sdk_init()

add_executable(semaforo_pico
    src/main.c
    src/semaforo.c
    src/one_shot.c
)

target_include_directories(semaforo_pico PRIVATE include)
target_link_libraries(semaforo_pico pico_stdlib)

pico_add_extra_outputs(semaforo_pico)
' > CMakeLists.txt
