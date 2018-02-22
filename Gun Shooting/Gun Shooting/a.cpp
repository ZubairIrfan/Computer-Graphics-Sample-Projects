#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Turtle.h"
#include <glut.h>
#include <Windows.h>
#include "RGBA.h"


float xx = 0, yy=0;
float line1_x =138, line1_y=202;
float line1_x2=332, line1_y2=202;
float bullet_x=138, bullet_y = 198;
float offset = 0;
bool fire = false;
bool check = false;
bool headshot=false;
bool star= false;
float star_radius = 6;
float star_angle=0;
bool movingDown = false;
RGBApixmap pix[6];
void myInit(void)
{
  glClearColor(0.3f,0.3f,0.4f,1.0f);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
  //or glAlphaFunc(GL_NOTEQUAL,0.0);// accept fragment if fragment alpha not= reference alpha i.e. 1.0
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,200,0,200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
}
void display(void)
{
	
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	 glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0,0,1200,640);
   gluOrtho2D(0,1200,0,640);

    glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,2005);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0,0);
	  glVertex2f(0,0);
	    glTexCoord2f(1,0);
	  glVertex2f(1200,0); 
	  glTexCoord2f(1,1);
	  glVertex2f(1200,480);
	  glTexCoord2f(0,1);
	  glVertex2f(0,480);
	  glEnd();
	  glDisable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,2001);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0,0);
	  glVertex2f(10,10);
	    glTexCoord2f(1,0);
	  glVertex2f(140,10); 
	  glTexCoord2f(1,1);
	  glVertex2f(140,240);
	  glTexCoord2f(0,1);
	  glVertex2f(0,240);
	  glEnd();
	  glDisable(GL_TEXTURE_2D);

	  glColor3f(0.0f,0.6f,0.0f);

	  glBegin(GL_LINES);
	  glVertex2f(line1_x,line1_y);
	  glVertex2f(line1_x2, line1_y2);
	  glEnd();
  glColor3f(0.9f,0.9f,0.9f);


	   glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,2003);
  glBegin(GL_POLYGON);
  if(movingDown==false){
	  glTexCoord2f(0,0);
	  glVertex2f(800,10);
	    glTexCoord2f(1,0);
	  glVertex2f(930,10); 
	  glTexCoord2f(1,1);
	  glVertex2f(930,280);
	  glTexCoord2f(0,1);
	  glVertex2f(800,280);
  }
  else{
	  glTexCoord2f(0,0);
	  glVertex2f(930,130);
	    glTexCoord2f(1,0);
	  glVertex2f(930,0); 
	  glTexCoord2f(1,1);
	  glVertex2f(1200,0);
	  glTexCoord2f(0,1);
	  glVertex2f(1200,130);
  

  }
	  glEnd();

	  glDisable(GL_TEXTURE_2D);

	  if(fire){
		  glRasterPos2d(bullet_x,bullet_y);
		  pix[2].mDraw();
	  }

	  if(headshot==true){
		  glRasterPos2d(300,300);
		  pix[4].mDraw();
	  }

	  if(star==true){

		  glRasterPos2f(930+star_radius*cos(star_angle),290+star_radius*sin(star_angle));
		  pix[6].mDraw();
	  }

	  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100,100,-100,100);


	 glFlush();
  
}


void myTimer(int t)
{
	if(fire==true){ 
		if(check==false){
			offset = 0;
			check = true;
		}
		offset+=0.05;
		//applying parametric eqquation of line to bullet
		bullet_x = line1_x+ (line1_x2-line1_x)*offset;
		bullet_y = line1_y+ (line1_y2-line1_y)*offset;
		}

	if(bullet_x>1000 || bullet_y >480){   //range limit
		fire=false;
		check=false;
		bullet_x=138;
		bullet_y = 198;
	}
	if(bullet_x>=879 && (bullet_y>=(480-238) && bullet_y <=(480-203)) ){   //check for head shot
		headshot=true;
		star = true;
		movingDown=true;
	}
   glutPostRedisplay();
   glutTimerFunc(10,myTimer,t);			
  
	}
void myKeyboard(unsigned char key, int x, int y){
	if(key=='w'){
		if(fire==false){
		line1_x2--;
		line1_y2 = line1_y2+3;
		}
		//std :: cout << "asdasdsa" <<std :: endl;

	}
	if(key=='s'){
		if(fire==false){
		line1_x2++;
		line1_y2 = line1_y2-3;
		}
		//std :: cout << "asdasdsa" <<std :: endl;
	}
	if(key=='d'){
		if(line1_x2<600)
		line1_x2=line1_x2+2;
		
	}
	if(key=='a'){
		if(line1_x2>200)
			line1_x2=line1_x2-2;	
	}
	if(key=='f'){
		fire= true;
		headshot=false;
	}
	if(key=='r'){
		headshot=false;
		star= false;
		movingDown=false;
	}
	 std :: cout << y <<std :: endl;
	glutPostRedisplay();

}
void main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1200, 480);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Demo");
  myInit();
  pix[1].readBMPFile("gunman.bmp",1);
  pix[1].setChromaKey(255,255,255);
  pix[1].setTexture(2001);
  pix[2].readBMPFile("bullet.bmp",1);
  pix[2].setChromaKey(255,255,255);
  pix[2].setTexture(2002);
 pix[3].readBMPFile("gunman2.bmp",1);
  pix[3].setChromaKey(255,255,255);
  pix[3].setTexture(2003);
  pix[4].readBMPFile("headshot.bmp",1);
  pix[4].setChromaKey(255,255,255);
  pix[4].setTexture(2004);
   pix[5].readBMPFile("background.bmp",1);
  pix[5].setTexture(2005);
  
  /* pix[6].readBMPFile("star.bmp",1);
  pix[6].setTexture(2006);*/
  pix[6].setChromaKey(255,255,255);


 glutDisplayFunc(display);
  glutTimerFunc(500,myTimer,1);
  glutKeyboardFunc(myKeyboard);
  glutMainLoop();
}


