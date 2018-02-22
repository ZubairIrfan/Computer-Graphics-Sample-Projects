#include "includes.h"
class ray2
{
public:

	ray2();
	ray2(Point2 p, vector2 v);
	void set(Point2 p, vector2 v);
	Point2 base(void);
	vector2 direction(void);
	void setBase(Point2 p);
	ray2 calReflectedPath();

	

private:
	Point2 point;
	vector2 dir ;
};

// Constructors

ray2::ray2()
{
	Point2 p;
	vector2 v;
	point = p;
	dir = v;
}
ray2::ray2(Point2 p, vector2 v)
{
	point = p;
	dir = v;
}


// getters
Point2 ray2:: base(void)
{
	return point;
}// return components

vector2 ray2::direction(void)
{
	return dir;
}

//setters

void ray2::set(Point2 p, vector2 v)
{
	point = p;
	dir = v;
}


void ray2::setBase(Point2 p)
{
	point.set(p.getX(), p.getY());

}

// logic part
ray2 ray2:: calReflectedPath()
{
	// See Lecture Discussion and Implement
	// Book Section NO:  

	ray2 r;


	return r;
}