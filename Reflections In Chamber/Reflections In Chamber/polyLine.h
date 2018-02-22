#pragma once
#include "includes.h"
#include <vector>
#ifndef POLYLINE_H
#define POLYLINE_H

class PolyLine
{
	std::vector<Point2> myVerticeList;

	public:
		PolyLine()
		{
			this->position.set(0,0);
			this->numVerts = 0; 
			for(int i =0 ; i< MAX_VERTS;i++)
				this->vertexList[i].set(0.0,0.0);
			
		}

		void setPostition(float xx, float yy)
		{
			this ->position.set(xx,yy);
		
		}
		
		int getNumVertices()
		{ 
			return numVerts; 
		}

		Point2 getVertex(int index)
		{ 
			Point2 thisVertex(vertexList[index].getX(),vertexList[index].getY());
			
			return thisVertex; 
		}

		float getVertex_X(int index)
		{ 
			return this->vertexList[index].getX(); 
		}

		float getVertex_Y(int index)
		{ 
			return this->vertexList[index].getY(); 
			
		}



		void setVertex(int index,Point2 vertex)
		{
			this->vertexList[index].set(vertex.getX(),vertex.getY());
			
		 		
		}

		void drawPolyLine(Canvas *cvs,int numPoints)
		{
			this->vertexList[0].draw();
			//printf("\n%f	%f",vertexList[0].getX(),vertexList[0].getY());
			cvs->moveTo(vertexList[0].getX(),vertexList[0].getY());
			
			for(int i=1; i<numPoints; i++) //repeat n times
				{	this->vertexList[i].draw();
					cvs->lineTo(vertexList[i]);
					cvs->moveTo(vertexList[i]);
					//printf("\n%f	%f",vertexList[i].getX(),vertexList[i].getY());
				}
			cvs->moveTo(0,0);
		    //printf("\n\n");
		}
        
		

protected:
			int numVerts; 
			Point2 vertexList[MAX_VERTS]; 
			Point2 position;
};

#endif


class Ngon: public PolyLine
{
	public:
		Ngon():PolyLine() { radius =0; sides =0;}

		Ngon(float r,int s)
		{
			this->radius =r;
			this->sides =s;

			float angle =0;
			float angleInc = 2*PI / s; 

			for (int i =0; i<=s;i++)
			{
			 Point2 vertex(this->radius*cos(angle),this->radius*sin(angle));
			 this->setVertex(i,vertex);
			 angle += angleInc;			
			}	
		}
	
		 Ngon(Point2 c,float r,int s, float sAngle)
		{
			this->radius =r;
			this->sides =s;
			this->numVerts = s+1;
			this->position.set(c.getX(),c.getY());
			this->startAngle = sAngle;

			float angle =this->startAngle;
			float angleInc = 2*PI / s; 

			for (int i =0; i<=s;i++)
			{
				Point2 
				vertex(this->position.getX()+this->radius*cos(angle),
				this->position.getY()+this->radius*sin(angle));
				
				this->setVertex(i,vertex);
				angle += angleInc;			
			}	
		}
		Ngon(Point2 c,float r,int s, float sAngle,int x)  //just for calculation && saving of normals
		{
			this->radius =r;
			this->sides =s;
			this->numVerts = s+1;
			this->position.set(c.getX(),c.getY());
			this->startAngle = sAngle;

			float angle =this->startAngle;
			float angleInc = 2*PI / s; 

			for (int i =0; i<=s;i++)
			{
				Point2 
				vertex(this->position.getX()+this->radius*cos(angle),
				this->position.getY()+this->radius*sin(angle));
				
				this->setVertex(i,vertex);
				angle += angleInc;			
			}	
		}

        void drawRosette(Canvas *cvs)
		{
		 
		 for(int i =0;i<=this->sides;i++)
		 {  
		  cvs->moveTo(this->vertexList[i].getX(),this->vertexList[i].getY());	 
		   for (int j =i+1; j<this->sides;j++) 			  
			cvs->lineTo(this->vertexList[j].getX(),this->vertexList[j].getY());
		 
		 }
		}
        void setRadius(float f)
		{
		
			this ->radius=f;
		}

        void setStartAngle(float aa)
		{
		
			this->startAngle = aa;
		}
		void setSides(int num)
		{
			this->sides =  num;
		
		}


protected:
		float radius;
		int sides;
		float startAngle;

};

class Circle: public Ngon
{
	public:
	Circle(Point2 centre,float radius):Ngon(centre,radius,40,0)
	{
		
	} 

	void drawCircle(Canvas *cvs)
	{
		this->drawPolyLine(cvs,41);
	}

};

