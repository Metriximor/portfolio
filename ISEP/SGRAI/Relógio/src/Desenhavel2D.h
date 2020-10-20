//
// Created by Pedro Ivo on 17/10/2020.
//
#pragma once

#include "Cor.h"

class Desenhavel2D {
public:
    /**
     * Desenha o Desenhavel num contexto Open GL com uma determinada cor
     * @param cor a cor que pretendemos desenhar
     */
    virtual void desenhar(Cor cor) const = 0;
};
