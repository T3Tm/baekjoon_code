#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1713
    1713번 후보 추천하기
    1. 사진틀은 비어있음.
    2. 추천 받은 학생은 사진틀에 게시돼야함.
    3. 가장 추천 적게 받은 학생의 사진을 삭제하고 동일한 추천수가 있다면 가장 오래된 사진을 삭제
    4. 추천받은 횟수만 증가시킨다.
    5. 게시된 사진이 삭제되면 추천 0으로 초기화

    1<=학생 번호<=100
    총 추천 횟수 1000이하

    우선순위큐로 넣어서 관리
    번호가 같은 것이 들어가있을 수 있음.
    그러면 번호같은 경우
*/
using namespace std;
int n,recommand;
vector<pair<int,int>>arr(102,pair<int,int>(0,0));
int main(){
    fast;
    cin >> n >> recommand;
    int cnt=0;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        if(arr[number].first!=0){
            arr[number].first++;
        }else{
            arr[number].first++;
            arr[number].second=i;
            cnt++;
        }
    }
    for(int idx=n;idx<recommand;idx++){
        int number;
        cin >> number;
        if(arr[number].first!=0){//추천 받은 적 있을 때
            arr[number].first++;
        }else{//추천 받은 적 없어서 들어가는 상황
            if(cnt>=n){//안에 있는 것중 젤 작은 것 중 오래된 거 빼야됨.
                pair<int,int>value_idx(1002,1002);//추천수, 언제 들어갔는지
                int idx=0;
                for(int i=1;i<=100;i++){//100
                    if(arr[i].first==0)continue;
                    if(value_idx.first>arr[i].first){
                        value_idx=arr[i];
                        idx=i;
                    }else if(value_idx.first==arr[i].first && value_idx.second>arr[i].second){//같으면
                        value_idx=arr[i];
                        idx=i;
                    }
                }
                arr[idx]={0,0};//초기화
                cnt--;//한 개 줄었으니 줄이기.
            }
            arr[number].first++;
            arr[number].second=idx;
            cnt++;
        }
    }
    for(int i=1;i<=100;i++){
        if(arr[i].first!=0){
            cout << i << ' ';
        }
    }
    return 0;
}