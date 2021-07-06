cmake_minimum_required(VERSION 3.5)
project(Kenop VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
# set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 14)
#--------------------------------

#configura o diretório contendo os .h
include_directories( include )

#Cria um executável com nome "Kenop"
add_executable( Kenop
                src/func.cpp
                src/KenoBet.cpp
                src/main.cpp )

# The end
