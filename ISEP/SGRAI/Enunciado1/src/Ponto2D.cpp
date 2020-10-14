//
// Created by Pedro Ivo on 13/10/2020.
//

#include "../headers/Ponto2D.h"

Ponto2D::Ponto2D(double x, double y) : x(x), y(y) {}

double Ponto2D::distancia(Ponto2D outro) {
    return sqrt(pow(outro.x - x, 2) + pow(outro.y - y, 2));
}

Ponto2D Ponto2D::ponto_medio(Ponto2D outro) {
    double calc_x = (x + outro.x) / 2.0;
    double calc_y = (y + outro.y) / 2.0;
    return Ponto2D(calc_x, calc_y);
}

std::ostream &operator<<(std::ostream &os, const Ponto2D &d) {
    printf("x:% 5.2f y:% 5.2f",d.x,d.y);
    return os;
}
