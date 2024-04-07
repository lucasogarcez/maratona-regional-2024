#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 35) {
        printf("1\n");
    } else {
        if (n >= 36 && n <= 70) {
            printf("2\n");
        }else {
            if (n >= 71 && n <= 105) {
                printf("3\n");
            } else {
                if (n >= 106 && n <= 150) {
                    printf("4\n");
                }else {
                    printf("erro\n");
                }
            }
        }
    }
}