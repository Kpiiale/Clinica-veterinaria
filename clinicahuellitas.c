#include <stdio.h>

void IngresarNombreM(char nombre[50]);
void ID(int *id);
void IngresarEdad(int *edad);
void NombreDueno(char nombred[50]);
void Tipo(char tipo[50]);
void IngresarServicio(float *precio, char s[50]);
void facturacion(char nombre[50], int *id, char tipo[50], int *edad, char nombred[50], float *precio, char s[50]);

int menu(int *op, char nombre[50], int *id, char tipo[50], int *edad, char nombred[50], float *precio, char s[50]) {
    switch (*op) {
        case 1:
            IngresarNombreM(nombre);
            ID(id);
            Tipo(tipo);
            IngresarEdad(edad);
            NombreDueno(nombred);
            break;
        case 2:
            IngresarServicio(precio, s);
            break;
        case 3:
            facturacion(nombre, id, tipo, edad, nombred, precio, s);
            break;
        default:
            return *op;
    }
    return *op;
}

void IngresarNombreM(char nombre[50]) {
    printf("Ingresar el nombre de su mascota:\n");
    scanf("%s", nombre);
}

void ID(int *id) {
    printf("Ingresar el id de su mascota:\n");
    scanf("%d", id);
}

void IngresarEdad(int *edad) {
    printf("Ingresar la edad de su mascota:\n");
    scanf("%d", edad);
}

void NombreDueno(char nombred[50]) {
    printf("Ingresar el nombre del dueno:\n");
    scanf("%s", nombred);
}

void Tipo(char tipo[50]) {
    int op2;
    printf("Seleccionar qué tipo de mascota es:\n 1. Perro\n 2. Gato\n");
    scanf("%d", &op2);
    switch (op2) {
        case 1:
            strcpy(tipo, "Perro");
            break;
        case 2:
            strcpy(tipo, "Gato");
            break;
    }
}

void IngresarServicio(float *precio, char s[50]) {
    printf("Ingresar servicio:\n 1. Consulta\n 2. Peluqueria\n 3. Rayos X\n");
    int op3;
    scanf("%d", &op3);
    switch (op3) {
        case 1:
            *precio = 8.50;
            strcpy(s, "Consulta");
            break;
        case 2:
            *precio = 10;
            strcpy(s, "Peluqueria");
            break;
        case 3:
            *precio = 30;
            strcpy(s, "Rayos x");
            break;
    }
}

void facturacion(char nombre[50], int *id, char tipo[50], int *edad, char nombred[50], float *precio, char s[50]) {
    printf("----------------------FACTURA CLINICA HUELLITAS-----------------------------\n");
    printf("Nombre del dueno: %s\n", nombred);
    printf("Nombre de la mascota: %s\n", nombre);
    printf("ID de la mascota: %d\n", *id);
    printf("Tipo de mascota: %s\n", tipo);
    printf("Servicio: %s\n", s);
    printf("Precio: %.2f\n", *precio);
}

int main(int argc, char *argv[]) {
    char nombre[50], tipo[50], nombred[50], s[50];
    int id, edad;
    float precio;
    int op, n;

    printf("---------------------------------Bienvenido a la clinica Huellitas------------------------------------\n");
    printf("Por favor decida qué desea realizar:\n");
    do {
        printf("\n 1. Ingresar mascota\n 2. Ingresar servicio\n 3. Facturación\n 4. Salir\n");
        scanf("%d", &op);
        n = menu(&op, nombre, &id, tipo, &edad, nombred, &precio, s);
    } while (n != 4);
    printf("\nMuchas gracias por usar nuestros servicios.\n");
    return 0;
}
