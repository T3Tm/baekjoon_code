#include <iostream>
#include <vector>
using namespace std;
bool board[32][12];
int n,m,h;
struct Pair{
    int x,y;
};
vector<Pair>pick;

int result = 4;
bool calc(){
    for(int j=1;j<=n;j++){
        int now_h = 1,now_j = j;
        while(now_h <= h){
            if(board[now_h][now_j]){
                now_j++;
            }else if(board[now_h][now_j-1]){
                now_j--;
            }
            now_h++;
        }

        if(now_j != j)return false;
    }
    return true;
}

void bact(int depth, int pre){
    if(calc()){
        result= min(result, depth);
        return;
    }
    if(depth == min(3,(int)pick.size()))return;

    for(int i=pre;i<pick.size();i++){
        auto[x,y] = pick[i];
        if(board[x][y-1])continue;
        board[x][y] = 1;
        bact(depth + 1 , i+1);
        board[x][y] = 0;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> h;
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        board[a][b] = 1;
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j-1] || board[i][j])continue;
            pick.push_back({i,j});
        }
    }

    
    bact(0,0);
    cout << (result == 4 ? -1 : result);   
    return 0;
}