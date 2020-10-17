//
// Created by Pedro Ivo on 17/10/2020.
//

#include "PoligonoRegular.h"

PoligonoRegular::PoligonoRegular(Ponto2D centro, double raio, int num_lados) :
    circ(centro, raio), num_lados(num_lados) {}

void PoligonoRegular::desenhar() const {
    for(Ponto2D ponto : circ.calcular_pontos_no_perimetro(num_lados)) {
        glVertex2d(ponto.x, ponto.y);
    }
}

PoligonoRegular::PoligonoRegular(double x, double y, double raio, int num_lados) :
    circ(x, y, raio), num_lados(num_lados) {}
