#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 01번 O] 원하는 값을 찾아내자 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10] = { 4,3,6,1,3,1,5,3 };
int n, cnt=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < 8; i++) {
		if (a[i] == n) {
			cnt++;
		}
	}

	cout << "숫자" << n << "개수는" << cnt << "개";
	return 0;
}
