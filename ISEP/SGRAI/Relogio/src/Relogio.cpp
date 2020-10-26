//
// Created by Pedro Ivo on 18/10/2020.
//
#include "Relogio.h"

void Relogio::desenhar(Cor cor) const {
    background.desenhar(cor);
    mostrador.desenhar(cor.inverter());
}

Relogio::Relogio(const PoligonoRegular& background, Mostrador2D mostrador) : background(background),
                                                                      mostrador(std::move(mostrador)),
                                                                      secs(0), mins(0), hors(0) {}

Relogio &Relogio::operator=(const Relogio &r) {
    auto *background_ptr = (PoligonoRegular *) (&background);
    *background_ptr = r.background;
    mostrador = r.mostrador;
    secs = r.secs;
    mins = r.mins;
    hors = r.hors;
    return *this;
}

void Relogio::atualizar_para_tempo_atual() {
    const std::time_t now = std::time(nullptr);
    const std::tm cal_time = *std::localtime(std::addressof(now));
    secs = cal_time.tm_sec;
    mins = cal_time.tm_min;
    hors = cal_time.tm_hour;
    mostrador.atualizar(secs, mins, hors);
}
