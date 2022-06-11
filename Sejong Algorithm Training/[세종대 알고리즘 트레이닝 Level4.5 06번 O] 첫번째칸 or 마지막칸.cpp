#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level4.5 06번 O] 첫번째칸 or 마지막칸
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int ar[10] = { 3,9,12,15,55 };
int a, b, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum > 10) {
		cout << ar[4];
	}
	else { cout << ar[0]; }
    return 0;
}
