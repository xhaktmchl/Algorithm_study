#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 04번] 카드 종류 알아내기 O
문제:
접근: 완탐, 종류 체크 배열
풀이:
시간복잡도: O(n)=
*/
string str;
bool check[100];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str;
	//2.완탐; 문자열 탐색
	// 처음 나오는 종류이면 체크
	// 종류 카운트
	int len = str.size();
	for (int i = 0; i < len; i++) {
		int num = str[i] - 'A';
		if (check[num] == 0) {
			check[num] = 1;
			cnt++;
		}
	}
	//3.출력: 종류의 갯수
	cout << cnt<<"개";
	return 0;
}
