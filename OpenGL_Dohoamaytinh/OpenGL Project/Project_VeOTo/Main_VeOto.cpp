//
//#include<GL/freeglut.h>
//
//GLfloat alpha = 0; //khai báo toàn cục
//
//void truc() {
//	glBegin(GL_LINES);
//
//	glColor3f(1, 0, 0); //màu đỏ
//	//truc x
//	glVertex3f(0, 0, 0); //đỉnh thứ nhất
//	glVertex3f(10, 0, 0);
//
//	//truc y
//	glColor3f(0, 1, 0); //màu xanh lá
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 10, 0);
//
//	//truc z
//	glColor3f(0, 0, 1); // màu xanh biển (màu cuối có tác động tới màu của hình vẽ)
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 10);
//
//	glEnd();
//
//}
//
//void xoay() {
//	//cho xoay liên tục
//	glRotatef(alpha, 0, 1, 0);
//	alpha = alpha + 0.1; //sau khi alpha vẽ xong lần 1 thì tăng lên, vẽ xong lần 2 thì tăng lên...
//	if (alpha >= 360) //khi mà n lớn hơn hoặc = thì nó gán = 0 vì nếu không vòng lặp sẽ vô tận
//		alpha == 0;
//}
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //xóa bộ đệm màu và xóa bộ đệm chiều sâu của màu
//
//	//ve o day
//	glColor3f(1, 0, 0);
//	truc();
//
//	// vẽ thân 
//	glPushMatrix(); // đẩy vào trong stack
//	xoay();
//	glutWireCube(4); // hàm vẽ hình lập phương với kích thước là 5
//	/*
//	glTranslated(2, 0, 0); //dịch chuyển
//	glutWireTeapot(3); // kích thước
//	*/
//	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
//
//	//--------------------------------------------------
//	// vẽ đầu
//	glPushMatrix(); // đẩy vào trong stack
//	
//	//glutWireCube(3); // hàm vẽ hình lập phương với kích thước là 5
//	glTranslatef(0, 3, 0);
//	glutWireCube(2.5);
//	/*
//	glTranslated(2, 0, 0); //dịch chuyển
//	glutWireTeapot(3); // kích thước
//	*/
//	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
//
//	//--------------------------------------------------
//	// vẽ tay phải
//	glPushMatrix(); // đẩy vào trong stack
//	xoay();
//	//glutWireCube(3); // hàm vẽ hình lập phương với kích thước là 5
//	glRotatef(90, 1, 0, 0);
//	glScalef(1.5, 1, 0);
//	glTranslatef(2.3, -4, 0);
//	glutWireCube(2);
//	/*
//	glTranslated(2, 0, 0); //dịch chuyển
//	glutWireTeapot(3); // kích thước
//	*/
//	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
//
//
//
//	//--------------------------------------------------
//	// vẽ chân
//	glPushMatrix(); // đẩy vào trong stack
//	
//	//glutWireCube(3); // hàm vẽ hình lập phương với kích thước là 5
//	glScalef(1, 1.5, 0);
//	glTranslatef(-1, -3, 0);
//	glutWireCube(2);
//	/*
//	glTranslated(2, 0, 0); //dịch chuyển
//	glutWireTeapot(3); // kích thước
//	*/
//	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
//
//
//	glutPostRedisplay(); //hàm tự động gọi Display để tự động xoay
//	glFlush();
//
//}
//
//void init()  //xóa màn hình
//{
//	//xoa nen
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//
//	//kiem tra chieu sau
//	glEnable(GL_DEPTH_TEST); //enable chế độ kiểm tra chiều sâu
//}
//
////ham khoi tao ma tran chieu + bien doi moi khi thay doi cua so
//void reshape(int w, int h) { //w, h là chiều rộng và cao
//
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);  //(GLsizei)w: ép kiểu
//
//	//thiet lap chế độ chiếu
//	glMatrixMode(GL_PROJECTION);
//	//khoi tao ma trận đơn vị
//	glLoadIdentity();
//	// chiếu bối cảnh
//	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 30);
//	// (kc xa nhất thấy, khoảng cách gần nhất nhìn thấy
//
//	glMatrixMode(GL_MODELVIEW); // ma trận biến đổi
//	glLoadIdentity(); // load ma trận đơn vị
//
//	//chi ra vi tri dat camera
//	gluLookAt(2, 7, 15, 0, 0, 0, 0, 1, 0); //3 tham số đầu tiên là vtri đặt camera, 
//
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(750, 750);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Vẽ ấm trà");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape); // gọi hàm này để khi thay đổi cửa sổ
//	glutMainLoop();
//	return 0;
//}



#include <GL/glut.h>
static int dichchuyen = 0;
float spin = 0.0f;
GLfloat tinhtienz = 0.5f;
//Hàm Xử lý tốc độ quay của bánh xe.
void spinDisplay(void) {
	spin = spin + 1;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay(); //Đánh dấu mặt phẳng bình thường của cửa sổ hiện tại là cần được hiển thị lại
}
//Hàm khai bao thao tac xử lý chiếu sáng: ánh sáng bao quanh, ánh sáng khuếch tán, ánh sáng phản chiếu Red, Green, Blue.
void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess)
{
	GLfloat ambient[] = { ambientR, ambientG, ambientB }; //Ánh sáng môi trường
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB }; //Ánh sáng khuếch tán
	GLfloat specular[] = { specularR, specularG, specularB }; //Ánh sáng phản chiếu.
	GLfloat shine[] = { shininess };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);

}
void display(void)
{
	// clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); // thiết lập chế độ chiếu
	//Thao tác điều khiển ngăn xếp ma trận vẽ thanh nghiên giống đường đi
	glColor3f(1.0, 1.0, 0.0);
	setMaterial(0.0, 1.0, .0, 1.0, 1.0, 1.0, 1.0, 1.0, .0, 50); //Chỉnh sửa thông số màu ở đây để tạo màu nó phù hợp, dựa vào hàm setMaterial ở trên?
	glPushMatrix();
	glRotatef(50, 0, 1, 1);  //Ðộ nghiêng.
	glScalef(20, 0, 3.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Phép tịnh tiến sự kiện họa cảnh

	//Thao tác ma trận vẽ ô tô biến đổi điểm nhìn và biến đổi mô hình.
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 10, (GLfloat)dichchuyen / 10, 0);

	/*thân dưới xe*/
	glPushMatrix();
	setMaterial(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, .0, 50); //Chỉnh sửa thông số màu ở đây để tạo màu nó phù hợp, dựa vào hàm setMaterial ở trên?
	//Vẽ ngăn xếp trên thân trên hình
	glScalef(1, .5, 2);
	glutSolidCube(.5);
	//glutWireCube(0.5);
	glPopMatrix();

	//Vẽ ngăn xếp thân trên hình.
	glPushMatrix();
	setMaterial(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 50); //Chỉnh sửa thông số màu ở đây để tạo màu nó phù hợp, dựa vào hàm setMaterial ở trên?
	glTranslatef(0.55, 0.75, tinhtienz);
	glScalef(1.0, 0.5, 1.5);
	glutSolidCube(.35);
	glPopMatrix();

	glTranslatef(0.0, 0, 0.25);

	glPushMatrix();

	// Thao tác ma trận thao tác vẽ bánh xe và chuyển động.
	setMaterial(1.0, 1.0, 1.0, .0, .0, .0, 1.0, 1.0, 1.0, 50); //Chỉnh sửa thông số màu ở đây để tạo màu nó phù hợp, dựa vào hàm setMaterial ở trên?

	glRotatef(90, 0.0, 1.0, .0);
	glTranslatef(.1, -.4, 0);
	glRotatef(spin, 0.0, 0.0, 1.0);//Chinh thong so quay o day
	glutSolidTorus(.05, .1, 9, 9);       // wheel

	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, -0.3);
	glRotatef(spin, 0.0, 0.0, 1.0); //Chinh thong so quay o day
	glTranslatef(0.0, 0.0, -0.1);
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glPopMatrix();

	glTranslatef(0, 0, -.6);

	glPushMatrix();
	setMaterial(1.0, 1.0, 1.0, 0.0, .0, .0, 1.0, 1.0, 1.0, 50); //Chỉnh sửa thông số màu ở đây để tạo màu nó phù hợp, dựa vào hàm setMaterial ở trên?
	glRotatef(90, 0.0, 1.0, .0);
	glTranslatef(.2, -.45, 0);
	glRotatef(spin, 0.0, 0.0, 1.0);//Chinh thong so quay o day
	glutSolidTorus(.05, .1, 9, 9);       // wheel

	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.007, -.2);
	glRotatef(spin, 0.0, 0.0, 1.0); //Chinh thong so quay o day
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glPopMatrix();
	glPopMatrix();
	glFlush();
	glutSwapBuffers(); //bat su kien ban phim

}
// Hàm xử lý khởi
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}

//Hàm sử lý sự kiện hoạt cảnh bàn phím
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'm':
		dichchuyen = (dichchuyen + 1) / 1.1;
		glutPostRedisplay();
		break;
	case 'n':
		dichchuyen = (dichchuyen - 1) * 1.1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
//Hàm xử lý sự kiện thao tác với chuột
void MouseButton(int type_button, int state, GLint x, GLint y)
{
	switch (type_button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	default:
		break;
	}
}
void MouseMove(int x, int y) {
	int a = 5;
}
void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	init();
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("Hello, Car Model!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(MouseButton);

	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);

	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, .0, .0, .0, 0.0, 3.0, .0);

	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}






