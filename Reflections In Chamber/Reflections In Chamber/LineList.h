#pragma once

#include "includes.h"

class LineList {
public:

	LineSegment line[10];
	int num;

	LineList();
	LineList(int, PolyLine);
	

};


LineList::LineList() {
	num = 3;
	line[1] = LineSegment(Point2(0, 0), Point2(100, 100));
	line[2] = LineSegment(Point2(100, 100), Point2(200, 0));
	line[0] = LineSegment(Point2(200, 0), Point2(0, 0));
}

LineList::LineList(int n, PolyLine p)
{
	num = n;

	for (int i = 0; i <num; i++)
	{
		line[i] = LineSegment(p.getVertex(i), p.getVertex(i + 1));

	}


}