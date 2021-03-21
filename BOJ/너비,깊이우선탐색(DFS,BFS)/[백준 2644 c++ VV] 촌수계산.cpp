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

// [���� 2644 c++ VV] �̼����
// ����: ���� ������ ������ �̼� ��� ,������ ���� �ϰ� ã���� �ϴ� ������ �̼� ����ϰ� ������ -1��� Ž�� ����
// ���� ����� ����� �׷����� �����ؾ� ��
// ����1: ������ ���� �ϰ� �⺻ ������� �׷��� dfsŽ�� , ��������� ���ͷ� ����
// Ǯ��: �������� ���� ������Ŀ� ����
// ã���� �ϴ� ������忡�� dfs �����ϰ�
// �ٸ� Ǯ�̵��� dfs�Լ����� visited ��� �ʱ�ȭ �����ִµ� ���� ��� ������ �� �ʱ�ȭ �ؾ��Ѵٰ� �����ؼ� ����
// ��ǥ ���� ã���� ���� ���� �� ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 101

int n, node1, node2,m;
vector<int> ar[MAX];
int visited[MAX];
int cnt = 0;
int ans = -1;

void dfs(int start, int end,int cnt)
{
	if (start == end) { ans = cnt; return; }
	for (int i = 0; i < ar[start].size(); i++) {
		if (visited[ar[start][i]] == 0) {
			visited[start] = 1;
			dfs(ar[start][i], end,cnt+1);
			visited[start] = 0; // ���� ����� �� ��� ���湮 �ʱ�ȭ �ؾ���
		}
	} 
}

int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n>> node1>>node2>>m;
	for (int i = 0; i < m; i++) {
		int pa, ch;
		cin >> pa >> ch;
		ar[pa].push_back(ch);
		ar[ch].push_back(pa);
	}

	visited[node1] = 1;
	dfs(node1, node2,0);
	cout << ans;
	
	return 0;
}

