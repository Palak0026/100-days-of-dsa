#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s) {
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else {
            if(top == -1)
                return false;

            char t = stack[top--];

            if((ch == ')' && t != '(') ||
               (ch == '}' && t != '{') ||
               (ch == ']' && t != '['))
                return false;
        }
    }

    return top == -1;
}

int main() {
    char s[10000];
    scanf("%s", s);

    if(isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}