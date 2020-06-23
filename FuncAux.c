/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Author: Jhenny Cervera Vargas(20182841)     

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
#include <string.h>
#include <ctype.h>
#define MAX_LIN 80
#define MAX_PAL 30

void ProcesarCuento(char**palabrasFrec,int*frecuencias,int*cantPalFrec){
    
    FILE*archCuent;
    archCuent=abrirArch("cuentos.txt", "r");
    (*cantPalFrec)=0;
    char linea[600];
    while(1){
        leerCad(linea,600,archCuent);
        if(feof(archCuent)) break;
        ProcesamosLinea(linea,palabrasFrec,frecuencias,cantPalFrec);
    }

    fclose(archCuent);
}


void ProcesamosLinea(char* linea,char**palabrasFrec,int*frecuencias,int *cantPalFrec){
    
    int i=0, c, pos, lon;
    char palabra[20];
    while(1){
        if(linea[i]==0) return;
        if(linea[i]==' ' || linea[i]==',') i++;
        else{
            c=0; //inicilizo el indice de palabra
            while(linea[i]!=' ' && linea[i]!=0 ){
                palabra[c]=linea[i];
                i++;
                c++;
            }
            palabra[c]=0;
            if(verificarSignosPunt(palabra)) continue; //desarta la palabra que tiene signos de puntuacion
            convertirMinuscula(palabra);
            pos=bucarPal(palabra,palabrasFrec,*cantPalFrec);
            if(pos!=-1){
               frecuencias[pos]++;
            }
            else{  //si no encontramos la palbra lo agregamos al arreglo
                lon=strlen(palabra);
                palabrasFrec[*cantPalFrec]=(char*)malloc(sizeof(char)*(lon+1)); //asignamos memoria de acuerdo al tamaño de la palabra
                strcpy(palabrasFrec[*cantPalFrec],palabra);
                (*cantPalFrec)++;
            }   
        }
        
    }
    
}

int verificarSignosPunt(char* pal){
    for(int i=0; pal[i]; i++){
        if(ispunct(pal[i])) return 1;
    }
    return 0;
}

void leerCad(char* cad, int tope, FILE*arch){
    int nCar;
    fgets(cad, tope, arch);
    nCar=strlen(cad);
    if(cad[nCar-1]=='\n') cad[nCar-1]=0;
}

FILE* abrirArch(const char* nombreArch, const char* modo){
    FILE* arch;
    arch=fopen(nombreArch,modo);
    if(arch==NULL){
        printf("ERROR: No se puede abrir el archivo %s\n",nombreArch );
        exit(1);
    }
    return arch;
}

int bucarPal(char*palabra,char**palabrasFrec,int cont){
    for(int i=0; i<cont; i++){
        if(strcmp(palabra,palabrasFrec[i])==0) return i;
    }
    return -1;
}


void convertirMinuscula(char*palabra){
    for(int i=0; palabra[i]; i++){
        palabra[i]+=( (palabra[i]>='A' && palabra[i]<='Z') ? 32 : 0 );
    }
}

void convertirMayuscula(char*palabra){
    for(int i=0; palabra[i]; i++){
        palabra[i]-=( (palabra[i]>='a' && palabra[i]<='z') ? 32 : 0 );
    }
    
}

void PasarPalabrasMayuscula(char**palabrasFrec,int cantPalFrec){
    for(int i=0; i<cantPalFrec; i++){
        convertirMayuscula(palabrasFrec[i]);
    }
}

void OrdenarFrecuencia(char **palabrasFrec,int* frecuencias, int cantPalFrec){
    for(int i=0; i<cantPalFrec-1; i++){
        for(int j=i+1; j<cantPalFrec; j++){
            if(frecuencias[i]<frecuencias[j]){
                intercambiarI(frecuencias, i, j);
                intercambiarCad(palabrasFrec, i, j);
                
            }
        }
    }
}

void intercambiarCad(char**personas,int i, int j){
    char* aux;
    aux=personas[i];
    personas[i]=personas[j];
    personas[j]=aux;
}
void intercambiarI(int *arr,int  i,int  j){
    
    int aux;
    aux=arr[i];
    arr[i]=arr[j];
    arr[j]=aux;
    
}

void ImprimirRep(char**palabrasFrec,int*frecuencias,int cantPalFrec){
    FILE*archRep;
    archRep=abrirArch("Texto.txt", "w");
    int lon, numBlancos;
    //imprimimos cabecera
    fprintf(archRep, "%40s\n", "FRECUENCIA DE PALABRAS");
    imprimeLinea(archRep, MAX_LIN, '=', 1);
    fprintf(archRep, "%s %30s\n", "PALABRA", "FRECUENCIA");
    
    for(int i=0; i<cantPalFrec; i++){
        fprintf(archRep, "%s",palabrasFrec[i]);
        lon=strlen(palabrasFrec[i]);
        numBlancos=MAX_PAL-(lon);   //calculamos espacios para darle formato a los numeros que le siguen a las palabras
        imprimeLinea(archRep, numBlancos, ' ', 0);
        fprintf(archRep, "%d\n",frecuencias[i]);
    }
    imprimeLinea(archRep, MAX_LIN, '-', 1);
    fprintf(archRep, "Total  %d palabras\n",cantPalFrec);
    fclose(archRep);
}
void imprimeLinea(FILE*archRep,int cant,char c,int op){
    for(int i=0; i<cant; i++){
        fputc(c, archRep);
    }
    if(op) fputc('\n',archRep);
}