#include <bits/stdc++.h>
using namespace std;
/*

*/  
int n;
void bact(int depth, string& result){
    if(depth == n){
        for(int i=0;i<n;i++){
            cout << result[i];
        }
        exit(0);
    }
    for(int plus=1;plus<4;plus++){
        if (depth != 0 && result[depth-1] - '0' == plus)continue;
        result[depth] = plus + '0';
        bool inner = 0;
        for(int slice=2;slice <= (depth + 1)/2;slice++){
            int start = (depth + 1) - slice;
            string compare1 = result.substr(start, slice);//마지막 slice개
            string compare2 = result.substr(start - slice, slice);//slice개
            if(compare1 == compare2){
                inner = 1;
                break;
            }
        }
        if(inner)continue;//이 경우에는 불가능
        //가능한 경우 그냥 temp로 해놓고 넘어가기
        bact(depth + 1 ,result);
        result[depth] = ' ';
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n;
    string result(81, ' ');
    bact(0,result);
    return 0;
}