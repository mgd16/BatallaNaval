//
//  main.cpp
//  BatallaNaval
//
//  Created by Javier on 11/5/13.
//  Copyright (c) 2013 Javier. All rights reserved.
//

#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
//if windows
#include <windows.h>
//include opnegl & glut...

#else
// Must be something else, in this case can only be OSX
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include "GameManager.h"

int main(int argc, const char * argv[])
{
	return 0;
}

