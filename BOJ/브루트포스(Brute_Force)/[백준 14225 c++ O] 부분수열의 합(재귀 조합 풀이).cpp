#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 14225 c++ O] 부분수열의 합
// 문제: 부분수열의 모든 합을 제외한 가장 작은 자연수 구하기
// 접근: 부분수열의 조합 -> 완탐(재귀 순차탐색) -> 조합이므로 중복 없음, -> 부분수열의 합을 visit 배열로 유무처리
// 재귀인자(현재 수열의 인덱스, 현재까지  부분수열 합)
// 시간복잡도: O(2^n) : 2^20 = 약100만 
// 공간복잡도: 모든 합 최대 = 200만 , visit[200만]
// 접근2: 완탐 재귀(조합) -> 숫자 선택 하고 / 안하고 -> 마지막 까지 탐색햇을때 모드 부분수열 나옴
// 풀이1: 모든 재귀 순차탐색
// 수여 입력
// 완탐 재귀 (, 중복없이 다음 인덱스 탐색, 수열이 끝까지 탐색했을 때 종료)
// 풀이2: 완탐 재귀 조합
#define MAX 21
int n;
vector<int> a(MAX);
vector<bool> visit(2000010);

// 재귀 조합
void re1(int idx, int sum) {
	if (idx == n) {
		visit[sum] = 1;
		return;
	}
	re1(idx + 1, sum + a[idx]); // 숫자 선택하는 경우
	re1(idx + 1, sum); // 선택하지 않는경우
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	re1(0, 0);
	cout<<find(visit.begin() + 1, visit.end(), 0)-visit.begin()<<'\n';
	return 0;
}



