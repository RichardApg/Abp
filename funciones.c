#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int *numProductos) {
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*numProductos]);
    printf("Ingrese el tiempo de fabricacion (en horas): ");
    scanf("%d", &tiempos[*numProductos]);
    printf("Ingrese los costos necesarios: ");
    scanf("%d", &recursos[*numProductos]);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &cantidades[*numProductos]);
    (*numProductos)++;
}

void editarProducto(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int numProductos) {
    char nombreBusqueda[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBusqueda);
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos.\n");
            printf("Nuevo nombre: ");
            scanf("%s", nombres[i]);
            printf("Nuevo tiempo de fabricacion: ");
            scanf("%d", &tiempos[i]);
            printf("Nuevos costos necesarios: ");
            scanf("%d", &recursos[i]);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &cantidades[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int *numProductos) {
    char nombreBusqueda[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBusqueda);
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcularTotales(int tiempos[], int recursos[], int cantidades[], int numProductos, int *tiempoTotal, int *recursosTotal) {
    *tiempoTotal = 0;
    *recursosTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        *tiempoTotal += tiempos[i] * cantidades[i];
        *recursosTotal += recursos[i] * cantidades[i];
    }
}

int verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoDisponible, int recursosDisponibles) {
    return (tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponibles);
}

void mostrarProductos(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int numProductos) {
    printf("\nLista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s | Tiempo: %d | Recursos: %d | Cantidad: %d\n", 
                nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}
