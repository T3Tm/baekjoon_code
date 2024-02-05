#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr)
/*
 https://www.acmicpc.net/problem/25556
 25556번 포스택
 
 순열 A의 원소들을 앞 원소부터 순서대로 네 개의 스택 중
 하나에 넣는다.
 넣을 때 그럼 오름차순으로 넣으면 되겠네
 4(6,7,8,9,10), 3,5 , 2 ,1
 
 9
 8
 7
 6
 4 3
 0,0,0,0
*/
using namespace std;
int n;
int main() {
    fast;cin >> n;
    int arr[4]{};
    for(int i=1;i<=n;i++){
        int num;cin >> num;
        if(arr[0]<num)arr[0]=num;
        else if(arr[1]<num)arr[1]=num;
        else if(arr[2]<num)arr[2]=num;
        else if (arr[3]<num)arr[3]=num;
        else{
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    return 0;
}
