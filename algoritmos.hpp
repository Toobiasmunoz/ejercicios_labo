#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Completar con las funciones del enunciado

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){ // Supone que la coleccion es no vacia.
    // Corregido sin operador asignacion (Ej8).
    auto it = c.begin();
    auto actual = c.begin();
    while ( it != c.end() ) {
        if ( *it < *actual ) {
            actual = it;
            ++it;
        } else {
            ++it;
        }
    }
    return *actual;


}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){ // Supone que la coleccion es no vacia.
    auto it = c.begin();
    auto suma = *it;
    ++it;
    int largo = 1;
    while ( it != c.end() ) {
        suma = suma + *it;
        ++it;
        largo++;
    }
    return suma/largo;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    // Corregido sin operador asignacion (Ej8).
    auto min = desde;
    for ( auto it = desde; it != hasta; ++it ) {
        if ( *it < *min ) min = it;
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    auto suma = *desde;
    int largo = 1;
    auto it = desde;
    ++it;
    for ( it; it != hasta; ++it) {
        suma = suma + *it;
        largo++;
    }
    return suma/largo;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto it = c.begin();
    while ( it != c.end() ) {
        if ( *it == elem ) {
            it = c.erase(it);
        } else {
            ++it;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c){
    bool res = true;
    for ( auto it = c.begin(); it != c.end(); ++it ) {
        if ( *it > *(++it) ) {
            res = false;
            return res;
        }
    }
    return res;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,const typename Contenedor::value_type& elem) {
    Contenedor c1;
    auto it1 = c1.begin();
    Contenedor c2;
    auto it2 = c2.begin();
    for ( auto it = c.begin(); it != c.end(); ++it ) {
        if ( *it < elem) {
            it1 = c1.insert(it1,*it);
            ++it1;
        } else {
            it2 = c2.insert(it2,*it);
            ++it2;
        }
    }
    return make_pair(c1,c2);
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto itres = res.begin();
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    while ( it1 != c1.end() && it2 != c2.end() ) {
        if ( *it1 < *it2 ) {
            itres = res.insert(itres,*it1);
            ++itres;
            ++it1;
        } else {
            itres = res.insert(itres,*it2);
            ++itres;
            ++it2;
        }
    }

    if ( it1 == c1.end() ) {
        while ( it2 != c2.end() ) {
            itres = res.insert(itres,*it2);
            ++itres;
            ++it2;
        }

            ++it2;
        } else {
        while ( it1 != c1.end() ) {
            itres = res.insert(itres,*it1);
            ++itres;
            ++it1;
        }

    }

}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
