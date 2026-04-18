#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i = 1; i < n; i++) {
        if(currSum < 0)
            currSum = arr[i];
        else
            currSum += arr[i];

        if(currSum > maxSum)
            maxSum = currSum;
    }

    printf("%d", maxSum);

    return 0;
}