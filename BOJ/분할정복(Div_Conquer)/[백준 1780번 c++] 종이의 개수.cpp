#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<string> // c++ 문자열 클래스
#include<vector> // 동적배열 라이브러리
#include<stack>
#include<queue>
#include<algorithm>  // sort와 unique 사용
#include<cmath> // 제곱이나 루트함수 사용
#include<cstring> // memset 함수

// 백준 1780번 종이의 개수
// 접근: 백준 다른4분할 문제랑 비슷하다고 생각하고 분할정복 생각함
// 풀이: 분할정복 재귀를 이용해 각 구역에서 탐색하다 숫자 다르면 9분할 함
// 주의: 분할할 때 인덱스 조심

#define MAX 5000
using namespace std; // cin,cout 편하게 사용 라이브러리

int n;
int minu = 0;
int zero = 0;
int plu = 0;

int map[MAX][MAX];
// 분할정복 함수
void div_con(int row, int col,int N)
{
	// 종이 개수가 1인 경우 
	if (N == 1)
	{
		if (map[row][col] == -1) { minu++; }
		if (map[row][col] == 0) { zero++; }
		if (map[row][col] == 1) { plu++; }
		return;
	}
	

	// 9분할 탐색하면서 재귀
	for (int i = row; i < row+N; i++)
	{
		for (int j = col; j < col + N; j++)
		{
			// 종이가 같지 않으면
			if (map[row][col] != map[i][j])
			{
			   // 9분할
				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						div_con(row+ r * N / 3,col+  c * N / 3, N / 3); // 분할을 시작하는 위치
					}
				}
				return;
			}
		}
	}

	// 다 돌았는데 넘어오면 다 같은 숫자종이
	if (map[row][col] == -1) { minu++; }
	if (map[row][col] == 0) { zero++; }
	if (map[row][col] == 1) { plu++; }
}

int main()
{
	// IO 속도 향상
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	// 분할정복 탐색
	div_con(0, 0, n);

	cout << minu << '\n';
	cout << zero << '\n';
	cout << plu << '\n';
    return 0;
}



