#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 03번 O] Level과 Branch
문제:
접근: 
풀이:
	//1.입력
	//2.재귀
	//1)기저조건: 만약 레벨==입력, 중단
	//2)재귀
	// branch만큰 반복
시간복잡도: O()=
*/
int level, branch;

void re(int cnt) {
	if (cnt == level) {
		return;
	}

	for (int i = 0; i < branch; i++) {
		re(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> level >> branch;
	//2.재귀
	//1)기저조건: 만약 레벨==입력, 중단
	//2)재귀 
	// branch만큰 반복
	re(0);
	return 0;
}
