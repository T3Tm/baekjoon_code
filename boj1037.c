#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(void *a, void *b) {
    return (*(int *)a) - (*(int *)b);
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    printf("%d", arr[0] * arr[n - 1]);
}