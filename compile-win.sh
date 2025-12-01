#!/bin/bash

x86_64-w64-mingw32-g++ -O2 main.cpp -o app.exe -I/home/renan/sfml_windows/SFML-2.6.2//include/ -L/home/renan/sfml_windows/SFML-2.6.2//lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -mwindows
