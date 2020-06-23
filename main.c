/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 22 de junio de 2020, 19:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    char* palabrasFrec[1000];
    int frecuencias[1000], cantPalFrec;
    
    //incializando cont de palbrasfrecuentes
    for(int i=0; i<1000;i++) frecuencias[i]=1;
    
    ProcesarCuento(palabrasFrec,frecuencias,&cantPalFrec);
/*
    for(int i=0; i<cantPalFrec; i++){
        printf("%s  %d\n",palabrasFrec[i],frecuencias[i]);
    }
*/
    PasarPalabrasMayuscula(palabrasFrec,cantPalFrec);
    OrdenarFrecuencia(palabrasFrec,frecuencias,cantPalFrec);
    ImprimirRep(palabrasFrec,frecuencias,cantPalFrec);
    
    return (EXIT_SUCCESS);
}

