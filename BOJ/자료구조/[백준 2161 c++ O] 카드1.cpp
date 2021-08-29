#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2161 c++ O] 카드1
// 문제: 
// 접근: 일방향 순환 -> 큐로 순환
// 시간복잡도: O(n) = 1000
// 풀이: 
queue<int> q;
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		int front = q.front(); q.pop();
		int tp = q.front(); q.pop();
		q.push(tp);
		cout << front << " ";
	}
	cout << q.front() << '\n';
	return 0;
}
