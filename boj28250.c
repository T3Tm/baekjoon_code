#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    boj28250

    결론 :
    0 0 => 1
    0 1 => 2
    0 x => 1
*/
int n;
int arr[200002];
int number[3];  // 0의 갯수, 1의 갯수, 2의 갯수
void inputs() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}
void solve() {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            res += number[0];       // 1로 더해야 되는 상황
            res += 2L * number[1];  // 2로 더해야 되는 상황
            res += number[2];       // 1로 더해야 되는 상황
        } else if (arr[i] == 1) {   //
            res += 2L * number[0];  // 2로 더해야 되는 상황
        } else if (arr[i] >= 2) {
            arr[i] = 2;
            res += number[0];  // 1로 더해야 되는 상황
        }
        number[arr[i]]++;  // 0 -> 0 , 1 -> 1, 2이상은 2로 맵핑되려면?
    }
    printf("%lld", res);
}
int main() {
    inputs();
    solve();
    return 0;
}