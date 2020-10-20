//
// Created by Pedro Ivo on 19/10/2020.
//
#include "Marca2D.h"

Marca2D::Marca2D(const Ponto2D pntInterior, const Ponto2D pntExterior, const float lineWidth) :
        pnt_interior(pntInterior), pnt_exterior(pntExterior), line_width(lineWidth) {}

void Marca2D::desenhar(Cor cor) const {
    glColor3ub(cor.red, cor.green, cor.blue);
    glLineWidth(line_width);
    glBegin(GL_LINES);
    glVertex2d(pnt_interior.x, pnt_interior.y);
    glVertex2d(pnt_exterior.x, pnt_exterior.y);
    glEnd();
}

std::ostream &operator<<(std::ostream &os, const Marca2D &d) {
    os << " pnt_interior: " << d.pnt_interior << " pnt_exterior: "
       << d.pnt_exterior << " line_width: " << d.line_width;
    return os;
}

Marca2D &Marca2D::operator=(const Marca2D &marca2D) {
    auto *line_width_ptr = (float*)(&line_width);
    *line_width_ptr = marca2D.line_width;
    auto *pnt_interior_ptr = (Ponto2D*)(&pnt_interior);
    *pnt_interior_ptr = marca2D.pnt_interior;
    auto *pnt_exterior_ptr = (Ponto2D*)(&pnt_exterior);
    *pnt_exterior_ptr = marca2D.pnt_exterior;
    return *this;
}
