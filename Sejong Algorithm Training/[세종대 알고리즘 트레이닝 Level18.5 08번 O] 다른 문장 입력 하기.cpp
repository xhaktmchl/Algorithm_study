#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 08번 O] 다른 문장 입력 하기
문제:
접근: 
풀이: 완탐
	//1.입력: 문장3개
	//2.완탐: check배열에 표시
	//만약 이미 1이라면
	//flag=0
	//3.출력
	//겹치면
	//안겹치면
시간복잡도: O()=
*/
string a[10];
bool check[200];
bool flag = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 문장3개
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	//2.완탐: check배열에 표시
	//만약 이미 1이라면 
	//flag=0
	for (int i = 0; i < 3; i++) {
		int len = a[i].size();
		for (int j = 0; j < len; j++) {
			if (check[a[i][j]] == 1) { flag = 0; }
			check[a[i][j]] = 1;
		}
	}
	//3.출력
	//겹치면
	//안겹치면
	if(flag==1){
		cout << "Perfect";
	}
	else { cout << "No"; }
	return 0;
}
