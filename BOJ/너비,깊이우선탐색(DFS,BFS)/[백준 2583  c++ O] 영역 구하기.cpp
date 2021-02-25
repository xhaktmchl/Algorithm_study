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

// [���� 2583  c++ O] ���� ���ϱ�
// ����: �迭���� ���簢���� ������ ������ ������ ���� ������ ������ ���Ľ��� ���ϴ� ����
// ����: �⺻ dfs �� Ž��
// Ǯ��: �迭 �Է¹ް�
// �⺻ ����Ž�� dfs �ϸ鼭 ������ ������ ���������� ���� ���� ����
// ���������� ������ ���Ϳ� ���� �� ����
using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 101

int graph[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int h, k, w;
vector<int> v;
int cnt = 0;
int block = 0;
void dfs(int row, int col)
{
	for (int i = 0; i < 4; i++)
	{
		int nrow = row + dy[i];
		int ncol = col + dx[i];
		// ���� �ȿ� �ְ� �湮���� ���� ���� ���簢�� ������
		if (nrow >= 0 && ncol >= 0 && nrow < h && ncol < w)
		{
			if (visited[nrow][ncol] == 0 && graph[nrow][ncol] == 0)
			{
				visited[nrow][ncol] = 1;
				cnt++;
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
	cin >> h >> w >> k;
	for (int i = 0; i < k; i++)
	{
		int xs, xe, ys, ye;
		cin >> xs >> ys >> xe >> ye;
		for (int j = ys; j < ye; j++)
		{
			for (int p = xs; p < xe; p++)
			{
				graph[j][p] = 1;
			}
		}

	}
	// ���̿켱Ž��
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == 0 && graph[i][j] == 0)
			{
				block++;
				cnt = 1;
				visited[i][j] = 1;
				dfs(i, j);
				v.push_back(cnt);
				
			}
		}
	}

	sort(v.begin(), v.end());
	
	cout << block << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}



