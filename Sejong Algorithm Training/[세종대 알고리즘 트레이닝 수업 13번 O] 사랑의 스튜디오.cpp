#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업 13번 O] 사랑의 스튜디오
문제:
접근:
풀이: 완탐
	//1.입력
	//2.완탐: 각 열의 좋아하는 인원 카운트
	//만약 최대값이면 최대값 저장, 번호 저장
	//만약 최소값이면 최소값 저장, 번호 저장
	//3.출력: 최대번호, 최소번호
시간복잡도: O(n*n)=10000
*/
int n;
int ad[110][110],cnt=0;
int maxN = -1,maxR=-1,minR=110,minN=110;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
		}
	}
	//2.완탐: 각 열의 좋아하는 인원 카운트
	//만약 최대값이면 최대값 저장, 번호 저장
	//만약 최소값이면 최소값 저장, 번호 저장
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (ad[j][i] == 1) { cnt++; }
		}
		if (cnt > maxR) {
			maxR = cnt;
			maxN = i;
		}
		if (cnt < minR) {
			minR = cnt;
			minN = i;
		}
	}
	//3.출력: 최대번호, 최소번호
	cout << maxN << " " << minN;
	return 0;
}
