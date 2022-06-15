#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 02번 O] 너와 나의 거리 구하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int dist[10] = { 4,2,5,1,6,7,3 };
char ch1, ch2;
int sum = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2;
	if (ch1 > ch2) { swap(ch1, ch2); }

	for (int i = ch1 - 'A'+1; i < ch2 - 'A'; i++) {
		sum += dist[i];
	}

	cout << sum;
	return 0;
}
