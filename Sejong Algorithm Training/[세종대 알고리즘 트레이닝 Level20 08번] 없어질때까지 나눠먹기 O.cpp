#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 08번] 없어질때까지 나눠먹기 O
문제:
접근: 재귀
풀이:
	//1.입력
	//2.재귀
	//1)기저조건: num이0이면
	// 중단
	//2) 재귀: num/2
	//3) 출력:num
시간복잡도: O()=
*/
int n;

void re(int num) {
	if (num == 0) {
		return;
	}

	re(num / 2);
	cout << num << " ";
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	//2.재귀
	//1)기저조건: num이0이면 
	// 중단
	//2) 재귀: num/2
	//3) 출력:num
	re(n);
	return 0;
}
