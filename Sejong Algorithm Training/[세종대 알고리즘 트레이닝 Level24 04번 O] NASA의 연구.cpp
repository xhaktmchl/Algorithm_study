#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 04번 O] NASA의 연구
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 문자열탐색하며 알파벳 카운트
	//3.갯수 탐색
	// 1)최대값보다 크면
	// 최댓값 갱신
	// 최대 알파벳 저장
	//2)최솟값보다 작으면
	//최솟값 갱식
	//최소 알파벳 저장
	//4.출력: 최대, 최소 알파벳
시간복잡도: O()=
*/
string a;
int cnt[200];
int maxN = 0,minN=1100;
char maxA,minA;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.완탐: 문자열탐색하며 알파벳 카운트
	int len = a.size();
	for (int i = 0; i < len; i++) {
		cnt[a[i]]++;
	}
	//3.갯수 탐색
	// 1)최대값보다 크면 
	// 최댓값 갱신
	// 최대 알파벳 저장
	//2)최솟값보다 작으면
	//최솟값 갱식
	//최소 알파벳 저장
	for (int i = 'A'; i <= 'K'; i++) {
		if (cnt[i] > maxN) {
			maxN = cnt[i];
			maxA = (char)i;
		}
		if (cnt[i] < minN) {
			minN = cnt[i];
			minA = (char)i;
		}
	}
	//4.출력: 최대, 최소 알파벳
	cout << maxA << '\n' << minA;
	return 0;
}
