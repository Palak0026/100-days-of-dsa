#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n], result[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int prefix = 1;

    for(int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    for(int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}