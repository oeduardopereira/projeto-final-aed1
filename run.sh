#!/bin/bash

if [ -n "$1" ]; then
	g++ $1 -o app -lsfml-graphics -lsfml-window -lsfml-system
else
	g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system
fi
./app
