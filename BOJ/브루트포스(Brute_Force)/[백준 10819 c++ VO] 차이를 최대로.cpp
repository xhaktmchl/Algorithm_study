#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10819 c++ VO] 차이를 최대로 
// 접근:최대값-> 완탐,그리디,dp, -> 주어진 식의 조합중 최대값 구하기-> 완전탐색 재귀 /  dfs -> 중복안됨=방문배열 사용
// 접근2: 수열 -> 수열 정렬시키고 next_permutation 함수 이용
// 시간복잡도: O(n!*n) : 순열의 경우=n! , 합계산=n
// 풀이:
// 수열 입력
// 정렬시켜 첫 순열 만들기
// 모든 수열에 대해 합 구하기
// 개념:next_permutation(시작주소,끝주소) : 오름차순 정렬시키고 쓰면 역순 차례로 나오고 마지막 false 리턴
#define MAX 9
int n;
int a[MAX];
int maxN=-100000;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 모든 순열 구현
	sort(a, a + n); // 첫 순열 만들기
	do {
		int sum = 0;
		for (int i = 0; i < n-1; i ++) {
			sum += abs(a[i] - a[i + 1]);
		}
		maxN = max(maxN, sum);
	} while (next_permutation(a, a + n));

	cout << maxN << '\n';
	return 0;
}
