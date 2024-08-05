#include <bits/stdc++.h>
using namespace std;
int dx[]{-1,-1,-1,0,0,1,1,1};
int dy[]{-1,0,1,-1,1,-1,0,1};
int bombConfirm(vector<vector<char>> &board, int x, int y){
    int boundary = board.size();
    
    int ret{};
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= boundary || ny < 0 || ny>=boundary)continue;
        if(board[nx][ny] == '.')continue;
        ret += board[nx][ny] - '0';
    }

    return ret;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    vector<vector<char>> board(n);
    for(auto &row: board){
        string a; cin >> a;
        for(int i=0;i<a.size();i++)row.push_back(a[i]);
    }

    vector<vector<char>> result(n, vector<char>(n,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] >= '1' && board[i][j] <= '9'){
                result[i][j] = '*';//폭탄으로
            }else{
                //그러면 8개로 몇 개 있는지 확인.
                int bombNumber = bombConfirm(board, i, j);
                if(bombNumber > 9) result[i][j] ='M';
                else result[i][j] = bombNumber + '0';
            }
        }
    }

    for(auto &row : result){
        for(auto &column : row)cout << column;
        cout << "\n";
    }

    return 0;
}