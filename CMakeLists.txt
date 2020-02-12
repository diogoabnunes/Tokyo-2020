cmake_minimum_required(VERSION 3.15)
project(Tokyo2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tokyo2020 main.cpp Data.cpp Data.h Pessoa.cpp Pessoa.h Atleta.cpp Atleta.h Staff.cpp Staff.h utils.cpp utils.h Comitiva.cpp Comitiva.h menu.cpp menu.h Exception.cpp Exception.h Medalhas.cpp Medalhas.h Records.cpp Records.h)
