#!/bin/bash

if [ -n "$1" ]; then
	if [["$1" != "--not-run"]]; then
		g++ $1 -o app -lsfml-graphics -lsfml-window -lsfml-system -utf-8
		./app
	else
		g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system -utf-8
		echo "Compiled with success"
	fi
else
	g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system -utf-8
	./app
fi

