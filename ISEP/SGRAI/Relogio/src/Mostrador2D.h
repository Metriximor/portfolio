//
// Created by Pedro Ivo on 19/10/2020.
//
#pragma once

#include <vector>
#include "Marca2D.h"
#include "PoligonoRegular.h"
#include "Ponteiro.h"

class Mostrador2D : public Desenhavel2D {
private:
    typedef std::vector<Marca2D> Marcas;
    Marcas marcas;
    Marcas marcasPrincipais;
    Ponteiro pnt_secs;
    Ponteiro pnt_mins;
    Ponteiro pnt_hors;
public:
    void desenhar(Cor cor) const override;
    explicit Mostrador2D(const PoligonoRegular &pol_reg);

    void atualizar(uint8_t segundos, uint8_t minutos, uint8_t horas);
};


