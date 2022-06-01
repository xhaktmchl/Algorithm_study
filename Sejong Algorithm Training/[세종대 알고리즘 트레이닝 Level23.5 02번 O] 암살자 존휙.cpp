#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23.5 02번 O] 암살자 존휙
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 행,열 각각에 서로 같은 것이 있는지
	//있으면 flag=0
	//3.출력:
시간복잡도: O()=
*/
int row[5];
int col[5];
int cntR[10], cntC[10];
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 3; i++) {
		cin >> row[i] >> col[i];
	}
	//2.완탐: 행,열 각각에 서로 같은 것이 있는지
	//있으면 flag=0
	for (int i = 0; i < 3; i++) {
		cntR[row[i]]++;
		cntC[col[i]]++;
		if (cntR[row[i]] > 1 || cntC[col[i]] > 1) {
			flag = 0;
		}
	}
	//3.출력:
	if (flag == 1) { cout << "안전"; }
	else { cout << "위험"; }
	return 0;
}
