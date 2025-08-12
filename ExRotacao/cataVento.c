#include <GL/freeglut.h>

float angulo = 0.0f;

void initCataVento(void){

	glClearColor(0.0, 0.0, 0.0, 0.0);

	gluOrtho2D(0.0, 500.0, 0, 500.0);

}

void helicesFunc(void){

    glBegin(GL_TRIANGLES);
        glColor3f(.0, 1.0, .0);
		glVertex2i(250, 250);
		glVertex2i(230, 200);
		glVertex2i(270, 200);

        glColor3f(1.0, 1.0, .0);
        glVertex2i(250, 250);
        glVertex2i(200, 230);
        glVertex2i(200, 270);

        glColor3f(.0, .0, 1.0);
        glVertex2i(250, 250);
		glVertex2i(230, 300);
		glVertex2i(270, 300);

        glColor3f(1.0, 0.0, 1.0);
        glVertex2i(250, 250);
        glVertex2i(300, 230);
        glVertex2i(300, 270);
	glEnd();

}

void cataVentoFunc(void){

	glColor3f(1.0, .0, .0);
	glBegin(GL_POLYGON);
		glVertex2i(248, 250);
		glVertex2i(251, 250);
		glVertex2i(248, 100);
		glVertex2i(251,100);
	glEnd();

}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);

    cataVentoFunc();

    glPushMatrix();
        glTranslatef(250.0f, 250.0f, 0.0f);
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        glTranslatef(-250.0f, -250.0f, 0.0f);
        helicesFunc();
    glPopMatrix();

    glFlush();

}

void teclado(unsigned char tecla, int x, int y){
    if(tecla == 'b'){
        angulo += 10.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cata-Vento");

	initCataVento();

	glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

	glutMainLoop();	
}
