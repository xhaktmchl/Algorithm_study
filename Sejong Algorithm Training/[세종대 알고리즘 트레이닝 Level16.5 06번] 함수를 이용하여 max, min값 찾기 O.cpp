#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 06번] 함수를 이용하여 max, min값 찾기 O
문제:
접근:
풀이:
시간복잡도: O()
*/
string a;
int len = 0;
int maxIdx = -1, minIdx = -1;

void maxIndex() {
	char maxCh = a[0];
	maxIdx = 0;

	len = a.size();

	for (int i = 0; i < len; i++) {
		if (a[i] > maxCh) {
			maxCh = a[i];
			maxIdx = i;
		}
	}
}

void minIndex() {
	char minCh = a[0];
	minIdx = 0;

	len = a.size();
	for (int i = 0; i < len; i++) {
		if (a[i] < minCh) {
			minCh = a[i];
			minIdx = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.최대 인덱스 함수
	//완탐, 최대 문자 인덱스 최신화 및 저장
	maxIndex();
	//3.최소 인덱스 함수
	//완탐, 최소 문자 인덱스 최신화 및 저장
	minIndex();
	//4.출력
	cout << maxIdx << '\n'<<minIdx<<'\n';
	return 0;
}
