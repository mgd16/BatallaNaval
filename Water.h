//
//  Water.h
//  BatallaNaval
//
//  Created by Javier on 11/5/13.
//  Copyright (c) 2013 Javier. All rights reserved.
//

#ifndef __BatallaNaval__Water__
#define __BatallaNaval__Water__

#include <iostream>
#include <OpenGL/gl.h>

class Water {
private:
	void setTexture();
	void drawTriangle(GLfloat *v1, GLfloat *v2, GLfloat *v3);
	void subdivide(GLfloat *v1, GLfloat *v2, GLfloat *v3, long depth);
	float center[3];

public:
	//subdivide mesh to get better watter movement
  void subdivideMesh();
	
	//opengl draw call
	void draw();
	
	//animate hit
	void hit(int x, int y);
};

#endif /* defined(__BatallaNaval__Water__) */
