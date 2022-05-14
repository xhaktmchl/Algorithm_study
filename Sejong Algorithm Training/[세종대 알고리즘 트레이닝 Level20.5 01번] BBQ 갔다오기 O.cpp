#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 01번] BBQ 갔다오기 O
문제:
접근: 재귀
풀이:
시간복잡도: O()=
*/

//재귀
//1)cnt( 몇번째 인지)
//2)기저조건: cnt==3이면 중단
//3)재귀
void re(int cnt) {
	if (cnt == 3) {
		return;
	}

	re(cnt + 1);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//재귀
	re(1);
	return 0;
}
