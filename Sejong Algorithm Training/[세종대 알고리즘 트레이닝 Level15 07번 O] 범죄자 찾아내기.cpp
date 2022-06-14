#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15 07번 O] 범죄자 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10] = "ABCZETQ";
string input;
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> input;
	
	for (int i = 0; i < 5; i++) {
		flag = 0;
		for (int j = 0; j < 7; j++) {
			if (a[j] == input[i]) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) {
			cout << input[i] << "=마을사람" << '\n';
		}
		else { cout << input[i] << "=외부사람" << '\n'; }
	}
	return 0;
}
