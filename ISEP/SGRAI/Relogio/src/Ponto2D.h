//
// Created by Pedro Ivo on 13/10/2020.
//

#ifndef SGRAI_PONTO2D_H
#define SGRAI_PONTO2D_H
#include <cmath>
#include <ostream>

/**
 * Um ponto com coordenadas cartesianas
 */
class Ponto2D {
public:
    const double x;
    const double y;
    /**
     * Construtor do ponto
     * @param x coordenada cartesiana referente ao eixo x
     * @param y coordenada cartesiana referente ao eixo y
     */
    Ponto2D(double x, double y);
    /**
     * Calcula a distancia cartesiana entre dois pontos
     * @param outro o ponto com o qual queremos comparar a distancia
     * @return
     */
    double distancia(Ponto2D outro);
    /**
     * Calcula as coordenadas do ponto médio entre dois pontos
     * @param outro o ponto com o qual queremos calcular o ponto médio
     * @return um ponto que se encontre no meio dos dois pontos
     */
    Ponto2D ponto_medio(Ponto2D outro);

    /**
     * Assignment operator overload
     * @param ponto2D o ponto que queremos copiar
     */
    Ponto2D& operator=(const Ponto2D &ponto2D);

    friend std::ostream &operator<<(std::ostream &os, const Ponto2D &d);
};


#endif //SGRAI_PONTO2D_H
