/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file fechas.cc
 * @author Edgar Joel Martín Melián
 * @date 29/12/2020
 * @brief Este archivo contiene el código main del programa.
 * @bug No hay bugs conocidos
 */

#include <iostream>
#include "fecha.h"

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main (int argc, char* argv[]) {
    Usage(argc, argv);
    std::string date{argv[1]};
    std::string n{argv[2]};
    std::string output{argv[3]};
    const int kN = stoi(n);

    File(date, kN, output);

    return 0;
}