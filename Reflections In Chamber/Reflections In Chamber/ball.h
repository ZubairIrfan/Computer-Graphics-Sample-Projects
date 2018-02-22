#pragma once
#include "includes.h"

class Ball
{
	public:

	Ball();
	Ball(float,float,ray2);
	void setMovingPath(Point2,vector2);
	void drawBall(void);
	void moveBall(void);
	ray2 getMovingPath(){ return movingPath; }
	Point2 getBase() { ray2 r = this->getMovingPath();  return r.base();  }
	vector2 getDir() { ray2 r = this->getMovingPath();  return r.direction();  }
	

	private:
		float radius;
		float weight;
        ray2  movingPath;

};

Ball::Ball()
{
   radius =	0.5;
   weight =20;
   movingPath.set(Point2(2,0),vector2(-4,0));
}

Ball::Ball(float r,float w, ray2 path)
{
   radius =	r;
   weight =w;
   movingPath = path;

}

void Ball::setMovingPath(Point2 p,vector2 v)
{
	movingPath.set(p,v);


}

void Ball::drawBall()
{
	Point2 position = movingPath.base();
	
	glPushMatrix();
		glTranslatef(position.getX(),position.getY(),0);
		glutSolidSphere(this->radius,40,40);
	glPopMatrix();
}

float gettime()
{
    static __int64 i64Frequency=0;
    static __int64 i64BeginCount=0;
    if (i64Frequency==0){	// do this only for the first time
       QueryPerformanceFrequency((LARGE_INTEGER*)&i64Frequency);
       QueryPerformanceCounter((LARGE_INTEGER*)&i64BeginCount); //retrieve the number of
												//ticks since system start (64bit int).

    }
    __int64 i64CurrentCount;
    QueryPerformanceCounter((LARGE_INTEGER*)&i64CurrentCount);
    return  (float)(i64CurrentCount-i64BeginCount)/i64Frequency;
}



void Ball::moveBall()
{
	static float prevtime=0.0f;		// previous frame’s time
    float currtime = gettime();		// current frame’s time
    float elapsedtime = currtime - prevtime;	// elapsed time	
	
	
	Point2 newPosition = movingPath.base()+(elapsedtime*movingPath.direction());
	movingPath.setBase(newPosition);
	//printf("%f\t       %f\n",newPosition.getX(),newPosition.getY());
	//printf("elapsed time is %f\n",elapsedtime);
			
	prevtime=currtime;

}



