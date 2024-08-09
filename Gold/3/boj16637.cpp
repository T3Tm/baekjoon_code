#include <bits/stdc++.h>
using namespace std;
int n;
string express;
int result{1 << 31};

int cal(int number, char op, int plus){
    int ret = number;
    switch (op)
    {
    case '+':
        ret += plus;
        break;
    case '-':
        ret -= plus;
        break;
    case '*':
        ret *= plus;
        break;
    default:
        ret /= plus;
        break;
    }
    return ret;
}

void bact(int depth, int num,bool flag, int pre){
    if(depth == n/2){
        result = max(result,num);
        return;
    }
    if(flag && depth){
        int cals = cal(express[depth*2] -'0', express[depth *2 + 1],express[depth *2 + 2] - '0');
        bact(depth+1,cal(pre, express[(depth-1)*2 + 1],cals), 0,num);
    }
    bact(depth+1,cal(num,express[depth * 2 + 1],express[depth * 2 + 2]-'0'),1,num);
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> express;
    bact(0,express[0] - '0',1, 0);
    cout << result;
    return 0;
}