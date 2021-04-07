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

// [백준 9184 c++ O] 신나는 함수 실행
// 문제: 입력값에 따라 주어진 재귀함수가 시간초과가 나지않는 코드 짜기
// 접근1: 재귀 시간 단축 -> dp로 함수 반환값 dp배열에 저장하며 반환
// 풀이: 주어진 대로 재귀함수를 작성한다
// 반환할 때 저장이 된 코드이면 dp 배열 바로 반환
// 저장이 않되어있으면 dp 배열에 재귀값 저장하며 반환

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 51

int dp[MAX][MAX][MAX];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) { return 1; }
	else if (a > 20 || b > 20 || c > 20) {
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(20, 20, 20); } // 저장 않됬으면 저장하며 반환
		else { return  dp[a][b][c]; } // 저장 됬으면 바로 반환
		
	}
	else if (a < b && b < c) {
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); }
		else { return  dp[a][b][c]; }
	}
	else { 
		if (dp[a][b][c] == 0) { return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); }
		else { return  dp[a][b][c]; }
	}
}

int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) { break; }
		printf("w(%d, %d, %d) = %d\n", x, y, z, w(x, y, z));
	}

	return 0;
}

