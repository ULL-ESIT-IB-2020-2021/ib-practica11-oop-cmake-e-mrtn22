/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file complejo.cc
 * @author Edgar Joel Martín Melián
 * @date 30/12/2020
 * @brief Este archivo contiene el código (definiciones) correspondientes a la clase "Complejo"
 * @bug No hay bugs conocidos
 * @see https://es.wikipedia.org/wiki/N%C3%BAmero_complejo
 * @see https://es.wikipedia.org/wiki/Unidad_imaginaria
 */

#include <iostream>
#include "complejo.h"

Complejo::Complejo(int real, int imaginario){
    real_ = real;
    imaginario_ = imaginario;
}

void Complejo::print(){
    std::cout << "{" << real_ << ", " << imaginario_ <<  "i}" << std::endl;
}

/** Calcula la suma de dos numeros complejos.
 *
 *  @param[in] complejo1 Primer complejo
 *  @param[in] complejo2 Complejo con el que se aplicará la suma
 * 
 *  @return Devuelve la suma en forma de complejo
 */
Complejo add(Complejo complejo1, Complejo complejo2){
    int real, imaginario;
    real = complejo1.getReal() + complejo2.getReal();
    imaginario = complejo1.getImaginario() + complejo2.getImaginario();
    return Complejo(real, imaginario);
}

/** Calcula la resta de dos numeros complejos.
 *
 *  @param[in] complejo1 Primer complejo
 *  @param[in] complejo2 Complejo con el que se aplicará la resta
 * 
 *  @return Devuelve la resta en forma de complejo
 */
Complejo sub(Complejo complejo1, Complejo complejo2){
    int real, imaginario;
    real = complejo1.getReal() - complejo2.getReal();
    imaginario = complejo1.getImaginario() - complejo2.getImaginario();
    return Complejo(real, imaginario);
}