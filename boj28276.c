#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    boj28276번
    1. 세로로 한 번 스캔을 한 뒤에 각 집합들을 계산 해준다.
        1-1 집합에 넘버링을 한다.
        1-2 각 집합에 포함된 수가 몇 개가 있는지 파악한다.
    2. 이분탐색을 통해 사람의 수를 탐색하고 그 사람의 수로 칸막이를 얼마나
   설치해야 되는지 계산한다. 2-1
    3. 마지막에 사람 수를 출력한다.

*/
typedef struct Pair {
    int left, right;
} Pair;
const int MAXSIZE = 1e6;
char **board;  // 보드
int r, c, w;
int parent[MAXSIZE + 2];  // 각 부모 집합 파악 1e6
int *verticalSet;         // 세로로 처음 있는 집합의 숫자 저장
int setCnt[MAXSIZE + 2];  // 집합의 갯수 저장 1e6
int **visited;            // 방문을 찍음과 동시에 같은 집합 알아내기
void inputs() {
    scanf("%d %d %d", &r, &c, &w);
    board = (char **)malloc(sizeof(char *) * r);
    visited = (int **)malloc(sizeof(int *) * r);
    verticalSet = (int *)malloc(sizeof(int) * c);
    for (int i = 0; i < r; i++) {
        board[i] = (char *)malloc(sizeof(char) * c);
        visited[i] = (int *)malloc(sizeof(int) * c);
        scanf("%s", board[i]);
    }
}

/* 집합 찾기 */
int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}
/* 집합 합치기 */
void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

/* 부모들 -1로 초기화 해준다.*/
void init(int size) {
    memset(parent, -1, sizeof(int) * size);  // 나오는 집합 수 만큼만?
}
/* 집합의 수를 알아내고 저장하기 */
int verticalFind() {
    int number = 0;  // 0번부터 집합을 시작해보자
    for (int col = 0; col < c; col++) {
        for (int row = 0; row < r; row++) {
            if (board[row][col] == '0') continue;  // 0 이면 볼 필요도 없음
            int Up = row - 1;
            if (Up >= 0 && board[row][col] == '1') {                // 전에 아이가 1이면 같은 집합으로 합치기
                int preSet = visited[row][col] = visited[Up][col];  // 이 집합으로 덮어쓰기
                setCnt[preSet]++;                                   // 갯수 증가
            } else {                                                // 새로운 집합 지정
                if (verticalSet[col] == -1) {                       // 현재 세로로된 첫 집합의 수를 파악
                    verticalSet[col] = number;
                }
                int nowSet = visited[row][col] = number++;
                setCnt[nowSet] = 1;  // 현재 넘버 한 개라고 지정
            }
        }
    }
    return number;
}
/* 매 라운드 초기화 작업 */
void roundInit(int dst[], int size) {
    // 저장 배열을 cpy하기
    memcpy(dst, setCnt, sizeof(int) * size);  // 사이즈 만큼만 복사하면 된다.
}

int countingWall(int mid, int cnt[]) {
    int ret = 0;  // 벽의 수
    /*
        lazy Update 하기
        한 쪽 열을 다 보고
        만약 mid를 넘어가는 상황이 나오면 그 때는 연결 안 하고
        mid 넘어가는 상황이 안 나왔다면 합쳐주기
    */
    for (int col = 0; col < c; col++) {
        bool flag = false;
        Pair *query = (Pair *)malloc(sizeof(Pair) * r);
        int queryIdx = 0;
        bool **check = (bool **)malloc(sizeof(bool *) * r);
        for (int i = 0; i < r; i++) {
            check[i] = (bool *)malloc(sizeof(bool) * c);
        }

        for (int row = 0; row < r; row++) {
            if (board[row][col] == '0') continue;  // 하품 아니면 필요 없음
            int nowSet = visited[row][col];        // 현재 집합의 수
            if (setCnt[nowSet] > mid) {            // 현재의 집합만 봤을 때 줄을 쳐야 되는 거면 말이 안됨
                ret = mid + 1;                     // 무조건 안된다고 말해주기
                goto EXIT;
            }

            // 내 집합과 맞붙혀 있는 모든 집합들을 갖고 오자.
            // 그리고 그 집합과 합친다고 생각 했을 때 몇이 되는지 파악하자.
            // 만약 그렇게 했는데 넘어간다면 break; 하고 다음 열로 넘어가자.
            // 아니라면 merge를 통해서 옆에 있는 집합과 다 연결을 해주고 다음 열로 넘어간다.

            int sameRow = row;
            int leftPlus = 0;
            int left = col - 1;
            while (-1 < left && sameRow < r && visited[sameRow][col] == nowSet) {  // 현재 집합이 같은 행의 끝까지 이동
                int leftSet = visited[sameRow][left];
                if (leftSet != -1 && !check[leftSet][nowSet]) {  // 이동하면서 왼쪽에 맞붙어 있으며, 더한적이 없는 아이들

                    check[leftSet][nowSet] = true;  // 합친 적 있다고 알려주기
                }
                sameRow++;
            }
        }
    }
EXIT:
    return ret;
}
void solve() {
    int parentSize = verticalFind();  // 세로로 집합의 수 알아내기
    init(parentSize);                 // 초기화 해줘야 되는 작업을 수행해보자.

    int left = 0, right = MAXSIZE;
    while (left <= right) {
        int mid = (left + right) / 2;  // 사람
        int setTemp[MAXSIZE + 2];
        roundInit(setTemp, parentSize);  // 매 라운드마다 초기화 해줘야 되는 작업.
        int wall =
            countingWall(mid, setTemp);  // 현재 mid에 관련해서 몇개를 세워야 되는지 확인
        if (wall > w) {                  // 벽을 더 세워야 되는 거면 안된다.
            left = mid + 1;              // 벽을 세우면 안되므로 인원을 늘리자
        } else {                         // 벽을 세울순 있음 그러니까 더 최댓값 찾자.
            right = mid - 1;             // 인원을 줄이자
        }
    }
    printf("%d", left);
}
int main() {
    inputs();
    solve();
    return 0;
}