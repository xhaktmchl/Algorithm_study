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

// [���� 5567 c++ V] ��ȥ�� 
// ����:  �׷��� �� �̾��� ����� ģ���� ģ���� ����  �� �� ����
// ����:  ��������Ʈ ����� �׷����� bfs Ž��
// Ư����: dfs���� depth�� �̿��ϴ� ����
// Ǯ��: 
// ��������Ʈ ����� �׷��� �Է�
// bfs Ž������ ����� ģ�� Ž���ϸ� �湮�迭�� ģ���迭 �ֽ�ȭ
// �ֽ�ȭ�� ģ���迭�� �̿��� ��������Ʈ Ž���ϸ� ģ���� ģ�� Ž���ϸ� �湮ó��
// �湮�迭 Ž���ؼ� ������ �� ���
// Ǯ��2:
// dfs�� 1(���)���� �����ϴ� �͸� dfs Ž�� 

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 501

int n, m;
int arr[MAX][MAX];
int visited[MAX];
int FrOfFriend[MAX];

void dfs(int node,int cnt) {
	
	if (cnt == 2) { // ģ���� ģ������ Ž��
		return;
	}
	for (int i = 2; i <= n; i++) {
		// �湮���� �ʰ� ģ�����
		if (arr[node][i]==1 && visited[i] == 0) {
			visited[i] = 1;
			FrOfFriend[i] = 1; // ģ���� �迭 ǥ��
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	
	}
}


int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n >> m;
	int n1, n2;
	// ��������Ʈ �Է�
	for (int i = 1; i <= m; i++)
	{
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	//bfs();
	visited[1] = 1;
	dfs(1, 0); // ��尡 1���� ����̺��� �����ؼ� ������ 2�� �ͱ����� dfs

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (FrOfFriend[i] == 1) {
			c++;
		}
	}
	cout << c << '\n';

	return 0;
}
