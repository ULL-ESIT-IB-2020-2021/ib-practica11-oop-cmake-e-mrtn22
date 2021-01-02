/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file fecha.cc
 * @author Edgar Joel Martín Melián
 * @date 29/12/2020
 * @brief Este archivo contiene el código (definiciones) correspondientes a la clase "Fecha" y tres funciones
 * @bug No hay bugs conocidos
 */

#include <iostream>
#include <fstream>
#include <cstdlib>    /// exit
#include <string>
#include "fecha.h"

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
    if (argc != 4) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
        std::cout << kHelpText << std::endl;
        exit(EXIT_SUCCESS);
    }
    std::cout << argv[0] << " - Gestión de fechas \n \
        Modo de uso: " << argv[0] << " dd/mm/aa N fichero_salida.txt \n \
        Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
    }
}

class Fechas {
    private:
        int year_{};
        int month_{};
        int day_{};
    public:
        int GetYear(){ return year_; } /// getter for year
        void SetYear(int year) { year_ = year;} /// setter for year

        int GetMonth(){ return month_; } /// getter for month
        void SetMonth(int month) { month_ = month;} /// setter for month

        int GetDay(){ return day_; } /// getter for day
        void SetDay(int day) { day_ = day;} /// setter for day

};

/** Calcula si un año es bisiesto o no. 
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] year Variable "Año" para calcular
 */
bool IsLeapYear(int year){
    if (year % 4 == 0){
        return true;
    }
    return false;
}

/** Realiza la ejecución del objetivo principal del programa. 
 *  Imprimie en el fichero de salida (tercer parámetro) las N (segundo parámetro) 
 *  fechas cronológicamente posteriores a la introducida (primer parámetro) con 
 *  una separación de un día entre fechas sucesivas.
 *
 *  @param[in] date Fecha
 *  @param[in] n Veces que se imprima en el texto las fechas
 *  @param[in] kFileName Nombre del archivo de texto
 */
void File(std::string date, int n, const std::string kFileName){
    std::ofstream output_file{"../output_file/" + kFileName}; ///output file

    if (!output_file){ /// If we couldn'topen output file
        std::cerr << "Error File: " << kFileName << " can't be oppened." << std::endl;
        exit(EXIT_SUCCESS);
    }

    if (date.at(2) && date.at(5) != '/' && date.length() != 10){
        std::cerr << "Error: " << date << " isn't in the correct format (dd/mm/yyyy)" << std::endl;
        exit(EXIT_SUCCESS);
    }

    if (date.at(2) && date.at(5) == '/'){
        Fechas date_modificable;
        date_modificable.SetDay(stoi(date.substr(0,2)));
        date_modificable.SetMonth(stoi(date.substr(3,2)));
        date_modificable.SetYear(stoi(date.substr(6,4)));

        if ((date_modificable.GetDay() > 31 && (date_modificable.GetMonth() == 1 || date_modificable.GetMonth() == 3 || date_modificable.GetMonth() == 5 || 
        date_modificable.GetMonth() == 7 || date_modificable.GetMonth() == 8 || date_modificable.GetMonth() == 10 || date_modificable.GetMonth() == 12)) ||
        (date_modificable.GetDay() > 30 && (date_modificable.GetMonth() == 4 || date_modificable.GetMonth() == 6 || date_modificable.GetMonth() == 9 || 
        date_modificable.GetMonth() == 11)) ||
        (date_modificable.GetDay() > 28 && date_modificable.GetMonth() == 2) ||
        (date_modificable.GetDay() > 29 && (date_modificable.GetMonth() == 2) && (IsLeapYear(date_modificable.GetYear()) == true)) ||
        (date_modificable.GetMonth() > 12)){
            std::cerr << "Error: " << date << " is not valid" << std::endl;
            exit(EXIT_SUCCESS);
        }
        /// Comprobar que la fecha sea correcta
        for(int i=0; i <= n; i++){
            output_file << date_modificable.GetDay() << "/" << date_modificable.GetMonth() << "/" << date_modificable.GetYear() << std::endl;
            date_modificable.SetDay(date_modificable.GetDay() + 2);

            switch(date_modificable.GetMonth()){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(date_modificable.GetDay()>31){
                        date_modificable.SetDay(date_modificable.GetDay() - 31);
                        date_modificable.SetMonth(date_modificable.GetMonth() + 1);
                    }
                    if(date_modificable.GetMonth()>12){
                        date_modificable.SetMonth(01);
                        date_modificable.SetYear(date_modificable.GetYear() + 1);
                    }
                    break;
                case 2:
                    if(date_modificable.GetDay() > 28 && IsLeapYear(date_modificable.GetYear()) == false){
                        date_modificable.SetDay(date_modificable.GetDay() - 28);
                        date_modificable.SetMonth(date_modificable.GetMonth() + 1);
                    }
                    if(date_modificable.GetDay() > 29 && IsLeapYear(date_modificable.GetYear()) == true){
                        date_modificable.SetDay(date_modificable.GetDay() - 29);
                        date_modificable.SetMonth(date_modificable.GetMonth() + 1);
                    }
                    break;
                default:
                    if(date_modificable.GetDay()>30){
                        date_modificable.SetDay(date_modificable.GetDay() - 30);
                        date_modificable.SetMonth(date_modificable.GetMonth() + 1);
                    }
                    break;
            }
        }
    }
    output_file.close();
}