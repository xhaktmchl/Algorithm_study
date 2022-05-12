#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 07번] 재귀 부메랑 O
문제:
접근: 재귀
풀이:
	//1.입력
	//2.재귀
	//1) 기저조건: 0번 인덱스이면
	//출력
	//중단
	//2) 현재 번호 출력
	//3) 재귀 idx-1
	//4) 원소 출력
시간복잡도: O()=
*/
int n;
int a[10] = { 3,7,4,1,9,4,6,2 };

void re(int idx) {
	if (idx == 0) {
		cout << a[idx] << " ";
		return;
	}

	cout << a[idx] << " ";
	re(idx - 1);
	cout << a[idx] << " ";
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	//2.재귀
	//1) 기저조건: 0번 인덱스이면
	//출력
	//중단
	//2) 현재 번호 출력
	//3) 재귀 idx-1
	//4) 원소 출력
	re(n);
	return 0;
}
