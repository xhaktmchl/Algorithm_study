#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 05번 V] 긴문장을 맨 앞으로
문제:
접근: 처음에 str.size() > int값 에러 남.
풀이: 
	//1.입력
	//2.탐색: 가장긴 단어
	//최대길이면 인덱스 저장
	//3.스왑
	//4.출력
시간복잡도: O()=
*/
string a[10];
int maxS = -1, maxIdx=-1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	//2.탐색: 가장긴 단어
	//최대길이면 인덱스 저장
	int len = 0;
	for (int i = 0; i < 3; i++) {
		len = a[i].size();
		if (len > maxS) {
			maxS = len;
			maxIdx = i;
		}
	}
	//3.스왑
	swap(a[0], a[maxIdx]);

	//4.출력
	for (int i = 0; i < 3; i++) {
		cout << a[i] << '\n';
	}
	return 0;
}
