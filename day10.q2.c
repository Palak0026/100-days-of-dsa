#include <stdio.h>

int main() {
    int nums1[] = {1,2,2,1};
    int nums2[] = {2,2};
    int n1 = 4, n2 = 2;

    int count[1001] = {0};
    int result[1000];
    int i, k = 0;

    for (i = 0; i < n1; i++)
        count[nums1[i]]++;

    for (i = 0; i < n2; i++) {
        if (count[nums2[i]] > 0) {
            result[k++] = nums2[i];
            count[nums2[i]]--;
        }
    }

    for (i = 0; i < k; i++)
        printf("%d ", result[i]);

    return 0;
}