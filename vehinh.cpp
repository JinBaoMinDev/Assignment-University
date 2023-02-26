#include <GL/glut.h>
#include <math.h>

struct toado{
	int x, y;
};

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=1,G=1,B=1, anpha=1
//    glOrtho(-500,500,-250,250,-1,1);
    glOrtho(0,1000,0,650,-1,1);
}

void draw4point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc,-y + yc);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void EllipsBresenham(int xc,int yc,double a, double b)	
{	 
   	
   	int x = 0;
	int y = b; 
	
	float x0 = a*a/sqrt(a*a + b*b); 
	float P = a*a*(1-2*b)+ b*b;
	draw4point(xc,yc,x,y);
	while (x <= x0) 
    	{
		if (P <0)	
           P += (2*b*b)*(2*x + 3);
            
		else
           {	
            
            P += (2*b*b)*(2*x+3) + 4*a*a*(1-y);
		    y--;
		   }
		x++;
        draw4point(xc,yc,x,y);
		}
	
	x=a;
	y=0;
	
	P=b*b*(1-2*a)+ a*a;
	draw4point(xc,yc,x,y);
	while (x > x0) 
    	{
		if (P <0)	
            P +=(2*a*a)*(2*y + 3);
		else
           {	
            P += (2*a*a)*(2*y + 3) + 4*b*b*(1-x);
            
		    x--;
		   }
		y++;
        draw4point(xc,yc,x,y);
		}
}

bool KtraEllipse (int x, int y, int xc, int yc, int a, int b)
{
	return pow(x-xc, 2)/(a*a)+pow(y-yc,2)/(b*b)<1;
}

void FillEllipse(int xc, int yc, int a, int b)
{
	//B1: Tim hinh chu nhat W bao hinh tron: Xmin, Xmax, Ymin,	
	int xmin = xc - a;
	int xmax = xc + a;
	int ymin = yc - b;
	int ymax = yc + b;
	//B2: To mau
	for (int x=xmin; x<=xmax; x++) {
		for (int y=ymin; y<=ymax; y++) {
			if (KtraEllipse(x, y, xc, yc, a, b))
			{
				glBegin (GL_POINTS);
					glVertex2i(x, y);
				glEnd();
			}
		}
	}
}

void draw8point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc - y, yc - x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc - x, yc + y);
	glEnd();
}


void CircleMidpoint(int xc, int yc, int R) {
	int x = 0, y = R;
	int p = 5/4 - R;
	draw8point(xc, yc, x, y);
	while(x < y) {
		if(p < 0) {
			p += 2 * x + 3;
		} else {
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;
		draw8point(xc, yc, x, y);
	}
}

bool KtraCircle (int x, int y, int xc, int yc, int R)
{
	return (x-xc) * (x-xc) + (y-yc) * (y-yc) <R*R;
}

void FillCircle(int xc, int yc, int r)
{
	//B1: Tim hinh chu nhat W bao hinh tron: Xmin, Xmax, Ymin,	
	int xmin = xc - r;
	int xmax = xc + r;
	int ymin = yc - r;
	int ymax = yc + r;
	//B2: To mau
	for (int x=xmin; x<=xmax; x++) {
		for (int y=ymin; y<=ymax; y++) {
			if (KtraCircle(x, y, xc, yc, r))
			{
				glBegin (GL_POINTS);
					glVertex2i(x, y);
				glEnd();
			}
		}
	}
}

void FillEllipseMixCircle(int xc, int yc, int r, int a, int b)
{
	//B1: Tim hinh chu nhat W bao hinh tron: Xmin, Xmax, Ymin,	
	int xmin = xc - a;
	int xmax = xc + a;
	int ymin = yc - b;
	int ymax = yc + b;
	//B2: To mau
	for (int x=xmin; x<=xmax; x++) {
		for (int y=ymin; y<=ymax; y++) {
			if (KtraEllipse(x, y, xc, yc, a, b) && !KtraCircle(x, y, xc, yc, r))
			{
				glBegin (GL_POINTS);
					glVertex2i(x, y);
				glEnd();
			}
		}
	}
}

void Rectangle(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
	glBegin(GL_LINE_LOOP);
		glVertex2i(xa, ya);
		glVertex2i(xb, yb);
		glVertex2i(xc, yc);
		glVertex2i(xd, yd);
	glEnd();
}

void Triangle(int xe, int ye, int xf, int yf, int xg, int yg) {
	glBegin(GL_LINE_LOOP);
		glVertex2i(xe, ye);
		glVertex2i(xf, yf);
		glVertex2i(xg, yg);
	glEnd();
}

int xc, yc, r;
int xe, ye, a, b;
int r1;
int x2, y2, a2, b2;
int xr1, xr2, xr3, xr4, yr1, yr2, yr3, yr4;
int xt1, yt1, xt2, yt2, xt3, yt3;
int xc2, yc2, r2, xt4, yt4, xt5, yt5, xt6, yt6;

long DTich (toado A, toado B, toado C)
{
	return fabs (B.x*A.y - A.x*B.y + C.x*B.y - B.x*C.y + A.x*C.y - C.x*A.y);
}

bool KTra(toado P, toado A, toado B, toado C)
{
	return DTich(A, B, C) == DTich(P,B,C) + DTich(P,A,B) + DTich(P,A,C);
}

void FillRetangleMixTriangle()
{
	//B1: Tim hinh chu nhat W bao ABC: xmin, xmax, ymin, ymax
	int xmin=xr1;
	if (xmin>xr2) xmin=xr2;
	if (xmin>xr3) xmin=xr3;
	if (xmin>xt1) xmin=xt1;
	if (xmin>xt2) xmin=xt2;
	if (xmin>xt3) xmin=xt3;
	int xmax=xr1;
	if (xmax<xr2) xmax=xr2;
	if (xmax<xr3) xmax=xr3;
	if (xmax<xt1) xmax=xt1;
	if (xmax<xt2) xmax=xt2;
	if (xmax<xt3) xmax=xt3;
	int ymin=yr1;
	if (ymin>yr2) ymin=yr2;
	if (ymin>yr3) ymin=yr3;
	if (ymin>yt1) ymin=yt1;
	if (ymin>yt2) ymin=yt2;
	if (ymin>yt3) ymin=yt3;
	int ymax=yr1;
	if (ymax<yr2) ymax=yr2;
	if (ymax<yr3) ymax=yr3;
	if (ymax<yt1) ymax=yt1;
	if (ymax<yt2) ymax=yt2;
	if (ymax<yt3) ymax=yt3;
	//B2: To mau
	toado P;
	toado A; A.x = xt1; A.y = yt1;
	toado B; B.x = xt2; B.y = yt2;
	toado C; C.x = xt3; C.y = yt3;
	toado D; D.x = xr1; D.y = yr1;
	toado E; E.x = xr2; E.y = yr2;
	toado F; F.x = xr3; F.y = yr3;
	for (P.x=xmin; P.x<=xmax; P.x++) {
		for(P.y=ymin;P.y<=ymax;P.y++) {
			if (KTra(P,A,B,C) && KTra(P,D,E,F))
			{
				glBegin (GL_POINTS);
				glVertex2i (P.x, P.y);
				glEnd();
    		}
		}
	}
}

void FillCircleMixTriangle() {
	int xmin=xt4;
	if(xmin>xt5) xmin=xt5;
	if(xmin>xt6) xmin=xt6;
	int xmax=xt4;
	if(xmax<xt5) xmax=xt5;
	if(xmax<xt6) xmax=xt6;
	int ymin=xt4;
	if(ymin>yt5) ymin=yt5;
	if(ymin>yt6) ymin=yt6;
	int ymax=yt4;
	if(ymax<yt5) ymax=yt5;
	if(ymax<yt6) ymax=yt6;
	toado P;
	toado A; A.x=xt4; A.y=yt4;
	toado B; B.x=xt5; B.y=yt5;
	toado C; C.x=xt6; C.y=yt6;
	for(P.x=xmin;P.x<=xmax;P.x++) {
		for(P.y=ymin; P.y<=ymax; P.y++) {
			if(KTra(P,A,B,C) && !KtraCircle(P.x, P.y, xc2, yc2, r2)) {
				glBegin (GL_POINTS);
				glVertex2i (P.x, P.y);
				glEnd();
			}
		}
	}
		
	int xmin2 = xc2 - r2;
	int xmax2 = xc2 + r2;
	int ymin2 = yc2 - r2;
	int ymax2 = yc2 + r2;
	for (int x=xmin2; x<=xmax2; x++) {
		for (int y=ymin2; y<=ymax2; y++) {
			toado P; P.x = x; P.y = y;
			if (KtraCircle(x, y, xc2, yc2, r2) && !KTra(P,A,B,C))
			{
				glBegin (GL_POINTS);
					glVertex2i(x, y);
				glEnd();
			}
		}
	}
}

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  // ==> Red
    CircleMidpoint(xc, yc, r);
    EllipsBresenham(xe, ye, a, b);
    EllipsBresenham(x2, y2, a2, b2);
    CircleMidpoint(x2, y2, r1);
    Rectangle(xr1, yr1, xr2, yr2, xr3, yr3, xr4, yr4);
    Triangle(xt1, yt1, xt2, yt2, xt3, yt3);
    CircleMidpoint(xc2, yc2, r2);
    Triangle(xt4, yt4, xt5, yt5, xt6, yt6);
    glViewport(0,0,1000,650);
    glFlush();
}

void mykey(unsigned char key, int x, int y) {
	glColor3f(1.0, 0.0, 0.0); // Red
	FillCircle(xc, yc, r);
	FillEllipse(xe, ye, a, b);
	FillEllipseMixCircle(x2, y2, r1, a2, b2);
	FillRetangleMixTriangle();
	FillCircleMixTriangle();
	glFlush();
}

int main(int argc, char** argv) {
    int mode=GLUT_SINGLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    
    xc = 150, yc = 500, r = 50;
    xe = 400, ye = 500, a = 100, b = 50;
    r1 = 50, x2 = 200, y2 = 225, a2 = 150, b2 = 75;
    xr1 = 450, yr1 = 200, xr2 = 650, yr2 = 200, xr3 = 650, yr3 = 50, xr4 = 450, yr4 = 50;
    xt1 = 550, yt1 = 125, xt2 = 750, yt2 = 175, xt3 = 625, yt3 = 300;
    xc2 = 850, yc2 = 400, r2 = 100, xt4 = 575, yt4 = 375, xt5 = 825, yt5 = 375, xt6 = 700, yt6 = 550; 
    
    glutInitWindowSize(1000, 650);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("THUAT TOAN VE DUONG TRON");
    initGL();
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(mykey); //goi ham xu ly su kien nhan phim
    glutMainLoop();
}

