#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1966 c++ O] 프린터 큐
// 문제: 
// 접근: 순서대로 순환 -> 큐 로 순환 탐색 
// 시간복잡도: 
// 풀이: 
// 큐에 중요도, 처음 인덱스 정보 저장 , 중요도 벡터 따로 저장
// 큐 순서대로 순환하며 프린터될 중요도와 일치하고 우리가 알고싶은 인덱스와 일치하면 프린터 순서 출력
// 아니면 큐에 첫번째 것 푸쉬 한 다음 다시 팝

int t, n, m;
int maxN = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n >> m;
		queue<pair<int, int>> q;
		vector<int> order; // 중요도 배열
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			q.push({ num,i});
			order.push_back(num);
		}
		sort(order.begin(), order.end(),greater<int>()); // 중요도 내림차순-> 프린터될 순서
		
		int c = 0,idx=0;
		while (!q.empty()) {
			if (q.front().first != order[idx]) { // 뒤에 중요도가 높은것이 있으면
				q.push(q.front());
			}
			else { // 프린터 될 순서이면
				c++; idx++; // 프린터 순 증가 , 다음 중요도 가리킴
				if (q.front().second == m) {
					cout << c << '\n'; // 원하는 인덱스 프린터이면 순서 출력
					break;
				}
			}
			q.pop();
		}
	}
	return 0;
}
