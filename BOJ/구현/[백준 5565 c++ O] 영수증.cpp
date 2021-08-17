#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5565 c++ O] 영수증 
// 문제: 
// 접근: 남은 가격= 전체-9개 합
// 풀이: 
int sum = 0;
int all;
int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> all;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << all - sum << '\n';
	return 0;
}
