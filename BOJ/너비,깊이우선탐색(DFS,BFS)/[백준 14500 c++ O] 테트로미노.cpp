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

// [백준 14500 c++ O] 테트로미노
// 문제: 가능한 5종류의 칸의 합 중 테트로미노 각 칸의 합의 최대값 구하기
// 접근:  칸의 개수 4개 -> depth가 4인 dfs 생각 ->  근데 ㅗㅓㅏㅜ 는 dfs로 탐색 불가능한 모양 이어서 따로 계산 
// 풀이: 
// 뎁스가4 인 완전탐색 dfs로 테트로 미노의 최댓값 갱신
// ㅏㅓㅗㅜ 모양은 중심칸의 인덱스 조건 걸고 각자 계산 후 최댓값 갱신
// 최댓값 출력
// 주의 : dfs 에 memset으로 visited 배열 초기화 하면 시간초과 -> 그냥 다시 0 대입

using namespace std; // cin,cout 편하게 사용 라이브러리 
#define MAX 501

int ar[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[MAX][MAX];

int n, m;
int maxnum = 0;

void dfs(int row, int col,int sum,int cnt)
{
	if (cnt == 4) {
		maxnum = max(sum, maxnum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int currow = dy[i] + row;
		int curcol = dx[i] + col;

		if (currow >= 0 && currow < n && curcol >= 0 && curcol < m) {
			if (visited[currow][curcol] == 0) {
				visited[currow][curcol] = 1;
				dfs(currow, curcol, sum+ar[currow][curcol],cnt+1);
				visited[currow][curcol] = 0;
			}
		}
	}
}


int main()
{
	// IO 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 나머지 테트로미노 모양 계산
			visited[i][j] = 1;
			dfs(i, j, ar[i][j], 1);
			//memset(visited, 0, sizeof(visited));
			visited[i][j] = 0;
			// ㅏㅓㅗㅜ모양 계산
			if (i > 0 && i < n - 1 && j < m - 1) { // ㅏ 모양
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i + 1][j] + ar[i - 1][j], maxnum);
			}
			if (i > 0 && i < n - 1 && j >0) { // ㅓ모양
				maxnum = max(ar[i][j] + +ar[i][j - 1] + ar[i + 1][j] + ar[i - 1][j], maxnum);
			}
			if (i > 0 && j > 0 && j < m - 1) {// ㅗ
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i][j - 1] + ar[i - 1][j], maxnum);
			}
			if (i < n - 1 && j >0 && j < m - 1) { // ㅜ
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i][j - 1] + ar[i + 1][j], maxnum);
			}
			
		}

		
		
	}

	cout << maxnum<<'\n';
	

	return 0;
}
