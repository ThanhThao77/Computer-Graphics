///* vẽ ấm trà xoay bình thường*/
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
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //xóa bộ đệm màu và xóa bộ đệm chiều sâu của màu
//	
//	//ve o day
//	glColor3f(1, 0, 0);
//	truc();
//	//glutSolidTeapot(3);
//
//	glPushMatrix(); // đẩy vào trong stack
//	/*glColor3f(1, 0, 0);
//	glutSolidTeapot(3);*/
//
//	/*glTranslated(0, -3, 0);
//	glColor3f(0, 1, 0);
//	glutSolidTeapot(3);*/
//
//	//cho xoay liên tục
//	glRotatef(alpha, 0, 1, 0);
//	alpha = alpha + 0.1; //sau khi alpha vẽ xong lần 1 thì tăng lên, vẽ xong lần 2 thì tăng lên...
//	if (alpha >= 360) //khi mà n lớn hơn hoặc = thì nó gán = 0 vì nếu không vòng lặp sẽ vô tận
//		alpha == 0;
//
//	// glutWireTeapot(3); // hàm vẽ ấm trà với kích thước là 3
//	glutSolidTeapot(3);
//	/*
//	glTranslated(2, 0, 0); //dịch chuyển
//	glutWireTeapot(3); // kích thước
//	*/
//
//	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
//	
//	glutPostRedisplay(); //hàm tự động gọi Display để tự động xoay
//
//	glFlush();
//
//}
//
//void init()  //xóa màn hình
//{
//	//xoa nen
//	glClearColor(1.0, 1.0, 1.0, 0.0); 
//
//	//kiem tra chieu sau
//	glEnable(GL_DEPTH_TEST); //enable chế độ kiểm tra chiều sâu
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	//glEnable(GL_LIGHT0); // đối tượng chiếu sáng = các tham số mặc định. Còn nếu dùng light 1 den 7 thì n đen xì. Màu đối tg hiển thị do nguồn sáng và chất liệu
//	//glEnable(GL_COLOR_MATERIAL); // neu dung cai nay thi hinh sdung luon cai mau chieu sang
//
//	// khai baos
//	GLfloat posi[] = { 0.0,1.0,0.0,1.0 }; //vtri trục z bằng 1
//	GLfloat ambient[] = { 1,0,0,1 }; 
//	GLfloat diffu[] = { 0.0, 0.95, 0.0, 1.0 };
//	GLfloat specu[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat shininess[] = { 15.0 };
//		// muon dat chat lieu thi phai cho phan xa nguon sang
//		//specu: pahn xa
//		// shininess: cuong do
//
//		// thu 2: thiet lap nguon sang
//	glLightfv(GL_LIGHT0, GL_POSITION, posi);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specu);
//	glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
//
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
//	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 30 );
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



#include<GL/freeglut.h>

GLfloat alpha = 0; //khai báo toàn cục

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

void ve() {
	glBegin(GL_DEPTH_BITS | GL_LINES);
	glutSolidTeapot(3.0);
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	//Thiết lập nguồn sáng nhg nếu chưa có nguồn sáng sẽ chỉ ra màu đen
	glEnable(GL_LIGHTING);
	//Nguồn sáng từ 1 đến 7 đen vì chưa thiết lập
	glEnable(GL_LIGHT1);
	//Cái này có màu sẵn
	glEnable(GL_LIGHT0);

	//Dung lenh nay thi chat lieu dung luon mau nguon sang
//	glEnable(Gl_color_material);

	//Thiet lap nguon sang
	GLfloat posi[] = { 0,1,0,1 };

	//Chay nguon sang
	glLightfv(GL_LIGHT1, GL_POSITION, posi);

	//Thiet lap anh sang moi truong
	GLfloat ambient[] = { 0,0,1,1 };

	//Chay anh sang moi truong
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);

	//Thiet lap anh sang khuech tan
	GLfloat diffu[] = { 1,0,0,1 };

	//Chay anh sang khuech tan
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffu);

	////Thiet lap phan xa specu
	GLfloat specu[] = { 1,1,0,1 };

	//Chay phan xa
	glLightfv(GL_LIGHT1, GL_SPECULAR, specu);

	//Thiet lap do bong
	GLfloat shine[] = { 50 };

	/*Thiet lap chat lieu material*/
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specu);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glColor3f(1.0, 1.0, 1.0);

	glDisable(GL_LIGHTING);
	truc();

	glEnable(GL_LIGHTING);

	glPushMatrix(); // đẩy vào trong stack
	//cho xoay liên tục
	glRotatef(alpha, 0, 1, 0);
	alpha = alpha + 0.05; //sau khi alpha vẽ xong lần 1 thì tăng lên, vẽ xong lần 2 thì tăng lên...
	if (alpha >= 360) //khi mà n lớn hơn hoặc = thì nó gán = 0 vì nếu không vòng lặp sẽ vô tận
		alpha == 0;
	ve();
	glPopMatrix(); // khi thực hiện xong thì lấy ra, dùng hàm popmatrix
	glutPostRedisplay(); //hàm tự động gọi Display để tự động xoay

	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 30);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}

//#include<GL/freeglut.h>/* hàm thực hiện các thao tác vẽ theo yêu cầu của chương trình */
//
//GLfloat alpha = 0;
//
//vẽ trục tọa độ
//void truc() {
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(10, 0, 0);
//
//	glColor3f(.0, 1.0, 0.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 10, 0);
//
//	glColor3f(.0, .0, 1.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 10);
//	glEnd();
//}
//
//void ve() {
//	glScalef để phóng to thu nhỏ hình, 
//	glTranslatef để di chuyển hình,
//	glRotatef để xoay hình (xoay quanh trục nào thì cho trục đấy là 1)
//	Ghi chú: Vẽ xong hình nào cx đưa nó về trục tọa độ
//	glColor3f(0, 0, 0); //Thiết lập màu cho vật mình vẽ (theo bảng màu rgb)
//	glBegin(GL_POLYGON | GL_DEPTH_BITS); /* bắt đầu vẽ đa giác */
//	glutWireCube(0.5);//Tạo hình lập phương với các cạnh là 0.5
//
//
//	glColor3f(1, 0, 0);
//	glRotated(45, 0, 0, 1);//Xoay quanh Oz với góc 45 độ
//	glTranslatef(0.6, 0, 0);
//	glutWireCube(0.5);
//
//	Đưa về gốc tọa độ
//	glTranslatef(-0.6, 0, 0);
//	glRotated(-45, 0, 0, 1);//Xoay quanh Oz với góc 45 độ
//
//
//	Bắt đầu vẽ tiếp
//	glTranslatef(0, 0.6, 0);
//	glutSolidCube(0.5);
//	glEnd(); /* kết thúc vẽ đa giác */
//}
//
//void ve2() {
//	glColor3f(0, 0, 0); //Thiết lập màu cho vật mình vẽ (theo bảng màu rgb)
//	glBegin(GL_POLYGON | GL_DEPTH_BITS); /* bắt đầu vẽ đa giác */
//	glutWireTeapot(0.5);
//	glEnd(); /* kết thúc vẽ đa giác */
//}
//
//void display(void)
//{
//	/* xóa mọi pixel */
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	truc();
//	Sử dụng pushMatrix và popMatrix để cho mỗi 1 hành động riêng
//	glPushMatrix();
//	alpha = alpha + 0.01;
//	if (alpha >= 360) alpha = 0;
//	glRotated(alpha, 0, 0, 1);
//	ve();
//	glPopMatrix();
//
//	glPushMatrix();
//	ve2();
//	glPopMatrix();
//
//	/*
//	* thực hiện quá trình đẩy ra buffer
//	*/
//	glutPostRedisplay();
//	glFlush();
//}
///* hàm thực hiện các khởi tạo */
//void init(void)
//{
//	/* chọn màu để xóa nền (tức là sẽ phủ nền bằng màu này) */
//	glClearColor(1, 1, 1, 0.0); /* Nen mau trang*/
//	/* thiết lập các thông số cho view */
//	glEnable(GL_DEPTH_TEST);
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 30);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//Góc nhìn để cho thầy xem
//	gluLookAt(5, 5, 3, 0, 0, 0, 0, 1, 0);
//
//	Góc nhìn dùng để vẽ
//	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
//}
//
///* hàm main của chương trình */
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /* khởi tạo chế độ vẽ
//   single buffer và hệ màu RGB */
//	glutInitWindowSize(800, 600); /* khởi tạo window kích thước 800x600 */
//	glutInitWindowPosition(150, 150); /* khởi tạo window tại ví trí
//   (100,100) trên screen */
//	glutCreateWindow("rectangle"); /* tên của window là ‘rectangle’ */
//	init(); /* khởi tạo một số chế độ đồ họa */
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display); /* thiết lập hàm vẽ là hàm display() */
//	glutMainLoop(); /* bắt đầu chu trình lặp thể hiện vẽ */
//	return 0;
//}