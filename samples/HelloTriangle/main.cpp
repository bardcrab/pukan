/**
 *
 *  Copyright (c) 2020 bardcrab
 *
 *  This file is part of Pukan API implementation.
 *  This is free software distributed as-is without any warranty.
 *  By using this software you agree that you are responsible for
 *  any possible harm or damage caused by usage of this software.
 *
**/


#include <pukan/pukan.h>


/**
 *
 *  Simple things should be simple. Here is example how to achieve
 *  your first triangle with usage of powerful but simple Pukan API.
 *  Basic triangle is common to be implemented first. And while you
 *  might spent many hours implementing this with other API's that
 *  often bloated with huge amount of initialization code and other
 *  very boring things, Pukan API gives you ability to quickly get
 *  your first triangle ready. Enjoy power of Pukan API!
 *
**/


int main (int argc, char *argv[]) {
    PkHelloTriangleInfo info;
    info.mWindowWidth = 1024;
    info.mWindowHeight = 576;
    info.mApplicationName = "Hello (Pukan) Triangle";
    info.mEngineName = "pukan/over\\vulkan";
    PkHelloTriangle hello_triangle (info);
    hello_triangle.run ();
    return 0;
}







