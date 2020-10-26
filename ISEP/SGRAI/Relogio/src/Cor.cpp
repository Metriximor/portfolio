//
// Created by Pedro Ivo on 19/10/2020.
//

#include "Cor.h"

Cor::Cor(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}

Cor Cor::inverter() const {
    return Cor(255 - this->red, 255-this->green, 255-this->blue);
}
