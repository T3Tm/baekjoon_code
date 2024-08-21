#include <bits/stdc++.h>
using namespace std;
int arr[102];
bool visited[102];
vector<int> result;
void dfs(int cur, vector<int>& temp){
    temp.push_back(cur);
    visited[cur] = 1;

    int next = arr[cur];
    if(!visited[next]){
        dfs(next, temp);
    }else{//이미 방문 했음
        //그럼 temp를 천천히 보면서 back()이 가리키는 index 찾기
        for(int i=0;i<temp.size();i++){
            if(temp[i] == next){//마지막으로 가야하는 곳이랑 temp랑 같으면 이곳부터 사이클이 탄생
                //여기부터 result에 기입.
                while(i < temp.size()){
                    result.push_back(temp[i++]);
                }
                break;
            }
        }
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++)cin >> arr[i];
    //4 -> 5 5 -> 5
    //5에서 5를 갈 때 이미 방문 했던 것
    //그럼 마지막을 기점으로 이전에 어디부터 잘라야 되는지 확인 그럼 그 인덱스부터 잘라서 기록
    //
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        vector<int>temp;//해당 들어간 것을 순서대로 넣는다.
        dfs(i, temp);
    }

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for(auto &v: result)cout << v << '\n';
    return 0;
}