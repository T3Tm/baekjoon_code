#include <bits/stdc++.h>
using namespace std;
/*
    A ~ Z
    1 ~ 26
    a ~ z
    27 ~ 52

    10920
*/
unordered_map<string, int>numToInt;
int idx;
int parent[200002];
int parentSize[200002];
int find(int cur)
{
    if (parent[cur] < 0)
        return cur;
    return parent[cur] = find(parent[cur]);
}

void merg(int a, int b)
{
    a = find(a); // 양수
    b = find(b); // 양수

    if (a == b)
        return;
    if (b > a)
    {
        swap(a,b);
    }
    parentSize[b] += parentSize[a];
    parent[b] += parent[a];
    parent[a] = b;
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        /*
            2명 이름 받기
        */
        memset(parent,-1,sizeof parent);
        fill(parentSize,parentSize+200002, 1);
        idx = 0;
        numToInt.clear();
        for (int i = 0; i < n; i++)
        {
            string first, second;
            cin >> first >> second;
            if (!numToInt.count(first))numToInt[first] = idx++;
            if (!numToInt.count(second))numToInt[second] = idx++;
            merg(numToInt[first], numToInt[second]); // O(1)
            int parentIdx = find(numToInt[first]);
            cout << parentSize[parentIdx] << '\n';
        }
    }
    // 1 3
    // 1
    return 0;
}