#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업 08번 O] 카드를 뒤집어 점수 더하기
문제:
접근: 
풀이: 완탐 재귀
	//1.입력
	//2.완탐 재귀: 각 카드의 앞,뒤 경우
	//1)기저: 만약 n번째 카드이면
	//합이 a,b범위 내에 있으면 카운트
	//중단
	//2)재귀
	//idx번째 카드들 더한 경우
	//idx번째 카드를 뺀 경우
	//3.출력:
시간복잡도: O(2^n)=2^20=약 100만
*/
int n;
int input[30],a,b,cnt=0;

//2.완탐 재귀: 각 카드의 앞,뒤 경우
//1)기저: 만약 n번째 카드이면 
//합이 a,b범위 내에 있으면 카운트
//중단
//2)재귀
//idx번째 카드들 더한 경우
//idx번째 카드를 뺀 경우
void re(int idx,int sum) {
	if (idx == n) {
		if (sum >= a && sum <= b) {
			cnt++;
		}
		return;
	}

	re(idx + 1, sum + input[idx]);
	re(idx + 1, sum - input[idx]);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	cin >> a >> b;
	//2.완탐 재귀: 각 카드의 앞,뒤 경우
	//1)기저: 만약 n번째 카드이면 
	//합이 a,b범위 내에 있으면 카운트
	//중단
	//2)재귀
	//idx번째 카드들 더한 경우
	//idx번째 카드를 뺀 경우
	re(0, 0);
	//3.출력:
	cout << cnt;
	return 0;
}
