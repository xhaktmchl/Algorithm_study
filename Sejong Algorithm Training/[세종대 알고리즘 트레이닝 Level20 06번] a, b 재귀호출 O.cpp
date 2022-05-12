#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 06번] a, b 재귀호출 O
문제:
접근: 재귀
풀이:
	//1.입력
	//2.재귀
	//1)기저조건: b 까지 오면
	// 출력
	//중단
	//2)숫자 출력
	//3)재귀: 숫자+1
	//4)숫자 출력
시간복잡도: O()=
*/
int a, b;

void re(int cur) {
	if (cur == b) {
		cout << cur << " ";
		return;
	}

	cout << cur<<" ";
	re(cur + 1);
	cout << cur << " ";
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> a >> b;
	//2.재귀
	//1)기저조건: b 까지 오면 
	// 출력
	//중단
	//2)숫자 출력
	//3)재귀: 숫자+1
	//4)숫자 출력
	re(a);
	return 0;
}
