#ifndef _OBJECT_CPP_ // If not defined
#define _OBJECT_CPP_ // Define the class name
#include "object.h" // Object class
#include "dimen.h" // Dimension constants
#include <string.h> // String manipulation
#include <windows.h> // Windows API
#include <stdio.h> // Standard Input Output
#include <stdarg.h> // Variable Argument List
#include "colour.h" // Colour constants
#include "strings.h" // String constants
#include <cstdarg> // For variadic arguments

// Default constructor
Object::Object() {}

Object::Object(GLfloat x, GLfloat y)
{
	this->x = x;
	this->y = y;
}

// Destructor
Object::~Object() {}

// 2D primitives
void Object::drawPoint(GLfloat x, GLfloat y, GLfloat size)
{
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	this->glEndReset();
}

void Object::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness)
{
	glPushMatrix();
	glLineWidth(thickness);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glPopMatrix();
	this->glEndReset();
}

void Object::drawTriangle(GLfloat x1, GLfloat y1,
						  GLfloat x2, GLfloat y2,
						  GLfloat x3, GLfloat y3)
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);

	this->glEndReset();
}

void Object::drawQuad(GLfloat x1, GLfloat y1,
					  GLfloat x2, GLfloat y2,
					  GLfloat x3, GLfloat y3,
					  GLfloat x4, GLfloat y4)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
	glPopMatrix();
	this->glEndReset();
}

void Object::drawRect(GLfloat width, GLfloat height)
{
	GLfloat currentX, currentY;

	GLfloat startX, startY, endX, endY;
	startX = this->x - (width / 2);
	startY = this->y - (height / 2);
	endX = this->x + (width / 2);
	endY = this->y + (height / 2);

	currentX = startX;
	currentY = startY;

	// Draw the rectangle
	this->drawQuad(startX, startY, endX, startY, endX, endY, startX, endY);
}

// 2D Circle & Torus
void Object::drawCircle(GLfloat radius, GLfloat startDegree, GLfloat endDegree)
{
	endDegree += startDegree > endDegree ? 360 : 0;
	GLfloat angle = (endDegree - startDegree) * M_PI / 180;	   // get the angle in radian
	int triangleAmount = (int)((endDegree - startDegree) / 3); // Calculate the triangle amount base on the angle
	GLfloat cx = this->x;
	GLfloat cy = this->y;

	// Pre-rotate the circle to counter the drawing rotation
	this->rotate(-90 + startDegree, cx, cy);

	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cx, cy); // center of circle
	for (int i = 0; i <= triangleAmount; i++)
	{
		GLfloat currentAngle = i * angle / triangleAmount;

		glVertex2f(
			cx + (radius * cos(currentAngle)),
			cy - (radius * sin(currentAngle)));
	}

	this->glEndReset();
}

void Object::drawIrregularRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, 
                                    GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4)
{
    glPushMatrix(); // Save the current transformation state

    glBegin(GL_POLYGON); // Start drawing a polygon
        glVertex2f(x1, y1); // Define vertex 1
        glVertex2f(x2, y2); // Define vertex 2
        glVertex2f(x3, y3); // Define vertex 3
        glVertex2f(x4, y4); // Define vertex 4
    glEnd(); // End the polygon drawing

    glPopMatrix(); // Restore the transformation state
}


void Object::drawTorus(GLfloat radius, GLfloat thickness, GLfloat startDegree, GLfloat endDegree)
{
	endDegree += startDegree > endDegree ? 360 : 0;
	GLfloat angle = (endDegree - startDegree) * M_PI / 180;	 // get the angle in radian
	int triangleAmount = (int)(endDegree - startDegree) * 4; // Calculate the triangle amount base on the angle
	GLfloat cx = this->x;
	GLfloat cy = this->y;
	GLfloat currentX, currentY, currentAngle;
	GLfloat radius_outer = radius + (thickness / 2);
	GLfloat radius_inner = radius - (thickness / 2);

	// Pre-rotate the circle to counter the drawing rotation
	this->rotate(-90 + startDegree, cx, cy);

	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i <= triangleAmount; i++)
	{
		currentAngle = i * angle / triangleAmount;
		glVertex2f(
			cx + (radius_outer * cos(currentAngle)),
			cy - (radius_outer * sin(currentAngle)));
		glVertex2f(
			cx + (radius_inner * cos(currentAngle)),
			cy - (radius_inner * sin(currentAngle)));
	}
	this->glEndReset();
}

// Rounded rectangle
void Object::drawRoundedRectFill(GLfloat width, GLfloat height, GLfloat radius)
{
	GLfloat originalX = this->x;
	GLfloat originalY = this->y;
	GLfloat startX1, startX2, endX1, endX2;
	GLfloat startY1, startY2, endY1, endY2;
	startX1 = this->x - (width / 2);
	startX2 = this->x - (width / 2) + radius;
	endX1 = this->x + (width / 2) - radius;
	endX2 = this->x + (width / 2);
	startY1 = this->y - (height / 2);
	startY2 = this->y - (height / 2) + radius;
	endY1 = this->y + (height / 2) - radius;
	endY2 = this->y + (height / 2);

	GLfloat diameter = radius * 2;

	// Draw the rectangles
	// Center rectangle
	this->drawQuad(startX2, startY2, endX1, startY2, endX1, endY1, startX2, endY1);
	// Start rectangle
	this->drawQuad(startX1, startY2, startX2, startY2, startX2, endY1, startX1, endY1);
	// End rectangle
	this->drawQuad(endX1, startY2, endX2, startY2, endX2, endY1, endX1, endY1);
	// Top rectangle
	this->drawQuad(startX2, endY1, endX1, endY1, endX1, endY2, startX2, endY2);
	// Bottom rectangle
	this->drawQuad(startX2, startY1, endX1, startY1, endX1, startY2, startX2, startY2);

	// Draw the corners
	// Top left corner
	this->x = startX2;
	this->y = endY1;
	this->drawCircle(radius, 270, 360);

	// Top right corner
	this->x = endX1;
	this->y = endY1;
	this->drawCircle(radius, 0, 90);

	// Bottom right corner
	this->x = endX1;
	this->y = startY2;
	this->drawCircle(radius, 90, 180);

	// Bottom left corner
	this->x = startX2;
	this->y = startY2;
	this->drawCircle(radius, 180, 270);

	// Reset the position
	this->x = originalX;
	this->y = originalY;
}

void Object::drawRoundedRectLine(GLfloat width, GLfloat height, GLfloat radius, GLfloat thickness)
{
	GLfloat originalX = this->x;
	GLfloat originalY = this->y;
	GLfloat startX1, startX2, startX3, endX1, endX2, endX3;
	GLfloat startY1, startY2, startY3, endY1, endY2, endY3;
	startX1 = this->x - (width / 2) - (thickness / 2);
	startX2 = this->x - (width / 2) + (thickness / 2);
	startX3 = this->x - (width / 2) + radius;
	endX1 = this->x + (width / 2) - radius;
	endX2 = this->x + (width / 2) - (thickness / 2);
	endX3 = this->x + (width / 2) + (thickness / 2);
	startY1 = this->y - (height / 2) - (thickness / 2);
	startY2 = this->y - (height / 2) + (thickness / 2);
	startY3 = this->y - (height / 2) + radius;
	endY1 = this->y + (height / 2) - radius;
	endY2 = this->y + (height / 2) - (thickness / 2);
	endY3 = this->y + (height / 2) + (thickness / 2);

	GLfloat diameter = radius * 2;

	// Draw the rectangles
	// Start rectangle
	this->drawQuad(startX1, startY3, startX2, startY3, startX2, endY1, startX1, endY1);
	// End rectangle
	this->drawQuad(endX2, startY3, endX3, startY3, endX3, endY1, endX2, endY1);
	// Top rectangle
	this->drawQuad(startX3, endY2, endX1, endY2, endX1, endY3, startX3, endY3);
	// Bottom rectangle
	this->drawQuad(startX3, startY1, endX1, startY1, endX1, startY2, startX3, startY2);

	// Draw the corners
	// Top left corner
	this->x = startX3;
	this->y = endY1;
	this->drawTorus(radius, thickness, 270, 360);

	// Top right corner
	this->x = endX1;
	this->y = endY1;
	this->drawTorus(radius, thickness, 0, 90);

	// Bottom right corner
	this->x = endX1;
	this->y = startY3;
	this->drawTorus(radius, thickness, 90, 180);

	// Bottom left corner
	this->x = startX3;
	this->y = startY3;
	this->drawTorus(radius, thickness, 180, 270);

	// Reset the position
	this->x = originalX;
	this->y = originalY;
}

// 2D transformation
void Object::translate(GLfloat tX, GLfloat tY)
{
	this->x = this->x + tX;
	this->y = this->y + tY;
}
void Object::rotate(GLfloat t, GLfloat pX, GLfloat pY)
{
	glTranslated(pX, pY, 0);
	glRotatef(-t, 0.0f, 0.0f, 1.0f);
	glTranslated(-pX, -pY, 0);
}
void Object::mirrorX()
{
	glTranslated(this->x, this->y, 0);
	glScalef(-1, 1, 1);
	glTranslated(-this->x, -this->y, 0);
}
void Object::mirrorY()
{
	glTranslated(this->x, this->y, 0);
	glScalef(1, -1, 1);
	glTranslated(-this->x, -this->y, 0);
}

void Object::scale(GLfloat sX, GLfloat sY)
{
	glTranslated(this->x, this->y, 0);
	glScalef(sX, sY, 1);
	glTranslated(-this->x, -this->y, 0);
}

void Object::scale(GLfloat scale)
{
	this->scale(scale, scale);
}

void Object::drawText(float x, float y, const char* text, float scale, float boldness) {
    glPushMatrix();
    glTranslatef(x, y, 0);
	// Compress horizontal spacing slightly
    glScalef(scale * 0.11f, scale * 0.1f, 1.0f);
    glLineWidth(boldness);  // Controls boldness
    
    for (const char* c = text; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void Object::drawItalicText(float x, float y, const char* text, float scale, float italicAngle) {
    glPushMatrix();
    glTranslatef(x, y, 0);
	glRotatef(-11.25, 0, 0, 1);
    
    // Apply shear transformation for italic effect
    GLfloat shearMatrix[16] = {
        1.0f, italicAngle, 0.0f, 0.0f,   // italicAngle controls the slant
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(shearMatrix);
    
    glScalef(scale * 0.11f, scale * 0.1f, 1.0f);
	glLineWidth(3.2f); // Controls boldness
    
    for (const char* c = text; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void Object::glEndReset()
{
	glEnd();
	glPopMatrix();
	glLoadIdentity();								 // Reset the matrix.
	gluOrtho2D(0, WINDOWS_WIDTH, 0, WINDOWS_HEIGHT); // Set canvas to windows width and height.
}

#endif