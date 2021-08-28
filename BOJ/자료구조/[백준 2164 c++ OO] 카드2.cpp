#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2164 c++ OO] 카드2
// 문제:
// 접근: 기본 큐 자료구조 구현 
// 시간복잡도: O(50000) 
// 풀이: 
// 큐에 1~n까지 푸쉬
// 법칙에 따라 팝,팝, 푸쉬 반복
// 마지막 수 출력
int n;
queue<int> q;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		q.pop();
		int tp = q.front(); 
		q.pop();
		q.push(tp);
	}
	cout << q.front() << '\n';
	return 0;
}
