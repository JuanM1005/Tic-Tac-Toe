#include "JuegoGato.h"

JuegoGato::JuegoGato(){
    jugador = 'X';
    inicializar_Tablero();
}

void JuegoGato::inicializar_Tablero(){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            tablero[i][j] = ' '; // Se inicializa el tablero con espacios en blanco
        }
    }
}

void JuegoGato::mostrar_Tablero(){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            cout<< tablero[i][j];
            if(j < COLUMNAS - 1){
                cout<< " | "; // Separador de columnas
            }
        }
        cout<< endl; 
        if(i < FILAS - 1){
            cout << "--|---|---\n"; // Separador de filas
        }
    }
    cout<< endl;
}

bool JuegoGato::verificar_Ganador(char jugador){
    // Se verifican las filas
    for(int i = 0; i < FILAS; i++){
        if(tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador){
            return true; // Retorna verdadero si el jugador relleno una fila completa
        }
    }
    // Se verifican las columnas
    for(int i = 0; i < COLUMNAS; i++){
        if(tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador){
            return true; // Retorna verdadero si el jugador relleno una columna completa
        }
    }
    // Se verifican las diagonales
    if((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
       (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
        return true; // Retorna verdadero si el jugador relleno las diagonales completas
    }
    return false; // Si no se cumple ninguna condición de victoria, retorna false
}

bool JuegoGato::verificar_Empate(){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if(tablero[i][j] == ' '){ // Verifica si hay espacios en blanco, de lo contrario retorna que no hay empate
                return false;
            }
        }
    }
    return true; // Si no hay espacios vacios, hay un posible empate
}

void JuegoGato::turno_Jugador(){
    int fila, columna; // El jugador asignara donde poner su eleccion
    bool movimientoValido = false; // Indica si el movimiento del jugador es valido

    while(!movimientoValido){
        cout<< "Turno del jugador "<< jugador<< ". Ingrese fila y columna (0 - 2): ";
        cin>> fila>> columna;

        // Se verifica si la posicion es valida
        if(fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS && tablero[fila][columna] == ' '){
            tablero[fila][columna] = jugador; //Se asigna lo que el jugador puso
            movimientoValido = true; // El movimiento se marca como valido
        } else {
            cout<< "Movimiento no valido. Intentalo de nuevo"<< endl;
        }
    }
}

void JuegoGato::jugar(){
    bool juego_Terminado = false;

    while(!juego_Terminado){ // El bucle se ejecuta mientras el juego no haya terminado
        mostrar_Tablero();
        turno_Jugador();

        //Verificar si el jugador actual ha ganado
        if(verificar_Ganador(jugador)){
            mostrar_Tablero();
            cout<< "El jugador "<< jugador<< " ha ganado!"<< endl;
            juego_Terminado = true; // El juego ha terminado porque ha habido un ganador
        } else if (verificar_Empate()){
            mostrar_Tablero();
            cout<< "EMPATE!"<< endl;
            juego_Terminado = true; // El juego ha terminado porque ha habido un empate
        } else {
            jugador = (jugador == 'X') ? 'O' : 'X'; // Se cambia el turno del jugador
        }

    }
}
