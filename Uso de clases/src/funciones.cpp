#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1

bool pertenece(int a, vector<int> v){
    bool res = false;
    for( int i=0; i < v.size(); i++){
        if ( a == v[i] ) return true;
    }
    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;
    for(int i =0; i < s.size(); i++){
        if ( !pertenece(s[i],res)) res.push_back(s[i]);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> s_set;
    for( int i=0 ; i < s.size(); i++){
        s_set.insert( s[i]);
    }

    vector<int> res;
    for( int n : s_set){
        res.push_back(n);
    }
    return res;

}

// Ejercicio 3


bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    for( int i = 0; i < a.size() ; i++){
        res = res && pertenece(a[i], b);
    }
    for( int i = 0; i < b.size() ; i++){
        res = res && pertenece(b[i], a);
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> a_set;
    set<int> b_set;
    for ( int i =0; i < a.size(); i++){
        a_set.insert( a[i]);
    }
    for ( int i =0; i < b.size(); i++){
        b_set.insert( b[i]);
    }
    bool res = true;
    for( int n : a_set){
        res = res && (b_set.count( n) == 1) ;
    }
    for( int n : b_set){
        res = res && (a_set.count(n) == 1);
    }
    return res;
}



// Ejercicio 5

int cant_apariciones( vector<int> v, int a ){
    int res=0;
    for(int i=0; i < v.size(); i++){
        if ( v[i] == a) res++;
    }
    return res;
}
map<int, int> contar_apariciones(vector<int> s) {
    vector<int> s_sinrep = quitar_repetidos(s);
    map<int,int> res;
    for( int i=0 ; i < s_sinrep.size(); i++){
        res.insert( pair<int,int>(s_sinrep[i], cant_apariciones(s,s_sinrep[i])));
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    for( int i = 0; i < s.size(); i++){
        if (cant_apariciones(s, s[i]) == 1 ){
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int n : a) {
        if ( b.count(n) == 1 ){
            res.insert(n);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for( int i=0 ; i < s.size(); i++){
       int resto = s[i] % 10;
       if ( !res.count( resto ) ) {
           res.insert( pair<int,set<int>>( resto, {s[i]}) );
       } else {
           res[resto].insert(s[i]);
       }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res = str;
    for( int i = 0 ; i < str.size() ; i++){
        for ( int j = 0 ; j < tr.size() ; j++){
            if ( str[i] == tr[j].first ) {
                res[i] = tr[j].second ;
            }
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for ( Mail m1 : s){
        for ( Mail m2 : s){
            if ( m1.libretas() != m2.libretas()) {
                for ( LU libreta : m1.libretas() ) {
                    if ( m2.libretas().count(libreta) > 0 ) return true;
                }
            }
        }
    }
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for ( Mail m : s){
        if ( m.adjunto() && m.fecha() > res[m.libretas()].fecha() ) {
            res[m.libretas()] = m;
        }
    }
    return res;
}
