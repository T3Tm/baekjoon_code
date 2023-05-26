#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr)
/*
 https://www.acmicpc.net/problem/27931
 27931번 Parity Constraint Closest Pair (Easy)
 홀수, 짝수
 홀수 - 홀수 = 짝수
 짝수 - 짝수 = 짝수
 짝수 - 홀수 = 홀수
 x,x1,x2,x3 홀수
 y,y1,y2,y3 짝수
 
 
 */
using namespace std;
int main() {
    fast;
    int n;cin >> n;
    vector<int>h,z,r;
    for(int i=0;i<n;i++){//50만번
        int num;cin >> num;
        if(num&1)h.push_back(num);
        else z.push_back(num);
        r.push_back(num);
    }
    sort(h.begin(),h.end());//nlgn50만번
    sort(z.begin(),z.end());//nlgn50만번
    sort(r.begin(),r.end());//50만번
    long long a,b=a=1e10;
    for(int i=1;i<h.size();i++)a=min((long long)h[i]-h[i-1],a);
    for(int j=1;j<z.size();j++)a=min((long long)z[j]-z[j-1],a);
    int front=0;
    for(int i=1;i<n && front <n;i++){//n번
        if(r[i]%2){//홀수 , front가 가리키는 것이 짝수 여야함.
            while(front < i && r[front]%2!=0)front++;
            if(front==i)continue;
            b=min(b,(long long)abs(r[i]-r[front]));
            if(r[i]%2!=r[i-1]%2)b=min(b,(long long)r[i]-r[i-1]);
        }else{//짝수 , front가 가리키는 것이 홀수 여야 함
            while(front < i && r[front]%2==0)front++;
            if(front==i)continue;
            b=min(b,(long long)abs(r[i]-r[front]));
            if(r[i]%2!=r[i-1]%2)b=min(b,(long long)r[i]-r[i-1]);
        }
    }
    cout << (a==1e10 ? -1 : a) << ' '<< (b==1e10 ? -1 : b);
    return 0;
}
