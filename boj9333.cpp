#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/9333
    9333번 돈 갚기

    B달러 빌림
    매월 초에 금액의 R퍼센트의 이자가 붙음

    상근이는 매월 말에 과외비 M달러를 받음
    M을 선영이에게 갚을 수 있음.
    
    돈을 갚는데 몇 달 걸리는지 구해주세요.
    
    이자는 가까운 센트로 반올림한다.
    100센트는 1달러
    0.5센트보다 크거나 같은 경우 1센트로 올림,
    나머지는 버림

    금액 * 
    R<=50.00 
    R*100을 하고 int처리하면 소숫점 2번째 자리까지 나옴.
    R<=5000 일 것이고
    B,M<= 50000.00 이면 *100 해서 
    B,M<=5000000 이다.
    R퍼센트는0.01을 곱하는 것이다.
    
    200 *0.01 *0.01 해야됨 강제로 100을 곱했었으니까
    금액*0.02

    100
    0.5 센트부터 1센트, 2센트 
*/
using namespace std;
int t;
long long input(){
    long long a=0,b=0,r=0;
    string temp;
    bool flag=true;
    cin >> temp;
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='.'){
            flag=false;
            continue;
        }
        if(flag){
            a=a*10+(temp[i]-'0');
        }else{
            b=b*10+(temp[i]-'0');
        }
    }
    r=a*100+b;
    return r;
}
int main(){
    fast;
    cin >> t;
    while(t--){
        int month=0;
        long long r=input(),b=input(),m=input()*100;
        for(int i=1;i<=1200;i++){
            long long value=(r*b)/100;
            if((value%100)/10>=5){
                value=value-(value%100)+100;
            }else{
                value=value-(value%100);
            }
            if(value>=m){
                break;
            }
            b=b*100+value;
            b-=m;
            if(b<=0){
                month=i;
                break;
            }
            b/=100;
        }
        if(month){
            cout << month << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
    return 0;
}