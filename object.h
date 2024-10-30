#ifndef _OJBECT_H_
#define _OBJECT_H_
#include <iostream>
#include "math.h"
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433
#endif

using namespace std;

class Object
{
public:
	Object();
	Object(GLfloat x, GLfloat y);
	~Object();

	// 2D primitives
	void drawPoint(GLfloat x, GLfloat y, GLfloat size);
	void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness);
	void drawTriangle(GLfloat x1, GLfloat y1,
					  GLfloat x2, GLfloat y2,
					  GLfloat x3, GLfloat y3);
	void drawQuad(GLfloat x1, GLfloat y1,
				  GLfloat x2, GLfloat y2,
				  GLfloat x3, GLfloat y3,
				  GLfloat x4, GLfloat y4);
	void drawRect(GLfloat width, GLfloat height);
	void drawIrregularRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4);

	// 2D Circle & Torus
	void drawCircle(GLfloat radius, GLfloat startDegree, GLfloat endDegree);
	void drawTorus(GLfloat radius, GLfloat thickness, GLfloat startDegree, GLfloat endDegree);

	// Rounded rectangle
	void drawRoundedRectFill(GLfloat width, GLfloat height, GLfloat radius);
	void drawRoundedRectLine(GLfloat width, GLfloat height, GLfloat radius, GLfloat thickness);

	// 2D transformation
	void translate(GLfloat tX, GLfloat tY);
	void rotate(GLfloat t, GLfloat pX, GLfloat pY);
	void orbitTo(GLfloat anchorX, GLfloat anchorY, GLfloat radius, GLfloat angle);
	void mirrorX();
	void mirrorY();
	void scale(GLfloat sX, GLfloat sY);
	void scale(GLfloat scale);

	// Utilities
	void drawText(float x, float y, const char *text, float scale = 1.0f, float boldness = 1.0f);
	void drawItalicText(float x, float y, const char *text, float scale = 1.0f, float italicAngle = 0.3f);

	void static glEndReset();

	// Private members
	GLfloat x, y;
};

#endif