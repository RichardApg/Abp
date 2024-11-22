#ifndef FUNCIONES_H
#define FUNCIONES_H

float leerDecimalPositivo(const char* mensaje);
void ingresarProductos(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int *numProductos);
void editarProducto(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int numProductos);
void eliminarProducto(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int *numProductos);
void calcularTotales(float tiempos[], float recursos[], float cantidades[], int numProductos, float *tiempoTotal, float *recursosTotal);
int verificarFactibilidad(float tiempoTotal, float recursosTotal, float tiempoDisponible, float recursosDisponibles);
void mostrarProductos(char nombres[][50], float tiempos[], float recursos[], float cantidades[], int numProductos);

#endif
