#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 100
#define MAX_JUGADORES 100

typedef struct {
    int id;
    char nombre[50];
    int numero_jugado;
    float cantidad;
} Jugador;

Jugador jugadores[MAX_JUGADORES];
int total_jugadores = 0;
int numeros_ganadores[3];
time_t seed;

void generar_numeros_ganadores() {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        numeros_ganadores[i] = rand() % 100;
    }
    printf("Numeros ganadores: %d, %d, %d\n", numeros_ganadores[0], numeros_ganadores[1], numeros_ganadores[2]);
}

void registrar_jugador() {
    if (total_jugadores >= MAX_JUGADORES) {
        printf("No se pueden registrar más jugadores.\n");
        return;
    }
    printf("Ingrese su nombre: ");
    scanf(" %49s", jugadores[total_jugadores].nombre);
    printf("Ingrese su número jugado (0-99): ");
    scanf("%d", &jugadores[total_jugadores].numero_jugado);
    printf("Ingrese la cantidad apostada: ");
    scanf("%f", &jugadores[total_jugadores].cantidad);

    jugadores[total_jugadores].id = total_jugadores + 1;
    total_jugadores++;
    printf("Jugador registrado con éxito.\n");
}

void guardar_jugadas() {
    FILE *archivo = fopen("jugadas.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < total_jugadores; i++) {
        fprintf(archivo, "ID: %d, Nombre: %s, Numero Jugado: %d, Cantidad: %.2f\n",
                jugadores[i].id, jugadores[i].nombre,
                jugadores[i].numero_jugado, jugadores[i].cantidad);
    }
    fclose(archivo);
    printf("Jugadas guardadas en archivo.\n");
}

void mostrar_jugadores() {
    for (int i = 0; i < total_jugadores; i++) {
        printf("ID: %d, Nombre: %s, Numero Jugado: %d, Cantidad: %.2f\n",
               jugadores[i].id, jugadores[i].nombre,
               jugadores[i].numero_jugado, jugadores[i].cantidad);
    }
}

void calcular_premios() {
    printf("Resultados de la lotería:\n");
    for (int i = 0; i < total_jugadores; i++) {
        float premio = 0;
        if (jugadores[i].numero_jugado == numeros_ganadores[0]) {
            premio = jugadores[i].cantidad * 100;
        } else if (jugadores[i].numero_jugado == numeros_ganadores[1]) {
            premio = jugadores[i].cantidad * 50;
        } else if (jugadores[i].numero_jugado == numeros_ganadores[2]) {
            premio = jugadores[i].cantidad * 10;
        }
        printf("Jugador %s ganó %.2f unidades.\n", jugadores[i].nombre, premio);
    }
}

void menu() {
    int opcion;
    do {
        printf("\n--- Menú Lotería ---\n");
        printf("1. Registrar Jugador\n");
        printf("2. Mostrar Jugadores\n");
        printf("3. Mostrar Números Ganadores\n");
        printf("4. Calcular Premios\n");
        printf("5. Guardar Jugadas\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrar_jugador();
                break;
            case 2:
                mostrar_jugadores();
                break;
            case 3:
                generar_numeros_ganadores();
                break;
            case 4:
                calcular_premios();
                break;
            case 5:
                guardar_jugadas();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
}

int main() {
    generar_numeros_ganadores();
    menu();
    return 0;
}
