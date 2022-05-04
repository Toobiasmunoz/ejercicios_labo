//
// Created by clinux01 on 04/05/22.
//

#ifndef SOLUCION_DICCIONARIO_HPP
#define SOLUCION_DICCIONARIO_HPP
#include <vector>

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    std::vector<Clave> claves() const; // devuelve las claves ordenadas de menor a mayor. Se asume operator<=.
private:
    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave,Valor>::Diccionario() {
}

template<class Clave, class Valor>
Diccionario<Clave,Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave,Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave,Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave,Valor>::obtener(Clave k) const { // Asume que esta la clave, sino --> assert(false)
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}


template<class Clave>
void swap(Clave& a, Clave& b){
    Clave temp = a;
    a = b;
    b = temp;
}


template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() const{
    std::vector<Clave> claves; // Vector vacio a llenar con las claves.
    for ( int i=0; i < _asociaciones.size(); i++){
        claves.push_back(_asociaciones[i].clave);
    }
    // Ahora ordeno el vector claves de menor a mayor. "Selection sort"
    if ( claves.size() != 0) {
        for (int i = 0; i < claves.size() - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < claves.size(); j++) {
                if (claves[j] < claves[min_index]) {
                    min_index = j;
                }
            }
            swap(claves[min_index], claves[i]);
        }
    }

    return claves;

    /*
    for( Asociacion a : _asociaciones){ // Otra forma mas compacta.
        claves.insert(std::upper_bound(claves.begin(), claves.end(), a.clave),a.clave);
    }
    return claves;
*/
}





#endif //SOLUCION_DICCIONARIO_HPP
