#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    string t; cin >> t;
    string word = "#";
    for(auto &v: t){
        word.push_back(v);
        word.push_back('#');
    }

    int n = word.size();

    vector<int>A(n);
    int r=-1,q=-1;
    for(int i=0;i<n;i++){
        if(r>=i){
            int ii = 2 * q - i;
            A[i] = min(r - i, A[ii]);
        }
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && word[i + A[i] + 1] == word[i - A[i] - 1]){
            A[i]++;
        }

        if (i + A[i] > r){
            r = i + A[i], q = i;
        }
    }

    int ans{};
    for(int i=0;i<n;i++){
        ans = max(ans, A[i]*2 + 1);
    }
    cout << ans / 2;
    return 0;
}