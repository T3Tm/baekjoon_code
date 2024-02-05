#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/19949
    19949번 영재의 시험
    
    5개중 한 개 선택
    10문제 

    5C1 * 10
    
    3개의 연속된 문제의 답은 같지 않게 한다.


    영재의 점수가 5점 이상일 경우의 수를 구하여라.

    1문제 == 1점
    
    재귀 + 백트래킹 문제같다.

    모든 경우의 수 5^10 == 약 9백만
*/
using namespace std;
int arr[11];
int result;
void youngjaeTest(int depth,int exceptNum,int preNumber,int score){//재귀 깊이 최대 10
    if(depth == 10){
        if(score>=5)result++;
        return;
    }
    for(int i=1;i<=5;i++){
        if(exceptNum==i)continue;
        if(preNumber==i){//다음에 i는 뽑으면 안됨.
            youngjaeTest(depth+1,i,i,(arr[depth]==i ? score+1 : score));
        }else{//연속으로 뽑은 거 아님
            youngjaeTest(depth+1,0,i,(arr[depth]==i ? score+1 : score));
        }
    }
    
}
int main(){
    fast;
    for(int i=0;i<10;i++)cin >> arr[i];//문제 정답
    youngjaeTest(0,0,0,0);
    cout << result;
    return 0;
}