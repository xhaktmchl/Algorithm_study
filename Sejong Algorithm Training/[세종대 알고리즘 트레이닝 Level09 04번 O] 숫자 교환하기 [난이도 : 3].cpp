#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 04번 O] 숫자 교환하기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[10] = { 3,4,2,5,7,9 };
int idx1, idx2;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> idx1 >> idx2;
	swap(a[idx1], a[idx2]);

	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
