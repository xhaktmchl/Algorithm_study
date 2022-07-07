#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0707 01번 O] 버스 주차요금 저렴한 곳 찾기
문제:
접근:
풀이: 슬라이딩 윈도우
	//1.입력
	//2.sliding window
시간복잡도: O(klogk)=
접근:
풀이2: prefix 메모이제이션으로 각 구간까지의 합 저장해놓기
시간복잡도: O(klogk)=
*/
int w;
int a[20] = { 1,2,3,3,5,1,0,1,3 };
int sum[20];
int tpsum = 0;
int minN;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> w;
	//2.sliding window
	int e=w, s=0;
	//초기 구간 합
	for (int i = 0; i < e-1; i++) {
		tpsum += a[i];
	}
	// 각 슬라이드 구간의 합 구하고, 뒷구간 늘리기
	//최저비교
	//슬라이드 앞 구간 땡기기
	minN = 9870980987;
	for (int i = w-1; i < 9; i++) {
		tpsum += a[e-1]; e++;
		if (tpsum < minN) {
			minN = tpsum;
		}
		tpsum -= a[s];
		s++;
	}
	//3.출력
	cout << minN;
	return 0;
}
