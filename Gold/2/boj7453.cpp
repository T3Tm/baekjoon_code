#include <bits/stdc++.h>
using namespace std;
/*
*/
int A[4002],B[4002],C[4002],D[4002];
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n; // <=4000

    
    for(int i=0;i<n;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }    
    
    vector<int>ab;
    for(int i=0;i<n;i++){//배열 A에 있는 숫자 중 하나를 뽑는다.
        for(int j=0;j<n;j++){
            ab.push_back(A[i] + B[j]);
        }
    }
    sort(ab.begin(), ab.end());

    long long cnt{};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto endIter = upper_bound(ab.begin(),ab.end(), -(C[i] + D[j]));
            auto beginIter = lower_bound(ab.begin(),ab.end(), -(C[i] + D[j]));

            cnt += endIter - beginIter;
        }
    }

    cout << cnt;
    return 0;
}