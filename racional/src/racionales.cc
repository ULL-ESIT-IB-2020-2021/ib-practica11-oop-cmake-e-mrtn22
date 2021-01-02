/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file racionales.cc
 * @author Edgar Joel Martín Melián
 * @date 01/01/2021
 * @brief Este archivo contiene el código main del programa.
 * @bug No hay bugs conocidos
 * @see https://en.wikipedia.org/wiki/Rational_number
 * @see https://es.wikipedia.org/wiki/Unidad_imaginaria
 */

#include <iostream>
#include <fstream>
#include "racional.h"
#include "tools.h"

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main (int argc, char* argv[]) {
    Usage(argc, argv);
    std::string input_file{argv[1]};
    std::string output_file{argv[2]};

    Func(input_file, output_file);
    return 0;
}