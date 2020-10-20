//
// Created by Pedro Ivo on 19/10/2020.
//
#pragma once

#include "Ponto2D.h"
#include "Desenhavel2D.h"

#include <GL/glut.h>
#include <ostream>

class Marca2D : public Desenhavel2D {
public:
    const float line_width;
    const Ponto2D pnt_interior;
    const Ponto2D pnt_exterior;
    Marca2D(Ponto2D pntInterior, Ponto2D pntExterior, float lineWidth);

    /**
     * Assignment operator overload
     * @param marca2D the thing we want to assign
     */
    Marca2D& operator=(const Marca2D &marca2D);

    friend std::ostream &operator<<(std::ostream &os, const Marca2D &d);

    void desenhar(Cor cor) const override;
};


