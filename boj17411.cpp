#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/17411
  17411번 가장 긴 증가하는 부분 수열 6
 10 50 20 20 10 40 10 50 30 30 20 40 40 50 20 20 40 10 50 30
 1  2  2  2  1  3  1  4  3  3  2  4  4  5  2  2  4  1  5  3
                         2  2     it.second
*/
using namespace std;
const int MOD =1e9+7;
int arr[1000000], dp[1000000], n;
vector<int>dps{ -1000000001 };//dp를 구하는 배열
map<int,map<int,int>>cnt{{0,{{-1000000001 ,1}}}};//dp 길이 : {arr[i] : 갯수}
long long answer;
int main() {
    fast; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;//해당 인덱스에 숫자 저장.
        if (dps.back() < num) {//단순히 크면 그냥 뒤에다가 넣으면 된다.
            dps.push_back(num);
            dp[i] = dps.size()-1;
            cnt[dp[i]][num]=0;
            answer=0;
        }
        else {
            auto it = lower_bound(dps.begin(), dps.end(), num);//num보다 크거나 같은 곳을 알게됨.
            int idx = it - dps.begin();//idx를 알아내기
            *it = num;//해당 숫자로 덮기.
            dp[i] = idx;
        }
        auto it = prev(cnt[dp[i]-1].lower_bound(arr[i]));//지금 들어온 수보다 하나 작은 값 갖고 오기.
        long long temp=0;
        while(1){
            auto nowCnt=(*it).second;
            temp=(temp%MOD+nowCnt%MOD)%MOD;
            if(it==cnt[dp[i]-1].begin())break;
            it--;//이전의 갯수도 계속 갖고 오기
        }
        if(cnt[dp[i]].find(num)==cnt[dp[i]].end()){//한 번도 들어온 적 없음
            cnt[dp[i]][num]=temp;
        }else{//들어온 적 있음. 그러면 갯수를 추가해주면 된다.
            cnt[dp[i]][num]=(temp+cnt[dp[i]][num])%MOD;
        }
        if(dps.size()==dp[i]+1){//최고인 순간.
            answer=(answer+temp)%MOD;
        }
    }
    cout << dps.size() - 1 << ' ' << answer;
    return 0;
}
