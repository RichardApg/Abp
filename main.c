#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 100

int main() {
    char nombres[MAX_PRODUCTOS][50];
    float tiempos[MAX_PRODUCTOS], recursos[MAX_PRODUCTOS], cantidades[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion;
    float tiempoDisponible, recursosDisponibles;

    tiempoDisponible = leerDecimalPositivo("Ingrese el tiempo de produccion disponible (en horas): ");
    recursosDisponibles = leerDecimalPositivo("Ingrese la cantidad de recursos disponibles(en dolares): ");

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
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                ingresarProductos(nombres, tiempos, recursos, cantidades, &numProductos);
                break;
            case 2:
                editarProducto(nombres, tiempos, recursos, cantidades, numProductos);
                break;
            case 3:
                eliminarProducto(nombres, tiempos, recursos, cantidades, &numProductos);
                break;
            case 4: {
                float tiempoTotal, recursosTotal;
                calcularTotales(tiempos, recursos, cantidades, numProductos, &tiempoTotal, &recursosTotal);
                printf("Tiempo total: %.2f horas\n", tiempoTotal);
                printf("Recursos totales: %.2f\n", recursosTotal);
                if (verificarFactibilidad(tiempoTotal, recursosTotal, tiempoDisponible, recursosDisponibles)) {
                    printf("La produccion es factible.\n");
                } else {
                    printf("No se puede cumplir con la demanda.\n");
                }
                break;
            }
            case 5:
                mostrarProductos(nombres, tiempos, recursos, cantidades, numProductos);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}
