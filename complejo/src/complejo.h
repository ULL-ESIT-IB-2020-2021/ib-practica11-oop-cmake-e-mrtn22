/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file complejo.h
 * @author Edgar Joel Martín Melián
 * @date 30/12/2020
 * @brief Este archivo declara la clase "Complejo"
 * @bug No hay bugs conocidos
 */

#include <iostream>

#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo{
    private:
        int real_;
        int imaginario_;

    public:
        Complejo(int real = 0, int imaginario = 0);
        int getReal(){return real_;}
        int getImaginario(){return imaginario_;}
        void print();
};
Complejo add(Complejo complejo1, Complejo complejo2);
Complejo sub(Complejo complejo1, Complejo complejo2);

#endif // Complejo