#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 9086 c++ O] 문자열 
// 문제: 
// 접근: 
// 시간복잡도: 
// 풀이1:  
int n;
string s;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		//cout << s.front() << s.back() << '\n';
		cout << s[0] << s[s.size()-1] << '\n';
	}
    return 0;
}
