#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 09번 O] n번 반대로 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;
int a[10] = { 5,4,1,2,7,8 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 5; j >= 0; j--) {
			cout << a[j] << " ";
		}cout << '\n';
	}
    return 0;
}
