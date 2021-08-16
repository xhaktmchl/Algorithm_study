#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 11005 c++ O] 진법 변환 2
// 문제:10 진법 -> b진법으로 변환
// 접근: 
// 시간복잡도: 
// 풀이: 
int b,sum=0;
string s;
int n;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n>> b;
	while (n > 0) {
		int tp = n % b; // 나머지
		if (tp >= 10) { s += 'A' + (tp - 10);}// A~Z
		else {	s += '0'+tp; } // 0~9
		n /= b;
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
	return 0;
}
