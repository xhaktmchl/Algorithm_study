#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 05번] 잡초문자 제거하기 O
문제: 
접근: 
풀이: 완탐
시간복잡도: O(n)
*/
string str;
int idx;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	// 입력
	cin >> str>>idx;
	// 완전 탐색 및 출력
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if(i!= idx) cout << str[i];
	}
	return 0;
}
