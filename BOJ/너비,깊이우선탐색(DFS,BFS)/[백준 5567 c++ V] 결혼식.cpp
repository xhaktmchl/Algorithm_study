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
// Ǯ��: 
// ��������Ʈ ����� �׷��� �Է�
// bfs Ž������ ����� ģ�� Ž���ϸ� �湮�迭�� ģ���迭 �ֽ�ȭ
// �ֽ�ȭ�� ģ���迭�� �̿��� ��������Ʈ Ž���ϸ� ģ���� ģ�� Ž���ϸ� �湮ó��
// �湮�迭 Ž���ؼ� ������ �� ���

using namespace std; // cin,cout ���ϰ� ��� ���̺귯�� 
#define MAX 501

int n, m;
int arr[MAX][MAX];
int visited[MAX];
int FrOfFriend[MAX];

void bfs() {
	// ����� ģ�� Ž��
	for (int i = 1; i <= n; i++) {
		// ����̿� ģ����� �湮ó��
		if (arr[1][i] == 1) {
			visited[i] = 1;
			FrOfFriend[i] = 1; // ģ���� ģ��
		}
	}

	// ģ���� ģ�� Ž��
	for (int i = 1; i <= n; i++) {
		if (FrOfFriend[i] == 1) { // ������� ģ�����
			for (int j = 1; j <= n; j++) { 
				if (arr[i][j] == 1) {// ģ���� ģ�� ��� Ž���� �湮
					visited[j] = 1;
				}
			}
		}
	}

	// �ʴ��ϴ� ������ �� ���
	int c = 0;
	for (int i = 2; i <= n; i++) { // ����̸� �����ؼ� 2������ ����
		if (visited[i] == 1)
		{
			c++;
		}
	}
	cout << c;
}


int main()
{
	// IO �ӵ� ���
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);// ����� �ð� ����
	cin >> n>>m;
	int n1, n2;
	// ��������Ʈ �Է�
	for (int i = 1; i <= m; i++)
	{
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	bfs();
	
	return 0;
}
