//
// Created by Pedro Ivo on 18/10/2020.
//
#pragma once
#include <utility>

#include "PoligonoRegular.h"
#include "Mostrador2D.h"
#include "Marca2D.h"

class Relogio : public Desenhavel2D {
private:
    const PoligonoRegular background;
    Mostrador2D mostrador;
    uint8_t secs;
    uint8_t mins;
    uint8_t hors;
public:
    /**
     * Instancia um relógio
     * @param background o background do relógio que pretendemos desenhar
     * @param mostrador os ponteiros e as marcas das horas
     */
    Relogio(PoligonoRegular background, Mostrador2D mostrador);

    Relogio& operator=(const Relogio &r);

    /**
     * Incrementa um segundo no relógio
     */
    void inc_segundo();

    void desenhar(Cor cor) const override;
};


