#include <GL/glut.h>
#include <math.h>

float a,b,c,d,e, min, max;
int round(float x)
{
	if (x>0) return int (x+0.5);
	else return int (x-0.5);
}

float f_2(float x) {
	return (a*x*x + b*x + c);
}

float f_3(float x) //Tinh ham bac 3
{
	return (a*x*x*x + b*x*x + c*x + d);
}

float f_4(float x) {
	return (a*x*x*x*x + b*x*x*x + c*x*x + d*x + e);
}

float f_1_1(float x) {
	return ((a*x+b) / (c*x+d));
}

float f_2_1(float x) {
	return ((a*x*x + b*x + c) / (d*x + e));
}

void initGL ()
{
	glClearColor (1.0f, 1.0f, 1.0f, 1.0f); //R=1,G=1,B=1, anpha=1
	glOrtho (-320,320,-240,240,-1,1);
}

void vedothi_bac2() {
	//Ve truc toa do
	glColor3f (1.0, 0.0, 0.0); // ==> Red
	glBegin (GL_LINES);
		//Ve truc OX
		glVertex2i (-320,0);
		glVertex2i (320,0);
		//Ve truc OY
		glVertex2i (0,-240);
		glVertex2i (0,240);
	glEnd();
	int x1,y1, //diem xuat phat
		x2,y2; //diem ve den
	float x, //bien chay tu min-->max
		  dx,//buoc tang x
		  k; //he so phong to
	//B1: Xac dinh doan can ve
	min=-320; max=320;
	//B2: khoi tao bien
	a=1;b=0;c=-3;
	k=(float)640/15; //he so phong to
	dx=0.1; //buoc tang x
	//B3: Chon diem xuat phat
	//B3: Chon diem xuat phat
	glColor3f (0.0, 0.0, 1.0); // ==> Blue
	x=min;
	x1=round(x*k);
	y1=round(f_2(x) *k);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x1,y1);
	//B4: Lap de ve do thi
	while (x<max)
	{
		x=x+dx;
		x2=round (x*k);
		y2=round (f_2(x) *k);
		glVertex2i (x1,y1);
		glVertex2i (x2,y2);
		x1 = x2; y1 = y2;
	}
	glEnd();
}

void vedothi_bac3()
{
	//Ve truc toa do
	glColor3f (1.0, 0.0, 0.0); // ==> Red
	glBegin (GL_LINES);
		//Ve truc OX
		glVertex2i (-320,0);
		glVertex2i (320,0);
		//Ve truc OY
		glVertex2i (0,-240);
		glVertex2i (0,240);
	glEnd();
	int x1,y1, //diem xuat phat
		x2,y2; //diem ve den
	float x, //bien chay tu min-->max
		  dx,//buoc tang x
		  k; //he so phong to
	//B1: Xac dinh doan can ve
	min=-320; max=320;
	//B2: khoi tao bien
	a=1;b=-3;c=-1;d=2;
	k=(float)640/15; //he so phong to
	dx=0.1; //buoc tang x
	//B3: Chon diem xuat phat
	//B3: Chon diem xuat phat
	glColor3f (0.0, 0.0, 1.0); // ==> Blue
	x=min;
	x1=round(x*k);
	y1=round(f_3(x) *k);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x1,y1);
	//B4: Lap de ve do thi
	while (x<max)
	{
		x=x+dx;
		x2=round (x*k);
		y2=round (f_3(x) *k);
		glVertex2i (x1,y1);
		glVertex2i (x2,y2);
		x1 = x2; y1 = y2;
	}
	glEnd();
}

void vedothi_bac4() {
	//Ve truc toa do
	glColor3f (1.0, 0.0, 0.0); // ==> Red
	glBegin (GL_LINES);
		//Ve truc OX
		glVertex2i (-320,0);
		glVertex2i (320,0);
		//Ve truc OY
		glVertex2i (0,-240);
		glVertex2i (0,240);
	glEnd();
	int x1,y1, //diem xuat phat
		x2,y2; //diem ve den
	float x, //bien chay tu min-->max
		  dx,//buoc tang x
		  k; //he so phong to
	//B1: Xac dinh doan can ve
	min=-320; max=320;
	//B2: khoi tao bien
	a=1;b=0;c=-3;d=1;e=2;
	k=(float)640/15; //he so phong to
	dx=0.1; //buoc tang x
	//B3: Chon diem xuat phat
	//B3: Chon diem xuat phat
	glColor3f (0.0, 0.0, 1.0); // ==> Blue
	x=min;
	x1=round(x*k);
	y1=round(f_4(x) *k);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x1,y1);
	//B4: Lap de ve do thi
	while (x<max)
	{
		x=x+dx;
		x2=round (x*k);
		y2=round (f_4(x) *k);
		glVertex2i (x1,y1);
		glVertex2i (x2,y2);
		x1 = x2; y1 = y2;
	}
	glEnd();
}

void vedothi_bac1_1()
{
	//Ve truc toa do
	glColor3f (1.0, 0.0, 0.0); // ==> Red
	glBegin (GL_LINES);
		//Ve truc OX
		glVertex2i (-320,0);
		glVertex2i (320,0);
		//Ve truc OY
		glVertex2i (0,-240);
		glVertex2i (0,240);
	glEnd();
	int x1,y1, //diem xuat phat
		x2,y2; //diem ve den
	float x, //bien chay tu min-->max
		  dx,//buoc tang x
		  k; //he so phong to
	//B1: Xac dinh doan can ve
	min=-320; max=320;
	//B2: khoi tao bien
	a=-1;b=2;c=1;d=1;
	k=(float)640/15; //he so phong to
	dx=0.1; //buoc tang x
	//B3: Chon diem xuat phat
	//B3: Chon diem xuat phat
	glColor3f (0.0, 0.0, 1.0); // ==> Blue
	x=min;
	x1=round(x*k);
	y1=round(f_1_1(x) *k);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x1,y1);
	//B4: Lap de ve do thi
	while (x<max)
	{
		x=x+dx;
		x2=round (x*k);
		y2=round (f_1_1(x) *k);
		glVertex2i (x1,y1);
		glVertex2i (x2,y2);
		x1 = x2; y1 = y2;
	}
	glEnd();
}

void vedothi_bac2_1()
{
	//Ve truc toa do
	glColor3f (1.0, 0.0, 0.0); // ==> Red
	glBegin (GL_LINES);
		//Ve truc OX
		glVertex2i (-320,0);
		glVertex2i (320,0);
		//Ve truc OY
		glVertex2i (0,-240);
		glVertex2i (0,240);
	glEnd();
	int x1,y1, //diem xuat phat
		x2,y2; //diem ve den
	float x, //bien chay tu min-->max
		  dx,//buoc tang x
		  k; //he so phong to
	//B1: Xac dinh doan can ve
	min=-320; max=320;
	//B2: khoi tao bien
	a=1;b=2;c=2;d=1;e=1;
	k=(float)640/15; //he so phong to
	dx=0.1; //buoc tang x
	//B3: Chon diem xuat phat
	//B3: Chon diem xuat phat
	glColor3f (0.0, 0.0, 1.0); // ==> Blue
	x=min;
	x1=round(x*k);
	y1=round(f_2_1(x) *k);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x1,y1);
	//B4: Lap de ve do thi
	while (x<max)
	{
		x=x+dx;
		x2=round (x*k);
		y2=round (f_2_1(x) *k);
		glVertex2i (x1,y1);
		glVertex2i (x2,y2);
		x1 = x2; y1 = y2;
	}
	glEnd();
}

void mydisplay () {
	glClear(GL_COLOR_BUFFER_BIT);
	vedothi_bac2_1();
	glViewport(0,0,640,480);
	glFlush();
}
int main() {
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow ("VE DO THI HAM SO");
	initGL();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
}
