#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include "RGBA.h"

int mario_x=16; int mario_y=1;
float gx,gy,r=3,gd=1;
RGBApixmap pix;
RGBApixmap Flagpix1;
RGBApixmap Flagpix2;
RGBApixmap Finishpix;
RGBApixmap GameOver,YouWin;

bool game_stop=false;
bool game_over=false;
//bhoot axis initialization
int bhoot_1_x=32; int bhoot_1_y=95;
int bhoot_2_x=66; int bhoot_2_y=86;
int bhoot_3_x=96; int bhoot_3_y=54;
int bhoot_4_x=66; int bhoot_4_y=46;
int bhoot_5_x=44; int bhoot_5_y=4;

int bhoot_1_min = 95; int bhoot_1_max = 20;
int bhoot_2_min = 94; int bhoot_2_max = 20;
int bhoot_3_min = 95; int bhoot_3_max = 65;
int bhoot_4_min = 66; int bhoot_4_max = 32;
int bhoot_5_min = 4; int bhoot_5_max = 20;

bool bhoot_1_check=false;
bool bhoot_2_check=false;
bool bhoot_3_check=false;
bool bhoot_4_check=false;
bool bhoot_5_check=false;

int route_1_x_max = 17, route_1_min=0;
int route_2_x_max = 95, route_2_min=0;
int route_3_x_max = 17, route_3_min=0;
int route_4_x_max = 93, route_4_min=17;
int route_5_x_max = 30, route_5_min=0;
int route_6_x_max = 100, route_6_min=30;
int route_7_x_max = 93, route_7_min=17;
int route_8_x_max = 64, route_8_min=30;
int route_9_x_max = 95, route_9_min=64;

int current_route =1;
void setRouteNumber(){
	if(mario_x == 16 && mario_y >=route_1_min && mario_y <route_1_x_max){
	current_route = 1;
}
	else
if(mario_y ==17 && mario_x>route_2_min && mario_x <route_2_x_max){
	current_route = 2;
}
else
if(mario_x == 30 && mario_y<route_4_x_max && mario_y>route_4_min){
	current_route = 4;
}
else
if(mario_x ==42 && mario_y<17 && mario_y>0){
	current_route = 3;
}
else
if(mario_y==59 && mario_x<route_5_x_max && mario_x>route_5_min){
	current_route=5;
}
else
if(mario_y==83 && mario_x<route_6_x_max && mario_x>route_6_min){
	current_route=6;
}
else
if(mario_x==64 && ((mario_y<route_7_x_max &&mario_y>83) || (mario_y>route_7_min && mario_y<83))){
	current_route=7;
}
else
if(mario_y==51 && mario_x<route_9_x_max && mario_x>route_9_min){
	current_route=9;
}
else
if(mario_y==43 && mario_x<route_8_x_max && mario_x>route_8_min){
	current_route=8;
}

}
void drawWalls(){
	glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,100,0,100);

	//wall number 1
	glColor3f(0.75f,0.4f,0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(14,0);
	glVertex2f(14,16);
	glVertex2f(0,16);
	glEnd();

	//wall number 2
	glBegin(GL_POLYGON);
	glVertex2f(0,24);
	glVertex2f(28,24);
	glVertex2f(28,58);
	glVertex2f(0,58);
	glEnd();

	//wall number 3
	glBegin(GL_POLYGON);
	glVertex2f(0,66);
	glVertex2f(28,66);
	glVertex2f(28,100);
	glVertex2f(0,100);
	glEnd();

	//wall number 4
	glBegin(GL_POLYGON);
	glVertex2f(36,90);
	glVertex2f(62,90);
	glVertex2f(62,100);
	glVertex2f(36,100);
	glEnd();

	//wall number 5
	glBegin(GL_POLYGON);
	glVertex2f(36,50);
	glVertex2f(62,50);
	glVertex2f(62,82);
	glVertex2f(36,82);
	glEnd();

	//wall number 6
	glBegin(GL_POLYGON);
	glVertex2f(36,24);
	glVertex2f(62,24);
	glVertex2f(62,42);
	glVertex2f(36,42);
	glEnd();

	//wall number 7
	glBegin(GL_POLYGON);
	glVertex2f(22,0);
	glVertex2f(40,0);
	glVertex2f(40,16);
	glVertex2f(22,16);
	glEnd();

	//wall number 8
	glBegin(GL_POLYGON);
	glVertex2f(48,0);
	glVertex2f(100,0);
	glVertex2f(100,16);
	glVertex2f(48,16);
	glEnd();

	//wall number 9
	glBegin(GL_POLYGON);
	glVertex2f(70,24);
	glVertex2f(100,24);
	glVertex2f(100,50);
	glVertex2f(70,50);
	glEnd();

	//wall number 10
	glBegin(GL_POLYGON);
	glVertex2f(70,58);
	glVertex2f(100,58);
	glVertex2f(100,82);
	glVertex2f(70,82);
	glEnd();

	//wall number 11
	glBegin(GL_POLYGON);
	glVertex2f(70,90);
	glVertex2f(100,90);
	glVertex2f(100,100);
	glVertex2f(70,100);
	glEnd();

	//closed Doors
	//1
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0,16);
	glVertex2f(1,16);
	glVertex2f(1,24);
	glVertex2f(0,24);
	glEnd();

	//2
	glBegin(GL_POLYGON);
	glVertex2f(0,58);
	glVertex2f(1,58);
	glVertex2f(1,66);
	glVertex2f(0,66);
	glEnd();

	//3
	glBegin(GL_POLYGON);
	glVertex2f(28,99);
	glVertex2f(36,99);
	glVertex2f(36,100);
	glVertex2f(28,100);
	glEnd();
	
	//4
	glBegin(GL_POLYGON);
	glVertex2f(62,99);
	glVertex2f(70,99);
	glVertex2f(70,100);
	glVertex2f(62,100);
	glEnd();

	//5
	glBegin(GL_POLYGON);
	glVertex2f(99,50);
	glVertex2f(100,50);
	glVertex2f(100,58);
	glVertex2f(99,58);
	glEnd();

	//6
	glBegin(GL_POLYGON);
	glVertex2f(99,16);
	glVertex2f(100,16);
	glVertex2f(100,24);
	glVertex2f(99,24);
	glEnd();

	//7
	glBegin(GL_POLYGON);
	glVertex2f(40,0);
	glVertex2f(48,0);
	glVertex2f(48,1);
	glVertex2f(40,1);
	glEnd();
}
void drawBhoot(int x, int y){
	//head
	float color_1 = rand()%255;
	float color_2 = rand()%255;
	float color_3 = rand()%255;

	glColor3f(color_1/255,color_2/255,color_3/255);
	for(float a=0;a<3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f(x+cos(a)*r,y+sin(a)*r);
		glVertex2f(x+cos(a+0.01)*r,y+sin(a+0.01)*r);
		glVertex2f(x,y);
		glEnd();
	}
	//body
	glBegin(GL_POLYGON);
	glVertex2f(x+r,y);
	glVertex2f(x+r,y-r);
	glVertex2f(x+r/2,y-r+gd);
	glVertex2f(x,y-r);
	glVertex2f(x-r/2,y-r+gd);
	glVertex2f(x-r,y-r);
	glVertex2f(x-r,y);
	glEnd();

	//Eyes
	glColor3f(115.0f/255,4.0f/255,15.0f/255);
	for(float a=0;a<2*3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f((x-1)+cos(a)*0.5,(y+0.5)+sin(a)*0.5);
		glVertex2f((x-1)+cos(a+0.01)*0.5,(y+0.5)+sin(a+0.01)*0.5);
		glVertex2f(x-1,y+0.5);
		glEnd();
	}
	glColor3f(115.0f/255,4.0f/255,15.0f/255);
	for(float a=0;a<2*3.142;a+=0.01){
		glBegin(GL_POLYGON);
		glVertex2f((x+1)+cos(a)*0.5,(y+0.5)+sin(a)*0.5);
		glVertex2f((x+1)+cos(a+0.01)*0.5,(y+0.5)+sin(a+0.01)*0.5);
		glVertex2f((x+1),(y+0.5));
		glEnd();
	}

}
void moveBhoots(){
	//moving Bhoot 1
	if(bhoot_1_y==bhoot_1_min){
		bhoot_1_check=true;
	}
	if(bhoot_1_y==bhoot_1_max){
		bhoot_1_check=false;
	}
	if(bhoot_1_check==false){
		bhoot_1_y++;
	}
	else
		bhoot_1_y--;

	//moving Bhoot 2
	if(bhoot_2_y==bhoot_2_min){
		bhoot_2_check=true;
	}
	if(bhoot_2_y==bhoot_2_max){
		bhoot_2_check=false;
	}
	if(bhoot_2_check==false){
		bhoot_2_y=bhoot_2_y+2;
	}
	else
		bhoot_2_y=bhoot_2_y-2;

	//moving Bhoot 3
	if(bhoot_3_x==bhoot_3_min){   //95    
		bhoot_3_check=false;
	}
	if(bhoot_3_x==bhoot_3_max){ //66
		bhoot_3_check=true;
	}
	if(bhoot_3_check==false){
		bhoot_3_x=bhoot_3_x-1;
	}
	else
		bhoot_3_x=bhoot_3_x+1;

	//moving Bhoot 4
	if(bhoot_4_x==bhoot_4_min){   //95    
		bhoot_4_check=false;
	}
	if(bhoot_4_x==bhoot_4_max){ //66
		bhoot_4_check=true;
	}
	if(bhoot_4_check==false){
		bhoot_4_x=bhoot_4_x-1;
	}
	else
		bhoot_4_x=bhoot_4_x+1;

	//moving Bhoot 5
	if(bhoot_5_y==bhoot_5_min){   //95    
		bhoot_5_check=false;
	}
	if(bhoot_5_y==bhoot_5_max){ //66
		bhoot_5_check=true;
	}
	if(bhoot_5_check==false){
		bhoot_5_y=bhoot_5_y+1;
	}
	else
		bhoot_5_y=bhoot_5_y-1;

}
void checkBhootCollision(){
	std :: cout << "bhoot x y" <<std :: endl;
    std :: cout << bhoot_5_x <<std :: endl;
    std :: cout << bhoot_5_y <<std :: endl;
	if((mario_x+8 >=bhoot_1_x || mario_y+8==bhoot_1_y || mario_y==bhoot_1_y+3)&& mario_x+2<=bhoot_1_x){
		
		if(mario_x+8>=bhoot_1_x  && ((bhoot_1_y<=mario_y+5 && abs(bhoot_1_y-mario_y)<=4)|| (bhoot_1_y>=mario_y-5 && abs(bhoot_1_y-mario_y)<=4))){
			game_over=true;
		game_stop=true;
		}
		else if((mario_y+8==bhoot_1_y || mario_y-3==bhoot_1_y) && mario_x+2==bhoot_1_x){
		
			game_over=true;
		game_stop=true;
		}
	}

		//checking bhoot 2
		
			if((mario_x+8 >=bhoot_2_x || mario_y+8==bhoot_2_y || mario_y==bhoot_2_y+3)&&mario_x+2<=bhoot_2_x){
		
		if(mario_x+8>=bhoot_2_x  && ((bhoot_2_y<=mario_y+5 && abs(bhoot_2_y-mario_y)<=4)|| (bhoot_2_y>=mario_y-5 && abs(bhoot_2_y-mario_y)<=4))){
			std :: cout << "collision detected **********************2-1" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
		else if((mario_y+8==bhoot_2_y || mario_y-3==bhoot_2_y) && mario_x+2==bhoot_2_x){
			std :: cout << "collision detected **********************2-2" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
		//checking bhoot 3
		
			if((mario_x+8 >=bhoot_3_x || mario_y+8==bhoot_3_y || mario_y==bhoot_3_y+3)&&mario_x+2<=bhoot_3_x){
		
		if(mario_x+8>=bhoot_3_x  && ((bhoot_3_y<=mario_y+5 && abs(bhoot_3_y-mario_y)<=4)|| (bhoot_3_y>=mario_y-5 && abs(bhoot_3_y-mario_y)<=4))){
			std :: cout << "collision detected **********************3-1" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
		else if((mario_y+8==bhoot_3_y || mario_y-3==bhoot_3_y) && mario_x+2==bhoot_3_x){
			std :: cout << "collision detected **********************3-2" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
	}
			}
			//checking bhoot 4
		
			if((mario_x+8 >=bhoot_4_x || mario_y+8==bhoot_4_y || mario_y==bhoot_4_y+3)&&mario_x+2<=bhoot_4_x){
		
		if(mario_x+8>=bhoot_4_x  && ((bhoot_4_y<=mario_y+5 && abs(bhoot_4_y-mario_y)<=4)|| (bhoot_4_y>=mario_y-5 && abs(bhoot_4_y-mario_y)<=4))){
			std :: cout << "collision detected **********************4-1" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
		else if((mario_y+8==bhoot_4_y || mario_y-3==bhoot_4_y) && mario_x+2==bhoot_4_x){
			std :: cout << "collision detected **********************4-2" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
	}
					//checking bhoot 5
		
			if((mario_x+8 >=bhoot_5_x || mario_y+8==bhoot_5_y || mario_y==bhoot_5_y+3)&&mario_x+2<=bhoot_5_x){
		
		if(mario_x+8>=bhoot_5_x  && (((bhoot_5_y<=mario_y+5 && abs(bhoot_5_y-mario_y)<=3))|| (bhoot_5_y>=mario_y-5 && abs(bhoot_5_y-mario_y)<=3))){
			std :: cout << "collision detected **********************5-1" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
		else if((mario_y+8==bhoot_5_y || mario_y-3==bhoot_5_y) && mario_x+2==bhoot_5_x){
			std :: cout << "collision detected **********************5-2" <<std :: endl;
			game_over=true;
		game_stop=true;
		}
	}
			}
	//if((mario_x+8 == bhoot_1_x && mario_y+8 == bhoot_1_y) || (mario_x+8 == bhoot_2_x && mario_y+8 == bhoot_2_y) || (mario_x+8 == bhoot_3_x && mario_y+8 == bhoot_3_y) || (mario_x+8 == bhoot_4_x && mario_y+8 == bhoot_4_y) || (mario_x+8 == bhoot_5_x && mario_y+8 == bhoot_5_y)){
	//	game_over=true;
	//	game_stop=true;
	//}

void display(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,100,0,100);
	 drawWalls();
	
	 setRouteNumber();
	 if(mario_x>99){
		 glRasterPos2f(0,40);
		 game_stop=true;
	 YouWin.mDraw();
	 }
	 if(game_over==true){
		 glRasterPos2f(20,20);
		 GameOver.mDraw();
	 }
	 drawBhoot(bhoot_1_x,bhoot_1_y);
	 drawBhoot(bhoot_2_x,bhoot_2_y);
	 drawBhoot(bhoot_3_x,bhoot_3_y);
	 drawBhoot(bhoot_4_x,bhoot_4_y);
	 drawBhoot(bhoot_5_x,bhoot_5_y);
	
	 glRasterPos2f(mario_x,mario_y);
	 pix.mDraw();
	 
	 glRasterPos2f(23,0);
	 Flagpix1.mDraw();
	  glRasterPos2f(8.5,0);
	 Flagpix2.mDraw();
	   glRasterPos2f(92,91);
	 Finishpix.mDraw();

	  checkBhootCollision();
	  glFlush();
}
void myKeyboard(unsigned char key, int x,int y){
	if(game_stop==false){
	if(key=='a'){
		if(current_route==2 && mario_x >route_2_min && mario_x<=route_2_x_max){
mario_x--;
		}
		else if(current_route==4 && mario_y==59){
			mario_x--;
		}
		else if(current_route==5 && mario_x<=route_5_x_max && mario_x > route_5_min){
			mario_x--;
		}
		else if(current_route==6 && mario_x<=route_6_x_max && mario_x > route_6_min){
			mario_x--;
		}
		else if(current_route==9 && mario_x<=route_9_x_max && mario_x >= route_9_min){
			mario_x--;
		}
		else if(current_route==8 && mario_x<route_8_x_max && mario_x >= route_8_min){
			mario_x--;
		}
		else if(current_route==7 && mario_y==43){
			mario_x--;
		}
std :: cout << "next line" <<std :: endl;
std :: cout << mario_x <<std :: endl;
	std :: cout << mario_y <<std :: endl;
	
	}
	else if(key =='d')
	{
		if(current_route==2 && mario_x >=route_2_min && mario_x<route_2_x_max){
mario_x++;
		}
		else if(current_route==5 && mario_x<route_5_x_max && mario_x >= route_5_min){
			mario_x++;
		}
		else if(current_route==6 && mario_x<route_6_x_max && mario_x >= route_6_min){
			mario_x++;
		}
		else if(current_route==4 && mario_y==83){
			mario_x++;
		}
		else if(current_route==7 && mario_y==51){
			mario_x++;
		}
		else if(current_route==9 && mario_x<route_9_x_max && mario_x >= route_9_min){
			mario_x++;
		}
		else if(current_route==4 && mario_y==43){
			mario_x++;
		}
		else if(current_route==8 && mario_x<route_8_x_max && mario_x >= route_8_min){
			mario_x++;
		}

std :: cout << "next line" <<std :: endl;
std :: cout << mario_x <<std :: endl;
	std :: cout << mario_y <<std :: endl;
	}
	else if(key =='w')
	{
		if(current_route==1 && mario_y <route_1_x_max){
mario_y++;
		}
		else if(current_route==2 && mario_x==30){
			mario_y++;
		}
		else if(current_route==4 && mario_y <route_4_x_max){
			mario_y++;
		}
		else if(current_route==3 && mario_y <route_4_x_max){
			mario_y++;
		}
		else if(current_route==6 && mario_x==64){
			mario_y++;
		}
		else if(current_route==7 && mario_y <route_7_x_max && mario_y >= route_7_min){
			mario_y++;
		}
		else if(current_route==2 && mario_x==64){
			mario_y++;
		}
std :: cout << "next line" <<std :: endl;
	std :: cout << mario_x << std :: endl;
	std :: cout << mario_y << std :: endl;

	}
	else if(key =='s')
	{
		if(current_route==1 && mario_y >route_1_min){
		
mario_y--;
		
		}
		else if(current_route==2 && mario_y==17 && mario_x==16){
			mario_y--;
		}
		else if(current_route==2 && mario_y <route_2_x_max && mario_x==42){
			mario_y--;
		}
		else if(current_route==4 && mario_y >route_4_min){
			mario_y--;
		}
		else if(current_route==3 && mario_y >route_3_min){
			mario_y--;
		}
		else if(current_route==6 && mario_x==64){
			mario_y--;
		}
		else if(current_route==7 && mario_y <=route_7_x_max && mario_y > route_7_min){
			mario_y--;
		}

std :: cout << "next line" <<std :: endl;
std :: cout << mario_x <<std :: endl;
	std :: cout << mario_y <<std :: endl;
	}
	
	
			
}
if(key=='r'){
	game_stop=false;
	mario_x=16;
	mario_y=1;
	game_over=false;
}
glutPostRedisplay();
}

void myTimer(int t)
{
	if(game_stop==false){
	 moveBhoots();
	}
   glutPostRedisplay();
   glutTimerFunc(100,myTimer,t);			
  
	}
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0
  
  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Mario Escape Game");
    myInit();

  pix.readBMPFile("m1.bmp",1);
  pix.setChromaKey(255,255,255);
  Flagpix1.readBMPFile("S1.bmp",1);
  Flagpix1.setChromaKey(255,255,255);
   Flagpix2.readBMPFile("S2.bmp",1);
  Flagpix2.setChromaKey(255,255,255);
  Finishpix.readBMPFile("Finish.bmp",1);
  Finishpix.setChromaKey(255,255,255);
   GameOver.readBMPFile("gameover.bmp",1);
  GameOver.setChromaKey(255,255,255);
   YouWin.readBMPFile("youwin.bmp",1);
  YouWin.setChromaKey(255,255,255);

  glutDisplayFunc(display);
  glutTimerFunc(500,myTimer,1);
  glutKeyboardFunc(myKeyboard);
  glutMainLoop();
}