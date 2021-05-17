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

// [���� 14500 c++ O] ��Ʈ�ι̳�
// ����: ������ 5������ ĭ�� �� �� ��Ʈ�ι̳� �� ĭ�� ���� �ִ밪 ���ϱ�
// ����:  ĭ�� ���� 4�� -> depth�� 4�� dfs ���� ->  �ٵ� �Ǥä��� �� dfs�� Ž�� �Ұ����� ��� �̾ ���� ��� 
// Ǯ��: 
// ������4 �� ����Ž�� dfs�� ��Ʈ�� �̳��� �ִ� ����
// ���äǤ� ����� �߽�ĭ�� �ε��� ���� �ɰ� ���� ��� �� �ִ� ����
// �ִ� ���
// ���� : dfs �� memset���� visited �迭 �ʱ�ȭ �ϸ� �ð��ʰ� -> �׳� �ٽ� 0 ����

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
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
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ������ ��Ʈ�ι̳� ��� ���
			visited[i][j] = 1;
			dfs(i, j, ar[i][j], 1);
			//memset(visited, 0, sizeof(visited));
			visited[i][j] = 0;
			// ���äǤ̸�� ���
			if (i > 0 && i < n - 1 && j < m - 1) { // �� ���
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i + 1][j] + ar[i - 1][j], maxnum);
			}
			if (i > 0 && i < n - 1 && j >0) { // �ø��
				maxnum = max(ar[i][j] + +ar[i][j - 1] + ar[i + 1][j] + ar[i - 1][j], maxnum);
			}
			if (i > 0 && j > 0 && j < m - 1) {// ��
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i][j - 1] + ar[i - 1][j], maxnum);
			}
			if (i < n - 1 && j >0 && j < m - 1) { // ��
				maxnum = max(ar[i][j] + ar[i][j + 1] + ar[i][j - 1] + ar[i + 1][j], maxnum);
			}
			
		}

		
		
	}

	cout << maxnum<<'\n';
	

	return 0;
}
