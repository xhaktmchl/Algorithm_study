#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level06.5 11번 O] 너와 나의 간격 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> ch1 >> ch2;
	cout << (int)(ch2 - ch1);
    return 0;
}
