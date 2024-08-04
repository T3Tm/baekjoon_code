#include <bits/stdc++.h>
using namespace std;
/*
(H)2(0)
*/
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    string words;
    cin >> words;

    int alpha[26]{};
    alpha['H' - 'A'] = 1;
    alpha['C' - 'A'] = 12;
    alpha['O' - 'A'] = 16;

    stack<int> s;
    for(auto& word: words){
        if(word == '('){
            s.push('(');
        }else if(word == ')'){
            int cal{};
            while(s.top() != '('){
                int top = s.top();
                cal += top;
                s.pop();
            }
            s.pop();
            s.push(cal);
        }else if(isalpha(word)){
            s.push(alpha[word - 'A']);
        }else{//숫자
            int top = s.top();
            s.pop();
            s.push(top * (word - '0'));
        }
    }
    
    int result{};

    while(!s.empty()){
        result += s.top();
        s.pop();
    }

    cout << result;
    return 0;
}