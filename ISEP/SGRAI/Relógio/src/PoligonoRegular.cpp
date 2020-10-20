//
// Created by Pedro Ivo on 17/10/2020.
//
#include "PoligonoRegular.h"

void PoligonoRegular::desenhar(Cor cor) const {
    glColor3ub(cor.red, cor.green, cor.blue);
    glBegin(GL_POLYGON);
    for (Ponto2D ponto : this->calcular_pontos_no_perimetro()) {
        glVertex2d(ponto.x, ponto.y);
    }
    glEnd();
}

std::ostream &operator<<(std::ostream &os, const PoligonoRegular &poly_reg) {
    os << "Centro: " << poly_reg.centro << "\nRaio: " << poly_reg.raio << "\nNúmero de lados:" << poly_reg.num_lados;
    return os;
}

PoligonoRegular::PoligonoRegular(const Ponto2D &centro, const double raio, const uint32_t numLados) :
        centro(centro), raio(raio), num_lados(numLados) {}

std::vector<Ponto2D> PoligonoRegular::calcular_pontos_no_perimetro() const {
    typedef std::vector<Ponto2D> Pontos;
    Pontos pontos;
    for (uint32_t t = 0; t < 360; t += 360 / num_lados) {
        double x = raio * cos(RAD(t)) + centro.x;
        double y = raio * sin(RAD(t)) + centro.y;
        pontos.push_back(Ponto2D(x, y));
    }
    return pontos;
}

Ponto2D PoligonoRegular::calcular_ponto(uint8_t posicao) const {
    double x = raio * cos(RAD(posicao * 360.0 / num_lados)-M_PI_2) + centro.x;
    double y = raio * sin(RAD(posicao * 360.0 / num_lados)+M_PI_2) + centro.y;
    return Ponto2D(x, y);
}

PoligonoRegular &PoligonoRegular::operator=(const PoligonoRegular &p) {
    auto *centro_ptr = (Ponto2D*)(&centro);
    *centro_ptr = p.centro;
    auto *raio_ptr = (double*)(&raio);
    *raio_ptr = p.raio;
    auto *num_lados_ptr = (uint32_t*)(&num_lados);
    *num_lados_ptr = p.num_lados;
    return *this;
}
