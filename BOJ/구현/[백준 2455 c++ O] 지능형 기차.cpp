#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2455 c++ O] 지능형 기차
// 문제:
// 접근: 
// 풀이: 
int a, b;
int sum = 0,maxN=0;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		maxN = max(maxN, sum);
	}
	cout << maxN << '\n';
	return 0;
}
