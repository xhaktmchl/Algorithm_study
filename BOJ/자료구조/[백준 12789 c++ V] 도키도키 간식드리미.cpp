#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
#include <stack>
#include <queue>
using namespace std;
// [백준 12789 c++ V] 도키도키 간식드리미
// 문제:
// 접근: 대기순서 -> 벡터저장, 한 곳에 대기 -> 스택
// 시간복잡도: O(2000)
// 풀이1:  
// 큐에 대기순서 입력
// 입장해야하는 순번인지 검사 1.큐대기열, 2.스택 대기열,3.없으면 스택에 들어감
// 마지막 스택에 남은 사람은 모두 순서대로여야 함
int n;
int i = 0;
queue<int> a;
stack<int> st;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push(num);
	}
	int cur = 1;
	while(!a.empty()){ // 첫 대기자 순서대로 확인
		if (a.front() == cur) { cur++; a.pop(); } // 큐 대기열에 다음순번 있는 경우
		else {
			// 스택 대기열에 다음순번 있는 경우
			if (!st.empty() && st.top() == cur) { 
				cur++; 
				st.pop();
				continue;
			} // 없으면 스택에 들어감
			st.push(a.front()); a.pop();
		}
	}
	// 스택에 있는 대기자 순서대로 인지 검사
	bool ok = 1;
	while (!st.empty()) {
		if (st.top() == cur) { cur++; st.pop(); }
		else {
			ok = false;
			break;
		}
	}
	if (ok) { cout << "Nice" << '\n'; }
	else { cout << "Sad" << '\n'; }
    return 0;
}
