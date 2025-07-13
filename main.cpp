#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

float speed = 0.5f;
char text[] = " ";
float sun = 0.0f;
float moon = 0.0f;
float plane = 0.0f;
float sunspeed=0.5f;
float moonspeed=0.5f;
int mode=0;
double cloudPosition = 0.0f;
double boatPosition=0.0f;
double carPosition=0.0f;


void sunAnimation(int value){//sun move

    if(sun>250.0f){
        sun = -300.0f;
    }
    sun+=sunspeed;
    glutPostRedisplay();
    glutTimerFunc(25, sunAnimation, 0);
    glutSwapBuffers();
}

void moonAnimation(int value){//moon move

    if(moon>250.0f){
        moon = -300.0f;
    }
    moon+=moonspeed;
    glutPostRedisplay();
    glutTimerFunc(25, moonAnimation, 0);
    glutSwapBuffers();
}

void drawcloud(float x, float y , float r){//Cloud
	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/180 ;

		float dx = r * cos(A);
		float dy = r * sin(A);
		glVertex2f(x+dx,y+dy );
	}
	glEnd();
}

void circle(float x, float y , float r ){

	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/180 ;

		float dx = r * cos(A);
		float dy = r * sin(A);
		glVertex2f(x+dx,y+dy );
	}
	glEnd();
}

void Sprint( float x, float y, char *st)
{
    int l = strlen(st ); // see how many characters are in text string.
    glColor3f(0.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( int i=0; i < l; i++){ // loop until i is greater then l
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void drawsky(){//Sky
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, 1080);
    glVertex2i(1920, 1080);
    glVertex2i(1920,0);
    glEnd();

}

void drawgrass(){//Grass
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, 500);
    glVertex2i(1920, 500);
    glVertex2i(1920,0);
    glEnd();

}

void drawtree(){//Tree
    glBegin(GL_QUADS);
    glVertex2i(60, 450);
    glVertex2i(60, 580);
    glVertex2i(80, 580);
    glVertex2i(80, 450);

    glBegin(GL_QUADS);
    glVertex2i(140, 450);
    glVertex2i(140, 580);
    glVertex2i(160, 580);
    glVertex2i(160, 450);

    glBegin(GL_QUADS);
    glVertex2i(220, 450);
    glVertex2i(220, 580);
    glVertex2i(240, 580);
    glVertex2i(240, 450);

    glBegin(GL_QUADS);
    glVertex2i(300, 450);
    glVertex2i(300, 580);
    glVertex2i(320, 580);
    glVertex2i(320, 450);

    glBegin(GL_QUADS);
    glVertex2i(380, 450);
    glVertex2i(380, 580);
    glVertex2i(400, 580);
    glVertex2i(400, 450);

    glBegin(GL_QUADS);
    glVertex2i(460, 450);
    glVertex2i(460, 580);
    glVertex2i(480, 580);
    glVertex2i(480, 450);

    glBegin(GL_QUADS);
    glVertex2i(540, 450);
    glVertex2i(540, 580);
    glVertex2i(560, 580);
    glVertex2i(560, 450);

    glBegin(GL_QUADS);
    glVertex2i(620, 450);
    glVertex2i(620, 580);
    glVertex2i(640, 580);
    glVertex2i(640, 450);

    glBegin(GL_QUADS);
    glVertex2i(700, 450);
    glVertex2i(700, 580);
    glVertex2i(720, 580);
    glVertex2i(720, 450);

    glBegin(GL_QUADS);
    glVertex2i(780, 450);
    glVertex2i(780, 580);
    glVertex2i(800, 580);
    glVertex2i(800, 450);

    glBegin(GL_QUADS);
    glVertex2i(860, 450);
    glVertex2i(860, 580);
    glVertex2i(880, 580);
    glVertex2i(880, 450);

    glBegin(GL_QUADS);
    glVertex2i(940, 450);
    glVertex2i(940, 580);
    glVertex2i(960, 580);
    glVertex2i(960, 450);

    glBegin(GL_QUADS);
    glVertex2i(1020, 450);
    glVertex2i(1020, 580);
    glVertex2i(1040, 580);
    glVertex2i(1040, 450);

    glBegin(GL_QUADS);
    glVertex2i(1100, 450);
    glVertex2i(1100, 580);
    glVertex2i(1120, 580);
    glVertex2i(1120, 450);

    glBegin(GL_QUADS);
    glVertex2i(1180, 450);
    glVertex2i(1180, 580);
    glVertex2i(1200, 580);
    glVertex2i(1200, 450);

    glBegin(GL_QUADS);
    glVertex2i(1260, 450);
    glVertex2i(1260 ,580);
    glVertex2i(1280, 580);
    glVertex2i(1280, 450);

    glBegin(GL_QUADS);
    glVertex2i(1340, 450);
    glVertex2i(1340, 580);
    glVertex2i(1360, 580);
    glVertex2i(1360, 450);

    glBegin(GL_QUADS);
    glVertex2i(1420, 450);
    glVertex2i(1420, 580);
    glVertex2i(1440, 580);
    glVertex2i(1440, 450);

    glBegin(GL_QUADS);
    glVertex2i(1500, 450);
    glVertex2i(1500, 580);
    glVertex2i(1520, 580);
    glVertex2i(1520, 450);

    glBegin(GL_QUADS);
    glVertex2i(1580, 450);
    glVertex2i(1580 ,580);
    glVertex2i(1600, 580);
    glVertex2i(1600, 450);

    glBegin(GL_QUADS);
    glVertex2i(1660, 450);
    glVertex2i(1660, 580);
    glVertex2i(1680, 580);
    glVertex2i(1680, 450);

    glBegin(GL_QUADS);
    glVertex2i(1740, 450);
    glVertex2i(1740, 580);
    glVertex2i(1760, 580);
    glVertex2i(1760, 450);

    glBegin(GL_QUADS);
    glVertex2i(1820, 450);
    glVertex2i(1820, 580);
    glVertex2i(1840, 580);
    glVertex2i(1840, 450);
    glEnd();
    //glFlush();
}

void drawleaf(){
     //tree leaf color

     circle(70, 570, 45);
     circle(70, 620, 35);
     circle(70, 660, 25);

         circle(150, 570, 45);
    circle(150, 620, 35);
     circle(150, 660, 25);

            circle(150, 570, 45);
    circle(150, 620, 35);
     circle(150, 660, 25);


                 circle(230, 570, 45);
    circle(230, 620, 35);
     circle(230, 660, 25);

                 circle(310, 570, 45);
    circle(310, 620, 35);
     circle(310, 660, 25);

                 circle(390, 570, 45);
    circle(390, 620, 35);
     circle(390, 660, 25);

                 circle(470, 570, 45);
    circle(470, 620, 35);
     circle(470, 660, 25);

                 circle(550, 570, 45);
    circle(550, 620, 35);
     circle(550, 660, 25);

                 circle(630, 570, 45);
    circle(630, 620, 35);
     circle(630, 660, 25);

                 circle(710, 570, 45);
    circle(710, 620, 35);
     circle(710, 660, 25);

                 circle(790, 570, 45);
    circle(790, 620, 35);
     circle(790, 660, 25);


                 circle(870, 570, 45);
    circle(870, 620, 35);
     circle(870, 660, 25);


                 circle(950, 570, 45);
    circle(950, 620, 35);
     circle(950, 660, 25);

                 circle(1030, 570, 45);
    circle(1030, 620, 35);
     circle(1030, 660, 25);

                 circle(1110, 570, 45);
    circle(1110, 620, 35);
     circle(1110, 660, 25);

                 circle(1190, 570, 45);
    circle(1190, 620, 35);
     circle(1190, 660, 25);

                 circle(1270, 570, 45);
    circle(1270, 620, 35);
     circle(1270, 660, 25);

                 circle(1350, 570, 45);
    circle(1350, 620, 35);
     circle(1350, 660, 25);

                 circle(1430, 570, 45);
    circle(1430, 620, 35);
     circle(1430, 660, 25);

                 circle(1510, 570, 45);
    circle(1510, 620, 35);
     circle(1510, 660, 25);

                 circle(1590, 570, 45);
    circle(1590, 620, 35);
     circle(1590, 660, 25);

                 circle(1670, 570, 45);
    circle(1670, 620, 35);
     circle(1670, 660, 25);

                 circle(1750, 570, 45);
    circle(1750, 620, 35);
     circle(1750, 660, 25);

                 circle(1830, 570, 45);
    circle(1830, 620, 35);
     circle(1830, 660, 25);
/*

    glBegin(GL_TRIANGLES);
    glVertex2i(30, 580);
    glVertex2i(70, 700);
    glVertex2i(110, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(100, 520);
    glVertex2i(150, 650);
    glVertex2i(200, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(110, 580);
    glVertex2i(150, 700);
    glVertex2i(190, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(180, 520);
    glVertex2i(230, 650);
    glVertex2i(280, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(190, 580);
    glVertex2i(230, 700);
    glVertex2i(270, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(260, 520);
    glVertex2i(310, 650);
    glVertex2i(360, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(270, 580);
    glVertex2i(310, 700);
    glVertex2i(350, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(340, 520);
    glVertex2i(390, 650);
    glVertex2i(450, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(350, 580);
    glVertex2i(390, 700);
    glVertex2i(440, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(420, 520);
    glVertex2i(470, 650);
    glVertex2i(530, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(430, 580);
    glVertex2i(470, 700);
    glVertex2i(520, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(500, 520);
    glVertex2i(550, 650);
    glVertex2i(610, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(510, 580);
    glVertex2i(550, 700);
    glVertex2i(600, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(580, 520);
    glVertex2i(630, 650);
    glVertex2i(690, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(590, 580);
    glVertex2i(630, 700);
    glVertex2i(680, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(660, 520);
    glVertex2i(710, 650);
    glVertex2i(770, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(670, 580);
    glVertex2i(710, 700);
    glVertex2i(760, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(740, 520);
    glVertex2i(790, 650);
    glVertex2i(850, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(750, 580);
    glVertex2i(790, 700);
    glVertex2i(840, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(820, 520);
    glVertex2i(870, 650);
    glVertex2i(930, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(830, 580);
    glVertex2i(870, 700);
    glVertex2i(920, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(900, 520);
    glVertex2i(950, 650);
    glVertex2i(1010, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(910, 580);
    glVertex2i(950, 700);
    glVertex2i(1000, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(980, 520);
    glVertex2i(1030, 650);
    glVertex2i(1090, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(990, 580);
    glVertex2i(1030, 700);
    glVertex2i(1080, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1070, 520);
    glVertex2i(1110, 650);
    glVertex2i(1170, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1070, 580);
    glVertex2i(1110, 700);
    glVertex2i(1160, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1150, 520);
    glVertex2i(1190, 650);
    glVertex2i(1250, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1150, 580);
    glVertex2i(1190, 700);
    glVertex2i(1240, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1230, 520);
    glVertex2i(1270, 650);
    glVertex2i(1330, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1230, 580);
    glVertex2i(1270, 700);
    glVertex2i(1320, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1310, 520);
    glVertex2i(1350, 650);
    glVertex2i(1410, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1310, 580);
    glVertex2i(1350, 700);
    glVertex2i(1400, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1390, 520);
    glVertex2i(1430, 650);
    glVertex2i(1490, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1390, 580);
    glVertex2i(1430, 700);
    glVertex2i(1480, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1470, 520);
    glVertex2i(1510, 650);
    glVertex2i(1570, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1470, 580);
    glVertex2i(1510, 700);
    glVertex2i(1560, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1550, 520);
    glVertex2i(1590, 650);
    glVertex2i(1650, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1550, 580);
    glVertex2i(1590, 700);
    glVertex2i(1640, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1630, 520);
    glVertex2i(1670, 650);
    glVertex2i(1730, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1630, 580);
    glVertex2i(1670, 700);
    glVertex2i(1720, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1710, 520);
    glVertex2i(1750, 650);
    glVertex2i(1810, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1710, 580);
    glVertex2i(1750, 700);
    glVertex2i(1800, 580);

    glBegin(GL_TRIANGLES);
    glVertex2i(1790, 520);
    glVertex2i(1830, 650);
    glVertex2i(1890, 520);

    glBegin(GL_TRIANGLES);
    glVertex2i(1790, 580);
    glVertex2i(1830, 700);
    glVertex2i(1890, 580);
*/
    glEnd();
    //glFlush();
}

void drawwater(){
    //water
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0 ,150);
    glVertex2i(1920, 150);
    glVertex2i(1920, 0);
    glEnd();


   /* glColor3f (0.92, 0.77, 0.44);//river side
    glBegin(GL_QUADS);
    glVertex2i(1520, 0);
    glVertex2i(1920 ,200);
    glVertex2i(1920, 180);
    glVertex2i(1560, 0);

    glBegin(GL_QUADS);
    glVertex2i(620, 0);
    glVertex2i(1920 ,450);
    glVertex2i(1920, 470);
    glVertex2i(575, 0);
    glEnd();


     glColor3f(0.0,0.0,0.0); //river side wall
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2i(1433,300);
    glVertex2i(1920,470);

    glVertex2i(1432,340);
    glVertex2i(1920,510);

    glVertex2i(1433,340);
    glVertex2i(1433,302);

    glVertex2i(569,0);
    glVertex2i(867,106);

    glVertex2i(430,0);
    glVertex2i(860,143);

    glVertex2i(867,106);
    glVertex2i(860,143);
    glEnd();
    //glFlush();

    //wall line
    glColor3f (0.50, 0.50, 0.50);//silver
    glBegin(GL_QUADS);
    glVertex2i(569, 0);
    glVertex2i(430 ,0);
    glVertex2i(860, 143);
    glVertex2i(867,106);

    glBegin(GL_QUADS);
    glVertex2i(1433,300);
    glVertex2i(1432 ,340);
    glVertex2i(1920,510);
    glVertex2i(1920,470);

    glEnd(); */

}

void drawroad(){//road
     //Road black color

    glBegin(GL_QUADS);
    glVertex2i(0, 150);
    glVertex2i(0, 300);
    glVertex2i(1920, 300);
    glVertex2i(1920, 150);
    glEnd();

}

void drawroadline(){
    glColor3f(0.96,0.74,0.0); //road side yellow colour 1
    glLineWidth(6);
    glBegin(GL_LINES);

    glVertex2i(0,150);
    glVertex2i(1920,150);

    glVertex2i(0,300);
    glVertex2i(1920,300);
    glEnd();
}

void drawmiddleline(){
    //road middle line
    glColor3f(1.0,1.0,1.0);
    glLineWidth(10);
    glBegin(GL_LINES);

    glVertex2i(0,225);
    glVertex2i(100,225);

    glVertex2i(200,225);
    glVertex2i(300,225);

    glVertex2i(400,225);
    glVertex2i(500,225);


    glVertex2i(600,225);
    glVertex2i(700,225);

    glVertex2i(800,225);
    glVertex2i(900,225);


    glVertex2i(1000,225);
    glVertex2i(1100,225);

    glVertex2i(1200,225);
    glVertex2i(1300,225);


    glVertex2i(1400,225);
    glVertex2i(1500,225);

    glVertex2i(1600,225);
    glVertex2i(1700,225);


    glVertex2i(1800,225);
    glVertex2i(1900,225);
    glEnd();

// zebra crossing
    glColor3f(1.0,1.0,1.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(1460,245);
    glVertex2i(1570,245);
    glVertex2i(1460,255);
    glVertex2i(1570,255);
    glVertex2i(1460,265);
    glVertex2i(1570,265);
    glVertex2i(1460,275);
    glVertex2i(1570,275);
    glVertex2i(1460,285);
    glVertex2i(1570,285);
    glVertex2i(1460,205);
    glVertex2i(1570,205);
    glVertex2i(1460,195);
    glVertex2i(1570,195);
    glVertex2i(1460,185);
    glVertex2i(1570,185);
    glVertex2i(1460,175);
    glVertex2i(1570,175);
    glVertex2i(1460,165);
    glVertex2i(1570,165);
    glEnd();

}

void drawwall(){
    glColor3f(0.46,0.54,0.47);
    glBegin(GL_QUADS);
    glVertex2i(0,300);
    glVertex2i(0,380);
    glVertex2i(280,380);
    glVertex2i(280,300);
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2i(280,300);
    glVertex2i(280,380);
    glVertex2i(560,380);
    glVertex2i(560,300);
    glEnd();

    glColor3f(0.66,0.57,0.42);
    glBegin(GL_QUADS);
    glVertex2i(560,300);
    glVertex2i(560,380);
    glVertex2i(840,380);
    glVertex2i(840,300);
    glEnd();

    glColor3f(0.0,0.4,0.4);
    glBegin(GL_QUADS);
    glVertex2i(840,300);
    glVertex2i(840,380);
    glVertex2d(1120,380);
    glVertex2d(1120,300);
    glEnd();

    glColor3f(0.8,0.86,0.53);
    glBegin(GL_QUADS);
    glVertex2i(1120,300);
    glVertex2i(1120,380);
    glVertex2d(1400,380);
     glVertex2d(1400,300);
    glEnd();


    glColor3f(0.0,0.8,0.4);
    glBegin(GL_QUADS);
    glVertex2i(1620,300);
    glVertex2i(1620,380);
    glVertex2d(1920,380);
    glVertex2d(1920,300);
    glEnd();

    glColor3f(0.74,0.74,0.74);
    glBegin(GL_QUADS);
    glVertex2i(1400,300);
    glVertex2i(1400,420);
    glVertex2d(1420,420);
    glVertex2d(1420,300);
    glEnd();

    glColor3f(0.74,0.74,0.74);
    glBegin(GL_QUADS);
    glVertex2i(1600,300);
    glVertex2i(1600,420);
    glVertex2d(1620,420);
    glVertex2d(1620,300);
    glEnd();

    glColor3f(0.71,0.71,0.71);
    glBegin(GL_QUADS);
    glVertex2i(1400,420);
    glVertex2i(1400,460);
    glVertex2d(1620,460);
    glVertex2d(1620,420);
    glEnd();

    glColor3f(.71,0.67,0.84);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2i(0,380);
    glVertex2i(1400,380);

    glVertex2i(1620,380);
    glVertex2i(1920,380);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    Sprint(1435,430,"5 STAR HOTEL ");
    glEnd();
}

void drawlamp(){
    glColor3f(0.0,0.0,0.0);
    circle(280, 383, 7);
    circle(560, 383, 7);
    circle(840, 383, 7);
    circle(1120,383, 7);
    glEnd();
}

void drawlamppost(){



  //lamppost
    glLineWidth(6);
    glBegin(GL_LINES);

    glVertex2i(250,300);
    glVertex2i(250,480);
    glVertex2i(250,480);
    glVertex2i(210,485);
    glVertex2i(250,480);
    glVertex2i(290,485);


   glVertex2i(530,300);
   glVertex2i(530,480);
   glVertex2i(530,480);
   glVertex2i(490,485);
   glVertex2i(530,480);
   glVertex2i(570,485);


    glVertex2i(810,300);
    glVertex2i(810,480);
    glVertex2i(810,480);
    glVertex2i(770,485);
    glVertex2i(810,480);
    glVertex2i(850,485);



    glVertex2i(1090,300);
    glVertex2i(1090,480);
    glVertex2i(1090,480);
    glVertex2i(1120,485);
    glVertex2i(1090,480);
    glVertex2i(1050,485);

    glVertex2i(1370,300);
    glVertex2i(1370,480);
    glVertex2i(1370,480);
    glVertex2i(1330,485);
    glVertex2i(1370,480);
    glVertex2i(1410,485);

    glVertex2i(1700,300);
    glVertex2i(1700,480);
    glVertex2i(1700,480);
    glVertex2i(1660,485);
    glVertex2i(1700,480);
    glVertex2i(1740,485);
    glEnd();
}

void lamplosplight(){
  //lamppost
    glLineWidth(6);
    glBegin(GL_LINES);

     glVertex2i(210,482);
      glVertex2i(223,480);

      glVertex2i(290,482);
      glVertex2i(277,480);

      glVertex2i(490,482);
      glVertex2i(503,480);

      glVertex2i(570,482);
      glVertex2i(557,480);

      glVertex2i(770,482);
      glVertex2i(783,480);

       glVertex2i(850,482);
        glVertex2i(837,480);

         glVertex2i(1050,482);
          glVertex2i(1063,480);

        glVertex2i(1120,482);
        glVertex2i(1107,480);

        glVertex2i(1330,482);
        glVertex2i(1343,480);

        glVertex2i(1410,482);
        glVertex2i(1397,480);

        glVertex2i(1660,482);
        glVertex2i(1673,480);

        glVertex2i(1740,482);
        glVertex2i(1727,480);


    glEnd();


}

void drawbuilding1(){//building 1

    glColor3f(0.4,0.3,0.0);
    glBegin(GL_QUADS);
    glVertex2i(300,350);
    glVertex2i(300,650);
    glVertex2i(450,650);
    glVertex2i(450,350);

    glBegin(GL_QUADS);
    glVertex2i(450,350);
    glVertex2i(450,650);
    glVertex2i(480,670);
    glVertex2i(480,370);

    glBegin(GL_QUADS);
    glVertex2i(300,650);
    glVertex2i(330,670);
    glVertex2i(480,670);
    glVertex2i(450,650);

    glEnd();

    glColor3f(.78,0.67,0.84); //building 1 line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(300,650);
    glVertex2i(450,650);

    glVertex2i(450,350);
    glVertex2i(450,650);

    glVertex2i(450,500);
    glVertex2i(300,500);

    glVertex2i(450,650);
    glVertex2i(480,670);

    glEnd();

    glColor3f (0.50, 0.50, 0.50);// building 1 rooftop

    glBegin(GL_TRIANGLES);
    glVertex2i(300, 650);
    glVertex2i(375, 700);
    glVertex2i(450, 650);

    glBegin(GL_TRIANGLES);
    glVertex2i(450, 650);
    glVertex2i(375, 700);
    glVertex2i(480, 670);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 1 line
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(300,650);
    glVertex2i(375,700);

    glVertex2i(450,650);
    glVertex2i(375,700);

    glVertex2i(375,700);
    glVertex2i(480,670);
    glEnd();


    glColor3f(1.0,1.0,1.0);// building 1 window and door
    glBegin(GL_QUADS);
    glVertex2i(320,590);
    glVertex2i(320,620);
    glVertex2i(360,620);
    glVertex2i(360,590);

    glBegin(GL_QUADS);
    glVertex2i(380,590);
    glVertex2i(380,620);
    glVertex2i(420,620);
    glVertex2i(420,590);

    glBegin(GL_QUADS);
    glVertex2i(380,530);
    glVertex2i(380,560);
    glVertex2i(420,560);
    glVertex2i(420,530);

    glBegin(GL_QUADS);
    glVertex2i(320,530);
    glVertex2i(320,560);
    glVertex2i(360,560);
    glVertex2i(360,530);

    glBegin(GL_QUADS);
    glVertex2i(320,440);
    glVertex2i(320,470);
    glVertex2i(360,470);
    glVertex2i(360,440);

    glBegin(GL_QUADS);
    glVertex2i(380,440);
    glVertex2i(380,470);
    glVertex2i(420,470);
    glVertex2i(420,440);

    glBegin(GL_QUADS);// building 1 door
    glVertex2i(350,350);
    glVertex2i(350,400);
    glVertex2i(400,400);
    glVertex2i(400,350);
    glEnd();


   /*  glColor3f(0.5,0.5,0.5); // building 1 door to road

    glBegin(GL_QUADS);
    glVertex2i(320,300);
    glVertex2i(350,350);
    glVertex2i(400,350);
    glVertex2i(370,300);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(320,300);
    glVertex2i(350,350);
    glVertex2i(400,350);
    glVertex2i(370,300);
    glEnd();
    */
}

void drawbuilding2(){

    glColor3f(0.57,0.28,0.18); // building 2

    glBegin(GL_QUADS);
    glVertex2i(600,350);
    glVertex2i(600,600);
    glVertex2i(750,600);
    glVertex2i(750,350);

    glBegin(GL_QUADS);
    glVertex2i(750,350);
    glVertex2i(750,600);
    glVertex2i(780,620);
    glVertex2i(780,370);
    glEnd();

    glColor3f (0.50, 0.50, 0.50);// building 2 rooftop
    glBegin(GL_TRIANGLES);
    glVertex2i(600, 600);
    glVertex2i(675, 650);
    glVertex2i(750, 600);

    glBegin(GL_TRIANGLES);
    glVertex2i(750, 600);
    glVertex2i(675, 650);
    glVertex2i(780, 620);
    glEnd();


    glColor3f(.78,0.67,0.84);; //building 2 rooftop line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(750,600);
    glVertex2i(675, 650);

    glVertex2i(600,600);
    glVertex2i(675, 650);

    glVertex2i(675, 650);
    glVertex2i(780, 620);

    glVertex2i(600, 350); // building 2 border  line
    glVertex2i(600, 600);

    glVertex2i(750, 350);
    glVertex2i(750, 600);
    glEnd();


    glColor3f(1.0,1.0,1.0); // building 2 door
    glBegin(GL_QUADS);
    glVertex2i(650,350);
    glVertex2i(650,400);
    glVertex2i(700,400);
    glVertex2i(700,350);
    glEnd();

    glColor3f(1.0,1.0,1.0);// window of building 2
    glBegin(GL_QUADS);
    glVertex2i(690,490);
    glVertex2i(690,525);
    glVertex2i(730,525);
    glVertex2i(730,490);

    glBegin(GL_QUADS);
    glVertex2i(690,540);
    glVertex2i(690,575);
    glVertex2i(730,575);
    glVertex2i(730,540);

    glBegin(GL_QUADS);
    glVertex2i(620,490);
    glVertex2i(620,525);
    glVertex2i(660,525);
    glVertex2i(660,490);

    glBegin(GL_QUADS);
    glVertex2i(620,540);
    glVertex2i(620,575);
    glVertex2i(660,575);
    glVertex2i(660,540);

    glBegin(GL_QUADS);
    glVertex2i(690,430);
    glVertex2i(690,460);
    glVertex2i(730,460);
    glVertex2i(730,430);

    glBegin(GL_QUADS);
    glVertex2i(620,430);
    glVertex2i(620,460);
    glVertex2i(660,460);
    glVertex2i(660,430);

    glBegin(GL_QUADS);
    glVertex2i(665,350);
    glVertex2i(685,390);
    glVertex2i(685,390);
    glVertex2i(665,350);
    glEnd();



   /* glColor3f(0.5,0.5,0.5); //building 2 door to road

    glBegin(GL_QUADS);
    glVertex2i(630,295);
    glVertex2i(650,350);
    glVertex2i(700,350);
    glVertex2i(680,295);

    glEnd();

    glColor3f(1.0,1.0,1.0);//building 2 door to road line
    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2i(650,350);
    glVertex2i(630,295);

    glVertex2i(700,350);
    glVertex2i(680,295);
    glEnd();
*/
}

void drawbuilding3(){//building 3

    glColor3f(0.41,0.61,0.54);
    glBegin(GL_QUADS);
    glVertex2i(900,350);
    glVertex2i(900,550);
    glVertex2i(1150,550);
    glVertex2i(1150,350);

    glBegin(GL_QUADS);
    glVertex2i(1150,350);
    glVertex2i(1150,550);
    glVertex2i(1180,570);
    glVertex2i(1180,370);

    glBegin(GL_QUADS);
    glVertex2i(900,550);
    glVertex2i(930,570);
    glVertex2i(1180,570);
    glVertex2i(1150,550);
    glEnd();


    glColor3f (0.50, 0.50, 0.50);// building 3 roof top
    glBegin(GL_TRIANGLES);
    glVertex2i(900, 550);
    glVertex2i(1025, 600);
    glVertex2i(1150, 550);

    glBegin(GL_TRIANGLES);
    glVertex2i(1150, 550);
    glVertex2i(1025, 600);
    glVertex2i(1180, 570);

    glBegin(GL_TRIANGLES);
    glVertex2i(900, 550);
    glVertex2i(1025, 600);
    glVertex2i(930, 570);
    glEnd();

    glColor3f(1.0,1.0,1.0);//window of  building 3
    glBegin(GL_QUADS);
    glVertex2i(910,480);
    glVertex2i(910,510);
    glVertex2i(950,510);
    glVertex2i(950,480);

    glBegin(GL_QUADS);
    glVertex2i(970,480);
    glVertex2i(970,510);
    glVertex2i(1010,510);
    glVertex2i(1010,480);

    glBegin(GL_QUADS);
    glVertex2i(1035,480);
    glVertex2i(1035,510);
    glVertex2i(1075,510);
    glVertex2i(1075,480);

    glBegin(GL_QUADS);
    glVertex2i(1100,480);
    glVertex2i(1100,510);
    glVertex2i(1135,510);
    glVertex2i(1135,480);

    glBegin(GL_QUADS);
    glVertex2i(910,380);
    glVertex2i(910,410);
    glVertex2i(950,410);
    glVertex2i(950,380);

    glBegin(GL_QUADS);
    glVertex2i(1095,380);
    glVertex2i(1095,410);
    glVertex2i(1140,410);
    glVertex2i(1140,380);

    glBegin(GL_QUADS);// building 3 door
    glVertex2i(1000,350);
    glVertex2i(1000,395);
    glVertex2i(1050,395);
    glVertex2i(1050,350);

    glEnd();


  /*  glColor3f(0.5,0.5,0.5);// building 3 door to road

    glBegin(GL_QUADS);
    glVertex2i(980,300);
    glVertex2i(1000,350);
    glVertex2i(1050,350);
    glVertex2i(1030,300);

    glEnd();
*/
    glColor3f(1.0,1.0,1.0);//building 3 roof top line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(900,550);
    glVertex2i(1025,600);

    glVertex2i(1025,600);
    glVertex2i(1180,570);

    glVertex2i(1025,600);
    glVertex2i(1150,550);

    glVertex2i(1025,600);
    glVertex2i(930,570);

    glVertex2i(900,550);
    glVertex2i(930,570);

    glEnd();

    glColor3f(.78,0.67,0.84); //building 3  line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(900,550);
    glVertex2i(1150,550);

    glVertex2i(1150,350);
    glVertex2i(1150,550);

    glVertex2i(1180,570);
    glVertex2i(1150,550);

    glVertex2i(1025,395);
    glVertex2i(1025,550);

    glVertex2i(900,450);
    glVertex2i(1150,450);

    glEnd();

/*
            glColor3f(1.0,1.0,1.0);//building 3 road line white
    glLineWidth(3);
    glBegin(GL_LINES);

        glVertex2i(980,300);
    glVertex2i(1000,350);

      glVertex2i(1050,350);
      glVertex2i(1030,300);
    glEnd();
    */
}

/*void drawboat(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(1375  , 40);
    glVertex2i(1450, 40);
    glVertex2i(1475, 70);
    glVertex2i(1350, 70);

    glBegin(GL_QUADS);
    glVertex2i(1525 , 70);
    glVertex2i(1600, 70);
    glVertex2i(1625, 100);
    glVertex2i(1500, 100);
    glEnd();

    glColor3f(0.50, 0.50, 0.50);
    glBegin(GL_QUADS);
    glVertex2i(1375, 70);
    glVertex2i(1450, 70);
    glVertex2i(1440, 100);
    glVertex2i(1385,100);

    glBegin(GL_QUADS);
    glVertex2i(1525, 100);
    glVertex2i(1600, 100);
    glVertex2i(1590, 130);
    glVertex2i(1535, 130);
    glEnd();

}*/

void drawcar(){

    glColor3f(0.0,0.4,0.4);
    glBegin(GL_QUADS);
    glVertex2i(90, 180);
    glVertex2i(90,225);
    glVertex2i(270,225);
    glVertex2i(270,180);
    glEnd();

    glColor3f(0.0,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(390, 180);
    glVertex2i(390,225);
    glVertex2i(570,225);
    glVertex2i(570,180);
    glEnd();

    glColor3f(0.0,0.2,0.4);
    glBegin(GL_QUADS);
    glVertex2i(690, 180);
    glVertex2i(690,225);
    glVertex2i(870,225);
    glVertex2i(870,180);
    glEnd();

    glColor3f(0.75,0.750,0.750);
    glBegin(GL_QUADS);
    glVertex2i(120, 225);
    glVertex2i(145,245);
    glVertex2i(215,245);
    glVertex2i(235,225);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(420, 225);
    glVertex2i(445,245);
    glVertex2i(515,245);
    glVertex2i(540,225);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(720, 225);
    glVertex2i(745,245);
    glVertex2i(815,245);
    glVertex2i(840,225);
    glEnd();

    glColor3f (0.0, 0.0, 0.0);
    circle(120, 180, 20);
    circle(235, 180, 20);
    glEnd();

    circle(435, 180, 20);
    circle(530, 180, 20);
    glEnd();

    circle(735, 180, 20);
    circle(830, 180, 20);
    glEnd();

}

void drawcar1(){
    glColor3f(0.0,0.2,0.4);
    glBegin(GL_QUADS);
    glVertex2i(890, 250);
    glVertex2i(890,295);
    glVertex2i(1070,295);
    glVertex2i(1070,250);
    glEnd();

    glColor3f(0.75,0.750,0.750);
    glBegin(GL_QUADS);
    glVertex2i(920, 295);
    glVertex2i(945,315);
    glVertex2i(1015,315);
    glVertex2i(1040,295);
    glEnd();

    glColor3f (0.0, 0.0, 0.0);
    circle(930, 250, 20);
    circle(1025, 250, 20);
    glEnd();
}

void drawline(){

     //road side water line
    glLineWidth(6);
    glBegin(GL_LINES);
    glVertex2i(0,175);
    glVertex2i(1420,175);
    glVertex2i(1600,175);
    glVertex2i(1920,175);
    glVertex2i(250,177);
    glVertex2i(250,155);
    glVertex2i(530,177);
    glVertex2i(530,155);
    glVertex2i(810,177);
    glVertex2i(810,155);
    glVertex2i(1090,177);
    glVertex2i(1090,155);
    glVertex2i(1370,177);
    glVertex2i(1370,155);
    glVertex2i(1700,177);
    glVertex2i(1700,155);
    glEnd();
}

void drawplane(){//Plane

      glBegin(GL_QUADS);
      glVertex2i(130,885);
      glVertex2i(410,885);
      glVertex2i(470,855);
      glVertex2i(220,855);
      glEnd();
}

void planewings(){//Plane wings
    glBegin(GL_QUADS);
    glVertex2i(270,865);
    glVertex2i(330,865);
    glVertex2i(260,835);
    glVertex2i(220,835);

    glVertex2i(255,885);
    glVertex2i(305,885);
    glVertex2i(260,905);
    glVertex2i(220,905);

    glVertex2i(130,885);
    glVertex2i(130,920);
    glVertex2i(140,920);
    glVertex2i(165,885);

    glVertex2i(140,882);
    glVertex2i(160,882);
    glVertex2i(135,867);
    glVertex2i(122,867);

    // window
    glVertex2i(420,875); // Door
    glVertex2i(430,875);
    glVertex2i(440,870);
    glVertex2i(420,870);

    glVertex2i(400,875);
    glVertex2i(410,875);
    glVertex2i(410,870);
    glVertex2i(400,870);

    glVertex2i(400,870);
    glVertex2i(410,870);
    glVertex2i(410,865);
    glVertex2i(400,865);

    glVertex2i(400,865);
    glVertex2i(410,865);
    glVertex2i(410,860);
    glVertex2i(400,860);

    glVertex2i(380,875);
    glVertex2i(390,875);
    glVertex2i(390,870);
    glVertex2i(380,870);

    glVertex2i(360,875);
    glVertex2i(370,875);
    glVertex2i(370,870);
    glVertex2i(360,870);

    glVertex2i(340,875);
    glVertex2i(350,875);
    glVertex2i(350,870);
    glVertex2i(340,870);

    glVertex2i(320,875);
    glVertex2i(330,875);
    glVertex2i(330,870);
    glVertex2i(320,870);

    glVertex2i(300,875);
    glVertex2i(310,875);
    glVertex2i(310,870);
    glVertex2i(300,870);


    glVertex2i(280,875);
    glVertex2i(290,875);
    glVertex2i(290,870);
    glVertex2i(280,870);


    glVertex2i(260,875);
    glVertex2i(270,875);
    glVertex2i(270,870);
    glVertex2i(260,870);

    glVertex2i(240,875);
    glVertex2i(250,875);
    glVertex2i(250,870);
    glVertex2i(240,870);

    glVertex2i(220,875);
    glVertex2i(230,875);
    glVertex2i(230,870);
    glVertex2i(220,870);

    glVertex2i(200,875);
    glVertex2i(210,875);
    glVertex2i(210,870);
    glVertex2i(200,870);
    glEnd();

}

void drawstar(){

    glColor3f(1.0, 1.0, 0.0); // stars
    glPointSize(3);
    glBegin(GL_POINTS);

    glVertex2i(120, 820);
    glVertex2i(520, 970);
    glVertex2i(820, 720);
    glVertex2i(1220, 890);
    glVertex2i(1520, 810);
    glVertex2i(1720, 900);

    glEnd();
}

void mydisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    if(mode==0){

        glPushMatrix();//Sky
        glColor3f(0.53,0.807,0.922);
        drawsky();
        glPopMatrix();

        glPushMatrix(); //sun
        glColor3f(1.0, 0.851, 0.4);
        glTranslatef(sun,sun,0.0 );
        circle(200, 900, 70);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.9, 0.9, 0.9);
        glTranslatef(cloudPosition,0.0 ,0.0 );
        circle(1000, 850, 45);
        circle(1060, 850, 50);
        circle(1120, 850, 45);

        circle(600, 850, 45);
        circle(660, 850, 50);
        circle(720, 850, 45);

        circle(1200, 950, 45);
        circle(1260, 950, 50);
        circle(1320, 950, 45);

        circle(500, 950, 45);
        circle(560, 950, 50);
        circle(620, 950, 45);

        circle(1500, 920, 45);
        circle(1560, 920, 50);
        circle(1620, 920, 45);
        glPopMatrix();
        //glutSwapBuffers();

        glPushMatrix();//grass
        glColor3f(0.317,1.0,0.317);
        drawgrass();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f (0.77, 0.53, 0.47); //brown color
        drawtree();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f (0.16, 0.49, 0.10); //brown color
        drawleaf();
        glPopMatrix();

        glPushMatrix();//Water
        glColor3f (0.317,1.0,0.317); //blue color
        drawwater();
        glPopMatrix();

        glPushMatrix();//Road
        glColor3f (0.50, 0.50, 0.50);
        drawroad();
        glPopMatrix();

        glPushMatrix();//Road
        drawroadline();
        glPopMatrix();


        glPushMatrix();//Road
        drawmiddleline();
        glPopMatrix();


        glPushMatrix();//Building 1
        drawbuilding1();
        glPopMatrix();

        glPushMatrix();//Building 2
        drawbuilding2();
        glPopMatrix();

        glPushMatrix();//Building 3
        drawbuilding3();
        glPopMatrix();

        glPushMatrix();//wall
        drawwall();
        glPopMatrix();

        glPopMatrix(); // lamppost
        glColor3f(0.290,0.30,0.33);
        drawlamppost();
        glPopMatrix();

        glPopMatrix();
        glColor3f(1.0,1.0,1.0);
        lamplosplight();
        glPopMatrix();

        glPushMatrix();//car
        glTranslatef(-carPosition,0.0,0.0);
        drawcar1();
        glPopMatrix();

        glPushMatrix();//car
        glTranslatef(carPosition,0.0,0.0);
        drawcar();
        glPopMatrix();

        glPushMatrix();
        drawlamp();
        glPopMatrix();

        glPopMatrix();//line
        glColor3f(0.25,0.250,0.250);
        drawline();
        glPopMatrix();

        glPushMatrix();//Boat
        glTranslatef(boatPosition,0.0,0.0);
       // drawboat();
        glPopMatrix();
        glutSwapBuffers();
          glPushMatrix();
}
    else{
        glPushMatrix();//Sky
        glColor3f (0.0, 0.0, 0.2);
        drawsky();
        glPopMatrix();

        glPushMatrix();//star
        drawstar();
        glPopMatrix();

        glPushMatrix();//Moon
        glColor3f(0.855, 0.851, 0.843);//light silver
        glTranslatef(moon ,moon ,0.0 );
        circle(200, 900, 70);
        glPopMatrix();

        glPushMatrix();//Cloud
        glColor3f(0.529,0.533,0.612);//silver
        glTranslatef(cloudPosition  ,0.0 ,0.0 );
        circle(1000, 850, 45);
        circle(1060, 850, 50);
        circle(1120, 850, 45);

        circle(600, 850, 45);
        circle(660, 850, 50);
        circle(720, 850, 45);

        circle(1200, 950, 45);
        circle(1260, 950, 50);
        circle(1320, 950, 45);

        circle(500, 950, 45);
        circle(560, 950, 50);
        circle(620, 950, 45);

        circle(1500, 920, 45);
        circle(1560, 920, 50);
        circle(1620, 920, 45);
        glPopMatrix();
        //glutSwapBuffers();

        glPushMatrix();//grass
        glColor3f (0.0, 0.25, 0.0);
        drawgrass();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f (0.4, 0.2, 0.0); //brown color
        drawtree();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f (0.0, 0.15, 0.00); //brown color
        drawleaf();
        glPopMatrix();

        glPushMatrix();//Water
        glColor3f(0.317,1.0,0.317);// Dark blue
        drawwater();
        glPopMatrix();

        glPushMatrix();//Road
        glColor3f (0.23, 0.230, 0.230);// kaj korte hbe
        drawroad();
        glPopMatrix();


        glPushMatrix();//Road
        drawroadline();
        glPopMatrix();


        glPushMatrix();//Road
        drawmiddleline();
        glPopMatrix();

        glPopMatrix();

        glPushMatrix();//Building 1
        drawbuilding1();
        glColor3f(0.2,0.0,0.0);
        glBegin(GL_QUADS);
        glVertex2i(300,350);
        glVertex2i(300,650);
        glVertex2i(450,650);
        glVertex2i(450,350);

        glBegin(GL_QUADS);
        glVertex2i(450,350);
        glVertex2i(450,650);
        glVertex2i(480,670);
        glVertex2i(480,370);


        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(320,590);
        glVertex2i(320,620);
        glVertex2i(360,620);
        glVertex2i(360,590);

        glBegin(GL_QUADS);
        glVertex2i(380,590);
        glVertex2i(380,620);
        glVertex2i(420,620);
        glVertex2i(420,590);

        glBegin(GL_QUADS);
        glVertex2i(380,530);
        glVertex2i(380,560);
        glVertex2i(420,560);
        glVertex2i(420,530);

        glBegin(GL_QUADS);
        glVertex2i(320,530);
        glVertex2i(320,560);
        glVertex2i(360,560);
        glVertex2i(360,530);

        glBegin(GL_QUADS);
        glVertex2i(320,440);
        glVertex2i(320,470);
        glVertex2i(360,470);
        glVertex2i(360,440);

        glBegin(GL_QUADS);
        glVertex2i(380,440);
        glVertex2i(380,470);
        glVertex2i(420,470);
        glVertex2i(420,440);

        glBegin(GL_QUADS);// building 1 door
        glVertex2i(350,350);
        glVertex2i(350,400);
        glVertex2i(400,400);
        glVertex2i(400,350);
        glPopMatrix();

        glPushMatrix();//Building 2
        drawbuilding2();

        glColor3f (0.2, 0.0, 0.098);
        glBegin(GL_QUADS);
        glVertex2i(600,350);
        glVertex2i(600,600);
        glVertex2i(750,600);
        glVertex2i(750,350);

        glBegin(GL_QUADS);
        glVertex2i(750,350);
        glVertex2i(750,600);
        glVertex2i(780,620);
        glVertex2i(780,370);

        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(690,490);
        glVertex2i(690,525);
        glVertex2i(730,525);
        glVertex2i(730,490);

        glBegin(GL_QUADS);
        glVertex2i(690,540);
        glVertex2i(690,575);
        glVertex2i(730,575);
        glVertex2i(730,540);

        glBegin(GL_QUADS);
        glVertex2i(620,490);
        glVertex2i(620,525);
        glVertex2i(660,525);
        glVertex2i(660,490);

        glBegin(GL_QUADS);
        glVertex2i(620,540);
        glVertex2i(620,575);
        glVertex2i(660,575);
        glVertex2i(660,540);

        glBegin(GL_QUADS);
        glVertex2i(690,430);
        glVertex2i(690,460);
        glVertex2i(730,460);
        glVertex2i(730,430);

        glBegin(GL_QUADS);
        glVertex2i(620,430);
        glVertex2i(620,460);
        glVertex2i(660,460);
        glVertex2i(660,430);

        glBegin(GL_QUADS);
        glVertex2i(665,350);
        glVertex2i(685,390);
        glVertex2i(685,390);
        glVertex2i(665,350);

        glBegin(GL_QUADS);
        glVertex2i(650,350);
        glVertex2i(650,400);
        glVertex2i(700,400);
        glVertex2i(700,350);
        glPopMatrix();

        glPushMatrix();//Building 3
        drawbuilding3();
        glColor3f(0.0,0.2,0.2);
        glBegin(GL_QUADS);
        glVertex2i(900,350);
        glVertex2i(900,550);
        glVertex2i(1150,550);
        glVertex2i(1150,350);

        glBegin(GL_QUADS);
        glVertex2i(1150,350);
        glVertex2i(1150,550);
        glVertex2i(1180,570);
        glVertex2i(1180,370);

        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(910,480);
        glVertex2i(910,510);
        glVertex2i(950,510);
        glVertex2i(950,480);

        glBegin(GL_QUADS);
        glVertex2i(970,480);
        glVertex2i(970,510);
        glVertex2i(1010,510);
        glVertex2i(1010,480);

        glBegin(GL_QUADS);
        glVertex2i(1035,480);
        glVertex2i(1035,510);
        glVertex2i(1075,510);
        glVertex2i(1075,480);

        glBegin(GL_QUADS);
        glVertex2i(1100,480);
        glVertex2i(1100,510);
        glVertex2i(1135,510);
        glVertex2i(1135,480);

        glBegin(GL_QUADS);
        glVertex2i(910,380);
        glVertex2i(910,410);
        glVertex2i(950,410);
        glVertex2i(950,380);

        glBegin(GL_QUADS);
        glVertex2i(1095,380);
        glVertex2i(1095,410);
        glVertex2i(1140,410);
        glVertex2i(1140,380);

        glVertex2i(1000,350);
        glVertex2i(1000,395);
        glVertex2i(1050,395);
        glVertex2i(1050,350);
        glPopMatrix();

        glPushMatrix();//wall
        drawwall();
           glColor3f(0.37,0.43,0.4);
    glBegin(GL_QUADS);
    glVertex2i(0,300);
    glVertex2i(0,380);
    glVertex2i(280,380);
    glVertex2i(280,300);
    glEnd();

    glColor3f(0.23,0.23,0.23);
    glBegin(GL_QUADS);
    glVertex2i(280,300);
    glVertex2i(280,380);
    glVertex2i(560,380);
    glVertex2i(560,300);
    glEnd();

    glColor3f(0.55,0.28,0.22);
    glBegin(GL_QUADS);
    glVertex2i(560,300);
    glVertex2i(560,380);
    glVertex2i(840,380);
    glVertex2i(840,300);
    glEnd();

    glColor3f(0.25,0.36,0.447);
    glBegin(GL_QUADS);
    glVertex2i(840,300);
    glVertex2i(840,380);
    glVertex2d(1120,380);
    glVertex2d(1120,300);
    glEnd();

    glColor3f(0.72,0.58,0.43);
    glBegin(GL_QUADS);
    glVertex2i(1120,300);
    glVertex2i(1120,380);
    glVertex2d(1400,380);
     glVertex2d(1400,300);
    glEnd();


    glColor3f(0.2,0.47,0.15);
    glBegin(GL_QUADS);
    glVertex2i(1620,300);
    glVertex2i(1620,380);
    glVertex2d(1920,380);
    glVertex2d(1920,300);
    glEnd();

    glColor3f(0.74,0.74,0.74);
    glBegin(GL_QUADS);
    glVertex2i(1400,300);
    glVertex2i(1400,420);
    glVertex2d(1420,420);
    glVertex2d(1420,300);
    glEnd();

    glColor3f(0.74,0.74,0.74);
    glBegin(GL_QUADS);
    glVertex2i(1600,300);
    glVertex2i(1600,420);
    glVertex2d(1620,420);
    glVertex2d(1620,300);
    glEnd();

    glColor3f(0.42,0.42,0.42);
    glBegin(GL_QUADS);
    glVertex2i(1400,420);
    glVertex2i(1400,460);
    glVertex2d(1620,460);
    glVertex2d(1620,420);
    glEnd();


       glColor3f(.71,0.67,0.84);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2i(0,380);
    glVertex2i(1400,380);

    glVertex2i(1620,380);
    glVertex2i(1920,380);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    Sprint(1435,430,"5 STAR HOTEL ");
    glEnd();

        glPopMatrix();

        glPopMatrix(); // lamppost
        glColor3f(0.0,0.0,0.0);
        drawlamppost();
        glPopMatrix();

        glPopMatrix();   // lappostlight
        glColor3f(1.0,1.0,0.0);
        lamplosplight();
        glPopMatrix();

        glPushMatrix();//car
        glTranslatef(-carPosition,0.0,0.0);
        drawcar1();
        glPopMatrix();

        glPushMatrix();//car
        glTranslatef(carPosition,0.0,0.0);
        drawcar();
        glPopMatrix();

        glPushMatrix(); //wall lamp light
        glColor3f(1.0,1.0,1.0);
        circle(280, 383, 7);
        circle(560, 383, 7);
        circle(840, 383, 7);
        circle(1120,383, 7);
        glPopMatrix();

        glPopMatrix();//line
        glColor3f(0.0,0.0,0.0);
        drawline();
        glPopMatrix();

        glPushMatrix();//Plane
        glTranslatef(plane,0.0,0.0);
        glColor3f(0.43,0.36,0.32);
        drawplane();
        glColor3f(0.72,0.72,0.72);
        planewings();
        glPopMatrix();

        //glPushMatrix();//Boat
        //drawboat();
       // glPopMatrix();


    }
}
void cloudAnimation(int value){ // Update cloud position
    cloudPosition += 4.0f; // Adjust speed as needed

    if (cloudPosition > 1350.0f){
        cloudPosition = -1700.0f; // Wrap to the left side
    }
    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(25, cloudAnimation, 0); // Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}
/*void boatAnimation(int value){//Update position
    boatPosition += speed;//Adjust speed
    if(boatPosition>600.0f){
        boatPosition = -1900.0f;//Wrap to the left side
    }
    glutPostRedisplay();//Notify GLUT that the display has changed
    glutTimerFunc(25, boatAnimation, 0);// Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}*/

void carAnimation(int value){//Update position
    carPosition += speed;//Adjust speed
    if(carPosition>1900.0f){
        carPosition = -900.0f;//go to the left side
    }
    glutPostRedisplay();//Notify GLUT that the display has changed
    glutTimerFunc(25, carAnimation, 0);// Notify GLUT  call update again in 25 milliseconds
    glutSwapBuffers();
}
void planeAnimation(int value){//Plane Animation
    plane += speed;
    if(plane>1900.0f){
        plane = -900.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(25, planeAnimation, 0);
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          speed+=0.5f;
         //  boatAnimation(0);
           carAnimation(0);
          break;
      case GLUT_KEY_DOWN:
         speed -=0.5f;
          // boatAnimation(0);
           carAnimation(0);
          break;
      case GLUT_KEY_RIGHT:
          speed+=0.5f;
             planeAnimation(0);
          break;
      case GLUT_KEY_LEFT:
         speed -=0.5f;
           planeAnimation(0);
          break;

    }
      glutPostRedisplay();  //  mode
    glutSwapBuffers();
}
/*void specialKey(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          speed+=0.5f;
             planeAnimation(0);
          break;
      case GLUT_KEY_DOWN:
         speed -=0.5f;
           planeAnimation(0);
          break;
    }
}*/
void myInit (void){
    glClearColor(0.0, 0.0,0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'd') {
        mode = 0;  //  day mode
    } else if (key == 'n') {
        mode = 1;  //  night mode
    }
    glutPostRedisplay();  // update mode
    glutSwapBuffers();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1920, 1080);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Project");
    glutDisplayFunc(mydisplay);
    glutSpecialFunc(specialKeys);
    //glutSpecialFunc(specialKey);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25,cloudAnimation,0);//Cloud
    //glutTimerFunc(25,boatAnimation,0);//Boat
    glutTimerFunc(25,carAnimation,0);
    glutTimerFunc(25,sunAnimation,0);
    glutTimerFunc(25,moonAnimation,0);
    glutTimerFunc(25,planeAnimation,0);
    myInit ();
    glutMainLoop();
}
