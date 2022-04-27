#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    //Completar miembros internos
    int mes_;
    int dia_;
};


void Fecha::incrementar_dia() {
    if ( dia_ < dias_en_mes( mes_ ) ) { // Sigue en el mismo mes al dia siguiente.
        dia_++;
    } else { //  Nuevo mes.
        if ( mes_ < 12) { // No es diciembre.
            mes_++;
            dia_ = 1;
        } else { // Mes de diciembre.
            mes_ = 1;
            dia_ = 1;
        }
    }
}

Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia) {}

int Fecha::mes() {
    return this->mes_;
}

int Fecha::dia() {
    return this->dia_;
}

ostream& operator<<(ostream& os, Fecha f){
    os << "" << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() && this->mes() == o.mes();
    return igual_dia;
}
#endif

// Ejercicio 11, 12

// Clase Horario

class Horario{
    public:

    Horario(uint hora, uint min);
    uint hora();
    uint min();

    bool operator== (Horario h);
    bool operator< (Horario h);
    private:

    uint hora_;
    uint min_;
};

bool Horario::operator<(Horario h) {
    bool menor_horario = ( this->hora() == h.hora() && this->min() < h.min() ) || ( this->hora() < h.hora() );
    return menor_horario;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora() && this->min() == h.hora();
    return igual_hora;
}

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min){}

uint Horario::hora(){
    return this->hora_;
}

uint Horario::min() {
    return this->min_;
}

ostream& operator <<(ostream& os, Horario h){
    os << "" << h.hora() << ":" << h.min();
    return os;
}



// Ejercicio 13

// Clase Recordatorio

class Recordatorio{

    public:
    Recordatorio(Fecha f, Horario h, string mensaje);
    Fecha f();
    Horario h();
    string mensaje();

    private:
    Fecha f_;
    Horario h_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string mensaje) : f_(f), h_(h), mensaje_(mensaje){}

Fecha Recordatorio::f(){
    return this-> f_;
}

Horario Recordatorio::h(){
    return this-> h_;
}

string Recordatorio::mensaje() {
    return this-> mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " " << "@" << " " << "" << r.f() << " " << "" << r.h();
    return os;
}

// Ejercicio 14

// Clase Agenda

class Agenda{ // Fecha, Horario, Recordatorio.
    public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

    private:
    Fecha hoy_;
    list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial){}

Fecha Agenda::hoy() {
    return this->hoy_;
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> rec_hoy;
    for ( Recordatorio r : recordatorios_) {
        if ( r.f() == hoy_ ) {
            rec_hoy.push_back(r);
        }
    }
    return rec_hoy;
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    auto it = recordatorios_.begin(); // Iterador.
    while ( it != recordatorios_.end() ) { // Agrega recordatorios de forma ordenada (ascendente).
        if ( rec.h() < it->h()) {
            recordatorios_.insert(it,rec);
            break;
        }
        it++;
    }
    if ( it == recordatorios_.end() ) recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}

ostream& operator<<(ostream& os, Agenda a){
    os << a.hoy() << endl;
    os << "=====" << endl;
    for ( Recordatorio r : a.recordatorios_de_hoy() ) {
        os << r << endl;
    }
    return os;
}

