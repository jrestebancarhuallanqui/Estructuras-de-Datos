/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: HP
 *
 * Created on 1 de julio de 2025, 09:03
 */

#include "funcionesAB.h"
#include "ArbolB.h"
#include "NodoGen.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

void insertarNodoGen(NodoArbol*&ptr, const NodoGen &temp) {
    ptr = crearNuevoNodo(nullptr, temp, nullptr);

}

void insertarNivel(NodoArbol*ptr, int*paq, int i, int n) {

    if (i == n)return;
    NodoGen temp;
    temp.cantidad = paq[i];
    temp.cromo = 1;
    insertarNodoGen(ptr->derecha, temp);
    insertarNivel(ptr->derecha, paq, i + 1, n);

    temp.cantidad = paq[i];
    temp.cromo = 0;
    insertarNodoGen(ptr->izquierda, temp);
    insertarNivel(ptr->izquierda, paq, i + 1, n);

}

void crearArbolCromosomico(ArbolBinario &arbol, int*paq, int n) {
    NodoGen temp;
    temp.cantidad = 0;
    temp.cromo = 0;

    plantarArbolBinario(arbol, nullptr, temp, nullptr);
    insertarNivel(arbol.raiz, paq, 0, n);
}

void calculaSolus(NodoArbol*ptr, int pesoParcial, int peso1, int peso2,
        int* sol, int &cont) {
    if (cont == 10)return;
    if (ptr == nullptr) {
        if (pesoParcial >= peso2 and pesoParcial <= peso1) {
            sol[cont] = pesoParcial;
            cont++;
        }
        return;
    }
    pesoParcial += ptr->nodo.cantidad * ptr->nodo.cromo;
    calculaSolus(ptr->derecha, pesoParcial, peso1, peso2, sol, cont);
////    if (ptr->izquierda)
        calculaSolus(ptr->izquierda, pesoParcial, peso1, peso2, sol, cont);
}

int main(int argc, char** argv) {

    ArbolBinario arbol;
    int paq[] = {10, 50, 20, 30, 40, 15, 25, 35, 45};
    int peso = 125, peso2 = 85;
    int sol[10]{};
    
    int n = sizeof (paq) / sizeof (paq[0]);
    int cont=0;
    construir(arbol);
    crearArbolCromosomico(arbol, paq, n);
    calculaSolus(arbol.raiz, 0, peso, peso2, sol,cont);
    for(int i=0;i<cont;i++){
        cout<<sol[i]<<endl;
    }
    return 0;
}

