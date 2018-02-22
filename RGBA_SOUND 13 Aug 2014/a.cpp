/****************************************************************************
 *                                                                          *
 * Working demo of RGBA class along with sound.
  *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <glut.h>
#include <Windows.h>
#include "RGBA.h"
#include "wav.h"


RGBApixmap pix[6];
float gx,gy,r=4,gd=1;
int bx=rand()%95,by=rand()%95;
int bx2=rand()%95,by2=rand()%95;
bool bhoot_check=true;
bool mouse_click = false;
int x = 0; int y=0;
bool check = true;
bool check2 = true;
int mario_x=0;
int mario_y=0;
int randomMovement = rand()%4;
int randomMovement2 = rand()%4;
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0
  

 /* glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
   PlayBackgroundSound("backmusic.wav");
  gluOrtho2D(0,640,0,480);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();*/


 
}

void drawButton(int x,int y){
		glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x+20,y);
	glVertex2f(x+20,y+10);
	glVertex2f(x,y+10);
	glEnd();
	if(mouse_click){
	glColor3f(79.0f/255,157.0f/255,26.0f/255);
	}
	else
	{
		glColor3f(234.0f/255,10.0f/255,250.0f/255);
	}
	glBegin(GL_POLYGON);
	glVertex2f(x+2,y+2);
	glVertex2f(x+18,y+2);
	glVertex2f(x+18,y+8);
	glVertex2f(x+2,y+8);
	glEnd();
	
}
void drawBhoot(int x, int y){
	//head
	glColor3f(145.0f/255,34.0f/255,65.0f/255);
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
void setBhoot_1_Location(){
	if((bx > 95 || bx <5 ||by >95 || by<5)&& check==false){
		 randomMovement = rand()%4;
		 check=true;
	 }
	 else
	 {
		 if(randomMovement ==0)  //move up
		 {
			 if(check==true){
				 check = false;
				 bx=rand()%95;
				 by=5;
			 }else
				 by++;
		 }
		 else 
		 if(randomMovement ==1)  //move down
		 {
			 if(check==true){
				 check=false;
				 bx=rand()%95;
				 by=95;
			 }else
				 by--;
		 }
		 else 
		 if(randomMovement ==2)  //move right
		 {
			 if(check==true){
				 check=false;
				 bx=5;
				 by=rand()%95;
			 }else
				 bx++;
		 }
		 else 
			 if(randomMovement ==3)  //move left
		 {
			 if(check==true){
				 check=false;
				 bx=95;
				 by=rand()%95;
			 }else
				 bx--;
		 }
	 }
}
void setBhoot_2_Location(){
	if((bx2 > 95 || bx2 <5 ||by2 >95 || by2<5)&& check2==false){
		 randomMovement2 = rand()%4;
		 check2=true;
	 }
	 else
	 {
		 if(randomMovement2 ==0)  //move up
		 {
			 if(check2==true){
				 check2 = false;
				 bx2=rand()%95;
				 by2=5;
			 }else
				 by2++;
		 }
		 else 
		 if(randomMovement2 ==1)  //move down
		 {
			 if(check2==true){
				 check2=false;
				 bx2=rand()%95;
				 by2=95;
			 }else
				 by2--;
		 }
		 else 
		 if(randomMovement2 ==2)  //move right
		 {
			 if(check2==true){
				 check2=false;
				 bx2=5;
				 by2=rand()%95;
			 }else
				 bx2++;
		 }
		 else 
			 if(randomMovement2 ==3)  //move left
		 {
			 if(check2==true){
				 check2=false;
				 bx2=95;
				 by2=rand()%95;
			 }else
				 bx2--;
		 }
	 }
}


void display(void)
{
	//glClearColor(1.0f,0.0f,0.0f,1.0f);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 
	 glViewport(0,0,50,50);
	 
	  glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,100,0,100);
     glRasterPos2f(0,0);
	
	 pix[0].mDraw();
	//// glRasterPos2f(10,0);
	 //pix[2].mDraw();
	 
	 glRasterPos2f(mario_x,mario_y);
	 pix[1].mDraw();
	

	///* std :: cout << bx <<std :: endl;*/
	//std :: cout << by <<std :: endl;
	// std :: cout << randomMovement <<std :: endl;
	 //moving bhoot
	 setBhoot_1_Location();
	 drawBhoot(bx,by);
	 setBhoot_2_Location();
	
	drawBhoot(bx2,by2);
	//drawButton(40,80);
	 glFlush();
  
}


void myTimer(int t)
{
   glutPostRedisplay();
   glutTimerFunc(100,myTimer,t);			
  
	}

void myMouse(int button,int state, int mx,int my){
	//std :: cout << mx <<std :: endl;
	//std :: cout << my <<std :: endl;
	int r = rand()%100;
	std :: cout << r <<std :: endl;
	if(mx>258 && mx<381 && my<92 && my>48){
	if(mouse_click==true)
		mouse_click=false;
	else
		mouse_click=true;
			
	
	 glutPostRedisplay();
	}
}
void myKeyboard(unsigned char key, int x,int y){

	if(key=='a'){
mario_x--;
	}
	else if(key =='d')
	{
mario_x++;
	}
	else if(key =='w')
	{
mario_y++;
	}
	else if(key =='s')
	{
mario_y--;
	}
	
			glutPostRedisplay();
}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("RGBA and Sound Demo");

  pix[0].readBMPFile("map_real.bmp",1);
  pix[1].readBMPFile("mariostanding.bmp",1);
  pix[1].setChromaKey(192,192,192);  // ye add karna hai mario pe chroma k liay
  pix[2].readBMPFile("ladder.bmp",1);
  pix[2].setChromaKey(255,255,255); // ye add karna hai ladder pe chroma k liay
    
  glutDisplayFunc(display);
    
  myInit();
  //glutIdleFunc(display);
  glutTimerFunc(500,myTimer,1);
  glutMouseFunc(myMouse);
  glutKeyboardFunc(myKeyboard);
  glutMainLoop();
}

