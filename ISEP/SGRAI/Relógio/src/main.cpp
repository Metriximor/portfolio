#include <iostream>
#include <GL/glut.h>
#include "Ponto2D.h"
#include "PoligonoRegular.h"
#include "Relogio.h"

void init();

void display();

void poligono(GLint n, GLfloat x0, GLfloat y0, GLfloat r);

void timer(int value);

void keyboard(unsigned char key, int x, int y);

int n_lados = 100;
PoligonoRegular poligon = PoligonoRegular(Ponto2D(0.5, 0.5), 0.5, n_lados);
Mostrador2D mostrador = Mostrador2D(poligon);
Relogio relogio = Relogio(poligon, mostrador);

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // NOLINT(hicpp-signed-bitwise)
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Poligono");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Ponto2D centro = Ponto2D(0.5, 0.5);
    poligono(n_lados, centro.x, centro.y, 0.5);
    glutSwapBuffers();
}

void poligono(GLint n, GLfloat x0, GLfloat y0, GLfloat r) {
    relogio.desenhar(Cor(255, 255, 255));
}

void timer(int value) {
    glutTimerFunc(1000, timer, 0);
    relogio.inc_segundo();
    glutPostRedisplay();
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