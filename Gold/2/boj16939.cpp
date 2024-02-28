#include <bits/stdc++.h>
using namespace std;
/*
    https://www.acmicpc.net/problem/16939
    16939번 2x2x2큐브

    큐브를 돌릴 수 있는 것은
    왼쪽 오른쪽
    위 아래

    앞으로 한 칸 3번
*/
// 4개씩 확인하면서 맞는지 확인 해야 된다.
bool isPossible(int now[])
{
    for (int i = 1; i < 22; i += 4)
    {
        if (now[i] != now[i + 1] || now[i + 1] != now[i + 2] || now[i + 2] != now[i + 3])
            return false;
    }
    return true;
}
int cmd[][8]
{
    {23, 21, 2, 4, 6, 8, 10, 12}, //left 0
        {24, 22, 1, 3, 5, 7, 9, 11},//right 1
        {13, 14, 5, 6, 17, 18, 21, 22}, //front
        {15, 16, 7, 8, 19, 20, 23, 24},//back
        {1 , 2 , 18 , 20 , 12 ,11, 15 , 13}, //top
        {3 , 4 , 17 , 19 , 10 , 9 , 16 , 14} // bottom
};
void spin(int now[],int num)
{
    //
    int temp = now[cmd[num][0]];
    int i=0;
    for(;i+1<8;i++){
        now[cmd[num][i]] = now[cmd[num][i+1]];
    }
    now[cmd[num][i]] = temp;
}
int main()
{
    int cube[25]{};
    int res = 0;
    for (int i = 1; i <= 24; i++)
        cin >> cube[i];
    for(int i=0;i<6;i++){
        spin(cube,i);//8번
        spin(cube,i);
        if(isPossible(cube)){//6번
            res++;
            break;
        }
        spin(cube,i);
        spin(cube,i);
        spin(cube,i);
        spin(cube,i);
        if(isPossible(cube)){
            res++;
            break;
        }
        spin(cube,i);
        spin(cube,i);
    }
    cout << res;
    return 0;
}