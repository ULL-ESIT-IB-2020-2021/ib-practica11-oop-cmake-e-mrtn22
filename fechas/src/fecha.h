/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file fecha.h
 * @author Edgar Joel Martín Melián
 * @date 29/12/2020
 * @brief Este archivo declara la clase "Fechas", tres funciones y el "HelpText"
 * @bug No hay bugs conocidos
 */

#include <iostream>

const std::string kHelpText = "Este programa imprime en el fichero de salida (tercer parámetro) las N \
(segundo parámetro) fechas cronológicamente posteriores a la introducida (primer parámetro) \
con una separación de un día entre fechas sucesivas.";

void Usage(int argc, char *argv[]);
class Fechas;
bool IsLeapYear(int year);
void File(std::string date, int n, const std::string kFileName);