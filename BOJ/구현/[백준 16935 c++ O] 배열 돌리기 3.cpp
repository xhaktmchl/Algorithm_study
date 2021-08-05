#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 16935 c++ O] 배열 돌리기 3
// 문제: 주어진 배열 구현을 수행
// 접근:  배열로 직접 구현 -> 일단 성공
// 접근2: 벡터로 구현 -> 가능한데 내 코드는 범위 에러 남
// 풀이: 

#define MAX 101
int n, m, r;
int a[MAX][MAX];
int b[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m >> r;
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[i][j] = a[n - i - 1][j];
					
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = b[i][j];
				}
			}
		}
		if (op == 2) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[i][j] = a[i][m-j-1];
					
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = b[i][j];
				}
			}
		}
		if (op == 3) {
			for (int  i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					b[i][j] = a[n-j-1][i];
					
				}
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = b[i][j];
				}
			}

			swap(n, m);
			c++;
		}
		if (op == 4) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					b[i][j] = a[j][m-i-1];
					
				}
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = b[i][j];
				}
			}

			swap(n, m);
			c++;
		}

		if (op == 5) {
			for (int  i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i < n / 2 && j < m / 2) { // b 1번 영역
						b[i][j] = a[i+n/2][j];
					}
					if (i < n / 2 && j >= m / 2) {// b 2번 영역
						b[i][j] = a[i][j-m/2];
					}
					if (i >= n / 2 && j >= m / 2) {// b 3번 영역
						b[i][j] = a[i-n/2][j];
					}
					if (i >= n / 2 && j < m / 2) {// b 4번 영역
						b[i][j] = a[i][j+m/2];
					}
					
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = b[i][j];
				}
			}
		}

		if (op == 6) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i < n / 2 && j < m / 2) { // b 1번 영역
						b[i][j] = a[i][j + m / 2]; 
					}
					if (i < n / 2 && j >= m / 2) {// b 2번 영역
						b[i][j] = a[i + n / 2][j];
					}
					if (i >= n / 2 && j >= m / 2) {// b 3번 영역
						b[i][j] = a[i][j - m / 2]; 
					}
					if (i >= n / 2 && j < m / 2) {// b 4번 영역
						b[i][j] = a[i - n / 2][j]; 
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = b[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}

	return 0;
}
