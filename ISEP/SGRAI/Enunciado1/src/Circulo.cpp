//
// Created by Pedro Ivo on 13/10/2020.
//

#include "../headers/Circulo.h"

Circulo::Circulo(Ponto2D centro, double raio, int num_fatias) : centro(centro), raio(raio) {
    for(int t = 0; t < 360; t += (360 / num_fatias)) {
        double x = raio * cos(RAD(t)) + centro.x;
        double y = raio * sin(RAD(t)) + centro.y;
        pontos.push_back(Ponto2D(x,y));
    }
}

std::ostream &operator<<(std::ostream &os, const Circulo &circulo) {
    os << "Centro: " << circulo.centro << "\nRaio: " << circulo.raio << "\nPontos: \n";
    for(Ponto2D ponto : circulo.pontos) {
        os << ponto << "\n";
    }
    return os;
}
