#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 100

int main() {
    char nombres[MAX_PRODUCTOS][50];
    int tiempos[MAX_PRODUCTOS], recursos[MAX_PRODUCTOS], cantidades[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion, tiempoDisponible, recursosDisponibles;

    printf("Ingrese el tiempo de produccion disponible (en horas): ");
    scanf("%d", &tiempoDisponible);
    printf("Ingrese la cantidad de recursos disponibles (dolares): ");
    scanf("%d", &recursosDisponibles);

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular totales y verificar factibilidad\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpieza del buffer

        if (opcion == 1) {
            ingresarProductos(nombres, tiempos, recursos, cantidades, &numProductos);
        } else if (opcion == 2) {
            editarProducto(nombres, tiempos, recursos, cantidades, numProductos);
        } else if (opcion == 3) {
            eliminarProducto(nombres, tiempos, recursos, cantidades, &numProductos);
        } else if (opcion == 4) {
            int tiempoTotal, recursosTotal;
            calcularTotales(tiempos, recursos, cantidades, numProductos, &tiempoTotal, &recursosTotal);
            printf("Tiempo total: %d horas\n", tiempoTotal);
            printf("Recursos totales: %d\n", recursosTotal);
            if (verificarFactibilidad(tiempoTotal, recursosTotal, tiempoDisponible, recursosDisponibles)) {
                printf("La produccion es factible.\n");
            } else {
                printf("No se puede cumplir con la demanda.\n");
            }
        } else if (opcion == 5) {
            mostrarProductos(nombres, tiempos, recursos, cantidades, numProductos);
        } else if (opcion != 6) {
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}
