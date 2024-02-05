#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;

    // 초기에 -1e9값을 넣음으로써 예외처리를 따로 안 함
    vector<int> dp = {-MAX - 1};  // 최장 수열 담는 배열
    // 숫자 : 갯수
    unordered_map<int, long long> numberToCount = {{-MAX - 1, 1}};
    map<int, map<int, long long>> lisToNumber = {{0, {{-MAX - 1, 1}}}};

    // LIS길이 : {숫자들}

    for (int i = 0, num; i < n; i++) {  // n(lgn + lgn)
        cin >> num;
        auto it = lower_bound(dp.begin(), dp.end(), num);  // 들어가야 되는 포인터 갖고 오
        // lgn
        int index = it - dp.begin();  // 해당 인덱스 갖고 오기
        auto &lisToSet = lisToNumber[index - 1];
        auto iter = lisToSet.lower_bound(num);  // 나보다 하나 작은 lis 중
        // 큰 값
        // lgn
        auto frontNumber = lisToSet.begin();
        long long cnt = frontNumber->second;
        if (index == dp.size()) {                         // 내가 새로운 곳에 넣어야 한다.
            if (iter == lisToSet.end()) {                 // 모든 아이들을 다 갖고 가도 됨.
                numberToCount[num] = cnt;                 // lis길이
            } else {                                      // lis 하나 작은 아이들 중에서 현재 num보다 작은 아이들의 갯수만 가져가야함.
                numberToCount[num] = cnt - iter->second;  // lisToNumber
            }
            dp.push_back(num);
        } else {  // 이전에 값에 대해서 넣어야 한다.
            // 전에 있던 갯수 추가로 더해놓기
            int nowIndexValue = dp[index];
            long long nowIndexCount = lisToNumber[index][nowIndexValue];          // 이 갯수와 앞에 있는 갯수 추가로 나한테 다시 저장
            if (iter == lisToSet.end()) {                                         // 모든 아이들을 다 갖고 가도 됨.
                numberToCount[num] = (cnt + nowIndexCount) % MOD;                 // lis길이
            } else {                                                              // lis 하나 작은 아이들 중에서 현재 num보다 작은 아이들의 갯수만 가져가야함
                numberToCount[num] = (cnt - iter->second + nowIndexCount) % MOD;  // lisToNumber
            }
            dp[index] = num;  // 현재 인덱스에 나를 덮어쓰기
        }
        lisToNumber[index][num] = numberToCount[num];  // 현재 길이의 갯수 저장
    }
    cout << dp.size() - 1 << ' ' << (numberToCount[dp.back()] + MOD) % MOD;
    return 0;
}