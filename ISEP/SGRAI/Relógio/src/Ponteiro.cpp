//
// Created by Pedro Ivo on 20/10/2020.
//
#include "Ponteiro.h"

Ponteiro::Ponteiro(const PoligonoRegular &poli, const float largura) :
        poli(poli), marca(poli.centro,poli.calcular_ponto(0), largura) {}

[[noreturn]] void Ponteiro::desenhar(Cor cor) const {
    marca.desenhar(cor);
}

void Ponteiro::definir_posicao(uint32_t posicao) {
    Ponto2D next_ponto = poli.calcular_ponto(posicao);
    marca = Marca2D(marca.pnt_interior, next_ponto, marca.line_width);
}
