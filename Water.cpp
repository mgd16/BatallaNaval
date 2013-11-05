//
//  Water.cpp
//  BatallaNaval
//
//  Created by Javier on 11/5/13.
//  Copyright (c) 2013 Javier. All rights reserved.
//

#include "Water.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

void Water::drawTriangle(float *v1, float *v2, float *v3)
{
	glBegin(GL_TRIANGLES);
	// Either set an individual color for a face, or
	//if (colorFlat)
	//	glColor3f(colorInd[colorI][0],colorInd[colorI][1], colorInd[colorI][2]);
	// Set a color for each vertex
	//else
	//	glColor3f(colorInd2[colorI][0],colorInd2[colorI][1], colorInd2[colorI][2]);
	
	//colorI = incColorInd( colorI );
	// NOTE: normal is ONLY equal to the coordinate when we assume the shape is a unit sphere (r = 1) centered at origin
	// Normal calculation for spheres not centered at the origin NOT implemented in this code
	glNormal3fv(v1);
	glVertex3fv(v1);
	
	// Set a color for each vertex
	//if (!colorFlat) {
	//	glColor3f(colorInd2[colorI][0],colorInd2[colorI][1], colorInd2[colorI][2]);
	//	colorI = incColorInd( colorI );
	//}
	// NOTE: normal is ONLY equal to the coordinate when we assume the shape is a unit sphere (r = 1) centered at origin
	// Normal calculation for spheres not centered at the origin NOT implemented in this code
	glNormal3fv(v2);
	glVertex3fv(v2);
	
	// Set a color for each vertex
//	if (!colorFlat) {
//		glColor3f(colorInd2[colorI][0],colorInd2[colorI][1], colorInd2[colorI][2]);
//		colorI = incColorInd( colorI );
//	}
	// NOTE: normal is ONLY equal to the coordinate when we assume the shape is a unit sphere (r = 1) centered at origin
	// Normal calculation for spheres not centered at the origin NOT implemented in this code
	glNormal3fv(v3);
	glVertex3fv(v3);
	glEnd();
	
}

void Water::subdivide(GLfloat *v1, GLfloat *v2, GLfloat *v3, long depth)
{
	GLfloat v12[3], v23[3], v31[3];
	GLint i;
	
//	float theta, phi, bump;
	
	// Draw triangle if depth is equal to zero and return (exit)
	if (depth == 0) {
		drawTriangle(v1,v2,v3);
		return;
	}
	
	// --------------------------------------------------------------------------------
	// 1) Calculate new vertices and normals using the midpoints of the current vertices...
	for (i = 0; i < 3; i++) {
		v12[i] = (v1[i]+v2[i])/2.0;
		v23[i] = (v2[i]+v3[i])/2.0;
		v31[i] = (v3[i]+v1[i])/2.0;
	}
	
	// 2) ...Find the vectors from the center of the sphere, to the new points...
	// NOTE: If model is unit sphere center at origin (i.e. center[3] = {0.0, 0.0, 0.0}) then this step is not needed
	for (i = 0; i < 3; i++) {
		v12[i] = v12[i] - center[i];
		v23[i] = v23[i] - center[i];
		v31[i] = v31[i] - center[i];
	}
	
	// 3) ...Normalize these vectors...
	// (Normal vectors should be normalized)
	// NOTE: normal is ONLY equal to the coordinate when we assume the shape is a unit sphere (r = 1)
	//normalize(v12);
//	normalize(v23);
//	normalize(v31);
//	
	// 4) ... And finally, multiply these normal vectors by th magnitude of the radius, plus the coordinate of the center
	// NOW we have the new point, based on our model
	// NOTE: If model is unit sphere center at origin (i.e. center[3] = {0.0, 0.0, 0.0}, radius = 1.0) then this step is not needed
	for (i = 0; i < 3; i++) {
		v12[i] = v12[i] + center[i];
		v23[i] = v23[i] + center[i];
		v31[i] = v31[i] + center[i];
	}
	
	// If shape is centered at the origin, then only steps 1) and 3) are needed
	// The variable center is cancelled out
	// --------------------------------------------------------------------------------
//	
//	// Solution for ITC - for LAD, simply omit this next part
//	// --------------------------------------------------------------------------------
//	// Calculate new vertices and normals using calc points and angles
//	// Include center offset and known radius
//	theta = acos( (float)((v12[2] - center[2])/radius)); // theta = acos ( z /r )
//	phi = atan2( (float)(v12[1] - center[1])/radius, (float)(v12[0] - center[0])/radius ); // phi = atan (y / x)
//	bump = 1.0 + 0.1*sin((float)numBumps*theta)*sin((float)numBumps*phi);
//	v12[0] = bump*sin(theta)*cos(phi)*radius + center[0];
//	v12[1] = bump*sin(theta)*sin(phi)*radius + center[1];
//	v12[2] = bump*cos(theta)*radius + center[2];
//	
//	theta = acos( (float)((v23[2] - center[2])/radius)); // theta = acos ( z /r )
//	phi = atan2( (float)(v23[1] - center[1])/radius, (float)(v23[0] - center[0])/radius ); // phi = atan (y / x)
//	bump = 1.0 + 0.1*sin((float)numBumps*theta)*sin((float)numBumps*phi);
//	v23[0] = bump*sin(theta)*cos(phi)*radius + center[0];
//	v23[1] = bump*sin(theta)*sin(phi)*radius + center[1];
//	v23[2] = bump*cos(theta)*radius + center[2];
//	
//	theta = acos( (float)((v31[2] - center[2])/radius)); // theta = acos ( z /r )
//	phi = atan2( (float)(v31[1] - center[1])/radius, (float)(v31[0] - center[0])/radius ); // phi = atan (y / x)
//	bump = 1.0 + 0.1*sin((float)numBumps*theta)*sin((float)numBumps*phi);
//	v31[0] = bump*sin(theta)*cos(phi)*radius + center[0];
//	v31[1] = bump*sin(theta)*sin(phi)*radius + center[1];
//	v31[2] = bump*cos(theta)*radius + center[2];
//	// --------------------------------------------------------------------------------
//	
	
	// Recursive call to subdivide() for each new face (triangle),
	// decreasing the depth parameter (i.e., with depth - 1)
	subdivide(v1,v12,v31,depth-1);
	subdivide(v2,v23,v12,depth-1);
	subdivide(v3,v31,v23,depth-1);
	subdivide(v12,v23,v31,depth-1);
}