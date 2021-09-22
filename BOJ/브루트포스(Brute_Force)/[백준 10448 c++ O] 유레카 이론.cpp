#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 10448 c++ O] 유레카 이론
문제: k가 삼각수의 3개의 삼각수의 합으로 표현 되는지 유무 출력
접근: 삼각수의 중복이 허용 -> 모든 수 더하는 완탐 재귀 -> 재귀 종료
시간복잡도: O(44*3) 
풀이1:
k가 1000 이하이기 때문에 삼각수 최대 n은 44 -> 삼각수 T44까지 저장
완탐 재귀 -> 합,더한 수의 갯수 인자 -> 3가지 삼각수를 더하는 모든 경우 재귀 -> 만들 수 있는 수 ok배열에 가능유무 저장
재귀종료, 3개의 수를 더한 경우
ok 에 가능 유무 저장해서 출력
*/
#define MAX 50
int t,k;
int a[MAX];
bool ok[1001];
// 완탐 재귀
void re(int sum,int cnt) { // 합,더한 삼각수 갯수
	if(cnt == 3) { ok[sum]=1; return; }
	
	for (int i = 1; i <= 44; i++) { // 삼각수 모든 수 탐색
		if (sum + a[i] <= 1000 && cnt + 1 <= 3) { // 합, 수의 갯수 조건
			re(sum + a[i], cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	// 삼각수 계산 및 저장
	for (int i = 1;i<=44; i++) {
		a[i] = i * (i + 1) / 2;
	}
	re(0, 0); // 완탐 재귀로 만들 수 있는 합 유무 저장
	while (t--) {
		cin >> k;
		if (ok[k]) { cout << 1 << '\n'; }
		else { cout << 0 << '\n'; }
	}
	return 0;
}
