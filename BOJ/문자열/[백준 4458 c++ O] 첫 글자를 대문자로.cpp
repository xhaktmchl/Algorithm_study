#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 4458 c++ O] 첫 글자를 대문자로
// 문제: 
// 접근: 아스키 코드로 직접 변환
// 시간복잡도: 
// 풀이1:  
#define MAX 10
int n;
string s;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n; cin.ignore();
	while (n--) {
		getline(cin, s); 
		if (s[0] >= 'a' && s[0] <= 'z') { s[0] -= 32; }
		cout << s << '\n';
	}
	return 0;
}
