#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23.5 01번 O] 왼쪽, 오른쪽 이동
문제:
접근: 
풀이: 시뮬레이션
	//1.4반복
	//2.입력: 방향
	//3.와탐: 배열 한칸 이동
	// 1)r
	//4인덱스 원소 따로 저장하고
	// 4~1까지 이동
	//0에 임시원소 저장
	//2)l
	//0인덱스 원소 따로 저장하고
	// 0~3까지 이동
	//4에 임시원소 저장
	//4.출력: 배열
시간복잡도: O(5*4)=
*/
char dir;
int tp;
int ar[10] = { 3,5,1,9,7 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.4반복
	for (int t = 0; t < 4; t++) {
		//2.입력: 방향
		cin >> dir;
	//3.와탐: 배열 한칸 이동
	// 1)r
	//4인덱스 원소 따로 저장하고 
	// 4~1까지 이동
	//0에 임시원소 저장
		if (dir == 'R') {
			tp = ar[4];
			for (int i = 4; i >= 1; i--) {
				ar[i] = ar[i - 1];
			}
			ar[0] = tp;
		}
	//2)l
	//0인덱스 원소 따로 저장하고 
	// 0~3까지 이동
		//4에 임시원소 저장
		if (dir == 'L') {
			tp = ar[0];
			for (int i = 0; i < 4; i++) {
				ar[i] = ar[i + 1];
			}
			ar[4] = tp;
		}
	}
	//4.출력: 배열
	for (int i = 0; i < 5; i++) {
		cout << ar[i] << " ";
	}
	return 0;
}
