#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 06번 O] 재귀는 몇번
문제:
접근: 
풀이: 
	//1.입룍
	//2.재귀
	//횟수 카운트
	//1)기저조건: 만약 현재 == lelvel이면 중단
	//2)재귀: 3회 cur+1반복
	//3.출력: 횟수
시간복잡도: O()=
*/
int branch, level,cnt=0;

void re(int cur) {
	cnt++;
	if (cur == level) {
		return;
	}

	for (int i = 0; i < branch; i++) {
		re(cur + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입룍
	cin >> branch >> level;
	//2.재귀
	//횟수 카운트
	//1)기저조건: 만약 현재 == lelvel이면 중단
	//2)재귀: 3회 cur+1반복
	re(0);
	//3.출력: 횟수
	cout << cnt;
	return 0;
}
