#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10984 c++ V] 내 학점을 구해줘
// 문제:
// 접근: 반올림 기능일 있는지 몰랐음
// 풀이: 소수점 한자리 까지 반올리해서 출력
// 개념: 
// printf("%.1f\n"): %.1f 소수점 한자리 까지 반올림 
int t, n;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	//cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n;
		int tc=0; double tg=0;
		for (int i = 0; i < n; i++) {
			int c; double g;
			cin >> c >> g;
			tc += c; 
			tg += g*c;
		}
		printf("%d %.1f\n", tc, tg / tc); // %.1f 소수점 한자리 까지 반올림
	}
	return 0;
}
