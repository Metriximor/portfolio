//
// Created by Pedro Ivo on 20/10/2020.
//

#pragma once

#include "Marca2D.h"
#include "PoligonoRegular.h"

class Ponteiro : public Desenhavel2D {
private:
    Marca2D marca;
    PoligonoRegular poli;
public:
    Ponteiro(const PoligonoRegular &poli, float largura);

    /**
     * Define a posição do ponteiro(0 é 12horas, 1 é 1h)
     * @param posicao a posição(em horas indexadas por 0)
     */
    void definir_posicao(uint32_t posicao);

    [[noreturn]] void desenhar(Cor cor) const override;
};


