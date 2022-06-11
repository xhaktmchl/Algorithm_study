#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level05.5 05번 O] 입력받은 값 배열에 채우기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch;
int ar[10] = { 4,1,2,3,5 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch;
	if (ch == 'a' || ch == 'b' || ch == 'c') {
		for (int i = 3; i >= 0; i--) {
			cout << ar[i]<<" ";
		}
	}
	else {
		for (int i = 4; i >= 1; i--) {
			cout << ar[i] << " ";
		}
	}
    return 0;
}
