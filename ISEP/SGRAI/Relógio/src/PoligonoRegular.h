//
// Created by Pedro Ivo on 17/10/2020.
//
#pragma once

#include <vector>
#include <cstdint>
#include "utils.h"
#include "Desenhavel2D.h"
#include "Ponto2D.h"

#include <GL/glut.h>

class PoligonoRegular : public Desenhavel2D {
public:
    const Ponto2D centro;
    const double raio;
    const uint32_t num_lados;

    /**
     * Instancia um Poligono Regular
     * @param centro o local do centro do poligono
     * @param raio a distancia do centro do poligono até ao ponto mais distante(á direita)
     * @param numLados o número de lados do poligono
     */
    PoligonoRegular(const Ponto2D &centro, double raio, uint32_t numLados);

    PoligonoRegular& operator=(const PoligonoRegular &p);

    /**
     * Desenha o poligono com o uso de GLUT
     */
    void desenhar(Cor cor) const override;

    /**
     * Calcula as coordenadas de um determinado número de pontos no perimetro do circulo
     * @param num_fatias o número de fatias que pretendemos ter no
     * @return um vetor com todos os pontos
     */
    [[nodiscard]] std::vector<Ponto2D> calcular_pontos_no_perimetro() const;

    [[nodiscard]] Ponto2D calcular_ponto(uint8_t posicao) const;

    //para imprimir
    friend std::ostream &operator<<(std::ostream &os, const PoligonoRegular &poligonoRegular);
};
