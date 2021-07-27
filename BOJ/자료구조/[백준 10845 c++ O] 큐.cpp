#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 10845 c++ O] 큐 
// 문제: 큐의 기본기능 구현
// 접근1: queue STL로 구현 
// 풀이: 
// n입력
// 명령문 반복 입력 및 출력
// 시간복잡도: O(n)
int n;
queue<int> q;
string cmd;
int num;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		if (cmd == "size") {
			cout << q.size() << '\n';
		}
		if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		if (cmd == "front") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
		}
		if (cmd == "back") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.back() << '\n';
		}
		if (cmd == "pop") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
			q.pop();
		}
	}
	
	return 0;
}
