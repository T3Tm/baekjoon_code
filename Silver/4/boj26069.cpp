#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    
    set<string> names{"ChongChong"};
    
    while(n--){
        string f1,f2; 
        cin >> f1 >> f2;
        if(names.count(f1)){
            names.insert(f2);
        }else if(names.count(f2)){
            names.insert(f1);
        }
    }

    cout << names.size();
    return 0;
}