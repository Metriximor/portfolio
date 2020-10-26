//
// Created by Pedro Ivo on 18/10/2020.
//
#pragma once
#include <chrono>
#include <ctime>

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
    Relogio(const PoligonoRegular& background, Mostrador2D mostrador);

    Relogio& operator=(const Relogio &r);

    void desenhar(Cor cor) const override;

    /**
     * Atualiza o relógio para mostrar a hora do sistema atual
     */
    void atualizar_para_tempo_atual();
};


