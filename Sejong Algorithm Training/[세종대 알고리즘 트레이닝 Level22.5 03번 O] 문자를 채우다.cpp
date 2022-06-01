#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 03번 O] 문자를 채우다
문제:
접근: 
풀이:
	//1.입력
	//2.입력된 문자에서 순차적으로 3x3배열 채워나가기
	//3.출력
시간복잡도: O(3*3*3)=
*/
char a[5][5][5];
char tar;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> tar;
	//2.입력된 문자에서 순차적으로 3x3배열 채워나가기
	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 3; p++) {
				a[i][j][p] = tar;
			}
		}
		tar += 1;
	}
	//3.출력
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			for (int p = 0; p < 3; p++) {
				cout << a[i][j][p];
			}cout << '\n';
		}cout << '\n';
	}
	return 0;
}
