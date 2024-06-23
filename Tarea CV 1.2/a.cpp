#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar decágono con polígono cerrado
    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glBegin(GL_POLYGON);
    for (int i = 0; i < 10; ++i) {
        float theta = 2.0f * 3.14159f * float(i) / 10.0f;
        glVertex2f(0.5f * cos(theta), 0.5f * sin(theta));
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Color de fondo blanco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f); // Definir el sistema de coordenadas
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Decágono Relleno");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
