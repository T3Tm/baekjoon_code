#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
    https://www.acmicpc.net/problem/10421
    수식 완성하기
            * * * * *
                * * *
                 
            * * * * *
          * * * * *
        * * * * * 15개 + 8개 = 23개 + 8개 = 31개
      * * * * * * * *
      4<=N<=6
      최대 6줄? 그럼 들어갈 수 있는 형태가 뭐가 
      A를 다 뽑고
      B는 하나씩 뽑을 때 그 숫자를 확인 숫자를 확인했을 때 할 수 없는 숫자라면 바로 접음.
*/
vector<int>line, numbers;
int answer;
int check(int N,int idx) {
    if (to_string(N).length() != line[idx])return 1;//길이 다르면 1리턴
    while (N) {
        int compare = N % 10;
        vector<int>::iterator it = find(numbers.begin(), numbers.end(), compare);
        if (it == numbers.end()) {//이런 숫자가 없어도 1리턴
            return 1;
        }
        N /= 10;
    }
    return 0;
}
void pickB(int depth,int result,int A) {//B숫자 뽑기
    if (depth == line[1]) {
        if (!check(result * A, depth + 2))answer++;
        return;
    }
    for (auto value : numbers) {
        int next = value * pow(10, depth) + result;
        if (check(value*A,depth+2))continue;
        pickB(depth + 1, next ,A);
    }
}
void pickA(int depth,int result) {//A숫자 뽑기 맨 뒤 숫자부터 뽑는 걸로 하자
    if (depth == line[0]) {//A다 뽑았어요 2,4,6,8,9
        pickB(0,0,result);
        return;
    }
    for (auto value : numbers) {//A뽑기
        pickA(depth + 1, value * pow(10, depth) + result);
    }
}
int main() {
    fast;
    int n,k;
    cin >> n;
    line.resize(n);
    for (int i = 0; i < n; i++)cin >> line[i];
    cin >> k;
    numbers.resize(k);
    for (int i = 0; i < k; i++)cin >> numbers[i];//2,4,6,8,9
    pickA(0, 0);
    cout << answer;
    return 0;
}