#include "SistemaDeMensajes.h"

// Completar...

SistemaDeMensajes::SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if ( !registrado(id) ) { // Si no esta registrado lo registro.
        _conns[id] = new ConexionJugador(ip);
    } else { // Si esta registrado sobreescribo.
        *_conns[id] = ConexionJugador(ip);

        // Otra opcion: (borrando y creando nueva memoria)
        //delete _conns[id];
        //_conns[id] = new ConexionJugador(ip);
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    // Requiere que este registrado el jugador.
    ConexionJugador(*_conns[id]).enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for ( int i = 0; i < punteros.size() ; i++){
        delete punteros[i];
    }
    for ( int i = 0; i < 4 ; i++){
        delete _conns[i];
    }
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* res = new Proxy(_conns[id]);
    punteros.push_back(res);
    return res;
}



