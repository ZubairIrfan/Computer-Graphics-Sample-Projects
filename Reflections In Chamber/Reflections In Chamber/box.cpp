
#include "includes.h"


PolyLine pillars[3];

bool PointInsidePolygon(Point2 p);
ray2 track(Point2(2,0),vector2(20,20));
Ball b1(3,20,track);
std::vector<Point2> normalVectors;
std::vector<Point2> LinesVectors;
std::vector<Point2> PHits;
bool check = true;
bool check1 = true;
bool collidePillar = false;
//float tHit = 0;
//Point2 normal;
//Point2 Phit = Point2(1000,1000);
int count =0;
int collideNormalIndex;

//int pillarIndex;



void calculatePhits(){
	PHits.clear();
	//std::cout <<count++ <<std::endl;
	//std::cout << "Round Completed" << std::endl;
	for(int i=0; i< normalVectors.size();i++){
	Point2 diff = Point2(pillars[0].getVertex(i).getX() - b1.getBase().getX(), pillars[0].getVertex(i).getY()- b1.getBase().getY());
	vector2 dir = b1.getDir();
//	std::cout << "dir X " << dir.deltaX() <<std::endl;
	float numerator = (normalVectors.at(i).getX() * diff.getX()) + (normalVectors.at(i).getY()*diff.getY()); 
	float denom = (normalVectors.at(i).getX()*dir.deltaX() + normalVectors.at(i).getY()*dir.deltaY());
	float thit = numerator / denom;
	/*std::cout << "numerator " << numerator <<std::endl;
	std::cout << "denomerator " << denom <<std::endl;
	std::cout << "tHit " << numerator/denom <<std::endl << std::endl;*/
	PHits.push_back(Point2((int)(b1.getBase().getX()+b1.getDir().deltaX()*thit),(int)(b1.getBase().getY()+b1.getDir().deltaY()*thit)));

	//std::cout << "Phit X " << i+1 << PHits.at(PHits.size()-1).getX()<<std::endl;
	//std::cout << "Phit Y " << i+1 << PHits.at(PHits.size()-1).getY()<<std::endl <<std::endl;
}
	
}
void calculateNewDirection(){
	float newDir1 = 2*(b1.getDir().deltaX()*(normalVectors.at(collideNormalIndex).getX()/(sqrt((pow(normalVectors.at(collideNormalIndex).getX(),2)+pow(normalVectors.at(collideNormalIndex).getY(),2)))))+(b1.getDir().deltaY()*(normalVectors.at(collideNormalIndex).getY()/(sqrt((pow(normalVectors.at(collideNormalIndex).getX(),2)+pow(normalVectors.at(collideNormalIndex).getY(),2))))))); //2 * (c * n )
		//std::cout << "newDir 1 " << newDir1 <<std::endl;
		Point2 newV = Point2(newDir1*(normalVectors.at(collideNormalIndex).getX()/(sqrt((pow(normalVectors.at(collideNormalIndex).getX(),2)+pow(normalVectors.at(collideNormalIndex).getY(),2))))),newDir1*(normalVectors.at(collideNormalIndex).getY()/(sqrt((pow(normalVectors.at(collideNormalIndex).getX(),2)+pow(normalVectors.at(collideNormalIndex).getY(),2))))));   // 2 * (c * n ) * n
		Point2 newV2 = Point2(b1.getDir().deltaX()-newV.getX(),b1.getDir().deltaY()-newV.getY());
		
		b1.setMovingPath(PHits.at(collideNormalIndex),vector2(newV2.getX(),newV2.getY()));
		//b1.setMovingPath(Phit,vector2(-2,2));
		b1.moveBall();
		collidePillar = false;
		calculatePhits();
		//std::cout << "NewDir X " << newV2.getX()<<std::endl;
	    //std::cout << "NewDir Y " << newV2.getY()<<std::endl;
}
void display(void)
{
  cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
  cvs.clearScreen(); //clear screen
  cvs.setWindow(-100,100,-100,100);
  cvs.setViewport(0, 640, 0, 480);
  cvs.drawAxis(0,200,-200,200); // blue color axis
  //cvs.drawAxis(0.4f,0.9f,0.5f);
  cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
  
  //Chamber();

	pillars[0] = Ngon(Point2(0,0),100,6,0);
	pillars[1] = Ngon(Point2(-6,1),10,3,0);
	pillars[2] = Circle(Point2(2,2),10);

	
	if(check==true){
	for(int i=0; i< pillars[0].getNumVertices()-1; i++){
		//std::cout<< pillars[0].getVertex(i).getX()<< "  " << pillars[0].getVertex(i).getY() << std::endl;
		if(i!=pillars[0].getNumVertices()-1)
		LinesVectors.push_back(Point2((pillars[0].getVertex_X(i+1)-pillars[0].getVertex_X(i)),pillars[0].getVertex_Y(i+1)-pillars[0].getVertex_Y(i)));
		else
			LinesVectors.push_back(Point2((pillars[0].getVertex_X(0)-pillars[0].getVertex_X(i)),pillars[0].getVertex_Y(0)-pillars[0].getVertex_Y(i)));
	}
	for(int i=0; i<LinesVectors.size(); i++){
		normalVectors.push_back(Point2(-LinesVectors.at(i).getY(), LinesVectors.at(i).getX()));
	}
	check=false;
	calculatePhits();
	}

	//calculatePhits();

   Chamber(3,pillars);   
   cvs.setColor(0,1,0);

	  for(int i=0;i<PHits.size();i++){
		   if((int)(b1.getBase().getX())==(int)(PHits.at(i).getX()) && (int)(b1.getBase().getY())==(int)(PHits.at(i).getY())){
			    collideNormalIndex = i;
				 calculateNewDirection();
		         break;
	  }

	 }
		if(!collidePillar) 
			b1.moveBall();
    
  b1.drawBall();
  
  glutSwapBuffers();
}// end display




bool PointInsidePolygon(Point2 p)
{
	// See Lecture Discussion and Implement
	// Book Section No:

	return true;
}	
void animate(void)
{
   glutPostRedisplay();

}
int main(int argc, char ** argv)
{
  // the window is opened in the Canvas constructor
  glutDisplayFunc(display);
  glutIdleFunc(animate);
  glutMainLoop();
}//end main

