#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 05회차 04번 백준 11729 X] 하노이 탑 이동 순서
문제:
접근: 
풀이:
	//1.입력
	//2.재귀: f(n, from, by, to) = n개의 원판을 from에서 by를 거쵸 to로 옮긴다.
	//1)기저: n==1이면 출력
	//2)a->b로 모두 옮김
	//3)a->c로 제일 큰 원판 1개 옮김
	//4)b->c로 나머지 원판 다 옮김
시간복잡도: O()= 
개념:
*/
int n;

void Hanoi(int num, int a, int b, int c) {
	if (num == 1) {
		cout << a << " " << c << '\n';
	}
	else {
		Hanoi(num - 1, a, c, b);
		Hanoi(1, a, b, c);
		Hanoi(num - 1, b, a, c);
	}
}

int cntHanoi(int num, int a, int b, int c) {
	int cnt = 0;
	if (num == 1) {
		cnt++;
	}

	else {
		cnt += cntHanoi(num - 1, a, c, b);
		cnt += cntHanoi(1, a, b, c);
		cnt += cntHanoi(num - 1, b, a, c);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.재귀: f(n, from, by, to) = n개의 원판을 from에서 by를 거쵸 to로 옮긴다.
	//1)기저: n==1이면 출력
	//2)a->b로 모두 옮김
	//3)a->c로 제일 큰 원판 1개 옮김
	//4)b->c로 나머지 원판 다 옮김
	cout<< cntHanoi(n, 1, 2, 3)<<'\n';
	Hanoi(n, 1, 2, 3);
	return 0;
}
