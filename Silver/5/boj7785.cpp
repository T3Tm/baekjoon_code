#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n; cin >> n;
    set<string, greater<string>> save;
    
    while(n--){
        string name, enterOrLeave;
        cin >> name >> enterOrLeave;
        
        if(enterOrLeave[0] == 'e'){
            save.insert(name);
        }else{
            save.erase(name);
        }
    }


    for(auto &name: save)cout << name << '\n';
    
    return 0;
}