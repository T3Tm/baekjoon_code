#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/4256
	트리
	왼쪽 자식이 순서가 먼저이다.

	노드 n개로 이루어진 이진 트리 BT라고 하자.

	전위 순회
	루트 -> left -> right
	3 < 루트 오른쪽에 있는 것이 left right인데
	3 -> 2 -> 1 -> 4이니까
	3 < 루트
	2번이 right, left일 수도 있다.


	중위 순회
	left -> 루트 -> right




	후위 순회
	left -> right -> 루트
	5 8 4 6 2 1 7 3
*/
int n;
vector<int>inorderInfo; // inorder의 idx 번호 알아내기
int preorder[1001],inorder[1001],postorder[1001];
void arrinput(int arr[]) {
	for (int i = 0; i < n;i++ ) {
		cin >> arr[i];
	}
}

//convert 같은 경우는 L/R/root 정렬해주는 함수
void convert(int left,int right,int front,int end,int s,int e) {
	postorder[right] = preorder[front];
	if (!(right - left))return;
	int mid = inorderInfo[preorder[front]]; //L 몇 개인지 R 몇 개인지 알아내기
	int nextleft = mid - s;
	int nextright = e - mid;
	if (nextleft) {
		// L 정렬
		convert(left, left+nextleft-1, front + 1, front + nextleft, s, mid - 1);
	}
	if (nextright) {
		//R 정렬 
		convert(left + nextleft, right - 1, front + nextleft + 1, end, mid+1, e);
	}
	
}
int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		inorderInfo.assign(n+1,0);
		arrinput(preorder);
		arrinput(inorder);
		for (int i = 0; i < n; i++) {
			inorderInfo[inorder[i]] = i;
		}
		convert(0,n-1,0,n-1,0,n-1);
		for (int i = 0; i < n; i++) {
			cout << postorder[i] << " ";
		}
		cout << endl;
	}
	return 0;
}