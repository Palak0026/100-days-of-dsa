/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a
 permutation of the integers from 1 to n with one element missing. Your task is to
 identify and return the missing element.*/


#include <stdio.h>

int main() {
    int n_minus_1;
    
    scanf("%d", &n_minus_1);
    
    int arr[n_minus_1];
    long long sum = 0;
    
    for(int i = 0; i < n_minus_1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    long long n = n_minus_1 + 1;
    long long total_sum = n * (n + 1) / 2;
    
    printf("%lld\n", total_sum - sum);
    
    return 0;
}