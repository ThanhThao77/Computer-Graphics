#include<GL/freeglut.h>

/* hàm thực hiện các thao tác vẽ theo yêu cầu của chương trình */
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // xóa mọi pixel
	/* vẽ hình chữ nhật có điểm trái-trên và phải-dưới
	* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(1.0, 1.0, 0.0); /* thiết lập màu vẽ: màu vàng */

	/*CHAN TRAI*/
	glBegin(GL_POLYGON); /* bắt đầu vẽ đa giác */
	glVertex3f(0.3, 0.1, 0.0); /* xác định các đỉnh của đa giác */
	glVertex3f(0.4, 0.1, 0.0);
	glVertex3f(0.4, 0.25, 0.0);
	glVertex3f(0.3, 0.25, 0.0);
	glEnd(); /* kết thúc vẽ đa giác */

	/*CHAN PHAI*/
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.6, 0.1, 0.0);
	glVertex3f(0.7, 0.1, 0.0);
	glVertex3f(0.7, 0.25, 0.0);
	glVertex3f(0.6, 0.25, 0.0);
	glEnd();

	/*THAN*/
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.3, 0.25, 0.0);
	glVertex3f(0.7, 0.25, 0.0);
	glVertex3f(0.7, 0.6 ,0.0);
	glVertex3f(0.3, 0.6, 0.0);
	glEnd();

	/*TAYTRAI*/
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, 0.5, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.3, 0.6, 0.0);
	glVertex3f(0.1, 0.6, 0.0);
	glEnd();

	/*TAYPHAI*/
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.75, 0.55, 0.0);
	glVertex3f(0.9, 0.75, 0.0);
	glVertex3f(0.8, 0.8, 0.0);
	glVertex3f(0.65, 0.6, 0.0);
	glEnd();

	/*DAU*/
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.4, 0.6, 0.0);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(0.6, 0.8, 0.0);
	glVertex3f(0.4, 0.8, 0.0);
	glEnd();
	/*
	* thực hiện quá trình đẩy ra buffer
	*/
	glFlush();
}
/* hàm thực hiện các khởi tạo */
void init(void)
{
	/* chọn màu để xóa nền (tức là sẽ phủ nền bằng màu này) */
	glClearColor(0.0, 0.0, 0.0, 0.0); /* màu đen */
	/* thiết lập các thông số cho view */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/* hàm main của chương trình */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /* khởi tạo chế độ vẽ
   single buffer và hệ màu RGB */
	glutInitWindowSize(700, 700); /* khởi tạo window kích thước 250 x 250 */
	glutInitWindowPosition(100, 100); /* khởi tạo window tại ví trí
   (100,100) trên screen */
	glutCreateWindow("rectangle"); /* tên của window là ‘rectangle’ */
	init(); /* khởi tạo một số chế độ đồ họa */
	glutDisplayFunc(display); /* thiết lập hàm vẽ là hàm display() */
	glutMainLoop(); /* bắt đầu chu trình lặp thể hiện vẽ */
	return 0;
}