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

// [���� 1325 c++ V] ȿ������ ��ŷ
// ����: ��ǻ�͸� ���� �����ϸ� ���� ���� ��� Ž���ϴ� ��ǻ�� ��ȣ ������������ ���
// ���� �⺻ �׷��� Ž�� ����
// a�� b �ŷ� = b->a ���� ���Ϲ��� ������ �ǹ�
// ����1: ��ǻ�͸� ���� �����ϸ� �� ��忡���� dfs�� Ž�� ���� ����
// Ǯ��: �� ��忡���� �⺻ dfs
// ��ǻ���� ���� �ִ밪���� ũ�� check���� clear�� ����
// ��ǻ���� ���� �ִ񰪰� ������ check���Ϳ� �߰�
// �������� �� ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯��
#define MAX 10001

int n, m;
vector<int> ar[MAX];
int visited[MAX];
int end_node, start_node;
int maxn=0;
vector<int> check;
int cnt = 0;

void dfs(int node)
{
	visited[node] = 1;

	for (int i = 0; i < ar[node].size(); i++) {
		if (visited[ar[node][i]] == 0) {
			cnt++;
			dfs(ar[node][i]);
		}
	}

}
int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n>>m ;
	for (int i = 0; i < m; i++) {
		// ���Ϳ� ���� �߰�
		cin >> end_node >> start_node;
		ar[start_node].push_back(end_node);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		dfs(i);

		if (cnt > maxn) {
			maxn = cnt;
			check.clear();
			check.push_back(i);
			
		}
		else if (cnt == maxn) {
			check.push_back(i);
		}

	}
	
	sort(check.begin(), check.end());
	for (int i = 0; i < check.size(); i++) {
		cout << check[i]<<" ";
	}
	
	return 0;
}

