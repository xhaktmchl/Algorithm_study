#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23.5 06번 O] 황금좌표 찾기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 이차 배열 에서 문자 같으면
	//문자 갯수 카운트
	//3.출력:
	// 최대 갯수면 , 문자저장, 갯수 갱신
	// 출력
시간복잡도: O()=
*/
char a[10][10];
char b[10][10] = {
	"ABCD",
	"BBAB",
	"CBAC",
	"BAAA"
};

int cnt[200];
int maxN = 0;
char maxCh;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	//2.완탐: 이차배열 탐색
	//이차 배열 에서 문자 같으면
	//문자 갯수 카운트
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == b[i][j]) {
				cnt[a[i][j]]++;
			}
		}
	}
	//3.출력:
	// 최대 갯수면 , 문자저장, 갯수 갱신
	// 출력
	for (int i = 'A'; i <= 'z'; i++) {
		if (maxN < cnt[i]) {
			maxCh = (char)i;
			maxN = cnt[i];
		}
	}
	cout << maxCh;
	return 0;
}
