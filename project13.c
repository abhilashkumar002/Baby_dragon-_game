#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLint dragon[3][46]={{100,116,140,170,180,150,182,186,193,200,206,210,213,240,235,228,226,208,207,206,220,224,217,211,212,215,211,204,190,183,170,194,190,160,174,134,117,228,216,208,208,213,213,233,164,222},{260,266,258,260,267,286,298,272,278,305,303,313,302,294,277,278,274,276,260,257,253,252,234,234,240,248,249,250,237,233,209,209,204,204,230,254,260,278,282,294,290,290,294,296,209,246},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};   // the dragon coordinates

GLfloat objcord[2][21]={{1000.0,1100.0,1050.0,-150.0,-150.0,-50.0,-50.0,800.0,900.0,850.0,350.0,350.0,450.0,450.0,600.0,700.0,650.0,-40.0,-10.0,-10.0,-40.0},{10.0,10.0,110.0,130.0,230.0,230.0,130.0,250.0,250.0,350.0,370.0,470.0,470.0,370.0,490.0,490.0,590.0,-40.0,-40.0,-10.0,-10.0}};   // different ojects coordinates


long int pixlen=20;				//time in millisecond to udate values
GLint frame=0, start=0, score=0;		//to control the frame
GLint xg=0, max5=750;				//rotating square values
char scr[20];					//string to store score
GLfloat red=0.746, green=0.847, blue=0.847;  	//initial background color

void display();

void renderBitmapString(float x,float y,float z,void *font,char*string)			//to print string and score on screen
{
	char *c;
	glRasterPos3f(x, y,z);
	for(c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void drawtriangle()				//first triangle
{
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][0],objcord[1][0],0.0);
		glVertex3f(objcord[0][1],objcord[1][1],0.0);
		glVertex3f(objcord[0][2],objcord[1][2],0.0);
	glEnd();
}

void drawsquare()				//first square
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][3],objcord[1][3],0.0);
		glVertex3f(objcord[0][4],objcord[1][4],0.0);
		glVertex3f(objcord[0][5],objcord[1][5],0.0);
		glVertex3f(objcord[0][6],objcord[1][6],0.0);
	glEnd();
}

void drawtriangle2()				//2nd triangle
{
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][7],objcord[1][7],0.0);
		glVertex3f(objcord[0][8],objcord[1][8],0.0);
		glVertex3f(objcord[0][9],objcord[1][9],0.0);
	glEnd();
}

void drawsquare2()				//second square
{
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][10],objcord[1][10],0.0);
		glVertex3f(objcord[0][11],objcord[1][11],0.0);
		glVertex3f(objcord[0][12],objcord[1][12],0.0);
		glVertex3f(objcord[0][13],objcord[1][13],0.0);
	glEnd();
}

void drawtriangle3()				//third triangle
{
	glColor3f(0.0,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][14],objcord[1][14],0.0);
		glVertex3f(objcord[0][15],objcord[1][15],0.0);
		glVertex3f(objcord[0][16],objcord[1][16],0.0);
	glEnd();
}

void drawsquare4()				//rotating square
{
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(-50.0,-50.0,-1.0);
		glVertex3f(-50.0,50.0,-1.0);
		glVertex3f(50.0,50.0,-1.0);
		glVertex3f(50.0,-50.0,-1.0);
	glEnd();
}

void drawscaler()				//scaling square
{
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
		glVertex3f(objcord[0][17],objcord[1][17],0.0);
		glVertex3f(objcord[0][18],objcord[1][18],0.0);
		glVertex3f(objcord[0][19],objcord[1][19],0.0);
		glVertex3f(objcord[0][20],objcord[1][20],0.0);
	glEnd();
}

void translating()				//to increase translation value and rotation angle and check if reached end		
{
	
		objcord[0][0]-=4;
		objcord[0][1]-=4;
		objcord[0][2]-=4;
		if(objcord[0][1]<=-50)
		{
			objcord[0][0]=1000;
			objcord[0][1]=1100;
			objcord[0][2]=1050; score++;	
		}
					
		objcord[0][3]+=2;
		objcord[0][4]+=2;
		objcord[0][5]+=2;
		objcord[0][6]+=2;
		if(objcord[0][3]>=1000)
		{
			objcord[0][3]=-150;
			objcord[0][4]=-150;
			objcord[0][5]=-50;
			objcord[0][6]=-50; score++;
		}
	
		objcord[0][7]-=6;
		objcord[0][8]-=6;
		objcord[0][9]-=6;
		if(objcord[0][7]<=-150)
		{
			objcord[0][7]=1000;
			objcord[0][8]=1100;
			objcord[0][9]=1050; score++;
		}
	
		objcord[0][10]+=5;
		objcord[0][11]+=5;
		objcord[0][12]+=5;
		objcord[0][13]+=5;
		if(objcord[0][10]>=1000)
		{
			objcord[0][10]=-150;
			objcord[0][11]=-150;
			objcord[0][12]=-50;
			objcord[0][13]=-50; score++;
		}
	
		objcord[0][14]-=5;
		objcord[0][15]-=5;
		objcord[0][16]-=5;
		if(objcord[0][14]<=-150)
		{
			objcord[0][14]=1000;
			objcord[0][15]=1100;
			objcord[0][16]=1050; score++;
		}
		
		objcord[0][18]+=5;
		objcord[0][19]+=5;
		if(objcord[0][18]>=1000)
		{
			objcord[0][18]=-10;
			objcord[0][19]=-10;
		}
		
		if(xg<max5)
		{		
			xg=xg+3;

		}	
	 	if(xg==max5-1||xg==max5-2||xg==max5-3||xg==max5-4)
		{		
			xg=-400;
		}
		
		
	
}


void drawdragon()					//function to draw dragon
{	
	
	glColor3f(1.0,0.647,0.0);
	glBegin(GL_POLYGON);		//part 1
		 glVertex2f(dragon[0][0],dragon[1][0]);
		  glVertex2f(dragon[0][1],dragon[1][1]);
		   glVertex2f(dragon[0][36],dragon[1][36]);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);		//part 2
		 glVertex2f(dragon[0][1],dragon[1][1]);
		  glVertex2f(dragon[0][2],dragon[1][2]);
		  glVertex2f(dragon[0][35],dragon[1][35]);
		   glVertex2f(dragon[0][36],dragon[1][36]);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);;
	glBegin(GL_POLYGON);		//part 3
		  glVertex2f(dragon[0][2],dragon[1][2]);
		  glVertex2f(dragon[0][3],dragon[1][3]);
		  glVertex2f(dragon[0][34],dragon[1][34]);
		  glVertex2f(dragon[0][35],dragon[1][35]);
	glEnd();
	
	//glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);		//part 4
		  glVertex2f(dragon[0][3],dragon[1][3]);
		  glVertex2f(dragon[0][4],dragon[1][4]);
		  glVertex2f(dragon[0][7],dragon[1][7]);
		  glVertex2f(dragon[0][8],dragon[1][8]);
		  glVertex2f(dragon[0][17],dragon[1][17]);
		  glVertex2f(dragon[0][19],dragon[1][19]);
		  glVertex2f(dragon[0][27],dragon[1][27]);
		  glVertex2f(dragon[0][28],dragon[1][28]);
		  glVertex2f(dragon[0][29],dragon[1][29]);
		  glVertex2f(dragon[0][34],dragon[1][34]);
	glEnd();
	
	//glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);		//part 5
		  glVertex2f(dragon[0][8],dragon[1][8]);
		  glVertex2f(dragon[0][9],dragon[1][9]);
		  glVertex2f(dragon[0][43],dragon[1][43]);
		  glVertex2f(dragon[0][16],dragon[1][16]);
		  glVertex2f(dragon[0][17],dragon[1][17]);
	glEnd();
	
	glColor3f(1.0,0.647,0.0);
	glBegin(GL_POLYGON);		//part 6
		 glVertex2f(dragon[0][10],dragon[1][10]);
		  glVertex2f(dragon[0][11],dragon[1][11]);
		   glVertex2f(dragon[0][12],dragon[1][12]);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);		//part 7
		  glVertex2f(dragon[0][39],dragon[1][39]);
		  glVertex2f(dragon[0][40],dragon[1][40]);
		  glVertex2f(dragon[0][41],dragon[1][41]);
		  glVertex2f(dragon[0][42],dragon[1][42]);
	glEnd();
	
	glColor3f(1.0,0.843,0.0);
	glBegin(GL_POLYGON);		//part 8
		  glVertex2f(dragon[0][4],dragon[1][4]);
		  glVertex2f(dragon[0][5],dragon[1][5]);
		  glVertex2f(dragon[0][6],dragon[1][6]);
		  glVertex2f(dragon[0][7],dragon[1][7]);
	glEnd();
	
	glColor3f(0.5,0.2,0.0);
	glBegin(GL_POLYGON);		//part 9
		  glVertex2f(dragon[0][19],dragon[1][19]);
		  glVertex2f(dragon[0][21],dragon[1][21]);
		  glVertex2f(dragon[0][45],dragon[1][45]);
		  glVertex2f(dragon[0][27],dragon[1][27]);
	glEnd();
	
	//glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);		//part 10
		  glVertex2f(dragon[0][29],dragon[1][29]);
		  glVertex2f(dragon[0][30],dragon[1][30]);
		  glVertex2f(dragon[0][44],dragon[1][44]);
		  glVertex2f(dragon[0][34],dragon[1][34]);
	glEnd();
	
	glBegin(GL_POLYGON);		//part 12
		  glVertex2f(dragon[0][33],dragon[1][33]);
		  glVertex2f(dragon[0][44],dragon[1][44]);
		  glVertex2f(dragon[0][31],dragon[1][31]);
		  glVertex2f(dragon[0][32],dragon[1][32]);
	glEnd();
	
	glBegin(GL_POLYGON);		//part 13
		  glVertex2f(dragon[0][22],dragon[1][22]);
		  glVertex2f(dragon[0][23],dragon[1][23]);
		  glVertex2f(dragon[0][25],dragon[1][25]);
		  glVertex2f(dragon[0][45],dragon[1][45]);
	glEnd();
	
}

void gameover()		//called to go to next frame when game is over
{
	frame=2;
	pixlen=20;
}
void collisioncheck()		//to check if game is over
{	
	int i,j;
	for(i=0;i<46;i++)
	{ 
		if((dragon[0][i]>=objcord[0][0] && dragon[0][i]<=objcord[0][1]) && (dragon[1][i]>=objcord[1][0] && dragon[1][i]<=objcord[1][2]))
			{ gameover();  }
		if((dragon[0][i]>=objcord[0][3] && dragon[0][i]<=objcord[0][5]) && (dragon[1][i]>=objcord[1][3] && dragon[1][i]<=objcord[1][4]))
			{ gameover();  }
		if((dragon[0][i]>=objcord[0][7] && dragon[0][i]<=objcord[0][8]) && (dragon[1][i]>=objcord[1][7] && dragon[1][i]<=objcord[1][9]))
			{ gameover();   }
		if((dragon[0][i]>=objcord[0][10] && dragon[0][i]<=objcord[0][12]) && (dragon[1][i]>=objcord[1][10] && dragon[1][i]<=objcord[1][11]))
			{ gameover();  }
		if((dragon[0][i]>=objcord[0][14] && dragon[0][i]<=objcord[0][15]) && (dragon[1][i]>=objcord[1][14] && dragon[1][i]<=objcord[1][16]))
			{ gameover();  }
	}
}

void animateobj(int value)				//timer function to display after translating			
{	if(frame==1)
	{
		translating();
	}
	if(frame==2)
	{
		display();
	}
	collisioncheck();				
	glutPostRedisplay(); 				
    	glutTimerFunc(pixlen,animateobj,0);
}

void translatetriangle()				//object translating func
{		
   		glPushMatrix();
 		glRotatef(xg,0.0,0.0,1.0);	
 		drawsquare4();			
   		glPopMatrix();
}

void myinit()						//init func
{
  glClearColor(red,green,blue,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-50.0,999.0,-50.0,599.0);
  glutPostRedisplay();
 // glMatrixMode(GL_MODELVIEW);
}

void keyboardEvent(unsigned char key,int x,int y)	//keyboard func
{	int i;
	
	if(key=='s') 		
		{ if(dragon[1][33]>=0)   for(i=0;i<46;i++)dragon[1][i]-=27;}
	if(key=='w') 		
		{ if(dragon[1][11]<=600)     for(i=0;i<46;i++)dragon[1][i]+=27;}
		
	if(key=='d') 		
		{  if(dragon[0][43]<=1000)    for(i=0;i<46;i++)dragon[0][i]+=30;}
	if(key=='a') 		
		{  if(dragon[0][0]>=0)     for(i=0;i<46;i++)dragon[0][i]-=30;}				
}

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	if(frame==0)
	{
		glColor3f(1.0,0.0,0.0);
    		renderBitmapString(150,560,0,GLUT_BITMAP_TIMES_ROMAN_24,"COMPUTER GRAPHICS AND VISUALISATION LAB PROJECT");
		renderBitmapString(250,520,0,GLUT_BITMAP_TIMES_ROMAN_24,"PROJECT NAME : BABY DRAGON GAME");
		glColor3f(0.0,0.5,1.0);
		renderBitmapString(300,400,0,GLUT_BITMAP_TIMES_ROMAN_24,"Controls to move dragon");
		renderBitmapString(300,375,0,GLUT_BITMAP_TIMES_ROMAN_24,"right side -> d");
		renderBitmapString(300,350,0,GLUT_BITMAP_TIMES_ROMAN_24,"left side -> a");
		renderBitmapString(300,325,0,GLUT_BITMAP_TIMES_ROMAN_24,"up side -> w");
		renderBitmapString(300,300,0,GLUT_BITMAP_TIMES_ROMAN_24,"down side -> s");
		renderBitmapString(200,275,0,GLUT_BITMAP_TIMES_ROMAN_24,"click right mouse button for more options");
		glColor3f(0.0,0.0,0.0);
		renderBitmapString(20,100,0,GLUT_BITMAP_TIMES_ROMAN_24,"Project Incharge :");
		renderBitmapString(20,70,0,GLUT_BITMAP_TIMES_ROMAN_24,"B.N Shankar Gowda");
		renderBitmapString(20,40,0,GLUT_BITMAP_TIMES_ROMAN_24,"Bhavana K V");
		renderBitmapString(675,100,0,GLUT_BITMAP_TIMES_ROMAN_24,"Project by :- Abhilash Kumar");
		renderBitmapString(750,70,0,GLUT_BITMAP_TIMES_ROMAN_24,"USN  :- 1BI14CS002");
		glFlush();
    		glutPostRedisplay();
	}
	if(frame==1)
	{
		drawscaler();
		translatetriangle();
  		drawdragon();
  		drawtriangle();
  		drawsquare();
  		drawtriangle2();
  		drawsquare2();
  		drawtriangle3();
  		
  		glColor3f(0.0,0.0,0.0); //score
  		sprintf(scr,"%d",score);
  		renderBitmapString(-40,0,0,GLUT_BITMAP_TIMES_ROMAN_24,"Score:");
		renderBitmapString(25,0,0,GLUT_BITMAP_TIMES_ROMAN_24,scr);
  		glFlush();
  		glutPostRedisplay();
  	}
  	if(frame==2)
	{	
		GLint dragon[3][46]={{100,116,140,170,180,150,182,186,193,200,206,210,213,240,235,228,226,208,207,206,220,224,217,211,212,215,211,204,190,183,170,194,190,160,174,134,117,228,216,208,208,213,213,233,164,222},{260,266,258,260,267,286,298,272,278,305,303,313,302,294,277,278,274,276,260,257,253,252,234,234,240,248,249,250,237,233,209,209,204,204,230,254,260,278,282,294,290,290,294,296,209,246},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

		glColor3f(1.0,0.0,0.0);
		renderBitmapString(300,400,0,GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER");
    		glColor3f(0.0,0.0,0.0); //score
  		sprintf(scr,"%d",score);
  		renderBitmapString(300,300,0,GLUT_BITMAP_TIMES_ROMAN_24,"Your Score:");
		renderBitmapString(420,300,0,GLUT_BITMAP_TIMES_ROMAN_24,scr);
		
		
		drawdragon();
    		glFlush();
    		glutPostRedisplay();
	}
  	glFlush();
  	glutSwapBuffers();
  	glutPostRedisplay();
}

void changes(int m)		//menu values
{
	switch(m)
	{
		case 0: exit(0);
			break;
		case 1: 
			frame=2;
			break;
		case 2: 
			frame=1;
			break;
		case 3: pixlen=20;
			frame=1;
			break;
		case 4: pixlen=20;
			frame=1;
			display();
			break;
		case 11: glClearColor(0.746,0.847,0.847,1.0);
			break;
		case 12: glClearColor(0.94,0.81,0.99,1.0);
			break;
		case 13: glClearColor(0.91,0.76,0.65,1.0);
			break;
		case 14: glClearColor(0.95,0.99,0.99,1.0);
			break;
		case 15: glClearColor(1.0,1.0,1.0,1.0);
			break;
		case 16: glClearColor(0.0,0.0,0.0,1.0);
			break;
	}
	
}

void menu()				//mouse functoning menu
{
	int main_menu,sub_menu;
	
	sub_menu = glutCreateMenu(changes);
	glutAddMenuEntry("Sky Blue",11);
	glutAddMenuEntry("Light Purple",12);
	glutAddMenuEntry("Light Wood",13);
	glutAddMenuEntry("Cream",14);
	glutAddMenuEntry("White",15);
	//glutAddMenuEntry("Black",16);
	glutCreateMenu(changes);
	glutAddMenuEntry("Stop Game",1);
	glutAddMenuEntry("Start Game",2);
	glutAddSubMenu("background colors",sub_menu);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char **argv)			//main function
{ 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(1000,600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Baby Dragon Game");
  glutKeyboardFunc(keyboardEvent);
  glutDisplayFunc(display);
  glutTimerFunc(pixlen,animateobj,0);
  myinit();
  menu();
  glutMainLoop();
}



