/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAux.h
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 22 de junio de 2020, 19:12
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H
void ProcesarCuento(char**,int*,int*);
FILE* abrirArch(const char* , const char* );
void leerCad(char* , int , FILE*);
int bucarPal(char*,char**,int );
void ProcesamosLinea(char* ,char**,int*,int *);
void convertirMinuscula(char*);
void convertirMayuscula(char*);
void PasarPalabrasMayuscula(char**,int );
void OrdenarFrecuencia(char **,int* , int );
void intercambiarCad(char**,int , int );
void intercambiarI(int *,int  ,int  );
void ImprimirRep(char**,int*,int );
void imprimeLinea(FILE*,int ,char ,int );
int verificarSignosPunt(char* pal);
#endif /* FUNCAUX_H */

