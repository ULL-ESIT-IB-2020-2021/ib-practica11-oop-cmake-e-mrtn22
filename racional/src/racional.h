/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file racional.h
 * @author Edgar Joel Martín Melián
 * @date 01/01/2021
 * @brief Este archivo declara la clase Racional del programa.
 * @bug No hay bugs conocidos
 * @see https://en.wikipedia.org/wiki/Rational_number
 * @see https://es.wikipedia.org/wiki/Unidad_imaginaria
 */

#include <iostream>
#include <fstream>

#ifndef RACIONAL_H
#define RACIONAL_H
class Racional{
    private:
        int numerador_ {0};
        int denominador_ {1};
    public:
        Racional() = default; ///default constructor
        Racional(int numerador, int denominador);
        Racional(std::string my_string);

        int getNumerador() const {return numerador_;}; ///getter para el numerador
        int getDenominador() const {return denominador_;}; ///getter para el denominador

        friend Racional operator/(const Racional &r1, const Racional &r2);
        friend Racional operator+(const Racional &r1, const Racional &r2);
        friend Racional operator-(const Racional &r1, const Racional &r2);
        friend Racional operator*(const Racional &r1, const Racional &r2);
        friend std::ofstream& operator<<(std::ofstream &out, const Racional &racional);
        friend std::ostream& operator<<(std::ostream &out, const Racional &racional);
};
char Comparacion(Racional r1, Racional r2);
#endif