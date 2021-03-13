#!/bin/sh

glib-compile-resources --target=resources.c --generate-source exampleapp.gresource.xml && \
g++ resources.c ExampleAppWindow.cpp ExampleApplication.cpp main.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`
