#include <stdio.h>

int main() {

    float p1, p2, p3 ,p4;

    scanf("%f %f %f %f", &p1, &p2, &p3, &p4);

    p2 *= 2;
    p3 *= 3;
    p4 *= 5;

    float media = ((p1 + p2 + p3 + p4) / (11));

    printf("%.2f\n", media);
    if (media >= 6.0)
        printf("classificado\n");
    else
        printf("desclassificado\n");

    return 0;
}