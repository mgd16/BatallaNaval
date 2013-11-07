//
//  mainWater.cpp
//  BatallaNaval
//
//  Created by Javier on 11/5/13.
//  Copyright (c) 2013 Javier. All rights reserved.
//
//	'main' to test and develop the water simulation

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

using namespace std;

void init();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void display(void);

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Water Test");
	
	glEnable(GL_DEPTH_TEST);
	init();
	
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutIdleFunc(display);
	
	glutMainLoop();
	return 0;
}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 0x1B:
			exit(0);
			break;
			
		default:
			break;
	}
}
void reshape(int w, int h){
	glViewport( 0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, (GLfloat) w/(GLfloat) h, 0.10, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	glRotatef(15.0, 1.0, 0.0, 0.0);
}

void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void display(void){
}
