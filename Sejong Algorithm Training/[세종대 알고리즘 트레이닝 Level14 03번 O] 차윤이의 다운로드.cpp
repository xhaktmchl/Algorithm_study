#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14 03번 O] 차윤이의 다운로드
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct FileDown {
	int a;
	int b;
}F;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	F f;
	cin >> f.a >> f.b;
	while (f.a < 100 || f.b < 100) {
		if (f.a < 100) { f.a++; }
		if (f.b < 100) { f.b++; }
		cnt++;
	}

	cout << cnt;
	return 0;
}
