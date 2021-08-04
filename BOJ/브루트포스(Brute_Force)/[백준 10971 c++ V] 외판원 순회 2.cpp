#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10971 c++ V] 외판원 순회 2
// 접근:최소비용-> 완탐(재귀,순열),그리디,dp, -> 중복없는 탐색 = 순열 -> 완전탐색 순열이용
// 접근2: 수열 -> 수열 정렬시키고 next_permutation 함수 이용
// 시간복잡도: O(n!*n) : 순열의 경우=n! , 가중치 합=n
// 풀이:
// 수열 입력
// 순열 완전탐색- 가지 못하는 경우 예외처리,- 갈 수 있으면 가중치 합 구하기
// 개념:next_permutation(시작주소,끝주소) : 오름차순 정렬시키고 쓰면 역순 차례로 나오고 마지막 false 리턴
#define MAX 11
int n;
int w[MAX][MAX];
bool visit[MAX];
long long minN = 100000001;
int a[MAX];

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
		a[i] = i;
	}
	// 완전탐색 , 순열
	do {
		long long sum=0;
		bool ok = 0;
		for (int i = 1; i < n; i++) {
			if (w[a[i]][a[i + 1]] == 0) { // 예외처리 가지 못하는 경우 
				ok = 1; break;
			}
			sum += w[a[i]][a[i + 1]];
		}
		if (ok || w[a[n]][a[1]] == 0) { continue; }// 예외처리 가지 못하는 경우 
		sum += w[a[n]][a[1]];
		minN = min(minN, sum);
	} while (next_permutation(a+1 , a + n+2 ));

	cout << minN << '\n';
	return 0;
}
