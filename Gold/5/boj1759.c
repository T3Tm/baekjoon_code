#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/1759
    1759번 암호 만들기
*/
int l, c;
char candidate[18];
char vowels[] = "aeiou";
void inputs() {
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++) {
        scanf(" %c", &candidate[i]);
    }
}
bool canPassword(char src[]) {
    bool isVowel = false;
    int cnt = 0;
    for (int i = 0; src[i]; i++) {
        bool flag = false;
        for (int j = 0; vowels[j]; j++) {
            if (src[i] == vowels[j]) {
                isVowel = true;
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;  // 모음 아님
    }
    return (cnt > 1) && isVowel;
}
void makePassword(int depth, int pre, char pass[]) {
    if (depth == l) {
        if (canPassword(pass)) {
            printf("%s\n", pass);
        }
        return;
    }
    for (int i = pre; i < c; i++) {
        pass[depth] = candidate[i];
        makePassword(depth + 1, i + 1, pass);
        pass[depth] = ' ';
    }
}
int compare(void* a, void* b) {
    return (*(char*)a) > (*(char*)b);
}
void solve() {
    qsort(candidate, c, sizeof(char), compare);
    char pass[17] = "";
    makePassword(0, 0, pass);
}
int main() {
    inputs();
    solve();
    return 0;
}