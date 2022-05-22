#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 07번 O] 글자수만큼 손가락 접기
문제:
접근: 
풀이: 
	//1.입력
	//2.재귀
	//출력: 현재 숫자
	//1)기저조건: 1이면 중단
	//2)재귀:
	//cur-1
	//3)출력: 숫자
시간복잡도: O()=
*/
string a;
int len;

void re(int cur) {
	cout << cur << " ";
	if (cur == 1) {
		return;
	}

	re(cur - 1);
	cout << cur << " ";
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.재귀
	//출력: 현재 숫자
	//1)기저조건: 1이면 중단
	//2)재귀: 
	//cur-1
	//3)출력: 숫자
	len = a.size();
	re(len);
	return 0;
}
