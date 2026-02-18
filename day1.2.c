//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <stdio.h>

int main() {
    int n, target;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    return 0;
}
