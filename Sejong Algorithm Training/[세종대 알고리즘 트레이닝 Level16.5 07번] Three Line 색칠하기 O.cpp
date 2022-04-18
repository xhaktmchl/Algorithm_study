#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 07번] Three Line 색칠하기 O
문제:
접근:
풀이:
시간복잡도: O()
*/
int a[10][10], l[10];;
int l1, l2, l3;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	int num = 1;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = num++;
		}
	}
	cin >> l[0] >> l[1] >> l[2];
	//2.라인 제거
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[l[i]][j] = 0;
		}
	}
	
	//3.출력
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
