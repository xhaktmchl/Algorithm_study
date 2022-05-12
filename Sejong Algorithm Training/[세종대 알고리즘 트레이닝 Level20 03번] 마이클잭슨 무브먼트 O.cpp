#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 03번] 마이클잭슨 무브먼트 O
문제:
접근: 재귀
풀이:
//1.입력: 배열
	//2.재귀(배열의 인덱스): 0~배열 끝 ~ 0인덱스 까지 출력
	//1) 기저조건: 배열 끝 인덱스 이면
	//2) 현재 배열 원소 출력
	//2) 재귀 idx+1
	//3) 현재 배열 원소 출력
시간복잡도: O()=
*/
int a[100];

void re(int idx) {
	if (idx == 5) {
		cout << a[idx] << " ";
		return;
	}

	cout << a[idx] << " ";
	re(idx + 1);
	cout << a[idx] << " ";
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
	//1.입력: 배열
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	//2.재귀(배열의 인덱스): 0~배열 끝 ~ 0인덱스 까지 출력
	//1) 기저조건: 배열 끝 인덱스 이면
	//2) 현재 배열 원소 출력
	//2) 재귀 idx+1
	//3) 현재 배열 원소 출력
	re(0);
	return 0;
}
