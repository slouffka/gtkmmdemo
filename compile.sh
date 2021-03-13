#!/bin/sh

g++ ExampleAppWindow.cpp ExampleApplication.cpp main.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`
