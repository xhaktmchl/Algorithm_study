#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [알고스팟 18.5 c++ O] 조세푸스 문제
// 문제:
// 접근: 요세푸스 일방향 순환탐색 -> 벡터, 큐 -> 큐로 순환
// 시간복잡도: O(t*n*k) = 50*1000*1000 =5천만
// 풀이: 
// 테케마다 큐로 병사번호 푸쉬
// 2명 남을 때까지 k번째 병사 팝
int t, n, k;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n >> k;
		// 큐에 병사번호 푸쉬
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		// 큐로 순환 탐색
		int cnt = 0;
		while (q.size() > 2) {
			if (cnt%k != 0) { q.push(q.front()); }
			q.pop();
			cnt++;
		}
		// 병사2명 출력
		int num1 = q.front(); q.pop();
		int num2 = q.front(); q.pop();
		if (num1 > num2) { swap(num1, num2); }
		cout << num1 <<" "<< num2 << '\n';
	}
	return 0;
}
