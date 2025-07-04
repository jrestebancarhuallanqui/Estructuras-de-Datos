/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 8 de junio de 2025, 16:56
 */

#include <iostream>
using namespace std;
#include "ArbolB.h"
#include "Elemento.h"
#include "funcionesAB.h"
/*
 *  ARBOLES BINARIOS 2025-1
 *  Clase ABB
 */
int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    struct Elemento elemento;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
    construir(arbol);
    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
    
    elemento.numero = 25;
    plantarArbolBinario(arbol1, nullptr, elemento, nullptr);
    
    elemento.numero = 75;
    plantarArbolBinario(arbol2, nullptr, elemento, nullptr);
    
    elemento.numero = 150;
    plantarArbolBinario(arbol4, nullptr, elemento, nullptr);
    
    elemento.numero = 50;
    plantarArbolBinario(arbol3, arbol1, elemento, arbol2);
    
    elemento.numero = 100;
    plantarArbolBinario(arbol, arbol3, elemento, arbol4);
       
    cout <<"Recorrer en pre orden: "<< endl;
    recorrerPreOrden(arbol); cout<<endl;
    
    cout <<"Recorrer en En orden: "<< endl;
    recorrerEnOrden(arbol); cout<<endl;
    
    cout <<"Recorrer en Post orden: "<< endl;
    recorrerPostOrden(arbol); cout<<endl;
    
    cout<<"Altura árbol: " << altura(arbol) <<endl;
    
    return 0;
}
