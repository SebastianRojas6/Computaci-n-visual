#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void drawSquare(int x1, int y1, int x2, int y2) {
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();
}

void drawTiger() {
    glColor3f(0.8, 0.5, 0.3); // Brown color

    // Body
    drawSquare(200, 150, 400, 350);

    // Head
    drawSquare(400, 300, 500, 400);

    // Ears
    drawTriangle(450, 400, 500, 450, 500, 400);
    drawTriangle(400, 400, 400, 450, 450, 400);

    // Eyes
    glColor3f(1.0, 1.0, 1.0); // White color
    drawSquare(440, 370, 460, 390);
    drawSquare(470, 370, 490, 390);

    glColor3f(0.0, 0.0, 0.0); // Black color
    drawSquare(450, 380, 450, 380);
    drawSquare(480, 380, 480, 380);

    // Nose
    glColor3f(0.0, 0.0, 0.0); // Black color
    drawSquare(465, 350, 475, 360);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTiger();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tiger");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
