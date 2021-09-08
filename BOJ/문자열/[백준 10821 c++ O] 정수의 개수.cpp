#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 10821 c++ O] 정수의 개수
// 문제: 
// 접근1: 
// 시간복잡도: 
// 풀이:
string s;
int c = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			c++;
		}
	}cout << c+1 << '\n';
	return 0;
}
