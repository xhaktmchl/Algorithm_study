#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c ���� �������
#include<string> // c++ ���ڿ� Ŭ����
#include<vector> // �����迭 ���̺귯��
#include<stack>
#include<queue>
#include<algorithm>  // sort�� unique ���
#include<cmath> // �����̳� ��Ʈ�Լ� ���
#include<cstring> // memset �Լ�

// ���� 1780�� ������ ����
// ����: ���� �ٸ�4���� ������ ����ϴٰ� �����ϰ� �������� ������
// Ǯ��: �������� ��͸� �̿��� �� �������� Ž���ϴ� ���� �ٸ��� 9���� ��
// ����: ������ �� �ε��� ����

#define MAX 5000
using namespace std; // cin,cout ���ϰ� ��� ���̺귯��

int n;
int minu = 0;
int zero = 0;
int plu = 0;

int map[MAX][MAX];
// �������� �Լ�
void div_con(int row, int col,int N)
{
	// ���� ������ 1�� ��� 
	if (N == 1)
	{
		if (map[row][col] == -1) { minu++; }
		if (map[row][col] == 0) { zero++; }
		if (map[row][col] == 1) { plu++; }
		return;
	}
	

	// 9���� Ž���ϸ鼭 ���
	for (int i = row; i < row+N; i++)
	{
		for (int j = col; j < col + N; j++)
		{
			// ���̰� ���� ������
			if (map[row][col] != map[i][j])
			{
			   // 9����
				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						div_con(row+ r * N / 3,col+  c * N / 3, N / 3); // ������ �����ϴ� ��ġ
					}
				}
				return;
			}
		}
	}

	// �� ���Ҵµ� �Ѿ���� �� ���� ��������
	if (map[row][col] == -1) { minu++; }
	if (map[row][col] == 0) { zero++; }
	if (map[row][col] == 1) { plu++; }
}

int main()
{
	// IO �ӵ� ���
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
	// �������� Ž��
	div_con(0, 0, n);

	cout << minu << '\n';
	cout << zero << '\n';
	cout << plu << '\n';
    return 0;
}



