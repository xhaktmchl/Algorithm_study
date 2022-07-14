#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0714 03번 O] Priority Queue
문제:
접근:
풀이: 
//1.입력
	//2.n번 명령
	//1)push 이면
	//2)pop이면
	//3)add 이면
시간복잡도: O()=
*/
int n;
string op;
priority_queue<int> pq;
int a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.n번 명령
	//1)push 이면
	//2)pop이면
	//3)add 이면
	for (int i = 0; i < n; i++) {
		cin >> op>>a;
		if (op == "push") {
			pq.push(a);
		}
		else if (op == "pop") {
			for (int j = 0; j < a; j++) {
				int cur = pq.top();
				cout << cur << " ";
				pq.pop();
			}cout << '\n';
		}
		else if (op == "add") {
			int cur = pq.top();
			pq.pop();
			pq.push(cur + a);
		}
	}
	return 0;
}
