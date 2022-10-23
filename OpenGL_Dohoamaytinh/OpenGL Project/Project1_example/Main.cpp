#include<GL/freeglut.h>

void Mydisplay() {}

//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);   //xóa mọi pixel
//	glColor3f(1.0, 1.0, 1.0);  // thiết lập màu vẽ: màu trắng
//
//	glBegin(GL_LINE_LOOP); // dạng đa giác đường line
//		glVertex3f(0.25, 0.25, 0.0);
//		glVertex3f(0.55, 0.25, 0.0);
//		glVertex3f(0.65, 0.55, 0.0);
//		glVertex3f(0.40, 0.75, 0.0);
//		glVertex3f(0.15, 0.55, 0.0);
//		glEnd();  // kết thúc vẽ đa giác đường line
//
//	glBegin(GL_POLYGON);  //bắt đầu vẽ đa giác
//		/*glVertex3f(-0.5, -0.5, 0.0);
//		glVertex3f(0.5, -0.5, 0.0);
//		glVertex3f(0.5, 0.5, 0.0);
//		glVertex3f(-0.5, 0.5, 0.0);
//		glEnd();  // kết thúc vẽ đa giác */
//
//		glVertex3f(1.25, 1.25, 0.0);
//		glVertex3f(1.55, 1.25, 0.0);
//		glVertex3f(1.65, 1.55, 0.0);
//		glVertex3f(1.40, 1.75, 0.0);
//		glVertex3f(1.15, 1.55, 0.0);
//		glEnd();  // kết thúc vẽ đa giác đường line
//
//	glFlush(); //thực hện qtrinh đẩy ra buffer
//}
//void init()
//{
//	glClearColor(1.0, 0.0, 0.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, 2.0, 0.0, 2.0, -2.0, 12.0);
}

int main(int argc, char** argv) {
	// 5 thủ tục cần thiết để khởi tạo cửa sổ:
	glutInit(&argc, argv);  //khởi tạo glut và xử lí mọi dòng lệnh đối số, thủ tục này luôn gọi đầu tiên
	glutInitDisplayMode(GLUT_RGB); //khởi tạo chế độ vẽ single buffer và hệ màu RGB
	glutInitWindowSize(300, 300);  //khởi tạo window kích thước 300x300
	glutInitWindowPosition(0, 0);  // khởi tạo window tại vị trí bên trái screen
	glutCreateWindow("OpenGL Sample Drawing");
	
	init();
	glutDisplayFunc(MyDisplay); //chỉ đc gọi duy nhất 1 lần trong ctrinh
	glutMainLoop();
	return 0;
}