#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/15828
	Router
*/
int main() {
	fast;
	int buffersize;
	cin >> buffersize;
	queue<int>buffer;
	while (1) {
		int n;
		cin >> n;
		if (n == -1)break;
		else if (!n)buffer.pop();
		else if(buffer.size()!=buffersize) buffer.push(n);
	}
	if (buffer.empty())cout << "empty";
	else {
		int size = buffer.size();
		for (int i = 0; i < size; i++) {
			cout << buffer.front() << " ";
			buffer.pop();
		}
	}
	
}