#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/25644
 * 25644번 최대 상승
 * 
 * N일 동안 회사 주가가 변하는지 예측 가능
 * 적당한 시점에 팔아서 최대한 이득을 볼 것이다. << 그리디
 * a1~an 배열 주어짐.
 * i번째에 사고, j번쨰에 판다면
 * aj-ai만큼 이득을 얻을 수 있음.
 * 
 * 
 * 주가가 아무리 높아도 주식을 살 수 있음.
 * 또한 사자마자 바로 팔 수 있다. << 무슨 의미지..(그럼 안 사면 되잖아)
 * 이것의 의미가 정답이 음수가 될 수 없고 무조건 0이 최소라는 거네.
 * 
 * 결론은 주식의 한 주를 적당한 시점에서 사고 어느 시점에서 팔아야 최고 이득이니?
 * stack 값을 넣는다. 다음 값이 작으면 stack 값 뺀다.
 * 
*/
using namespace std;
int n;
int arr[200002];//최대 10^9까지 이므로 int 자료형 가능
int result;
int main(){
    fast;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int minvalue=arr[0];
    for(int i=1;i<n;i++){
        if(minvalue < arr[i]){//큰 값이 들어오면 계산한다.
            result=max(result,arr[i]-minvalue);
        }
        minvalue=min(minvalue,arr[i]);//최솟값 저장
    }
    cout << result;
    return 0;
}