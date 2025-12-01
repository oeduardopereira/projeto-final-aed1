#!/bin/bash

if [ -n "$1" ]; then
	if [["$1" != "--not-run"]]; then
		g++ $1 -o app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -utf-8 -lFLAC
		./app
	else
		g++ main.cpp -o app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -utf-8 -lFLAC
		echo "Compiled with success"
	fi
else
	g++ main.cpp -o app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -utf-8 -lFLAC
	./app
fi

