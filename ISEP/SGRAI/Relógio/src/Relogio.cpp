//
// Created by Pedro Ivo on 18/10/2020.
//
#include "Relogio.h"

#include <utility>

void Relogio::desenhar(Cor cor) const {
    background.desenhar(cor);
    mostrador.desenhar(cor.inverter());
}

Relogio::Relogio(PoligonoRegular background, Mostrador2D mostrador) : background(std::move(background)),
                                                                      mostrador(std::move(mostrador)),
                                                                      secs(0), mins(0), hors(0) {}

void Relogio::inc_segundo() {
    ++secs;
    if (secs == 60) {
        ++mins;
        secs = 0;
    }
    if (mins == 60) {
        ++hors;
        mins = 0;
    }
    if (hors == 12) {
        hors = 0;
    }
    mostrador.atualizar(secs, mins, hors);
}

Relogio &Relogio::operator=(const Relogio &r) {
    auto *background_ptr = (PoligonoRegular *) (&background);
    *background_ptr = r.background;
    mostrador = r.mostrador;
    secs = r.secs;
    mins = r.mins;
    hors = r.hors;
    return *this;
}
