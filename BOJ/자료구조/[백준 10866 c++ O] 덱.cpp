#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;
// [백준 10866 c++ O] 덱 
// 문제: 덱의 기본기능 구현
// 접근1: deque STL로 구현 
// 풀이: 
// n입력
// 명령문 반복 입력 및 출력
// 시간복잡도: O(n)
int n;
deque<int> dq;
string cmd;
int num;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		if (cmd == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		if (cmd == "pop_front") {
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		if (cmd == "pop_back") {
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		if (cmd == "empty") {
			cout << dq.empty() << '\n';
		}
		if (cmd == "front") {
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.front() << '\n';
		}
		if (cmd == "back") {
			if (dq.empty()) { cout << -1 << '\n'; continue; }
			cout << dq.back() << '\n';
		}
		
	}
	
	return 0;
}
