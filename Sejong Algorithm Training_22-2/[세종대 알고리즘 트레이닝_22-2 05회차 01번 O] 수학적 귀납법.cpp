#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 05회차 01번 O] 수학적 귀납법
문제:
접근: 
풀이:
	//1.입력
	//2.재귀
	//1)기저조건: n==1일때 1반환
	//2)재귀 : f(n-1)+n
시간복잡도: O()= 
개념:
*/
int n,result;

int re(int num) {
	if (num == 1) { return 1; }

	return num + re(num - 1);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	//2.재귀
	//1)기저조건: n==1일때 1반환
	//2)재귀 : f(n-1)+n
	result = re(n);
	cout << result;
	return 0;
}
