#include <bits/stdc++.h>
using namespace std;

int dice[10002][6];
int mapping[10002][6];

int trans[]{5,3,4,1,2,0};
int result;
int n;
void bact(int depth, int now, int pre){//이전에 탑 알려줘야함.
	if(depth == n){
		result = max(result, now);
		return;
	}
	int bottom = dice[depth][mapping[depth][pre]];
	int top = dice[depth][trans[mapping[depth][bottom]]];
	int plus{6};
	if (top + bottom == 11)plus = 4;
	else if(top == 6 || bottom == 6)plus = 5;
	bact(depth + 1, now + plus, top);
}
int main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			cin>> dice[i][j];//i번째 j 번 등장
			mapping[i][dice[i][j]] = j;//어느 숫자가 어느 인덱스에 있는지 맵핑
		}
	}
	
	for(int i=0;i<6;i++){
		int now{6};
		int top = dice[0][i];
		int bottom = dice[0][trans[mapping[0][top]]];
		if (top + bottom == 11)now = 4;
		else if(top == 6 || bottom == 6)now = 5;
		bact(1,now,top);
	}
	cout << result;
	return 0;
}