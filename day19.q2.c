#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int total = 0;

    int maxSum = nums[0], currMax = 0;
    int minSum = nums[0], currMin = 0;

    for(int i = 0; i < n; i++) {
        total += nums[i];

        currMax = (currMax > 0 ? currMax + nums[i] : nums[i]);
        if(currMax > maxSum)
            maxSum = currMax;

        currMin = (currMin < 0 ? currMin + nums[i] : nums[i]);
        if(currMin < minSum)
            minSum = currMin;
    }

    int result;

    if(maxSum < 0)
        result = maxSum;
    else
        result = (maxSum > total - minSum ? maxSum : total - minSum);

    printf("%d", result);

    return 0;
}