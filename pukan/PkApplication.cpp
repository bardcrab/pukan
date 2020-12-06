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


void PkApplication::initVulkan (const PkApplicationInfo &info) {
    VkApplicationInfo  app_info { };
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = info.mApplicationName.c_str ();
    app_info.applicationVersion = VK_MAKE_VERSION (1, 0, 0);
    app_info.pEngineName = info.mEngineName.c_str ();
    app_info.engineVersion = VK_MAKE_VERSION (1, 0, 0);
    app_info.apiVersion = VK_API_VERSION_1_0;
    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions;
    glfw_extensions = glfwGetRequiredInstanceExtensions (&glfw_extension_count);
    VkInstanceCreateInfo create_info { };
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;
    create_info.enabledExtensionCount = glfw_extension_count;
    create_info.ppEnabledExtensionNames = glfw_extensions;
    create_info.enabledLayerCount = 0;
    if (VK_SUCCESS != check (vkCreateInstance (&create_info, nullptr, &mInstance))) {
        throw PkRuntimeError ("unable to create Vulkan instance.");
    }
}
void PkApplication::freeVulkan () {
    vkDestroyInstance (mInstance, nullptr);
}

void PkApplication::run () {
    while (!glfwWindowShouldClose (mWindow)) {
        glfwPollEvents ();
    }
}

PkApplication::PkApplication (const PkApplicationInfo &info) {
    if (GLFW_TRUE == glfwInit ()) {
        glfwWindowHint (GLFW_RESIZABLE, GLFW_FALSE);
        glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);
        mWindow = glfwCreateWindow (
            info.mWindowWidth,
            info.mWindowHeight,
            "Pukan window", nullptr, nullptr);
        if (glfwVulkanSupported ()) {
            if (nullptr != mWindow) {
                initVulkan (info);
            } else  throw PkRuntimeError ("unable to create GLFW window.");
        } else throw PkRuntimeError ("looks like Vulkan is not supported.");
    } else throw PkRuntimeError ("unable to initialize GLFW library.");
}
PkApplication::~PkApplication () {
    freeVulkan ();
    glfwDestroyWindow (mWindow);
    glfwTerminate ();
}


#define CASE(X) case X: puts (#X); break;
VkResult check (VkResult result) {
    switch (result) {
        case VK_SUCCESS: break;
        CASE (VK_NOT_READY)
        CASE (VK_TIMEOUT)
        CASE (VK_EVENT_SET)
        CASE (VK_EVENT_RESET)
        CASE (VK_INCOMPLETE)
        CASE (VK_RESULT_RANGE_SIZE)
        CASE (VK_RESULT_MAX_ENUM)
        CASE (VK_ERROR_OUT_OF_HOST_MEMORY)
        CASE (VK_ERROR_OUT_OF_DEVICE_MEMORY)
        CASE (VK_ERROR_INITIALIZATION_FAILED)
        CASE (VK_ERROR_DEVICE_LOST)
        CASE (VK_ERROR_MEMORY_MAP_FAILED)
        CASE (VK_ERROR_LAYER_NOT_PRESENT)
        CASE (VK_ERROR_EXTENSION_NOT_PRESENT)
        CASE (VK_ERROR_FEATURE_NOT_PRESENT)
        CASE (VK_ERROR_INCOMPATIBLE_DRIVER)
        CASE (VK_ERROR_TOO_MANY_OBJECTS)
        CASE (VK_ERROR_FORMAT_NOT_SUPPORTED)
        CASE (VK_ERROR_FRAGMENTED_POOL)
        //CASE (VK_ERROR_UNKNOWN)
        CASE (VK_ERROR_OUT_OF_POOL_MEMORY)
        CASE (VK_ERROR_INVALID_EXTERNAL_HANDLE)
        //CASE (VK_ERROR_FRAGMENTATION)
        //CASE (VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS)
        CASE (VK_ERROR_SURFACE_LOST_KHR)
        CASE (VK_ERROR_NATIVE_WINDOW_IN_USE_KHR)
        CASE (VK_SUBOPTIMAL_KHR)
        CASE (VK_ERROR_OUT_OF_DATE_KHR)
        CASE (VK_ERROR_INCOMPATIBLE_DISPLAY_KHR)
        CASE (VK_ERROR_VALIDATION_FAILED_EXT)
        CASE (VK_ERROR_INVALID_SHADER_NV)
        //CASE (VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT)
        CASE (VK_ERROR_NOT_PERMITTED_EXT)
        //CASE (VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT)
        //CASE (VK_THREAD_IDLE_KHR)
        //CASE (VK_THREAD_DONE_KHR)
        //CASE (VK_OPERATION_DEFERRED_KHR)
        //CASE (VK_OPERATION_NOT_DEFERRED_KHR)
        //CASE (VK_PIPELINE_COMPILE_REQUIRED_EXT)
        //CASE (VK_ERROR_OUT_OF_POOL_MEMORY_KHR)
        //CASE (VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR)
        //CASE (VK_ERROR_FRAGMENTATION_EXT)
        //CASE (VK_ERROR_INVALID_DEVICE_ADDRESS_EXT)
        //CASE (VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR)
        //CASE (VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT)
    }
    return result;
}
#undef CASE

