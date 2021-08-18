#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2446 c++ O] 별 찍기 - 9
// 문제: 
// 접근: 기본구현
// 풀이: 
int n;
int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			cout << " ";
		}
		// 별
		for (int j = 2*n - (2*i-1); j >= 1; j--) {
			cout << "*";
		}
		cout << '\n';
	}
	for (int i = 2; i <= n; i++) {
		for (int j = n - i; j >= 1; j--) {
			cout << " ";
		}
		// 별
		for (int j = 1; j <= (2 * i - 1); j++) {
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}
