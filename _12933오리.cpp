#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/12933
    오리
    울음 소리는 quack 이다. 올바른 소리는 한 번 또는 그 이상 내는 것이다.
    한 명이 울기 시작했는데 그게 끝나기도 전에 
    우는 것이 들린다면
    한 명씩 오리를 증가시켜줘야 한다.
    최대 오리는 2500마리까지 나올 수 있다.
    k가 들어오면 스택 안에 있는 값을 확인하여 quack이 되는지 확인한다.
    q가 들어오면 차례로 stack에 push
    k -> c -> a -> u -> q
    k를 만나면 stack에 c가 있는지 확인 없으면 -1 출력
    일단 스택에 다 넣는다 k를 만나면 하나씩 뺀다.
    k를 만나기 전에 만약 q가 연달아 들어왔으면 preduck을 하나 증가 시킨다.
*/
int main() {
    fast;
    int result = 0, preduck = 0;
    vector<char>duck;
    int visited[2501] = { 0 };
    string word;
    cin >> word;
    for (auto value : word) {
        if (value == 'q')preduck++;
        else if (value == 'k') {
            visited[duck.size()] = 1;
            map<char, int>check = { {'c',0},{'a',0},{'u',0},{'q',0} };
            int prevalue=-1;
            for (int idx = duck.size() - 1; idx >= 0; idx--) {
                if(!visited[idx])check[duck[idx]] = idx;
            }
            for (auto appear : {'c','a','u','q'}) {
                if (prevalue == -1) {
                    prevalue = check[appear];
                    visited[check[appear]]=1;
                    continue;
                }if (prevalue > check[appear]) {
                    prevalue = check[appear];
                    visited[check[appear]] = 1;
                }
                else {
                    result = -1;
                    goto Exit;
                }
            }
            preduck--;
        }
        duck.push_back(value);
        result = max(result, preduck);
    }
    for (int idx = 0; idx < word.length();idx++) {
        if (!visited[idx]) {
            result = -1;
            break;
        }
    }
Exit:
    cout << result;
    return 0;
}