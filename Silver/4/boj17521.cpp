#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/17521
 * 17521번 Byte Coin
 * 0.5초 문제 (5천만번 연산 가능)
 * 
 * 
 * 가격 등락을 예측할 수 있다.(정확히)
 * 
 * 
 * 결론 => N일 (마지막 날) 보유하고 있는 모든 코인을 매도하여 현금을 최대화하고 싶다.
 * 


 * 풀이 => 내가 생각했을 때는 저점일 때 사고 고점일 때 파는 것도 중요하지만
    젤 중요한 것은 있는 코인을 나눠서 판매할 수 없기에 언제 사고 언제 파는 지가 중요할 듯

    1. 그래프가 아래에서 위로 꺾일 때 산다.
    2. 그래프가 위에서 아래로 꺾일 때 판다.

    1. 
    
    최대 나올 수 있는 금액: 78,125,000,000,000,000 (7경)
    long long 자료형 같은 경우 922경까지 담을 수 있음.
    
*/
using namespace std;
int n;
vector<int>arr;
long long w,bought;//bought : coinNumber
bool UpAndDown;//up : true , down : false(현재 증가하는지, 감소하는지)
int main(){
    fast;
    cin >> n >> w;
    arr.resize(n);
    for(int i=0;i<n;i++)cin >> arr[i];
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){//전보다 커졌는지
            if(!UpAndDown){//감소했었던 것, 지금 구매 해야됨.
                bought = w/arr[i-1];//얼마나 구매할 수 있는지.
                w-=bought*arr[i-1];//현재 금액 빼기
            }
            UpAndDown=true;
        }else{//전보다 작거나 같아졌는지
            if(UpAndDown){//증가했던 것
                long long sell = bought*arr[i-1];
                w+=sell;
                bought=0;
            }
            UpAndDown=false;
        }
    }
    if(bought)w+=bought*arr[n-1];
    cout << w;
    return 0;
}