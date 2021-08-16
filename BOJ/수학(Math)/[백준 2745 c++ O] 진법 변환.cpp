#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2745 c++ O] 진법 변환    
// 문제: b진법 -> 10 진법으로 변환
// 접근: 
// 시간복잡도: 
// 풀이: 
int b,sum=0;
string s;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s>>b;
	int d = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9') { sum += (s[i] - '0') * d; } // 0~9 사이
		else { sum += (s[i] - 'A' + 10) * d;}// A~Z 사이
		d *= b;
	}
	cout << sum << '\n';
	return 0;
}
