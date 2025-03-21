#include <stdio.h>

/* Universidad.
El programa, al recibir información sobre el número de alumnos que han ingresado
a sus ocho diferentes carreras en los dos semestres lectivos de los últimos
cinco años, obtiene información útil para el departamento de escolar. */

const int F = 8, C = 2, P = 5;
/* Se declaran constantes para la fila, la columna y la profundidad. */
void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);
/* Prototipo de funciones. Cada prototipo de función corresponde a uno de los
incisos. */
void main(void)
{
    int UNI[F][C][P];
    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Fu Funcion3(UNI, 6, C, P);
    /* Se coloca el 6 como parámetro ya que es la clave de la Ingeniería en
    Computación. */
}
void Lectura(int A[][C][P], int FI, int CO, int PR)
/* La función Lectura se utiliza para leer un arreglo tridimensional de tipo
entero de FI filas, CO columnas y PR profundidad. Observa que al ser
tridimensional se necesitan tres ciclos para recorrer el arreglo. */
{
    nt K, I, J;
    for (K=0; K<PR; K++)
        for (I=0; I<FI; I++)
        for (J=0; J<CO; J++)
{
    printf("Año: %d\tCarrera: %d\tSemestre: %d ", K+1, I+1, J+1);
    scanf("%d", &A[I][J][K]);
}
}
void Funcion1(int A[][C][P],int FI, int CO, int PR)
/* Esta función se utiliza para determinar el año en el que ingresó el mayor
número de alumnos a la universidad. Observa que el primer ciclo externo
corresponde a los años. */
{
    int K, I, J, MAY = 0, AO = -1, SUM;
    for (K=0; K<PR; K++)
        /* Por cada año se suma el ingreso de los dos semestres de las ocho carreras.
        */
{
    SUM = 0;
    for (I=0; I<FI; I++)
        for (J=0; J<CO; J++)
        SUM += A[I][J][K];
    if (SUM > MAY)
{
    MAY = SUM;
    AO = K;
}
