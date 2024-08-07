#include <bits/stdc++.h>
using namespace std;
int isPalindrome(string& word){
    for(int i=0;i<=word.size()/2;i++){
        if(word[i] != word[word.size()-1-i])return i;//안 맞는 인덱스 return
    }
    return -1;
}

int isPalindrome(string& word, int idx){
    int left= 0, right = word.size() -1;
    if(left == idx)left++;
    else if(right == idx)right--;

    while(left < right){
        if(word[left] != word[right])return 0;    
        left++;
        right--;
        if(left == idx)left++;
        else if(right == idx)right--;
    }
    return 1;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int t;cin >> t;

    while(t--){
        string word; cin >> word;
        int Palindrome = isPalindrome(word); // 50000
        if(Palindrome == -1){
            cout << 0 << '\n';
        }else{//한 문자 지우면 되는지 확인
            //100000 
            int ret = isPalindrome(word, Palindrome); //5만
            int ret1 = isPalindrome(word, word.size() - Palindrome - 1); //5만
            if(ret || ret1)cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
    return 0;
}