#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 02번] 번지점프 O
문제:
접근: 재귀
풀이:
//1.입력:n;
	//2.재귀: n~0~n까지 출력
	//1)기저조건: curNum이0이면 중단
	//2)curNum출력
	//2)재귀: curNum-1
	//3)curNum출력
시간복잡도: O()=
*/
int n;

void re(int cur) {
	cout << cur << " ";
	if (cur <= 0) {
		return;
	}

	re(cur - 1);
	cout << cur << " ";
	return;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
	//1.입력:n;
	cin >> n;
	//2.재귀: n~0~n까지 출력 
	//1)기저조건: curNum이0이면 중단
	//2)curNum출력
	//2)재귀: curNum-1
	//3)curNum출력
	re(n);
	return 0;
}
