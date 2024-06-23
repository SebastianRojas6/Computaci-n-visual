#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;
const int NUM_SAMPLES = 1000;

void drawPolarGrid() {
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo para las coordenadas polares
    glLineWidth(1.0f);

    // Dibujar círculos concéntricos
    for (float r = 1.0f; r <= 10.0f; r += 1.0f) {
        glBegin(GL_LINE_LOOP);
        for (float theta = 0.0f; theta <= 2.0f * PI; theta += 0.01f) {
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();
    }

    // Dibujar líneas radiales
    glBegin(GL_LINES);
    for (float theta = 0.0f; theta < 2.0f * PI; theta += PI / 6.0f) { // Paso de 30 grados
        glVertex2f(0.0f, 0.0f);
        glVertex2f(10.0f * cos(theta), 10.0f * sin(theta));
    }
    glEnd();
}

void drawSpiral() {
    glColor3f(0.0f, 0.0f, 1.0f); // Azul para la espiral de Fermat
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    for (int j = 0; j <= NUM_SAMPLES; ++j) {
        float theta = 2 * PI * j / NUM_SAMPLES;
        float r = theta;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawPolarGrid();
    drawSpiral();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Color de fondo blanco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f); // Establecer el sistema de coordenadas
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Espiral de Fermat con coordenadas polares");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
