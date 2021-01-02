/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file tools.cc
 * @author Edgar Joel Martín Melián
 * @date 01/01/2021
 * @brief Este archivo contiene el codigo de dos Funciones.
 * @bug No hay bugs conocidos
 */

#include <iostream>
#include <fstream>
#include <cstdlib> /// exit
#include "tools.h"
#include "racional.h"

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
    if (argc != 3) {
        std::string parameter{argv[1]};
        if (parameter == "--help") {
            std::cout << kHelpText << std::endl;
            exit(EXIT_SUCCESS);
        }
        std::cout << argv[0] << " -- Números Racionales \n\
        Modo de uso: " << argv[0] << " fichero_entrada fichero_salida \n\
        Pruebe " << argv[0] << " --help para más información" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void Func(const std::string kInputFileName, const std::string kOutputFileName){
    std::ifstream input_file{"../files/input_files/" + kInputFileName}; ///input file
    if (!input_file){ /// If we couldn'topen output file
        std::cerr << "Error File: " << kInputFileName << " can't be oppened." << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::ofstream output_file{"../files/output_files/" + kOutputFileName}; ///output file
    if (!output_file){ /// If we couldn'topen output file
        std::cerr << "Error File: " << kOutputFileName << " can't be oppened." << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::string racional_texto_1, racional_texto_2;
    while(input_file >> racional_texto_1 >> racional_texto_2){
        /// std::cout << racional_texto_1 << " " << racional_texto_2 << std::endl;
        Racional racional_1 (racional_texto_1);
        Racional racional_2 (racional_texto_2);
        /// std::cout << racional_1 << " " << racional_2 << std::endl;
        if (racional_1.getDenominador() == 0 || racional_2.getDenominador() == 0){
            std::cerr << "Operación abortada! Error: alguno de los de los racionales contiene un denominador = 0" << std::endl;
            std::cerr << "Compruebe y corrija el fichero de entrada!" << std::endl;
            exit(EXIT_SUCCESS);
        }

        output_file << racional_1 << " + " << racional_2 << " = " << racional_1 + racional_2 << std::endl;
        output_file << racional_1 << " - " << racional_2 << " = " << racional_1 - racional_2 << std::endl;
        output_file << racional_1 << " * " << racional_2 << " = " << racional_1 * racional_2 << std::endl;
        output_file << racional_1 << " / " << racional_2 << " = " << racional_1 / racional_2 << std::endl;
        output_file << racional_1 << " " << Comparacion(racional_1, racional_2) << " " << racional_2 << std::endl;
        output_file << "--------------------------------------------" << std::endl;
    }
    input_file.close();
    output_file.close();
}