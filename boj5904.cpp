#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/5904
    5904 Moo 게임
    S(k) = S(k-1) + m + o*(k+2) + S(k-1)
    n이라는 숫자가 입력 되면 
    S(k) 에서 어디인지 일단 찾는다.
     수열의 길이는 1073741792 이다.
    S(26) = S(25) + m + o*28 + S(25)
    S(27) = S(26) + m + o*29 + S(26) 개 있는 것이다.
    예를 들어서 내가 53번째 글자가 무엇인지 알고 싶다면
    S(0) = 3
    S(1) = 10
    S(2) = 10 + 5 + 10 
    S(3) = 25 + 6 + 25 (10 + 5 + 10)
    
*/
using namespace std;
int arr[31]={3};
void ThreeSplit(int depth,int n){
    if(depth==0){
        vector<char>result={'m','o','o'};
        cout << result[n-1];
        exit(0);
    }
    if(n<=arr[depth-1]){//arr[k-1] 부분임
        ThreeSplit(depth-1,n);
    }else if(n<=arr[depth-1]+depth+3){//m+o*k+2 이 부분임.
        vector<char>result={'m'};
        for(int i=0;i<depth+2;i++){
            result.push_back('o');
        }
        n-=arr[depth-1];
        cout << result[n-1];
        exit(0);
    }else{//나머지는 arr[k-1]이 부분임.
        ThreeSplit(depth-1,n-(arr[depth-1]+depth+3));
    }
}
int main(){
    fast;
    int n;//1<=N<=10^9
    cin >> n;
    for(int i=1;i<=27;i++){
        arr[i]=2*arr[i-1]+i+3;
    }
    ThreeSplit(27,n);
    return 0;
}