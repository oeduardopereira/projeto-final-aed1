#!/bin/bash

x86_64-w64-mingw32-g++ -O2 main.cpp -o $1 -I/home/rms/sfml_windows/SFML-2.6.2/include -L/home/rms/sfml_windows/SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system -mwindows
