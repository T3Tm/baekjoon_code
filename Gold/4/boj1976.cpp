#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n,m; cin >> n >> m;
    int dist[202][202]{};
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dist[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j)continue;
                if(dist[i][k] && dist[k][j]){
                    dist[i][j] = 1;//갈 수 있음
                }
            }
        }
    }

    bool flag = true;
    if(m){
        int first ;cin >> first;
        for(int i=0;i<m-1;i++){//
            int next; cin >> next;
            if(first == next)continue;
            else if(!dist[first][next]){
                flag= false;
                break;
            }
            first = next;
        }
    }
    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}