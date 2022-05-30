#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19.5 02번 O] 안정적인 세포 판별
문제:
접근: 
풀이: 완탐
	//1.입력: 배열
	//2.완탐: 세포가 있으면
	//1)8방향 세포 탐색
	//있으면 flag=0
	//3.출력:
시간복잡도: O(5*4*8)=
*/
int a[10][10];
int dy[10] = { -1,-1,0,1,1,1,0,-1 };// 상 부터 시계방향
int dx[10] = { 0,1,1,1,0,-1,-1,-1 };
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 배열
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	//2.완탐: 
	// 세포가 있으면
	//1)8방향 세포 탐색
	//범위검사
	//있으면 flag=0
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 1) {
				for (int p = 0; p < 8; p++) {
					int rr = i + dy[p];
					int cc = j + dx[p];
					if (rr < 0 || rr >= 5 || cc < 0 || cc >= 4) { continue; }
					if (a[rr][cc] == 1) {
						flag = 0;
					}
				}
			}
		}
	}
	//3.출력:
	if (flag == 1) {
		cout << "안정된 상태";
	}
	else { cout << "불안정한 상태"; }
	return 0;
}
