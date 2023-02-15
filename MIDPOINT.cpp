#include <GL/glut.h>
#include <math.h>

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=1,G=1,B=1, anpha=1
    glOrtho(-500,500,-250,250,-1,1);
//    glOrtho(0,640,0,480,-1,1);
}

void MidLinex(int x1, int y1, int x2, int y2) 
{
	int x, y = y1,xmax;
	if(x1 < x2) {
		x = x1;
		xmax = x2;
	} else {
		x = x2;
		xmax = x1;
	}
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	while(x < xmax) {
		x++;
		glVertex2i(x, y);
	}
	glEnd();
}

void MidLiney(int x1, int y1, int x2, int y2) 
{
	int x = x1, y, ymax;
	if(y1 < y2) {
		y = y1;
		ymax = y2;
	} else {
		y = y2;
		ymax = y1;
	}
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	while(y < ymax) {
		y++;
		glVertex2i(x, y);
	}
	glEnd();
}

void MidLine1(int x1,int y1,int x2,int y2)
//he so goc 0<m<1
{
    int x_max,x,y;
    int dx=fabs(x1-x2);
    int dy=fabs(y1-y2);
    int p=dy-dx/2;
    //Chon diem xuat phat
    if (x1>x2) {
        x=x2;
        y=y2;
        x_max=x1;
    } else {
        x=x1;
        y=y1;
        x_max=x2;
    }
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    //Ve AB
    while (x < x_max) {
        if (p < 0)
            p += dy;
        else {
            p += dy-dx;
            y++;
        }
        x++;
        glVertex2i(x,y);
    }
    glEnd();
}

void MidLine2(int x1,int y1,int x2,int y2)
//he so goc -1<m<0
{
    int x_min,x,y;
    int dx=fabs(x1-x2);
    int dy=fabs(y1-y2);
    int p=dy-dx/2;
    //Chon diem xuat phat
    if (x1<x2) {
        x=x2;
        y=y2;
        x_min=x1;
    } else {
        x=x1;
        y=y1;
        x_min=x2;
    }
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    //Ve AB
    while (x > x_min) {
        if (p < 0)
            p += dy;
        else {
            p += dy-dx;
            y++;
        }
        x--;
        glVertex2i(x,y);
    }
    glEnd();
}


void MidLine3(int x1,int y1,int x2,int y2)
//he so goc -1>m>vocung
{
    int y_max,x,y;
    int dx=fabs(x1-x2);
    int dy=fabs(y1-y2);
    int p=dx-dy/2;
    if (y1>y2) {
        x=x2;
        y=y2;
        y_max=y1;
    } else {
        x=x1;
        y=y1;
        y_max=y2;
    }
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    while (y < y_max) {
        if (p<0) p=p+dx;
        else {
            x--;
            p=p+dx-dy;
        }
        y++;
        glVertex2i(x,y);
    }
    glEnd();
}

void MidLine4(int x1,int y1,int x2,int y2)
//he so goc 1<m<vocung
{
    int y_max,x,y;
    int dx=fabs(x1-x2);
    int dy=fabs(y1-y2);
    int p=dx-dy/2;
    if (y1>y2) {
        x=x2;
        y=y2;
        y_max=y1;
    } else {
        x=x1;
        y=y1;
        y_max=y2;
    }
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    while (y < y_max) {
        if (p<0) p=p+dx;
        else {
            x++;
            p=p+dx-dy;
        }
        y++;
        glVertex2i(x,y);
    }
    glEnd();
}

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  // ==> Red
    MidLine1(200, 50, 400, 100);
    MidLine4(100, 100, 200, 200);
    MidLine3(-100, 100, 200, 200);
    MidLine2(-200, 50, -400, 100);
    glViewport(0,0,1000,500);
    glFlush();
}



int main(int argc, char** argv) {
    int mode=GLUT_SINGLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("THUAT TOAN MIDPOINT");
    initGL();
    glutDisplayFunc(mydisplay);
    glutMainLoop();
}

