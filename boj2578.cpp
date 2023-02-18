#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/2578
    2578번 빙고
*/
using namespace std;
vector<pair<int,int>>graph(26,pair<int,int>(0,0));
int binggo[6][6];
int width(){
    int cnt=0;
    for(int i=0;i<5;i++){
        int inner=0;
        for(int j=0;j<5;j++){
            if(!binggo[i][j])inner++;
        }
        if(inner==5)cnt++;
    }
    return cnt;
}
int height(){
    int cnt=0;
    for(int j=0;j<5;j++){
        int inner=0;
        for(int i=0;i<5;i++){
            if(!binggo[i][j])inner++;
        }
        if(inner==5)cnt++;
    }
    return cnt;
}
int diagonal(){
    int cnt=0,inner=0;
    for(int row=0,column=0;row<5 && column<5;row++,column++){
        if(!binggo[row][column])inner++;
    }
    if(inner==5){
        cnt++;
    }
    inner=0;
    for(int row=0,column=4;row<5 && column>=0;row++,column--){
        if(!binggo[row][column])inner++;
    }
    if(inner==5){
        cnt++;
    }
    return cnt;
}
int main(){
    fast;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> binggo[i][j];
            graph[binggo[i][j]]={i,j};
        }
    }
    int result=0;
    bool flag=true;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp;
            cin >> temp;
            if(flag){
                int x=graph[temp].first;
                int y=graph[temp].second;
                binggo[x][y]=0;
                if(diagonal() + height() + width()>=3){
                    result=i*5+(j+1);
                    flag=false;
                }
            }
        }
    }
    cout << result;
    return 0;
}