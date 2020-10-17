//
// Created by Pedro Ivo on 13/10/2020.
//
#pragma once

#define _USE_MATH_DEFINES       //Tem que estar em primeiro lugar com cmath

#include <cmath>
#include <vector>
#include <ostream>
#include <GL/glut.h>

#include "Ponto2D.h"

#define RAD(x) (M_PI * (x) / 180.0)
#define GRAUS(x) (180.0 * (x) / M_PI)

/**
 * Circulo 2D
 */
class Circulo {
private:
    const Ponto2D centro;
    const double raio;
public:

    /**
     * @param centro o ponto em que o circulo está centrado
     * @param raio o raio do circulo
     */
    Circulo(Ponto2D centro, double raio);

    /**
     * @param x coordenada x do centro do circulo
     * @param y coordenada y do centro do circulo
     * @param raio raio do circulo
     */
    Circulo(double x, double y, double raio);

    /**
     * Calcula as coordenadas de um determinado número de pontos no perimetro do circulo
     * @param num_fatias o número de fatias que pretendemos ter no
     * @return um vetor com todos os pontos
     */
    [[nodiscard]] std::vector<Ponto2D> calcular_pontos_no_perimetro(int num_fatias) const;

    //para imprimir
    friend std::ostream &operator<<(std::ostream &os, const Circulo &circulo);
};
