#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17.5 01번] 저격 SUM O
문제:
접근:
풀이:
시간복잡도: O(n)=
*/
int a[15] = { 3,4,1,1,2,6,8,7,8,9,10 };
int startIdx;
int sum = 0;

void getSum(int idx) {
	for (int i = idx; i < idx + 5; i++){
		sum += a[i];
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> startIdx;
	//2.getSum으로 5칸 뒤까지 합
	getSum(startIdx);
	//3.출력
	cout << sum << '\n';
	return 0;
}
