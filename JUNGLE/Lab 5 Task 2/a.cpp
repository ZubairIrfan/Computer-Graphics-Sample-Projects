#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include "RGBA.h"
#include "wav.h"

RGBApixmap pix[10];
double x = 0, y=0;

int pos_x=0,pos_y=0;
int pos_x2=-100, pos_y2=100;
int pos_x3=-300, pos_y3=00;
int bird_x=1000, bird_y=830;
int bird2_x=1100, bird2_y=730;
int bird3_x=1030, bird3_y=890;
int bird4_x=1120, bird4_y=810;
int bird5_x=1280, bird5_y=920;
double tree_x=0, tree_y=0.75;
double tree2_x=0, tree2_y=0.5;
double tree3_x=0, tree3_y=0.25;
double tree4_x=0, tree4_y=0;
int bird_fr_x = -100 , bird_fr_y=730;
int bird2_fr_x = -150 , bird2_fr_y=830;
int bird3_fr_x = -190 , bird3_fr_y=690;
float color=0.0;
bool check_morning=false;
void myInit(void)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0

  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  PlayBackgroundSound("JUNGLE.wav");
}
void drawTrees(){
	//drawTrees  
	 //1
	 glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree_x,tree_y);
	 glVertex2d(200,100);
	 glTexCoord2f(tree_x+(0.06666666666666666666666666666667),tree_y);
	 glVertex2d(400,100);
	 glTexCoord2f(tree_x+(0.06666666666666666666666666666667),tree_y+0.25);
	 glVertex2d(400,500);
	  glTexCoord2f(tree_x,tree_y+0.25);
	 glVertex2d(200,500);
	 glEnd();
	 //2
	  glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree2_x,tree2_y);
	 glVertex2d(800,100);
	 glTexCoord2f(tree2_x+(0.06666666666666666666666666666667),tree2_y);
	 glVertex2d(980,100);
	 glTexCoord2f(tree2_x+(0.06666666666666666666666666666667),tree2_y+0.25);
	 glVertex2d(980,600);
	  glTexCoord2f(tree2_x,tree2_y+0.25);
	 glVertex2d(800,600);
	 glEnd();

	 //3
	   glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree3_x,tree3_y);
	 glVertex2d(600,150);
	 glTexCoord2f(tree3_x+(0.06666666666666666666666666666667),tree3_y);
	 glVertex2d(800,150);
	 glTexCoord2f(tree3_x+(0.06666666666666666666666666666667),tree3_y+0.25);
	 glVertex2d(800,550);
	  glTexCoord2f(tree3_x,tree3_y+0.25);
	 glVertex2d(600,550);
	 glEnd();

	 //4
	   glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree4_x,tree4_y);
	 glVertex2d(450,250);
	 glTexCoord2f(tree4_x+(0.06666666666666666666666666666667),tree4_y);
	 glVertex2d(700,250);
	 glTexCoord2f(tree4_x+(0.06666666666666666666666666666667),tree4_y+0.25);
	 glVertex2d(700,680);
	  glTexCoord2f(tree4_x,tree4_y+0.25);
	 glVertex2d(450,680);
	 glEnd();
 //5
	 glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree_x,tree_y);
	 glVertex2d(60,300);
	 glTexCoord2f(tree_x+(0.06666666666666666666666666666667),tree_y);
	 glVertex2d(260,300);
	 glTexCoord2f(tree_x+(0.06666666666666666666666666666667),tree_y+0.25);
	 glVertex2d(260,600);
	  glTexCoord2f(tree_x,tree_y+0.25);
	 glVertex2d(60,600);
	 glEnd();
	 //6
	  glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree2_x,tree2_y);
	 glVertex2d(400,150);
	 glTexCoord2f(tree2_x+(0.06666666666666666666666666666667),tree2_y);
	 glVertex2d(550,150);
	 glTexCoord2f(tree2_x+(0.06666666666666666666666666666667),tree2_y+0.25);
	 glVertex2d(550,500);
	  glTexCoord2f(tree2_x,tree2_y+0.25);
	 glVertex2d(400,500);
	 glEnd();

	 //7
	   glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree3_x,tree3_y);
	 glVertex2d(600,150);
	 glTexCoord2f(tree3_x+(0.06666666666666666666666666666667),tree3_y);
	 glVertex2d(800,150);
	 glTexCoord2f(tree3_x+(0.06666666666666666666666666666667),tree3_y+0.25);
	 glVertex2d(800,550);
	  glTexCoord2f(tree3_x,tree3_y+0.25);
	 glVertex2d(600,550);
	 glEnd();

	 //8
	   glBindTexture(GL_TEXTURE_2D,2003);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(tree4_x,tree4_y);
	 glVertex2d(0,100);
	 glTexCoord2f(tree4_x+(0.06666666666666666666666666666667),tree4_y);
	 glVertex2d(200,100);
	 glTexCoord2f(tree4_x+(0.06666666666666666666666666666667),tree4_y+0.25);
	 glVertex2d(200,400);
	  glTexCoord2f(tree4_x,tree4_y+0.25);
	 glVertex2d(0,400);
	 glEnd();


}
void drawCats(){
	
	 	 //BigCats //1
	glBindTexture(GL_TEXTURE_2D,2001);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(pos_x2+0,pos_y2+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(pos_x2+300,pos_y2+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(pos_x2+300,pos_y2+300);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(pos_x2+0,pos_y2+300);
	 glEnd();
	 //2
	 glBindTexture(GL_TEXTURE_2D,2001);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(pos_x3+0,pos_y3+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(pos_x3+300,pos_y3+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(pos_x3+300,pos_y3+300);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(pos_x3+0,pos_y3+300);
	 glEnd();
	 //3
	 glBindTexture(GL_TEXTURE_2D,2001);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(pos_x+0,pos_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(pos_x+300,pos_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(pos_x+300,pos_y+300);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(pos_x+0,pos_y+300);
	 glEnd();
}
void drawBirds(){
	//bird 1
	 glBindTexture(GL_TEXTURE_2D,2004);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird_x+0,bird_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird_x+140,bird_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird_x+140,bird_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird_x+0,bird_y+80);
	 glEnd();
	 //bird 2
	  glBindTexture(GL_TEXTURE_2D,2004);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird2_x+0,bird2_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird2_x+140,bird2_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird2_x+140,bird2_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird2_x+0,bird2_y+80);
	 glEnd();
	  //bird 3
	  glBindTexture(GL_TEXTURE_2D,2004);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird3_x+0,bird3_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird3_x+140,bird3_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird3_x+140,bird3_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird3_x+0,bird3_y+80);
	 glEnd();
	  //bird 4
	  glBindTexture(GL_TEXTURE_2D,2004);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird4_x+0,bird4_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird4_x+120,bird4_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird4_x+120,bird4_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird4_x+0,bird4_y+80);
	 glEnd();
	  //bird 5
	  glBindTexture(GL_TEXTURE_2D,2004);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird5_x+0,bird5_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird5_x+140,bird5_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird5_x+140,bird5_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird5_x+0,bird5_y+80);
	 glEnd();

	 //bird 1 fr
	 glBindTexture(GL_TEXTURE_2D,2005);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird_fr_x+0,bird_fr_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird_fr_x+110,bird_fr_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird_fr_x+110,bird_fr_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird_fr_x+0,bird_fr_y+80);
	 glEnd();
	 //bird 2 fr
	  glBindTexture(GL_TEXTURE_2D,2005);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird2_fr_x+0,bird2_fr_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird2_fr_x+120,bird2_fr_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird2_fr_x+120,bird2_fr_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird2_fr_x+0,bird2_fr_y+80);
	 glEnd();
	  //bird 3  fr
	  glBindTexture(GL_TEXTURE_2D,2005);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(x,y);
	 glVertex2d(bird3_fr_x+0,bird3_fr_y+0);
	 glTexCoord2f(x+0.5,y);
	 glVertex2d(bird3_fr_x+140,bird3_fr_y+0);
	 glTexCoord2f(x+0.5,y+0.25);
	 glVertex2d(bird3_fr_x+140,bird3_fr_y+80);
	  glTexCoord2f(x,y+0.25);
	 glVertex2d(bird3_fr_x+0,bird3_fr_y+80);
	  glEnd();

}
void drawEnvironment(){
	//drawing sun
	 if(color>0.4){
		  glBindTexture(GL_TEXTURE_2D,2006);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2d(150,800);
	 glTexCoord2f(1,0);
	 glVertex2d(250,800);
	 glTexCoord2f(1,1);
	 glVertex2d(250,900);
	  glTexCoord2f(0,1);
	 glVertex2d(150,900);
	  glEnd();
	 }
	 if(color<0.6){
		 //moon
		  glBindTexture(GL_TEXTURE_2D,2007);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2d(750,800);
	 glTexCoord2f(1,0);
	 glVertex2d(850,800);
	 glTexCoord2f(1,1);
	 glVertex2d(850,900);
	  glTexCoord2f(0,1);
	 glVertex2d(750,900);
	  glEnd();
	  //stars
	  glBindTexture(GL_TEXTURE_2D,2008);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2d(0,700);
	 glTexCoord2f(1,0);
	 glVertex2d(1000,700);
	 glTexCoord2f(1,1);
	 glVertex2d(1000,1000);
	  glTexCoord2f(0,1);
	 glVertex2d(0,1000);
	  glEnd();

	 }
	
}
void display(void)
{
	
	 glClearColor(0.0f+color,0.0f+color,0.0f+color,0.5f); 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0,1000,0,1000);
	glEnable(GL_TEXTURE_2D);

	//background
	glBindTexture(GL_TEXTURE_2D,2002);
	 glBegin(GL_POLYGON);
	 glTexCoord2f(0,0);
	 glVertex2d(0,0);
	 glTexCoord2f(1,0);
	 glVertex2d(1000,0);
	 glTexCoord2f(1,1);
	 glVertex2d(1000,1000);
	  glTexCoord2f(0,1);
	 glVertex2d(0,1000);
	 glEnd();

	 drawTrees();
	 drawCats();
	 drawBirds();
	 drawEnvironment();
	 
	 glDisable(GL_TEXTURE_2D);

	 

	  glFlush();
}
void myTimer(int t){
	//for cats animation
	if(x+0.5>=1){
		x=0;
		y=y+0.25;
	}
	else
		x=x+0.5;
	if(y+0.25>=1){
		y=0;
	}

	//for tree animation
	//tree 1
	if(tree_x+(0.06666666666666666666666666666667)>=1){
		tree_x=0;

	}
	else
		tree_x=tree_x+(0.06666666666666666666666666666667);

	std :: cout <<tree_x <<std :: endl;
	//tree 2
	if(tree2_x+(0.06666666666666666666666666666667)>=1){
		tree2_x=0;
	}
	else
		tree2_x=tree2_x+(0.06666666666666666666666666666667);
	//tree 3
	if(tree3_x+(0.06666666666666666666666666666667)>=1){
		tree3_x=0;
	}
	else
		tree3_x=tree3_x+(0.06666666666666666666666666666667);
	//tree 4
	if(tree4_x+(0.06666666666666666666666666666667)>=1){
		tree4_x=0;
	}
	else
		tree4_x=tree4_x+(0.06666666666666666666666666666667);


	//for cats movements
	pos_x=pos_x+30;
	pos_x2=pos_x2+30;
	pos_x3=pos_x3+20;
	bird_x=bird_x-25;
	bird2_x=bird2_x-20;
	bird3_x=bird3_x-30;
	bird4_x=bird4_x-40;
	bird5_x=bird5_x-30;

	bird3_fr_x=bird3_fr_x+50;
	bird_fr_x=bird_fr_x+20;
	bird2_fr_x=bird2_fr_x+30;
	if(pos_x>1000)
		pos_x=-100;
	if(pos_x2>1000)
		pos_x2=-200;
	if(pos_x3 >1000)
		pos_x3=-400;

	if(bird_fr_x>1000)
		bird_fr_x=-100;
	if(bird2_fr_x>1000)
		bird2_fr_x=-200;
	if(bird3_fr_x >1000)
		bird3_fr_x=-150;

	if(bird_x <-180)
		bird_x=1050;
	if(bird2_x <-180)
		bird2_x=1150;
	if(bird3_x <-180)
		bird3_x=1050;
	if(bird4_x <-180)
		bird4_x=1150;
	if(bird5_x <-180)
		bird5_x=1350;

	//backcolor logic
	if(check_morning==false){
	color=color+0.02;
	}
	else
		color= color-0.02;

	if(color+0.05 >= 1)
		check_morning=true;
	
	if(color<=0)
		check_morning=false;

	glutPostRedisplay();
   glutTimerFunc(200,myTimer,t);

}

void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("JUNGLE");
  myInit();
  pix[0].readBMPFile("runningcat.bmp",1);
  pix[0].setChromaKey(255,255,255);
  pix[0].setTexture(2001);

  pix[1].readBMPFile("Grass2.bmp",1);
   pix[1].setChromaKey(255,255,255);
  pix[1].setTexture(2002);

  pix[2].readBMPFile("tree_sp.bmp",1);
   pix[2].setChromaKey(255,255,255);
  pix[2].setTexture(2003);
  
   pix[3].readBMPFile("birds_sp.bmp",1);
   pix[3].setChromaKey(0,0,255);
  pix[3].setTexture(2004);
 
   pix[4].readBMPFile("birds_sp_fr.bmp",1);
   pix[4].setChromaKey(0,0,255);
    pix[4].setTexture(2005);

   pix[5].readBMPFile("sun.bmp",1);
   pix[5].setChromaKey(255,255,255);
   pix[5].setTexture(2006);
   pix[6].readBMPFile("moon.bmp",1);
   pix[6].setChromaKey(0,0,0);
    pix[6].setTexture(2007);
   pix[7].readBMPFile("stars.bmp",1);
   pix[7].setChromaKey(0,0,0);
    pix[7].setTexture(2008);
 
    glutDisplayFunc(display);
  glutTimerFunc(200,myTimer,1);
  glutMainLoop();
}