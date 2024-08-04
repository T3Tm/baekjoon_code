#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<long long>array;

    for(int i=0;i<n;i++){
        string num, transNumber{}; cin >> num;
        auto iter = num.rbegin();
        while (*iter == '0')iter++;
        while (iter != num.rend()){
            transNumber.push_back(*iter);
            iter++;
        }
        array.push_back(stoll(transNumber));
    }
    sort(array.begin(),array.end());
    for(auto& v: array)cout << v << '\n';
    return 0;
}
