#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define For(r) for (int i = 0; i < (r); i++)
#define FOR(a, b) for (int i = a; i < (b); i++)
#define SWAP(i, j)   \
    {                \
        int OOO = i; \
        i = j;       \
        j = OOO;     \
    }
typedef long long ll;
/*
    https://www.acmicpc.net/problem/2290
    2290번 LCD Test
    12 * 10 + 10 = 130
    1 : 맨 오른쪽으로 붙이고 s만큼 1행부터 붙이고 한 칸 뛰고 s만큼 다시 붙인다.
    //나머지 들어가지 않은 부분들은 다 공백으로 채우기
    2 : 맨 왼쪽 위부터
*/
int s;
char number[13];
char result[23][133];
void inputs() {
    scanf("%d %s", &s, number);
}
void fillVerticalWhileSpace(int x) {
    // x열을 다 공백으로 채우기
    For(2 * s + 3) {
        result[i][x] = ' ';  // 공백으로 채우기
    }
}
void makeNumber(int y, int number) {  // 어떤 숫자를 어떻게 만들지 생각
    int ybound = y + s + 2;
    if (number == 1) {
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
    } else if (number == 2) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 3) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 4) {
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
    } else if (number == 5) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 6) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][y] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 7) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
    } else if (number == 8) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][y] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 9) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[s + 1][y + i] = '-';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    } else if (number == 0) {
        FOR(1, s + 1) {
            result[0][y + i] = '-';
        }
        FOR(1, s + 1) {
            result[i][y] = '|';
        }
        FOR(1, s + 1) {
            result[i][ybound - 1] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][y] = '|';
        }
        FOR(s + 2, 2 * s + 2) {
            result[i][ybound - 1] = '|';
        }
        FOR(1, s + 1) {
            result[2 * s + 2][y + i] = '-';
        }
    }
}
void fillWhileSpace() {
    int size = strlen(number);
    for (int i = 0; i < 2 * s + 3; i++) {
        for (int j = 0; j < (s + 2) * size + size; j++) {
            if (!(result[i][j] == '-' || result[i][j] == '|')) {
                result[i][j] = ' ';
            }
        }
        result[i][(s + 2) * size + size] = '\0';  // 끝에 null줘서 문자 끝인 거 알려주기
    }
}
void solve() {
    int startx = 0;
    for (int i = 0; number[i]; i++) {
        makeNumber(startx, number[i] - '0');  // 이 숫자 만들기
        startx = startx + s + 2;
        fillVerticalWhileSpace(startx++);  // 공백으로 한 줄 채우고
    }
    // 나머지 공간들 다 공백으로 채우기
    fillWhileSpace();
    For(2 * s + 3) {
        printf("%s\n", result[i]);
    }
}
int main() {
    inputs();
    solve();
    return 0;
}