#include <stdio.h>

int main() {
    int n, j, cont = 0;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    for (int i = 0; i < n; i++) {
        j = 0;
        while (j < i && vet[i] != vet[j]) {
            j++;
            if (i == j) {
                for (j = i + 1; j < n; j++) {
                    if (vet[i] == vet[j]) {
                        cont++;
                    }
                }
            }
        }
    }

    int resultado = n - cont;
    printf("%d\n", resultado);

    return 0;
}