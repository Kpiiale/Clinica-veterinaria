#include <stdio.h>
#include <string.h>

void IngresarNombreM(char nombre[][50], int indice);
void ID(int id[], int indice);
void IngresarEdad(int edad[], int indice);
void NombreDueno(char nombred[][50], int indice);
void Tipo(int *op2);
void IngresarServicio(int *op3);
void facturacion(char nombre[][50], int id[], int *op2, int edad[], char nombred[][50], int *op3, int indice);
int menu(int *op, char nombre[][50], int id[], int *op2, int edad[], char nombred[][50], int *op3, int indice);

int main(int argc, char *argv[]) {
    char nombre[100][50], nombred[100][50];
    int id[100], edad[100];
    int op, op2, op3, n;
    int indice = 0;

    printf("---------------------------------Bienvenido a la clinica Huellitas------------------------------------\n");
    printf("Por favor decida qué desea realizar:\n");
    do {
        printf("\n 1. Ingresar mascota\n 2. Ingresar servicio\n 3. Facturacion\n 4. Salir\n");
        scanf("%d", &op);
        n = menu(&op, nombre, id, &op2, edad, nombred, &op3, indice);
        if (op == 1) {
            indice++;
        }
    } while (n != 4);
    printf("\nMuchas gracias por usar nuestros servicios.\n");
    return 0;
}

int menu(int *op, char nombre[][50], int id[], int *op2, int edad[], char nombred[][50], int *op3, int indice) {
    switch (*op) {
        case 1:
            IngresarNombreM(nombre, indice);
            ID(id, indice);
            Tipo(op2);
            IngresarEdad(edad, indice);
            NombreDueno(nombred, indice);
            break;
        case 2:
            IngresarServicio(op3);
            break;
        case 3:
            for (int i = 0; i < indice; i++) {
                facturacion(nombre, id, op2, edad, nombred, op3, i);
            }
            break;
        default:
            return *op;
    }
    return *op;
}

void IngresarNombreM(char nombre[][50], int indice) {
    printf("Ingresar el nombre de la mascota %d:\n", indice + 1);
    scanf("%s", nombre[indice]);
}

void ID(int id[], int indice) {
    printf("Ingresar el id de la mascota %d:\n", indice + 1);
    scanf("%d", &id[indice]);
}

void IngresarEdad(int edad[], int indice) {
    printf("Ingresar la edad de la mascota %d:\n", indice + 1);
    scanf("%d", &edad[indice]);
}

void NombreDueno(char nombred[][50], int indice) {
    printf("Ingresar el nombre del dueno de la mascota %d:\n", indice + 1);
    scanf("%s", nombred[indice]);
}

void Tipo(int *op2) {
    printf("Seleccionar qué tipo de mascota es la mascota:\n 1. Perro\n 2. Gato\n");
    scanf("%d", op2);
}

void IngresarServicio(int *op3) {
    printf("Ingresar servicio para la mascota\n 1. Consulta\n 2. Peluqueria\n 3. Rayos X\n");
    scanf("%d", op3);
}

void facturacion(char nombre[][50], int id[], int *op2, int edad[], char nombred[][50], int *op3, int indice) {
    printf("----------------------FACTURA CLINICA HUELLITAS-----------------------------\n");
    printf("Nombre del dueno de la mascota: %s\n", nombred[indice]);
    printf("Nombre de la mascota: %s\n", nombre[indice]);
    printf("ID de la mascota: %d\n", id[indice]);
    if (*op2 == 1) {
        printf("Tipo de mascota: Perro\n");
    }
    if (*op2 == 2) {
        printf("Tipo de mascota: Gato\n");
    }
    if (*op3 == 1) {
        printf("Servicio para la mascota: Consulta\n");
        printf("Precio para la mascota: $20\n");
    }
    if (*op3 == 2) {
        printf("Servicio para la mascota: Peluqueria\n");
        printf("Precio para la mascota: $30\n");
    }
    if (*op3 == 3) {
        printf("Servicio para la mascota: Rayos X\n");
        printf("Precio para la mascota: $300\n");
    }
    printf("\n");
}
