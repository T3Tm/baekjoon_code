#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
typedef long long ll;
/*
    https://www.acmicpc.net/problem/1248
    1248번 Guess
    최대 내가 정해야 되는 숫자는 10개
    x x x x x x x x x x
    각각 들어갈 수 있는 숫자가
    -10~10 이므로
    각각 음수인지 양수 , 0인지 나옴
    결론은 거의 10가지의 경우의 수를 갖고 있다는 것임
    10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10
    10^10?
    안 된다. 백트로 한 번 해보긴 해야 될듯 ..
    0, 1, 2, 3
       4, 5, 6    n-depth 현재 구간의 갯수가 나온다.
          7, 8
             9
*/
int n;
char sign[60];
int result[13];
void inputs() {
    scanf("%d %s", &n, sign);
}
void back(int depth, int start, int prefix[]) {
    if (depth == n + 1) {  // 숫자 다 뽑았을 때
        for (int i = 1; i <= n; i++) {
            printf("%d ", result[i]);
        }
        exit(0);
    }
    // 현재 수가 음수인지 양수인지 먼저 판별

    char plusMinusZero = sign[start];  // 플러스인지 마이너스인지 제로인지 확인
    if (plusMinusZero == '0') {
        prefix[depth] = prefix[depth - 1];
        result[depth] = 0;  // 무조건 0
        back(depth + 1, start + n - depth + 1, prefix);
    } else {  // 0이 아니라면
        for (int i = 1; i <= 10; i++) {
            int mul = 1;
            if (plusMinusZero == '-') {
                // 일단 음수여야 하는데,
                mul = -1;
            }
            result[depth] = mul * i;  // 이 숫자로 넣어줌
            prefix[depth] = prefix[depth - 1] + result[depth];
            int now = depth - 1;
            bool flag = true;
            int nowcur = start - (n - depth + 1);
            for (; now >= 1; now--) {  // depth를 하나씩 줄인다.
                // now가 행이여
                // depth가 열이여
                char nowPlusMinusZero = sign[nowcur];
                int v = prefix[depth] - prefix[now - 1];
                if (nowPlusMinusZero == '+') {  // 양수인데,
                    if (v <= 0) {
                        flag = false;
                        break;
                    } else if (mul < 0) {   // 이거 음수면 절대 안됨
                        result[depth] = 0;  // 복원
                        prefix[depth] = 0;  // 복원
                        return;
                    }
                } else if (nowPlusMinusZero == '-') {
                    if (v >= 0) {
                        flag = false;
                        break;
                    } else if (mul > 0) {   // 이거 음수면 절대 안됨
                        result[depth] = 0;  // 복원
                        prefix[depth] = 0;  // 복원
                        return;
                    }
                } else {
                    if (v < 0 && mul > 0) {  // 0이면 전에 있던 v가 음수라면 mul이 양수인지 확인
                        flag = false;
                        break;
                    } else if (v > 0 && mul < 0) {
                        flag = false;
                        break;
                    } else {                // 아예 안됨
                        result[depth] = 0;  // 복원
                        prefix[depth] = 0;  // 복원
                        return;
                    }
                }
                nowcur -= n - now + 1;
            }
            if (flag) back(depth + 1, start + n - depth + 1, prefix);
            result[depth] = 0;  // 복원
            prefix[depth] = 0;  // 복원
        }
    }
}
void solve() {
    int prefix[12] = {};
    back(1, 0, prefix);
}
int main() {
    inputs();
    solve();
    return 0;
}