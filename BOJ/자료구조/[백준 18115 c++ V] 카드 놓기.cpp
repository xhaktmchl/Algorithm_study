#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 18115 c++ V] 카드 놓기
// 문제: 
// 접근1: 
// 시간복잡도: O(n)
// 풀이: 
// 카드뽑는 순서 반대로 탐색하며
// 1~n까지 수를 데크에 
// 1명령은 push_front
// 2명령은 앞에것 팝, 넣어야될 숫자 푸쉬, 원래 앞에있던 숫자 푸쉬
// 3 명령은 뒤에 푸쉬
int n;
vector<int> a;
deque<int> dq;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push_back(num);
	}
	
	for (int i = 1; i <=n; i++) { // 1~n 까지 카드 순서
		if (a[n-i] == 1) { // 1 명령
			dq.push_front(i);
		}
		else if (a[n - i] == 2) { // 2 명령
			int tp=0;
			if (!dq.empty()) { // 데크 빈 경우 예외처리
				tp = dq.front();
				dq.pop_front();
			}
			dq.push_front(i);
			if(tp != 0) dq.push_front(tp);
		}
		else if (a[n - i] == 3) { // 3명령
			dq.push_back(i);
		}
	}
	while (!dq.empty()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
	return 0;
}
