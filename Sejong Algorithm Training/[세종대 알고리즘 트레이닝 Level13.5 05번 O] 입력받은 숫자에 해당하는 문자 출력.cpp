#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 05번 O] 입력받은 숫자에 해당하는 문자 출력
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[4][10] = {
	"457132",
	"DFQWGZ"
};
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 6; i++) {
		if (a[0][i]-'0' == n) {
			cout << a[1][i];
			break;
		}
	}
	return 0;
}
