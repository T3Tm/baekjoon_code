#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/14719
    14719번 빗물

    2차원 세계
    H : 세로
    W : 가로
    
    블럭 쌓인 것이 나옴.
*/
using namespace std;
int h,w,result;
int arr[502][502];
int idxvalue[502];
vector<pair<int,int>>value;//value,idx
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
int main(){
    fast;
    cin >> h >> w;
    for(int i=0;i<w;i++){
        int number;
        cin >> number;
        for(int j=0;j<=number;j++){
            arr[j][i]=1;
        }
        idxvalue[i]=number;
        value.push_back({number,i});
    }
    sort(value.begin(),value.end(),cmp);
    for(int i=1;i<w;i++){
        for(int idx=min(value[i].second,value[i-1].second)+1;idx<max(value[i].second,value[i-1].second);idx++){//2번째로 큰 수 에서 1번째로 큰 수의 인덱스 사이에 빗물 채우기.
            if(!arr[value[i].first][idx]){//이미 빗물 채워있으면 넣지 말기
                result+=(value[i].first-idxvalue[idx]);//빗물 채운 만큼 더해주기
                for(int j=idxvalue[idx];j<=value[i].first;j++){//빗물 채워놓기
                    arr[j][idx]=1;
                }
            }
        }
    }
    cout << result;
    return 0;
}