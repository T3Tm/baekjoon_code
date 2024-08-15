#include <bits/stdc++.h>
using namespace std;
int arr[3];
unordered_set<string>visited;
int full = (1 << 9) - 1;

void LeftRight(int& b, int i, int j){
    int ba = (full << (9 * (2 - i))) & b;
    int bb = (full << (9 * (2 - j))) & b;

    int t = 0;
    t |= ba >> 9;
    t |= bb << 9;


    t |= (full << (9 * (i+j-1))) & b;
    b = t;
}
void UpDown(int &a, int& b, int j){
    int ta = (full << (9 * (2 - j))) & a;
    int tb = (full << (9 * (2 - j))) & b;
    b &= (~tb);
    a &= (~ta);
    swap(ta,tb);
    b |= tb;
    a |= ta;
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        int v; cin >> v;
        arr[i]|= (1 << v) << (9 * (2 - j));
    }
    
    queue<tuple<int,int,int, int>>q;

    visited.insert(to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]));

    q.push({arr[0],arr[1],arr[2], 0});
    int result[]{
        ((1 << 1) << 18) | ((1 << 2) << 9) | (1 << 3),
        ((1 << 4) << 18) | ((1 << 5) << 9) | (1 << 6),
        ((1 << 7) << 18) | ((1 << 8) << 9) | (1 << 0)
    };

    
    int dx[]{-1,0,1,0};
    int dy[]{0,1,0,-1};
    while(!q.empty()){
        auto[a,b,c, d] = q.front();q.pop();
        if(result[0] == a && result[1] == b && result[2] == c){
            cout << d;
            exit(0);
        }

        int temp[]{a,b,c};
        
        bool flag{1};
        for(int i=0;i<3 && flag;i++){
            for(int j=0;j<3 && flag;j++){

                if(!(temp[i] & (1 << (9 *(2-j)))))continue;
                flag = 0;
                for(int z{};z<4;z++){
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    if(nx < 0 || nx>= 3 || ny < 0 || ny >= 3)continue;
                    if(z & 1){
                        LeftRight(temp[i], min(j, ny), max(ny,j));
                    }else{
                        UpDown(temp[i], temp[nx], j);
                    }
                    
                    if(visited.count(to_string(temp[0]) + to_string(temp[1]) + to_string(temp[2]))){
                        temp[0] = a;
                        temp[1] = b; 
                        temp[2] = c;
                        continue;
                    }
                    visited.insert(to_string(temp[0]) + to_string(temp[1]) + to_string(temp[2]));
                    q.push({temp[0],temp[1],temp[2], d + 1});
                    temp[0] = a;
                    temp[1] = b;
                    temp[2] = c;
                }
            }
        }
    }
    cout << -1;
    return 0;
}