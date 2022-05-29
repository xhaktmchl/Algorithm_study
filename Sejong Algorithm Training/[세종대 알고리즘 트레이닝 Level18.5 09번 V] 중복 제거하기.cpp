#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 09번 V] 중복 제거하기
문제:
접근: 
풀이: 문자열 중복제거
	//1.입력
	//2.정렬및 중복제거
	//3.출력
시간복잡도: O()=
*/
string a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	sort(a.begin(), a.end());
	//2.정렬및 중복제거
	a.erase(unique(a.begin(), a.end()), a.end());
	//3.출력
	cout << a;
	return 0;
}
