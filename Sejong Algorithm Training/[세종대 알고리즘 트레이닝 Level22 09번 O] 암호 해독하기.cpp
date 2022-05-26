#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 09번 O] 암호 해독하기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 문자열 배열 각 문자열 암호랑 같은지 비교
	//같으면 flag=1
	//3.출력:
시간복잡도: O()=
*/
string a;
string pas[10] = {
	"Jason",
	"Dr.tom",
	"EXEXI",
	"GK12P",
	"POW"
};
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> a;
	//2.완탐: 문자열 배열 각 문자열 암호랑 같은지 비교
	//같으면 flag=1
	for (int i = 0; i < 5; i++) {
		if (a == pas[i]) {
			flag = 1;
			break;
		}
	}
	//3.출력: 
	if (flag) {
		cout << "암호해제";
	}
	else { cout << "암호틀림"; }
	return 0;
}
