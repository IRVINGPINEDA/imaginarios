#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mis_operaciones.h"
// Función para multiplicar dos números grandes representados como cadenas
char* multiply(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int* result = (int*)calloc(len1 + len2, sizeof(int));
    char* product = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    int pos = 0;
    for (int i = 0; i < len1 + len2; ++i) {
        if (!(pos == 0 && result[i] == 0)) {
            product[pos++] = result[i] + '0';
        }
    }
    product[pos] = '\0';

    free(result);
    return pos == 0 ? strdup("0") : product;
}

// Función para elevar una base grande a un exponente grande
char* power(const char* base, unsigned long exponent) {
    char* result = strdup("1");
    char* base_copy = strdup(base);

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            char* temp = multiply(result, base_copy);
            free(result);
            result = temp;
        }
        char* temp = multiply(base_copy, base_copy);
        free(base_copy);
        base_copy = temp;
        exponent /= 2;
    }

    free(base_copy);
    return result;
}

void exponente(){
    char base[1000];
    unsigned long exponent;

    // Solicitar la base al usuario
    printf("Introduce la base: ");
    scanf("%999s", base);

    // Solicitar el exponente al usuario
    printf("Introduce el exponente: ");
    scanf("%lu", &exponent);

    // Calcular la potencia
    char* result = power(base, exponent);

    // Mostrar el resultado
    printf("%s elevado a %lu es %s\n", base, exponent, result);

    // Liberar la memoria utilizada
    free(result);

    
}

