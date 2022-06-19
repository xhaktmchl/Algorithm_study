#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 01번 O] char배열 대신 string
문제:
접근: 
풀이: 
	//1.입력
	//2.출력: 정순 출력, 역순 출력
시간복잡도: O()=
*/
string a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.출력: 정순 출력, 역순 출력
	cout << a<<'\n';
	int len = a.size();
	for (int i = len - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
