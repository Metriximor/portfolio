#include <iostream>
#include <GL/glut.h>
#include "Ponto2D.h"
#include "Circulo.h"
#include "PoligonoRegular.h"

void init();

void display();

void poligono(GLint n, GLfloat x0, GLfloat y0, GLfloat r);

void mostrador();

void keyboard(unsigned char key, int x, int y);

int n_lados;

int main(int argc, char **argv) {
    n_lados = 100;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Poligono");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    Ponto2D centro = Ponto2D(0.5, 0.5);
    glBegin(GL_POLYGON);
    poligono(n_lados, centro.x, centro.y, 0.5);
    glEnd();
    glFlush();
}

void poligono(GLint n, GLfloat x0, GLfloat y0, GLfloat r) {
    PoligonoRegular(x0, y0, r, n).desenhar();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            if (n_lados < 100) {
                ++n_lados;
                std::cout << "Aumentado número de lados" << std::endl;
            } else {
                std::cout << "Número de lados não pode ser maior que 100" << std::endl;
            }
            break;
        case '-':
            if (n_lados > 3) {
                --n_lados;
                std::cout << "Diminuido número de lados" << std::endl;
            } else {
                std::cout << "Número de lados não pode ser menor que 3" << std::endl;
            }
            break;
        default:
            std::cout << "Not implemented" << std::endl;
    }
    glutPostRedisplay();
}