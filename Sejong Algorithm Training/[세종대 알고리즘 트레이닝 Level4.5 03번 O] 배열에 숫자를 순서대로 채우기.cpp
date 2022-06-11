#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level4.5 03번 O] 배열에 숫자를 순서대로 채우기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 5; i++) {
		a[i] = n;
	}
	for (int i = 0; i < 5; i++) {
		cout << a[i];
	}
    return 0;
}
