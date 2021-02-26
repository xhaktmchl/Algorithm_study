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

// [���� 2644  c++ V] �̼����
// ����: �θ�� �ڽ��� �̼��� 1�� �ؼ� �־��� �� ����� �̼��� ���ϴ� ����
// ����: ������Ĺ�� dfs �� �θ�� �ڽ��� ���踦 ����� �׷����� ǥ��
// Ǯ��: ���͹迭�� 2���� �迭�� ����� �׷��� �Է�
// ã�⸸ �ϰ� �ʱ�ȭ �����൵ �Ǵ� �⺻ dfs �̿��ؼ� ��������Ʈ �׷��� Ž��

using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 101

vector<int> graph[MAX];
int visited[MAX];
int n, target1, target2, m;
int ans = -1;

void dfs(int p, int c,int cnt)
{
	visited[p] = 1;
	// ��������
	if (p == c) {
		ans = cnt; return;
	}
	
	for (int i = 0; i < graph[p].size(); i++)
	{
		if (visited[graph[p][i]] == 0)
		{
			dfs(graph[p][i], c, cnt + 1);
		}
	}
}
int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n >> target1 >> target2 >> m;
	for (int i = 0; i < m; i++)
	{
		int par, child;
		cin >> par >> child;
		// ����� �׷��� ����
		graph[par].push_back(child);
		graph[child].push_back(par);

	}
	dfs(target1, target2, 0);
	cout << ans;

	return 0;
}



