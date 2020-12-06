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


#pragma once


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


#include <vector>
#include <stdexcept>


struct PkRuntimeError : std::runtime_error {
public:
    PkRuntimeError (const char *msg)
        : std::runtime_error (msg)
    { }
};


#include "PkApplication.h"
#include "PkHelloTriangle.h"


VkResult check (VkResult result);

