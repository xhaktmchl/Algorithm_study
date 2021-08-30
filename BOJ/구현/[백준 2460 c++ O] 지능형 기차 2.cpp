#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2460 c++ O] 지능형 기차 2 
// 문제: 
// 접근: 기본 구현
// 시간복잡도: 
// 풀이: 
int sum = 0;
int a, b, maxN = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		maxN = max(maxN, sum);
	}
	cout << maxN << '\n';
	return 0;
}
