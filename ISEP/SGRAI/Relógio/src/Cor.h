//
// Created by Pedro Ivo on 19/10/2020.
//
#pragma once

#include <cstdint>

#define VERMELHO Cor(255,0,0)
#define VERDE Cor(0,255,0)
#define AZUL Cor(0,0,255)

class Cor {
public:
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;
    /**
     * Guarda os dados de uma cor rgb
     * @param red 0-255 para vermelho
     * @param green 0-255 para verde
     * @param blue 0-255 para azul
     */
    Cor(uint8_t red, uint8_t green, uint8_t blue);

    /**
     * Inverte uma cor para o seu contrário na roda de cores
     * @return a cor invertida
     */
    [[nodiscard]] Cor inverter() const;
};
