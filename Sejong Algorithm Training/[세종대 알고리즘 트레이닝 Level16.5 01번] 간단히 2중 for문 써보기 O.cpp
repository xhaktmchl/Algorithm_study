#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16.5 01번] 간단히 2중 for문 써보기 O
문제:
접근:
풀이:
시간복잡도: O()
*/
int a, b, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> a >> b >> c;
	//2.a~b까지 C번 반복 출력
	for (int i = 0; i < c; i++) {
		for (int j = a; j <= b; j++) {
			cout << j << " ";
		}cout << '\n';
	}
	return 0;
}
