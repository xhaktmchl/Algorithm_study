#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level4.5 02번 O] 복잡한 조건에 따라 문제 풀어보기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	if(n!=3){
		cout << "3이 아니다" << '\n';
	}
	if (n != 5) {
		cout << "5가 아니다" << '\n';
	}
	if (n > 1 && n < 10) {
		for (int i = 5; i >= 1; i--){
			cout << i << '\n';
		}
	}
    return 0;
}
