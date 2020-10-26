//
// Created by Pedro Ivo on 19/10/2020.
//
#include "Mostrador2D.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "UnreachableCode"
void Mostrador2D::desenhar(Cor cor) const {
    for (const Marca2D &marca : marcasPrincipais) {
        marca.desenhar(cor);
    }
    for (const Marca2D &marca : marcas) {
        marca.desenhar(cor);
    }
    pnt_secs.desenhar(cor);
    pnt_mins.desenhar(cor);
    pnt_hors.desenhar(VERMELHO);
}
#pragma clang diagnostic pop

Mostrador2D::Mostrador2D(const PoligonoRegular &pol_reg) :
        pnt_secs(PoligonoRegular(pol_reg.centro, pol_reg.raio * 0.75, 60), 2.5),
        pnt_mins(PoligonoRegular(pol_reg.centro, pol_reg.raio * 0.5, 60), 5),
        pnt_hors(PoligonoRegular(pol_reg.centro, pol_reg.raio * 0.3, 12), 9) {
    uint32_t num_lados = 60;
    typedef std::vector<Ponto2D> Pontos;
    Pontos pontos_exteriores = PoligonoRegular(pol_reg.centro, pol_reg.raio, num_lados)
            .calcular_pontos_no_perimetro();
    Pontos pontos_interiores_pequenos = PoligonoRegular(pol_reg.centro, pol_reg.raio * 0.9, num_lados)
            .calcular_pontos_no_perimetro();
    Pontos pontos_interiores_grandes = PoligonoRegular(pol_reg.centro, pol_reg.raio * 0.8, num_lados)
            .calcular_pontos_no_perimetro();
    for (uint32_t i = 0; i < num_lados; ++i) {
        if (i % 5 == 0) {
            marcasPrincipais.push_back(Marca2D(pontos_interiores_grandes.at(i), pontos_exteriores.at(i), 6.0));
            continue;
        }
        marcas.push_back(Marca2D(pontos_interiores_pequenos.at(i), pontos_exteriores.at(i), 3.0));
    }
}

void Mostrador2D::atualizar(uint8_t segundos, uint8_t minutos, uint8_t horas) {
    pnt_secs.definir_posicao(segundos);
    pnt_mins.definir_posicao(minutos);
    pnt_hors.definir_posicao(horas);
}
