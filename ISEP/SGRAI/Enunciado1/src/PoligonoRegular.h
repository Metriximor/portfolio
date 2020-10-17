//
// Created by Pedro Ivo on 17/10/2020.
//
#pragma once

#include "Circulo.h"
#include "Desenhavel2D.h"

class PoligonoRegular : public Desenhavel2D {
private:
    const Circulo circ;
    int num_lados;
public:
    /**
     * @param centro local onde se encontra o centro do poligono
     * @param raio o raio do poligono(do centro até o ponto mais distante)
     * @param num_lados o num de lados do poligono regular
     */
    PoligonoRegular(Ponto2D centro, double raio, int num_lados);

    /**
     * @param x coordenadas x do centro do poligono
     * @param y coordenadas y do centro do poligono
     * @param raio raio do poligono(do centro até ao ponto mais distante)
     * @param num_lados o número de lados do poligono regular
     */
    PoligonoRegular(double x, double y, double raio, int num_lados);

    /**
     * Desenha o poligono com o uso de GLUT
     */
    void desenhar() const override;
};
