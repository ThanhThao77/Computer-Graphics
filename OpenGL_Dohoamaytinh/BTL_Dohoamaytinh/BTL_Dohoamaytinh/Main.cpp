#include<GL/freeglut.h>

GLint dichchuyen = 0;
GLfloat spinspeed = 0.0f; 
GLdouble zoom_to = 0.05;
GLdouble zoom_nho = 0.05;

/*hàm xử lý tốc độ quay của bánh xe*/
void SpinDisplay() {
	spinspeed += 0.1; 
	if (spinspeed >= 360)
		spinspeed == 0;
	glutPostRedisplay(); //thông báo cho chương trình rằng: cần phải thực hiện việc lặp lại
}


/*Hàm khai bao thao tác xử lý chiếu sáng : ánh sáng bao quanh, ánh sáng khuếch tán, ánh sáng phản chiếu Red, Green, Blue.*/
void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess)
{
	GLfloat ambient[] = { ambientR, ambientG, ambientB }; //Ánh sáng môi trường
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB }; //Ánh sáng khuếch tán
	GLfloat specular[] = { specularR, specularG, specularB }; //Ánh sáng phản chiếu.
	GLfloat shine[] = { shininess }; // phản xạ
	//thiết lập chất liệu
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}


void truc() {
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); //màu đỏ
	//truc x
	glVertex3f(0, 0, 0); //đỉnh thứ nhất
	glVertex3f(10, 0, 0);

	//truc y
	glColor3f(0, 1, 0); //màu xanh lá
	glVertex3f(0, 0, 0);
	glVertex3f(0, 10, 0);

	//truc z
	glColor3f(0, 0, 1); // màu xanh biển (màu cuối có tác động tới màu của hình vẽ)
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 10);

	glEnd();

}

/*Vẽ trục đường đi của ô tô*/
void trucnghieng() {
	glRotatef(50, 0, 1, 1);  //Ðộ nghiêng.
	glScalef(30, 0, 3.0);
	setMaterial(0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 50);
	glutWireCube(1.0);
}

void thanduoixe() {
	setMaterial(0.0, 0.5, 0.1, 0.6, 0.6, 0.0, 0.0, 0.0, 1.0, 50);
	glScalef(1, 0.5, 2.5);
	//glutWireCube(0.5);
	glutSolidCube(.5);
}

void thantren() {
	setMaterial(0.0, 0.5, 0.1, 0.6, 0.6, 0.0, 0.0, 0.0, 1.0, 50);
	//ánh sáng mt, ánh sáng khuếch tán, ánh sáng phản xạ màu xanh dương
	//setMaterial(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(0.55, 0.75, 0.8);
	glScalef(1.0, 0.5, 1.7);
	//glScalef(0.8, 1, 1.7);

	//glutWireCube(0.35);
	glutSolidCube(.35);
}

void banhxe() {
	glTranslatef(0.55, 0.75, 0.8);
	glutSolidTorus(0.05, 0.12, 9.0, 9.0);

}
void triangle(void)
{
	glBegin(GL_TRIANGLES); // vẽ tam giác
	glVertex2f(1.0, 1.0);
	glVertex2f(0.5, 0.6);
	glVertex2f(1.0, 1.2);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //xóa bộ đệm màu và xóa bộ đệm chiều sâu của màu
	glColor3f(1.0, 1.0, 0.0);
	//truc();
	
	glPushMatrix(); // đẩy vào trong stack
	
	/*vẽ đường đi*/
	glPushMatrix();
	trucnghieng(); 
	glPopMatrix();
	
	/*-----------------------------------*/
	/*vẽ thân dưới xe*/
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 6, (GLfloat)dichchuyen / 6, 0); //phép tịnh tiến tạo sự di chuyển tại tọa độ (6, 6, 0)
	thanduoixe();
	glPopMatrix();

	/*vẽ thân trên xe*/
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 6.4, (GLfloat)dichchuyen / 6.4, 0);
	thantren();
	glPopMatrix();

	/*---------------------------------*/
	/*bánh xe phụ*/
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 6, (GLfloat)dichchuyen / 6, 0);
	glTranslatef(-0.6, -0.65, 0.0);
	banhxe();
	glPopMatrix();
	/*------------------------------------------*/

	glTranslatef(0.0, 0, 0.35);
	
	/*-----------------------------------------------*/
	/*vẽ 2 bánh xe sau*/
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 6, (GLfloat)dichchuyen / 6, 0);
	setMaterial(1.0, 1.0, .0, 0.0, 0.5, 0.0, 1.0, 1.0, 1.0, 50);
	
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.1, -0.4, 0.0);
	glRotatef(spinspeed, 0.0, 0.0, 1.0); // xoay một góc spinspeed quanh trục z
	//SpinDisplay(); //goi ham xoay banh xe lien tuc
	glutSolidTorus(zoom_to, 0.12, 9.0, 9.0);
	//glutSolidTorus(zoom_nho, 0.12, 9.0, 9.0);

	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, -0.5);
	glRotatef(spinspeed, 0, 0, 1);
	//glTranslatef(0.0, 0, -0.01);
	glutSolidTorus(zoom_to, 0.12, 9.0, 9.0);
	//glutSolidTorus(zoom_nho, 0.12, 9.0, 9.0);
	//glTranslatef(0.0, 0, 0.25);
	glPopMatrix();
	
	/*---------------------------------------------*/
	/*ve den xe*/
	glPushMatrix();
	glTranslatef(0.2, 0, -0.3);
	glTranslatef((GLfloat)dichchuyen / 6.5, (GLfloat)dichchuyen / 6.5, 0);
	setMaterial(1.0, 1.0, .0, 1.0, 1.5, 1.0, 0.0, 0.0, 1.0, 50);
	triangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 0, -0.3);
	glTranslatef((GLfloat)dichchuyen / 6.5, (GLfloat)dichchuyen / 6.5, 0);
	triangle();
	glPopMatrix();
	/*---------------------------------------------*/

	/*vẽ 2 bánh xe trước */
	glTranslatef(0, 0, -0.85);
	
	glPushMatrix();
	glTranslatef((GLfloat)dichchuyen / 6, (GLfloat)dichchuyen / 6, 0);
	setMaterial(1.0, 1.0, .0, 0.0, 0.5, 0.0, 1.0, 1.0, 1.0, 50);

	glRotatef(90, 0.0, 1.0, .0);
	glTranslatef(0.2, -0.45, 0);
	glRotatef(spinspeed, 0.0, 0.0, 1.0);//xoay banh xe lien tuc 
	//glRotatef(0,0.0, 0.0, 1.0);//Chinh thong so quay 
	glutSolidTorus(zoom_to, 0.12, 9.0, 9.0);
	//glutSolidTorus(zoom_nho, 0.12, 9.0, 9.0);


	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.007, -.2);
	glRotatef(spinspeed, 0.0, 0.0, 1.0);
	//glRotatef(0, 0.0, 0.0, 1.0);//Chinh thong so quay 
	glutSolidTorus(zoom_to, 0.12, 9.0, 9.0);
	//glutSolidTorus(zoom_nho, 0.12, 9.0, 9.0);
	glPopMatrix();

	/*---------------------------------------------*/

	glPopMatrix(); // khi thực hiện xong thì lấy ra

	

	glFlush();
	glutSwapBuffers(); /* thực hiện việc hoán đổi 2 buffer */
}

//ham khoi tao ma tran chieu + bien doi moi khi thay doi cua so
void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);  //(GLsizei)w: ép kiểu
	
	/* phép biến đổi hình chiếu */
	glMatrixMode(GL_PROJECTION); //thiet lap che do chieu
	glLoadIdentity(); // khoi tao ma tran dvi
	gluPerspective(40, (GLfloat)width / (GLfloat)height, 4, 20); //chieu boi canh

	/* thiết lập góc nhìn */
	glMatrixMode(GL_MODELVIEW); //ma trận biến đổi
	glLoadIdentity(); //load ma trận đvi
	//vtri dat camera
	gluLookAt(5, 5, 5, 0, 0, 0, 1, 2, 0); //vtri mắt (5,5,5), hướng nhìn tại tâm tọa độ, hướng đỉnh trục oy
}

//Hàm sử lý sự kiện hoạt cảnh bàn phím
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'z':
		zoom_to += 0.1;
		break;
	case 't': //xe di chuyển tiến lên
		dichchuyen = (dichchuyen + 1.6) / 1.1;
		glutPostRedisplay();
		break;
	case 'l': //xe di chuyển lùi 
		dichchuyen = (dichchuyen - 1) * 1.1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//kiem tra chieu sau
	glEnable(GL_DEPTH_TEST); //enable chế độ kiểm tra chiều sâu
	glShadeModel(GL_FLAT); // thiết lập chế độ shading là smooth

	/* kích hoạt nguồn sáng */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);*/
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Draw Car");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); // đăng ký hàm reshape cho sự kiện cửa sổ bị thay đổi kích thước
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}