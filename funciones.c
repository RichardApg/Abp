#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para leer un valor decimal positivo
float leerDecimalPositivo(const char* mensaje) {
    float valor;
    while (1) {
        printf("%s", mensaje);
        if (scanf("%f", &valor) != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero.\n");
            while (getchar() != '\n'); // Limpiar el buffer
            continue;
        }
        if (valor >= 0) {
            break;
        }
        printf("No se puede ingresar una cantidad negativa. Intente de nuevo.\n");
    }
    return valor;
}

void ingresarProductos(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int *numProductos) {
    printf("Ingrese el nombre del producto: ");
    getchar(); // Limpiar el buffer
    fgets(nombres[*numProductos], 50, stdin);
    nombres[*numProductos][strcspn(nombres[*numProductos], "\n")] = '\0'; // Eliminar salto de línea

    tiempos[*numProductos] = leerDecimalPositivo("Ingrese el tiempo de fabricacion (en horas): ");
    recursos[*numProductos] = leerDecimalPositivo("Ingrese los recursos necesarios (en dolares): ");
    cantidades[*numProductos] = leerDecimalPositivo("Ingrese la cantidad demandada: ");

    (*numProductos)++;
}

void editarProducto(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int numProductos) {
    char nombreBusqueda[50];
    int productoEncontrado = 0;

    printf("Ingrese el nombre del producto a editar: ");
    getchar(); // Limpiar el buffer para evitar conflictos
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0'; // Eliminar salto de línea

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            productoEncontrado = 1;
            printf("Producto encontrado. Ingrese los nuevos datos.\n");

            printf("Nuevo nombre: ");
            fgets(nombres[i], 50, stdin);
            nombres[i][strcspn(nombres[i], "\n")] = '\0'; // Eliminar salto de línea

            tiempos[i] = leerDecimalPositivo("Nuevo tiempo de fabricacion (en horas): ");
            recursos[i] = leerDecimalPositivo("Nuevos costos necesarios: ");
            cantidades[i] = leerDecimalPositivo("Nueva cantidad demandada: ");

            return;
        }
    }

    if (!productoEncontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int *numProductos) {
    char nombreBusqueda[50];
    int productoEncontrado = 0;

    printf("Ingrese el nombre del producto a eliminar: ");
    getchar(); // Limpiar el buffer
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = '\0'; // Eliminar salto de línea

    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nombres[i], nombreBusqueda) == 0) {
            productoEncontrado = 1;

            // Desplazar los productos restantes para eliminar el producto actual
            for (int j = i; j < *numProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                cantidades[j] = cantidades[j + 1];
            }

            (*numProductos)--; // Reducir el número de productos
            printf("Producto eliminado.\n");
            return;
        }
    }

    if (!productoEncontrado) {
        printf("Producto no encontrado.\n");
    }
}

void calcularTotales(float tiempos[], float recursos[], float cantidades[], int numProductos, float *tiempoTotal, float *recursosTotal) {
    *tiempoTotal = 0;
    *recursosTotal = 0;
    for (int i = 0; i < numProductos; i++) {
        *tiempoTotal += tiempos[i] * cantidades[i];
        *recursosTotal += recursos[i] * cantidades[i];
    }
}

int verificarFactibilidad(float tiempoTotal, float recursosTotal, float tiempoDisponible, float recursosDisponibles) {
    return (tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponibles);
}

void mostrarProductos(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int numProductos) {
    printf("\nLista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s | Tiempo: %.2f horas | Recursos: %.2f | Cantidad: %.2f\n", 
               nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}
