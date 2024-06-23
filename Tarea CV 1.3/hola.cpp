#include <GL/glut.h>
#include <cmath>

#define M_PI 3.14159265358979323846

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar polígono con polígono cerrado y relleno azul
    glColor3f(0.0f, 0.0f, 1.0f); // Color azul
    glBegin(GL_POLYGON);
    for (int i = 0; i < 15; ++i) {
        float theta = 2.0f * M_PI * float(i) / 15.0f;
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
    glutCreateWindow("Polígono de 15 lados");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
