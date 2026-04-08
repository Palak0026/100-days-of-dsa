#include <stdio.h>
#include <string.h>

void reverseString(char s[], int size) {
    int i = 0, j = size - 1;
    char temp;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char s[100000];

    scanf("%s", s);

    int size = strlen(s);

    reverseString(s, size);

    printf("%s", s);

    return 0;
}