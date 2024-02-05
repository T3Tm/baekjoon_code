#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/16435
 * 16435번 스네이크버드
 * 자신의 길이보다 작거나 같은 높이에 있는 과일들을 먹을 수 있다.
 * 처음 길이가 L일때 과일 들을 먹어 늘릴 수 있는 최대 길이 구하시오.
 * 그리디 문제
 * 1. arr를 정렬 시켜서
 * 2. 작은 것부터 하나씩 먹으면 되겠네
*/
using namespace std;
int n,l;
int arr[1002];
int main(){
    fast;
    cin >> n >> l;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]<=l){
            l++;
        }else{
            break;
        }
    }
    cout << l;
    return 0;
}