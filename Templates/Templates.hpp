//
// Created by clinux01 on 04/05/22.
//

#ifndef SOLUCION_TEMPLATES_HPP
#define SOLUCION_TEMPLATES_HPP

template<class T>
T cuadrado(T x){
    return x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e){ // Se asume operator[].
    for( int i = 0; i < c.size(); i++){
        if ( c[i] == e) return true;
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){ // Se asume que existe size() y operator[].
    bool res = true;
    if ( a.size() < b.size() ) {
        for ( int i=0; i < a.size(); i++ ){
            res = res && ( a[i] == b[i] );
        }
    } else {
        res = false;
    }
    return res;
}

template<class Contenedor, class Elem>
Elem maximo(Contenedor c){ // Se asume size(), operator[], operator< y que c tiene al menos un elemento.
    Elem max = c[0];
    for ( int i = 1; i < c.size(); i++){
        if ( max < c[i] ) max = c[i];
    }
    return max;
}


#endif //SOLUCION_TEMPLATES_HPP
