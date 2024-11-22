#ifndef FUNCIONES_H
#define FUNCIONES_H

void ingresarProductos(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int *numProductos);
void editarProducto(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int numProductos);
void eliminarProducto(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int *numProductos);
void calcularTotales(int tiempos[], int recursos[], int cantidades[], int numProductos, int *tiempoTotal, int *recursosTotal);
int verificarFactibilidad(int tiempoTotal, int recursosTotal, int tiempoDisponible, int recursosDisponibles);
void mostrarProductos(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int numProductos);

#endif
