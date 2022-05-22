#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 08번 O] 생일선물 마우스
문제:
접근: 시뮬레이션
풀이: 
	//1.입력
	//2.명령 수 만큼 수행
	//1)up
	//2)right
	//3)down
	//4)left
	//5)click
	//좌표 출력
시간복잡도: O()=
*/
int a;
string op[10010];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> op[i];
	}
	//2.명령 수 만큼 수행
	//1)up
	//2)right
	//3)down
	//4)left
	//5)click
	//좌표 출력
	int curX = 5, curY = 5;
	for (int i = 0; i < a; i++) {
		if (op[i] == "up") {
			curY += dy[0];
			curX += dx[0];
		}
		if (op[i] == "right") {
			curY += dy[1];
			curX += dx[1];
		}
		if (op[i] == "down") {
			curY += dy[2];
			curX += dx[2];
		}
		if (op[i] == "left") {
			curY += dy[3];
			curX += dx[3];
		}
		if (op[i] == "click") {
			cout << curY << "," << curX<<'\n';
		}
	}
	return 0;
}
