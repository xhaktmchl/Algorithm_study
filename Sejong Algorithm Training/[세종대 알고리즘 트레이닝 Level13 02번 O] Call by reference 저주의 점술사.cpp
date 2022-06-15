#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13 02번 O] Call by reference 저주의 점술사
문제:
접근: 
풀이: 
시간복잡도: O()=
*/

void moom(int n,int* n1, int* n2, int* n3) {
	*n1 = n - 4;
	*n2 = n + 3;
	*n3 = n * 2;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int n;
	cin >> n;
	int res1, res2, res3;
	moom(n,&res1, &res2, &res3);

	cout << res1<<" " << res2 <<" "<< res3;
	return 0;
}
