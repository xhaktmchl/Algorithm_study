#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 14501 c++ VO] 퇴사 
// 접근: 완전탐색으로 최대경우를 조사 -> 그때그때 더해지는 금액의 개수가 달라져서 단순 반복문으로 힘듦->완전탐색 재귀 또는 dfs
// 날짜 중복 안고 다음 날짜부터 넘어감=start인덱스부터 재귀탐색
// 시간복잡도: O()
// 풀이: 
// 시간,비용 배열에 저장하고
// 완전탐색 재귀
// 현재 날짜 상담가능한 경우 
// 상담 불가능한 경우
// 종료조건, 더이상 불가능한 경우
#define MAX 16
int n,maxN=0;
int p[MAX];
int t[MAX];

void re(int start, int sum) { // 날짜, 비용 합
	// 종료조건, 더이상 불가능한 경우
	if (start >= n) {
		maxN = max(maxN, sum);
		return;
	}

    // 해당 날짜에서부터 다음 탐색
	for (int i = start; i < n; i++) {
		if (i + t[i] <= n) { // 상담 가능 비용더함
			re(i + t[i], sum + p[i]);
		}
		else {// 상담 불가능 비용 안더함
			re(i + t[i], sum);
		}
		
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		cin >> p[i];
	}

	re(0, 0);

	cout << maxN << '\n';
	return 0;
}
