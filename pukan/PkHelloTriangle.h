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


struct PkHelloTriangleInfo : PkApplicationInfo {
	
};


struct PkHelloTriangle : PkApplication {
public:
    PkHelloTriangle (const PkHelloTriangleInfo &info);
    ~PkHelloTriangle ();
};




