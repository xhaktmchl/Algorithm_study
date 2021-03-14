#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c ���� �������
#include<string> // c++ ���ڿ� Ŭ����
#include<vector> // �����迭 ���̺귯��
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>  // sort�� unique ���
#include<cmath> // �����̳� ��Ʈ�Լ� ���
#include<cstring> // memset �Լ�
#include <set>
#include <map> // map����ü
#include <numeric> //accumulate(v.begin(), v.end(), 0);

// [���� 1743 c++ O] ���Ĺ� ���ϱ� 
// ����: �迭�� �������ִ� ���Ĺ��� ũ���� ���� ���� ū ���Ĺ��� ũ�⸦ ���
// ����: 4���������ϸ� �ϳ��� ���Ĺ��� ���� -> �⺻ dfs Ž��
// Ǯ��: �迭�� ũ��� ���Ĺ� ��ġ �Է�
// �⺻ ����Ž�� dfs 
// ���Ĺ��� �ִ�ũ�� �ֽ�ȭ
// ���Ĺ� �ִ�ũ�� ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 101

int n, m, k;
int ar[MAX][MAX];
int visited[MAX][MAX];
int cnt = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int max_n = 0;
// �⺻dfs
void dfs(int row, int col)
{
	visited[row][col] = 1;
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		int nrow = row + dy[i];
		int ncol = col + dx[i];

		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
			if (visited[nrow][ncol] == 0 && ar[nrow][ncol] == 1) {
				dfs(nrow, ncol);
			}
		}
	}
}

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int ro, co;
		cin >> ro >> co;
		ar[ro-1][co-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && ar[i][j] == 1) {
				dfs(i, j);
				max_n = max(max_n, cnt);
				cnt = 0;
			}
		}
	}

	cout << max_n;
	
	return 0;
}

