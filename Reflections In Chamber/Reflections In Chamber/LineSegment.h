#pragma once
#include "includes.h"

class LineSegment{
public:
	Point2  first, second;
	vector2 norm;
	LineSegment() {}
	LineSegment(Point2 f,Point2 s) {
		first = f;  second = s;

		//norm.set(f.getY() - s.getY(),s.getX() - f.getX());
		//norm.x = f.getY() - s.getY();
		//norm.y = s.getX() - f.getX();			//(-3,2)-(0,0)=(-3,2) N=>(-2,-3)
		//		cout << norm.getX() << " & y is : " << norm.getY() << endl;
	}


	
	void drawLine(LineSegment ls)
	{

		glBegin(GL_LINES);
		glVertex2f(ls.first.getX(), ls.first.getY());
		glVertex2f(ls.second.getX(), ls.second.getY());
		glEnd();
		glFlush();
	}
};

