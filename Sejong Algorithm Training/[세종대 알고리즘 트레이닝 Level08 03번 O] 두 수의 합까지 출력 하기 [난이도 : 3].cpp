#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level08 03번 O] 두 수의 합까지 출력 하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a, b,sum=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;
	sum = a + b;
	int cnt = 5;
	while (cnt <= sum) {
		cout << cnt++ << " ";
	}
	return 0;
}
