#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    gets(palavra);
    char *vogal = "aeiouAEIOU";
    
    for (int i = 0; i < strlen(palavra); i++) {
        if (!(strchr(vogal, palavra[i]))) {
            printf("%c", palavra[i]);
        }
    }

    return 0;
}