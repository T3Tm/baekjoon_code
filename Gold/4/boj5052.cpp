#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<string> arr(n);
        for(auto&v: arr)cin >> v;
        sort(arr.begin(), arr.end());

        unordered_set<string> save;
        for(int i=0;i<n;i++){
            string &v = arr[i];//
            
            string tmp;
            for(auto &ch: v){
                tmp.push_back(ch);
                if(save.count(tmp)){
                    break;
                }
            }

            if(tmp.size() != v.size()){
                break;
            }
            save.insert(v);
        }

        if(save.size() == n){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}