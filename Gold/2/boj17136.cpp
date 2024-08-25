#include <bits/stdc++.h>
using namespace std;
int board[12][12];   // 1x1 -> 10 x 10
int visited[11][11];
int total; // 전체 갯수 맞는지 체크하기 위함
const int INF = 0x3f3f3f3f;
int result{INF};
pair<int,int> find(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(visited[i][j] || !board[i][j])continue;
            return {i,j};
        }
    }
}
void dfs(int a, int b, int c, int d, int e, int left) // 안 칠한 것도 필요하네..
{   
    if (!left){//불가능하게 사용하지 않고 다 사용했음
        result = min(result, 5-a + 5-b + 5-d + 5-e + 5-c);
        return;
    }
    int tmp[6]{0, a, b, c, d, e};
    auto[x,y] = find();//1이 시작되는 좌측 상단 찾기
    // 1,2,3,4,5 잘라서 넘어가봅시다.
    for (int i = 1; i <= 5; i++)
    {
        if(!tmp[i])continue;
        int now{};
        if (x + i - 1 > 10 && y + i - 1 > 10)continue; // 애초에 이렇게는 자를 수가 없음
        
        for (int row = x; row < x + i; row++)
        {
            for (int column = y; column < y + i; column++)
            {
                if (visited[row][column])
                    continue;
                now += board[row][column];
            }
        }

        if (now == i * i)
        { // 해당 곳에 잘라서 넣으면 된다.
            tmp[i]--;
            for (int row = x; row < x + i; row++)
            {
                for (int column = y; column < y + i; column++)
                {
                    visited[row][column] = 1; // 방문 처리
                }
            }
            dfs(tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], left - now);
            tmp[i]++;
            for (int row = x; row < x + i; row++)
            {
                for (int column = y; column < y + i; column++)
                {
                    visited[row][column] = 0; // 방문 처리
                }
            }
        }else {//더 이상 채울 수 없음
            break;
        }
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> board[i][j];
            total += board[i][j];
        }
    }
    dfs(5, 5, 5, 5, 5, total);
    cout << (result == INF ? -1 : result); // 처음에는 다 5개씩 갖고 있음
    return 0;
}