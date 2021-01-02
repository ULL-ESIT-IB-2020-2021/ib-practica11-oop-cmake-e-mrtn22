/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file complejo_main.cc
 * @author Edgar Joel Martín Melián
 * @date 30/12/2020
 * @brief Este archivo contiene el código main del programa. Calcula la suma y resta de dos números complejos.
 * @bug No hay bugs conocidos
 * @see https://es.wikipedia.org/wiki/N%C3%BAmero_complejo
 * @see https://es.wikipedia.org/wiki/Unidad_imaginaria
 */

#include <iostream>
#include "complejo.h"

main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = add(complejo1, complejo2);
  resultado.print();
  resultado = sub(complejo1, complejo2);
  resultado.print();
}
