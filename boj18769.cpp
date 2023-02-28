#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/18769
    18769번 그리드 네트워크
*/
using namespace std;
int parent[500*500+2];
priority_queue<pair<int,pair<int,int>>>graph;

int find(int a){
    if (parent[a]==a)return a;
    return parent[a]=find(parent[a]);
}
void Union(int x,int y){
    int a=find(x);
    int b=find(y);
    if (a<b)parent[b]=a;
    else parent[a]=b;
}
int main(){
    fast;
    int T;
    cin >> T;
    while(T--){
        int r,c;
        cin >> r >>c;
        for(int i=0;i<r*c;i++)parent[i]=i;
        for(int row=0;row<r;row++){
            for(int column = 0;column<c-1;column++){
                int value;
                cin >> value;
                graph.push({-value,{c*row+column,c*row+column+1}});
            }
        }
        for(int row=0;row<r-1;row++){
            for(int column = 0;column<c;column++){
                int value;
                cin >> value;
                graph.push({-value,{c*row+column,c*row+column+c}});
            }
        }
        long long total=0,cnt=0;
        while(1){
            auto next=graph.top();graph.pop();
            int value=-next.first;
            auto loc = next.second;
            if(find(loc.first)!=find(loc.second)){
                Union(loc.first,loc.second);
                total+=value;
                cnt++;
            }
            if (cnt == r*c-1)break;
        }
        cout << total << endl;
    }
    return 0;
}