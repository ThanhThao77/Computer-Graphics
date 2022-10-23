#include<GL/freeglut.h>

void Bresenham(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = -2 * dy + dx;
	int x = x1;
	int y = y1;
	while (x <= x2)
	{
		glVertex2f(x, y);
		if (D > 0) {
			D = D - 2 * dy;
		}
		else {
			D = D - 2 * dy + 2 * dx;
			y++;
		}
		x++;
	}
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);   //xóa mọi pixel
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	 Bresenham(2, 1, 8, 5);
	glLineWidth(30);
	glEnd();  // kết thúc vẽ

	glFlush(); //thực hện qtrinh đẩy ra buffer
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
}





int main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); //khởi tạo chế độ vẽ single buffer và hệ màu RGB
	glutInitWindowSize(300, 300);  //khởi tạo window kích thước 300x300
	glutInitWindowPosition(0, 0);  // khởi tạo window tại vị trí bên trái screen
	glutCreateWindow("OpenGL Sample Drawing");
	init();
	
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}