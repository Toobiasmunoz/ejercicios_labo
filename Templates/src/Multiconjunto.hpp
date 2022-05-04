//
// Created by clinux01 on 04/05/22.
//

#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP
#include <vector>
#include "Diccionario.hpp"

template<class T>
class Multiconjunto{ // Clave de tipo T y valores de tipo int (ocurrencias).
public:
    Multiconjunto(); // Construye un multiconjunto vacio.
    void agregar(T x); // Agrega una aparicion del elemento x.
    int ocurrencias(T x); // Devuelve la cantidad de ocurrencias de x en el multiconjunto.
    bool operator<=(Multiconjunto<T> otro); // Devuelve true si el multiconjunto actual esta incluido en "otro".
private:
    Diccionario<T,int> d_;
};

template<class T>
Multiconjunto<T>::Multiconjunto(): d_() {}

template<class T>
void Multiconjunto<T>::agregar(T x){

    if ( !d_.def(x) ) {
        d_.definir(x,1);
    } else {
        d_.definir(x, ocurrencias(x)+1);
    }

}

template<class T>
int Multiconjunto<T>::ocurrencias(T x){
    if ( d_.def(x) ) {
        return d_.obtener(x);
    } else return 0;
}

template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) { // Supone que existe bool operator<=(T,T) que permite comparar elementos.
        for (int i = 0; i < (d_.claves()).size(); i++) {
            T elem = d_.claves()[i];
            if (d_.obtener(elem) <= otro.ocurrencias(elem)) {
            } else {
                return false;
            }
        }
        return true;
}

#endif //SOLUCION_MULTICONJUNTO_HPP
