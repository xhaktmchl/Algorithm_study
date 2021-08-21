#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10797 c++ O] 10부제
// 문제:
// 접근: 
// 풀이: 
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int n,c=0; 
	cin >> n;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (num % 10 == n) c++;
	}
	cout << c << '\n';
	return 0;
}
