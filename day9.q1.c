#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i = 0, j;
    char temp;

    scanf("%s", str);

    j = strlen(str) - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("%s", str);

    return 0;
}