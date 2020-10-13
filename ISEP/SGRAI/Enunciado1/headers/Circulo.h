//
// Created by Pedro Ivo on 13/10/2020.
//

#ifndef SGRAI_CIRCULO_H
#define SGRAI_CIRCULO_H


#include <vector>
#include "Ponto2D.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>

#define RAD(x) (M_PI * (x) / 180.0)
#define GRAUS(x) (180.0 * (x) / M_PI)

/**
 * Circulo 2D
 */
class Circulo {
private:
    const Ponto2D centro;
    const double raio;
    std::vector<Ponto2D> pontos;
public:
    /**
     * @param centro o ponto em que o circulo está centrado
     * @param raio o raio do circulo
     * @param num_fatias o número de fatias para efetuar no circulo
     */
    Circulo(Ponto2D centro, double raio, int num_fatias);

    friend std::ostream &operator<<(std::ostream &os, const Circulo &circulo);
};


#endif //SGRAI_CIRCULO_H
