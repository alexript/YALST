cmake_minimum_required(VERSION 2.8)
project(YALST)

add_library(LSTLIB STATIC src/memory.c src/names.c src/news.c src/interp.c src/primitive.c src/filein.c src/lex.c src/parser.c src/unixio.c src/tty.c initial.c st.c)
add_executable(YALST main.c)
target_link_libraries (YALST LSTLIB)