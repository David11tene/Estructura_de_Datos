/****************************************************************
*                Universidad de las Fuerzas Armadas - ESPE
*                          Programa de Listas
*
*Autores:    Cuenca Alisson
*            Ortega Kevin
*            Teneguzñay David
*
*Fecha de creacion: 2024-07-03
*Fecha de modificacion: 2024-07-07
*Nivel: Tercero                                 NRC: 16426
*
*******************************************************************/
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "..\OrdenamientoPorIntercambio\ListaSimple_Seleccion\mainSimple.cpp"
#include "..\OrdenamientoPorIntercambio\ListaDoble_Seleccion\mainDoble.cpp"
#include "..\OrdenamientoPorIntercambio\ListaCircular_Seleccion\mainCircular.cpp"

using namespace std;

void gotoxyMain(int x, int y);
void printMenuMain(const char* menu[], int size, int currentSelection);

int main() {
    system("cls");

    const char* menu[] = {
        "Menu de Registro Lista Simple",
        "Menu de Registro Lista Doble",
        "Menu de Registro Lista Circular",
        "Salir"
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int currentSelection = 0;
    int key;

    do {
        system("cls");
        cout << "\t\t.:MENU PRINCIPAL:." << endl;
        printMenuMain(menu, size, currentSelection);

        key = _getch();

        switch (key) {
            case 72: 
                if (currentSelection > 0) {
                    currentSelection--;
                }
                break;
            case 80: 
                if (currentSelection < size - 1) {
                    currentSelection++;
                }
                break;
            case 13: 
                switch (currentSelection) {
                    case 0:
                        mainSimple();
                        break;
                    case 1:
                        mainDoble();    
                        break;
                    case 2:
                        mainCircular();
                        break;
                    case 3:
                        cout << "Saliendo del programa..." << endl;
                        exit(0); 
                }
                if (currentSelection != 3) {
                    cout << "Presione cualquier tecla para continuar..." << endl;
                    _getch();
                }
                break;
        }
    } while (true);

    return 0;
}

void gotoxyMain(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenuMain(const char* menu[], int size, int currentSelection) {
    for (int i = 0; i < size; ++i) {
        if (i == currentSelection) {
            cout << "> " << menu[i] << " <" << endl;
        } else {
            cout << "  " << menu[i] << endl;
        }
    }
}