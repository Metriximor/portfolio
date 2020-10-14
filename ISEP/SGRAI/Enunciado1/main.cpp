#include <iostream>
#include "headers/Ponto2D.h"
#include "headers/Circulo.h"

int main() {
    Ponto2D ponto1 = Ponto2D(-1, 0);
    Ponto2D ponto2 = Ponto2D(1, 0);
    Circulo circulo = Circulo(ponto1.ponto_medio(ponto2), ponto1.distancia(ponto2)/2, 4);
    std::cout << circulo << std::endl;
    return 0;
}
