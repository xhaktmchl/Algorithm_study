#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 08번 O] 구간 듣기
문제:
접근:
풀이:
	//1.입력
	//2.(a,b-a+1) 구간만큼 substr
	//3.출력:c만큼 반복
시간복잡도: O()=
*/
string str;
int a, b, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str >> a >> b >> c;;
	//2.(a,b-a+1) 구간만큼 substr
	string tp = str.substr(a, b-a+1);
	//3.출력:c만큼 반복
	for (int i = 0; i < c; i++) {
		cout << tp;
	}
	return 0;
}
