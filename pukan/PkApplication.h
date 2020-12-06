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


struct PkApplicationInfo {
    int  mWindowWidth   = 800;
    int  mWindowHeight  = 600;
    std::string  mApplicationName;
    std::string  mEngineName;
};


struct PkApplication {
private:
    GLFWwindow *mWindow;
    VkInstance  mInstance;
private:
    void initVulkan (const PkApplicationInfo &info);
    void freeVulkan ();
public:
    void run ();
public:
    PkApplication (const PkApplicationInfo &info);
    virtual ~PkApplication ();
};





