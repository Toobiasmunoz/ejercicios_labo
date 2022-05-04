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
Clave minimo(std::vector<Clave> v){
    Clave min = v[0];
    for ( auto i = 1; i < v.size(); ++i){
        if ( v[i] < min) min = v[i];
    }
    return min;
}



template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() const{
    std::vector<Clave> claves; // Vector vacio a llenar con las claves.

/*
    for( Asociacion a : _asociaciones){ //Otra forma...
        claves.insert(std::upper_bound(claves.begin(), claves.end(), a.clave),a.clave);
    }
    return claves;
*/
    for ( int i=0; i < _asociaciones.size(); i++){
        claves.push_back(_asociaciones[i].clave);

    }
    // Ahora ordeno el vector res (al principio vacio) de menor a mayor.

    std::vector<Clave> res;
    for ( int i = 0; i < claves.size(); ++i) {
            Clave min = minimo(claves);
            res.push_back(min);
            // Terminar -> borrar el minimo.
    }
    return res;

}





#endif //SOLUCION_DICCIONARIO_HPP
