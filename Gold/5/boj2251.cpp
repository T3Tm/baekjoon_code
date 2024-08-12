#include <bits/stdc++.h>
using namespace std;
int x,y,z;
vector<int>result;
bool visited[202][202][202];
void xToy(int &q, int &w,int bound){
    w += q;//q -> w
    int w_variable = min(w,bound);
    q = w - w_variable;
    w = w_variable;
}
void restore(int &q, int &w,int &preq,int &prew){
    q = preq;
    w = prew;
}
void dfs(int a,int b, int c){
    visited[a][b][c]= 1;
    if(!a)result.push_back(c);
    int prea = a, preb =b ,prec =c;
    // prea -> b,c;
    xToy(a,b, y);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(a,b,prea,preb);

    xToy(a,c, z);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(a,c,prea,prec);

    //preb -> a, c
    xToy(b,a, x);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(b,a,preb,prea);

    xToy(b,c, z);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(b,c,preb,prec);

    //prec -> a, b
    xToy(c,a, x);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(c,a,prec,prea);

    xToy(c,b, y);
    if(!visited[a][b][c]){
        dfs(a,b,c);
    }
    restore(c,b,prec,preb);
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> x >> y >> z;
    dfs(0,0,z);

    sort(result.begin(),result.end());
    for(auto &v: result)cout << v << ' ';
    return 0;
}