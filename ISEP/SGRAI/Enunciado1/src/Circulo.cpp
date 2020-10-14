//
// Created by Pedro Ivo on 13/10/2020.
//

#include "../headers/Circulo.h"

Circulo::Circulo(Ponto2D centro, double raio) : centro(centro), raio(raio) {}

std::ostream &operator<<(std::ostream &os, const Circulo &circulo) {
    os << "Centro: " << circulo.centro << "\nRaio: " << circulo.raio;
    return os;
}

std::vector<Ponto2D> Circulo::calcular_pontos_no_perimetro(int num_fatias) {
    typedef std::vector<Ponto2D> Pontos;
    Pontos pontos;
    for(int t = 0; t < 360; t += (360 / num_fatias)) {
        double x = raio * cos(RAD(t)) + centro.x;
        double y = raio * sin(RAD(t)) + centro.y;
        pontos.push_back(Ponto2D(x,y));
    }
    return pontos;
}
