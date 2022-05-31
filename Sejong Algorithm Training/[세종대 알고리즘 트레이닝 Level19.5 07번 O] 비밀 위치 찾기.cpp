#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 07번 O] 비밀 위치 찾기
문제:
접근: 
풀이: 완탐
	//1.입력: 패턴
	//2.완탐: 배열 위치에서 패턴 있는지 탐색
	//1)현재 위치에서 4칸 검색
	//범위검사
	//불일치 flag=0
	//2)일치하면 카운트
	//3.출력:
시간복잡도: O(3*4*4)=
*/
char Map[10][10] = {
	"ABGK",
	"TTAB",
	"ACCD"
};

char pat[4][4];
int dx[] = { 0,1,1,0 };
int dy[] = { 0,0,1,1 };
bool flag = 1;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 패턴
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> pat[i][j];
		}
	}
	//2.완탐: 배열 위치에서 패턴 있는지 탐색
	//flag초기화
	//1)현재 위치에서 4칸 검색
	//범위검사
	//불일치 flag=0
	//2)일치하면 카운트
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			flag = 1;
			for (int p = 0; p < 4; p++) {
				int rr = i + dy[p];
				int cc = j + dx[p];

				if (rr < 0 || rr >= 3 || cc < 0 || cc >= 4) { continue; }
				if (Map[rr][cc] != pat[dy[p]][dx[p]]) { flag = 0; }
			}
			if (flag == 1) { cnt++; }
		}
		
	}
	//3.출력:
	if (cnt != 0) {
		cout << "발견(" << cnt << "개)";
	}
	else { cout << "미발견"; }
	return 0;
}
