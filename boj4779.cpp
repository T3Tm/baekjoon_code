#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/4779
    4779번 칸토어 집합
    3^12은 0~3^12의 인덱스까지 출력
    3^11은 0~3^11의 인덱스까지 출력

    3
    1,2,3
    0,1,2
    (End-Front+1)/3
    한 구간에 몇개씩 넣어야되는지 나옴
    123456789 

    
*/
using namespace std;
vector<char>result;
map<int,int>convert={{0,1},{1,3},{2,9},{3,27},{4,81},{5,243},{6,729},{7,2187},{8,6561},{9,19683},{10,59049},{11,177147},{12,531441}};
void saveset(int depth,char chr,int Front,int End){//일단 range를 받아야될듯
    if(depth==1){//더이상 3개로 못 쪼갬.
        result.push_back(chr);
        return;
    }
    int value=(End-Front+1)/3;
    saveset(depth-1,chr,Front,Front+value-1);
    saveset(depth-1,' ',Front+value,Front+value*2-1);
    saveset(depth-1,chr,Front+value*2,End);
}
int number;
int main(){
    fast;
    saveset(13,'-',1,531441);
    while(cin >> number){
        for(int i=0;i<convert[number];i++){
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}