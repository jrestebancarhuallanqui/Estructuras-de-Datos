/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
using namespace std;
int cont=0;



void inserta_izq(NodoArbol *tad,NodoGen dato){
    NodoArbol* nuevo = crearNuevoNodoArbol(nullptr,dato,nullptr);
    tad->izquierda = nuevo;
}
void inserta_der(NodoArbol *tad,NodoGen dato){
    NodoArbol* nuevo = crearNuevoNodoArbol(nullptr,dato,nullptr);
    tad->derecha = nuevo;
}

void insertanivel(NodoArbol* narbol,int *paq,
        int ini,int n){
    NodoGen temp;
    
    if(ini==n) return;
    //izquierda
    temp.cromo=0;
    temp.cantidad=paq[ini];
    inserta_izq(narbol,temp);
    insertanivel(narbol->izquierda,paq,ini+1,n);
    
    //derecha
    temp.cromo=1;
    temp.cantidad=paq[ini];    
    inserta_der(narbol,temp);
    insertanivel(narbol->derecha,paq,ini+1,n);
    
}


void crearbolcromo(ArbolBinario &arbol1,int *paq,
        int n){
    NodoGen temp;
    
    temp.cromo=0;
    temp.cantidad=0;
    plantarArbolBinario(arbol1,nullptr,temp,nullptr);
    insertanivel(arbol1.raiz,paq,0,n);
}
void insertasol(int cant,int *sol){
    int i;
    for(i=0;sol[i]!=0;i++);
    sol[i]=cant;
}

void calcula(NodoArbol *tad,int parcial,int peso,int *sol){
    if(esNodoVacio(tad)) return;
    parcial+=tad->elemento.cantidad*tad->elemento.cromo;
//    if(tad->elemento.cromo==1 and parcial<=peso)
//        insertasol(tad->elemento.cantidad,sol);
    if(esNodoVacio(tad->izquierda)){
        if(peso==parcial){
            cont++;
//            for(int i=0;i<10;i++)
//                cout << sol[i]<<" ";
//            cout << endl;
        }   
    }    
    else{
        calcula(tad->izquierda,parcial,peso,sol);
        calcula(tad->derecha,parcial,peso,sol);
    }
}



int main(int argc, char** argv) {
    ArbolBinario arbol;
    int paq[]={10,50,20,30,40};
    int peso=70;
    int sol[10]{};
    int n=sizeof(paq)/sizeof(paq[0]);
    
    construir(arbol);
    crearbolcromo(arbol,paq,n);
    recorrerEnOrden(arbol);
    cout<< endl;
    recorrerEnPreOrdenRecursivo(arbol.raiz);
    calcula(arbol.raiz,0,peso,sol); 
    cout << endl;
    cout << "La cantidad de posibilidades es:" << cont;
    return 0;
}

