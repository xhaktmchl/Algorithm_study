#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 07번 O] MAX, MIN 찾아내기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	
	int maxN = a[0];
	int minN = a[0];
	for (int i = 0; i < 7; i++) {
		maxN = max(maxN, a[i]);
		minN = min(minN, a[i]);
	}

	cout << "MAX=" << maxN << '\n' << "MIN=" << minN;
	return 0;
}
