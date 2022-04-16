#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 01번] 꼬리 찾기 O
문제: 
접근: 
풀이:
시간복잡도: O()
*/
string a[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 1.입력
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	// 2.각 문자열의 마지막 문자 출력
	for (int i = 0; i < 3; i++) {
		cout << a[i][a[i].size()-1];
	}
	return 0;
}
