/*
 *  Box.cpp
 *  Graphics Assignment Four
 *
 *  Created by Karl Grogan on 27/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Box.h"
#include <GLUT/glut.h>

// Moves the box 512 pixels every second. When it reaches teh other side of the window
// it goes back to the start.

Box::Box()
{
	boxX = 0;
	boxY = 0;
	rotAngle = 0;	
	lastFrameTime = 0;
}

/*
 This method moves the box
 */
void Box::MoveBox()
{
	if (lastFrameTime == 0)
    {
        lastFrameTime = glutGet(GLUT_ELAPSED_TIME);
    }
	int now = glutGet(GLUT_ELAPSED_TIME);
    int elapsedMilliseconds = now - lastFrameTime;
    float elapsedTime = elapsedMilliseconds / 1000.0f;
    lastFrameTime = now;
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    boxX += 512.0f * elapsedTime;
    if (boxX > windowWidth)
    {
        boxX -= windowWidth;
    }
	
}

// Moves (translates) the positioin ofthe box.
void Box::TranslateBox(int key)
{
    switch (key)
    {
		case GLUT_KEY_DOWN:      boxY -= 5;        break;
		case GLUT_KEY_UP:      boxY += 5;        break;
		case GLUT_KEY_LEFT:      boxX -= 5;        break;
		case GLUT_KEY_RIGHT:      boxX += 5;        break;
		case GLUT_KEY_F1:	rotAngle += 5;		break;
			
		default: break;
    }
}


void Box::RotateBox()
{
	rotAngle += 100;
}

void Box::DrawBox()
{
	glPushMatrix();
	glTranslatef(64, 64, 0);
	// Changes the position of the box x, y, or z directions. 
	glTranslatef(boxX, boxY, 0.0f);
	// Rotates the box about the x,y or z axis depending where the '1' is specified in the parameters.
	// The first parameter is the rotation angle.
	glRotatef(rotAngle, 0, 0, 1);
	
	
	
	glBegin(GL_QUADS);
		
	// Defines each vertex of the box(cube).
	glVertex2f(-64.0,-64.0);
	glVertex2f(64.0,-64.0);
	glVertex2f(64.0,64.0);
	glVertex2f(-64.0,64.0);
	glVertex2f(-64.0,-64.0);
	glVertex2f(64.0,-64.0);
	glVertex2f(64.0,64.0);
	glVertex2f(-64.0,64.0);
	
    glEnd();
	
	glPopMatrix();
	
}
