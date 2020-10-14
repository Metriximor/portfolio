#include <iostream>
#include "headers/Ponto2D.h"
#include "headers/Circulo.h"

int main() {
    Ponto2D ponto1 = Ponto2D(-1, 0);
    Ponto2D ponto2 = Ponto2D(1, 0);
    Circulo circulo = Circulo(ponto1.ponto_medio(ponto2), ponto1.distancia(ponto2)/2);
    for(Ponto2D ponto : circulo.calcular_pontos_no_perimetro(4)) {
        std::cout << ponto << std::endl;
    }
    return 0;
}
