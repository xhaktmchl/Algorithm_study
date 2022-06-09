#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level05 13번 O] 입력받은 값만큼 건너띄어서 출력하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int a[20] = { 3,4,1,5,8,1,7,7,3,6,9 };
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < 11; i += n) {
		cout << a[i] << " ";
	}
    return 0;
}
