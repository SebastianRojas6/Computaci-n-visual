#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(2.0f);

    glBegin(GL_LINE_STRIP);

    glVertex2f(2.7f, 3.93f);
    glVertex2f(0.98f, 1.69f);
    glVertex2f(5.54f, 3.17f);
    glVertex2f(5.56f, 1.27f);
    glVertex2f(4.22f, 3.43f);

    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 6.0, 0.0, 5.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Línea Continua con GL_LINE_STRIP");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
