#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수
#include <set>
#include <map> // map구조체
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [백준 12856 c++ &] 평범한 배낭
// 문제: 가방에 넣을 수 있는 무게대비 최대 가치를 구하는 문제
// 접근:  재귀로 모든 경우의 수 탐색 -> 시간초과 예상 안함
// 접근2: dp
// 풀이: 
// dp[i-1][j]// 기존 탐색했던 물건들로만 j를 만드는 것 //가방에 넣을수 있는지 없는지
// dp[i-1][j-w[i]] 기존 탐색했던 물건들로 무게j-w[i]를 만들고 현재 물건을 가방에 넣는  경우// 가방에 넣을 수 있으면 넣는것과 안넣는것중 가치 큰값 저잦ㅇ

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 101

int w[MAX];
int v[MAX];
int dp[MAX][100001];

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	//dp
	for (int i = 1; i <= n; i++) { // i번째 물건
		for (int j = 1; j <= k; j++) { // j 무게
			if (w[i] <= j) { dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);} // 물건 넣을 수 있는데 안 넣는 것과 그 물건을 전의 무게에서 넣은 것중 큰 값을 dp 에 저장
			else { dp[i][j] = dp[i - 1][j]; } // 물건 못넣은 것
		}
	}
	
	cout << dp[n][k];
	
	return 0;
}

