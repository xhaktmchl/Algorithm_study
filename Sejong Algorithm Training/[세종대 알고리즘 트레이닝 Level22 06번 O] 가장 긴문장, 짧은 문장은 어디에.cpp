#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 06번 O] 가장 긴문장, 짧은 문장은 어디에
문제:
접근: 
풀이: 완탐
	//1.입력
		//2.최대값이면 최대 길이, 인덱스 저장
	//3.최속값이면 최소 길이, 인덱스 저장
	//4.출력:
시간복잡도: O()=
*/
string a[10];
int len = 0, maxL = -1, maxIdx = -1, minL = 987987987, minIdx = -1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.최대값이면 최대 길이, 인덱스 저장
	//3.최속값이면 최소 길이, 인덱스 저장
	for (int i = 0; i < 4; i++) {
		len = a[i].size();
		if (len > maxL) {
			maxL = len;
			maxIdx = i;
		}
		if (len < minL) {
			minL = len;
			minIdx = i;
		}
	}
	//4.출력:
	cout << "긴문장:" << maxIdx << '\n' << "짧은문장:" << minIdx;
	return 0;
}
