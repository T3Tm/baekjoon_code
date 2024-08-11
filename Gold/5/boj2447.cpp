#include <bits/stdc++.h>
using namespace std;
int n;
/*
    table1table2table3
    table4table5table6
    table7table8table9
*/
void boj(int x, int y, int depth){
    if(depth == 3){
        if(x == 1 && y == 1)cout << ' ';
        else cout << '*';
        return;
    }
    //어디로 갈지 정하기 
    //9개의 공간으로 나누기
    int row = depth / 3;
    if(x < row){
        if(y < row){//table 1
            boj(x,y,depth/3);
        }else if(y < row * 2){//table 2
            boj(x,y-row,depth/3);
        }else {//table 3
            boj(x,y-(row * 2),depth/3);
        }
    }
    else if(x < row * 2){
        if(y < row){//table 4
            boj(x - row,y,depth/3);
        }else if(y < row * 2){//table 5
            //여기에 해당되면 그냥 다 출력하면 안됨.
            cout << ' ';
        }else {//table 6
            boj(x - row,y - (row * 2),depth/3);
        }
    }
    else{
        if(y < row){//table 7
            boj(x - (row * 2),y,depth/3);
        }else if(y < row * 2){//table 8
            boj(x - (row * 2),y - row,depth/3);
        }else {//table 9
            boj(x - (row * 2),y - (row * 2),depth/3);
        }
    }

}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            boj(i,j,n);
        }
        cout << '\n';
    }
    return 0;
}