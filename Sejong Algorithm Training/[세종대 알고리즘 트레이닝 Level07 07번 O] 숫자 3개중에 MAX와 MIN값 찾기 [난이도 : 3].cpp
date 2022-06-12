#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 07번 O] 숫자 3개중에 MAX와 MIN값 찾기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[5], maxN,minN;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		cin>>a[i];
	}

	maxN = a[0];
	minN = a[0];
	for (int i = 0; i < 3; i++) {
		maxN = max(maxN, a[i]);
		minN = min(minN, a[i]);
	}
	cout << "MAX=" << maxN << '\n';
	cout << "MIN=" << minN;
    return 0;
}
