#include <bits/stdc++.h>

using namespace std;
string n;
int k;
string result;
bool isEnd(const string & s){
    for(int i=0;i+1<s.size();i++){
        if(s[i] < s[i+1])return 0;
    }
    return 1;
}
void bact(int depth, string& tmp, int count){
    if(count == k){//더이상 못 사용함.
        result = max(result, tmp);
        return;
    }
    if(isEnd(tmp) || depth == tmp.size()){//해당 경로에서 더이상 뻗어 나가지 않아도 됨.
        if((k - count)%2){//1개 남았을 때는
            //같은 것이 있는지 판단 내리자. 있다면 그거 바꾸면됨.
            //없다면 마지막에 두 수를 바꿔야함.
            for(int i=0;i+1<tmp.size();i++){
                if(tmp[i] == tmp[i+1]){
                    result = max(result, tmp);
                    return;
                }
            }
            //없기 때문에 마지막 두 수 바꾸기
            swap(tmp[tmp.size() - 1], tmp[tmp.size() - 2]);
            result = max(result, tmp);
            swap(tmp[tmp.size() - 1], tmp[tmp.size() - 2]);
        }else{
            result = max(result, tmp);
        }
        return;
    }
    
    vector<int>next;
    for(int j = depth + 1; j<tmp.size();j++){
       if(tmp[depth] >= tmp[j])continue;

        if(!next.empty()){
            if(tmp[next[0]] < tmp[j]){
                next = vector<int>{j};
            }else if(tmp[next[0]] == tmp[j]){
                next.push_back(j);
            }
        }else{
            next.push_back(j);
        }
        
    }
    if(next.empty()){
        bact(depth + 1, tmp, count);
    }else{
        for(int idx: next){
            swap(tmp[idx], tmp[depth]);
            bact(depth+1, tmp, count+1);
            swap(tmp[idx], tmp[depth]);
        }
    }
    
}
int main(){
    cin >> n >> k;
    
    if(n.size() == 1)result = "-1";
    else if(n.size() == 2 && n[1] == '0')result = "-1";
    else{
        string tmp = n;
        bact(0, tmp, 0);  
    } 
    cout << result;
    return 0;
}