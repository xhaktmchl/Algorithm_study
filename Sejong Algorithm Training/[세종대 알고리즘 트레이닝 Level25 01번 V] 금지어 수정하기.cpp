#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level25 01번 V] 금지어 수정하기
문제:
접근:
풀이:
	//1.입력
	//2.각 문자열 마다 계속 반복
	//1)만약 문자열 find값이 -1이면 중단
	//2)replace
	//3.출력: 완성 문자열
시간복잡도: O()=
*/
string before[10] = { "KFC","MC","BICMAC","SHACK","SONY" };
string after[10] = { "#BBQ#","#BBQ#","#MACBOOK#","#SHOCK#","#NONY#" };
string str;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str;
	//2.각 문자열 마다 계속 반복
	//1)만약 문자열 find값이 -1이면 중단
	//2)replace
	for (int i = 0; i < 5; i++) {
		while (1) {
			if ((int)str.find(before[i]) == -1) {
				break;
			}
			str.replace(str.find(before[i]), before[i].size(), after[i]);
		}
	}
	//3.출력: 완성 문자열
	cout << str;
	return 0;
}
