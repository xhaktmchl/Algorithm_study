#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 04번 O] 겹치지 않도록
문제:
접근:완탐
풀이:
	//1.입력
	//2.완탐: 이차배열 둘 다 1인 부분 있는지 탐색
	// 있으면 flag=1, 중단
	//3.출력:
시간복잡도: O()=
*/
int a[10][10],b[10][10];
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> b[i][j];
		}
	}
	//2.완탐: 이차배열 둘 다 1인 부분 있는지 탐색
	// 있으면 flag=1, 중단
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 1 && b[i][j] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) { break; }
	}
	//3.출력:
	if (flag == 1) {cout << "걸리다";}
	else { cout << "걸리지않는다"; }
	return 0;
}
