cmake_minimum_required(VERSION 3.20.0)

set(ZEPHYR_CMAKE_MODULES_DIR ${ZEPHYR_BASE}/cmake)

include(${ZEPHYR_CMAKE_MODULES_DIR}/app/boilerplate.cmake)

project(hello_timer_activity)

target_sources(app PRIVATE src/main.c)
