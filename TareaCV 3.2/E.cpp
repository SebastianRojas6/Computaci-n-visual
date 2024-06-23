#include <GL/glut.h>
#include <cmath>

// Definir M_PI si no está definido
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Dimensiones de la ventana
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo blanco
    glColor3f(0.0, 0.0, 1.0); // Color de dibujo azul
    glPointSize(2.0); // Tamaño del punto
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0); // Configura el sistema de coordenadas
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibuja las líneas radiales y círculos concéntricos
    glColor3f(0.0, 0.0, 0.0); // Color negro para las líneas de la cuadrícula
    glBegin(GL_LINES);
    for (int i = 0; i < 360; i += 15) {
        float angle = i * M_PI / 180.0;
        glVertex2f(0.0, 0.0);
        glVertex2f(3.0 * cos(angle), 3.0 * sin(angle));
    }
    glEnd();

    for (float r = 0.5; r <= 3.0; r += 0.5) {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float angle = i * M_PI / 180.0;
            glVertex2f(r * cos(angle), r * sin(angle));
        }
        glEnd();
    }

    // Dibuja la gráfica de la rosa polar r = 2 * cos(2 * theta)
    glColor3f(0.0, 0.0, 1.0); // Color azul para la curva
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i++) {
        float theta = i * M_PI / 180.0;
        float r = 2 * cos(2 * theta);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Grafico Polar en OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
