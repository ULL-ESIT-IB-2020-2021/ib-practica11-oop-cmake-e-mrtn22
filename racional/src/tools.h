/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file tools.h
 * @author Edgar Joel Martín Melián
 * @date 01/01/2021
 * @brief Este archivo declara dos funciones
 * @bug No hay bugs conocidos
 */

#include <iostream>

const std::string kHelpText = "./racionales -- Números Racionales \n\
Modo de uso: ./racionales fichero_entrada fichero_salida \n\
\nfichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio \n\
fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`";

void Usage(int argc, char *argv[]);
void Func(std::string input_file, std::string output_file);