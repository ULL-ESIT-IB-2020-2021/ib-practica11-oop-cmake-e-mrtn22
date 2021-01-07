/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file racional.cc
 * @author Edgar Joel Martín Melián
 * @date 01/01/2021
 * @brief Este archivo contiene el código de la clase racional.
 * @bug No hay bugs conocidos
 * @see https://en.wikipedia.org/wiki/Rational_number
 * @see https://es.wikipedia.org/wiki/Unidad_imaginaria
 */

#include <iostream>
#include <string>
#include <fstream>
#include "racional.h"

/** Constructor de la clase Racional
 *  @param[in] numerador Parámetro para establecer el numerador
 *  @param[in] denominador Parámetro para establecer el denominador
 */
Racional::Racional(int numerador, int denominador){
    numerador_ = numerador;
    denominador_ = denominador;
}

/** Constructor de la clase Racional
 *  @param[in] my_string Parámetro de tipo string para descomponer sus partes (numerador/denominador)
 */
Racional::Racional(std::string my_string){
    int length = my_string.length();
    // std::cout << length << std::endl;
    std::string numerador{""}, denominador{""};
    for(int i = 0; my_string[i] != '/'; i++){
        numerador += my_string[i];
    }
    /// std::cout << numerador << std::endl;
    size_t pos = my_string.find("/");
    for(int i = pos + 1; i < length; i++){
        denominador += my_string[i];
        
    }
    /// std::cout << denominador_ << std::endl;
    numerador_ = stoi(numerador);
    denominador_ = stoi(denominador);
    /// std::cout << numerador << " " << denominador << std::endl;
}

Racional operator+(const Racional &r1, const Racional &r2){
    int numerador = (r1.numerador_ * r2.denominador_) + (r1.denominador_ * r2.numerador_);
    int denominador = (r1.denominador_ * r2.denominador_);
    return Racional(numerador, denominador);
}
Racional operator-(const Racional &r1, const Racional &r2){
    int numerador = (r1.numerador_ * r2.denominador_) - (r1.denominador_ * r2.numerador_);
    int denominador = (r1.denominador_ * r2.denominador_);
    return Racional(numerador, denominador);
}
Racional operator*(const Racional &r1, const Racional &r2){
    int numerador = r1.numerador_ * r2.numerador_;
    int denominador = r1.denominador_ * r2.numerador_;
    return Racional(numerador, denominador);
}
Racional operator/(const Racional &r1, const Racional &r2){
    int numerador = r1.numerador_ * r2.denominador_;
    int denominador = r1.denominador_ * r2.numerador_;
    return Racional(numerador, denominador);
}
std::ofstream& operator<<(std::ofstream &out, const Racional &racional){
    out << racional.numerador_ << "/" << racional.denominador_;
    return out;
}
std::ostream& operator<<(std::ostream &out, const Racional &racional){
    out << racional.numerador_ << "/" << racional.denominador_;
    return out;
}
char Comparacion(Racional r1, Racional r2){
    if(r1.getNumerador() * r2.getDenominador() == r1.getDenominador() * r2.getNumerador()){
        return '=';
    }
    else if(r1.getNumerador() * r2.getDenominador() > r1.getDenominador() * r2.getNumerador()){
        return '>';
    }
    else if(r1.getNumerador() * r2.getDenominador() < r1.getDenominador() * r2.getNumerador()){
        return '<';
    }
}