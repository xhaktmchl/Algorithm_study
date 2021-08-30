#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 20301 c++ O] 반전 요세푸스
// 문제: 요세푸스 방향이 양방향인 문제
// 접근1: 순환 탐색 -> 벡터,스택,큐,덱 -> 양방향 순환 -> 덱
// 순환횟수 인자, 뺀 숫자갯수 인자 로 덱의 순환방향 전환
// 시간복잡도: 
// 풀이: 
// 처음에 -> 방향으로 탐색 ,k번째 숫자이면 숫자 뺌, 뺀 숫자가 m 개가 되면 방향 인자 반대로
// <- 방향 탐색일 때 ,k번째 숫자이면 숫자 뺌,  뺀 숫자가 m 개가 되면 방향 인자 반대로
int n, k, m;
deque<int> dq;
vector<int> a; // 정답 배열
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	// 요세푸스 순열 탐색
	int dir = 1; // 방향 숫자
	int c = 0, cnt = 0; // 이동 횟수, 뺀 숫자갯수
	while (!dq.empty()) {
		c++;
		// -> 방향
		if (dir) {
			int tp = dq.front(); dq.pop_front();
			if (c == k) { 
				a.push_back(tp); 
				cnt++;
				c = 0;
				if (cnt % m == 0) { dir = 0; }
			}
			else if(c != k) dq.push_back(tp);
		}// <- 방향
		else {
			int tp = dq.back(); dq.pop_back();
			if (c == k) {
				a.push_back(tp);
				cnt++;
				c = 0;
				if (cnt % m == 0) { dir = 1; }
			}
			else if (c != k) dq.push_front(tp);
		}
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << '\n';
	}
	return 0;
}
