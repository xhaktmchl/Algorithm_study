#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2506 c++ O] 점수계산 
// 문제:
// 접근: 
// 풀이: 
int n,c=0,sum=0;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1) c++;
		else c = 0;
		sum += c;
	}
	cout << sum << '\n';
	return 0;
}
