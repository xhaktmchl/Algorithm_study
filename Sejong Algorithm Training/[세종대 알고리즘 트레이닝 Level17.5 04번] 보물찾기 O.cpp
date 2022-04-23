#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 04번] 보물찾기 O
문제:
접근:
풀이:
시간복잡도: O()=
*/
string s[3] = { "GKT","PAC" };
char target[4];
bool check[2];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> target[0] >> target[1];
	//2.탐색
	// 모든 문자완탐하며 2개의 타겟문자 있는지 find로 탐색
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (find(s[0].begin(), s[0].end(), target[j]) != s[0].end()) {
				check[0] = 1;
			}
			if (find(s[1].begin(), s[1].end(), target[j]) != s[1].end()) {
				check[1] = 1;
			}
		}
	}
	//3.출력
	//2개면 대발견
	//1개면 중발견
	//0개면 미발견
	for (int i = 0; i < 2; i++) {
		if (check[i] == 1) { cnt++; }
	}
	if (cnt == 2) { cout << "대발견"; }
	else if (cnt == 1) { cout << "중발견"; }
	else { cout << "미발견"; }
	return 0;
}
