#ifndef JUEGOGATO_H
#define JUEGOGATO_H

#include <iostream>
using namespace std;

class JuegoGato{
    private:
        static const int FILAS = 3;
        static const int COLUMNAS = 3;
        char tablero[FILAS][COLUMNAS];
        char jugador;

        void inicializar_Tablero();
        void mostrar_Tablero();
        bool verificar_Ganador(char);
        bool verificar_Empate();
        void turno_Jugador();
    public:
        JuegoGato();
        void jugar();
};

#endif