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

// ���� 1676�� ���丮�� 0�� ����
// ����1: ���丮�� ���ϰ� ���ڿ��� ��ȯ �� �ڿ������� ���
// ����2: ���丮�� ���� �� mod�̿��ؼ� ���� �ڿ��� ���� ���ʷ� 
// ������ �� �ð��ʰ����� Ʋ���µ�
// Ǯ��: ���μ� ���� ��� 2*5 �� 10���� 0�� �����Ƿ� 2��5�� ������ �������� 0�� �����̴�
// �׷��� 5�ǰ����� 2�� �������� �׻� �����Ƿ� 5�� ������ ���Ѵ�
// 5�� ������ ���ϴµ� 5,25,125 �� ���� ���� ���Ѱ��� 5�� ����
// ����: string �ڷ����� �� �ε��� �� ���̾ƿ��� ��
using namespace std; // cin,cout ���ϰ� ��� ���̺귯��

int n;

int main()
{
	// IO �ӵ� ���
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	// n������ 500 �����Ƿ�
	int zero = n / 5 + n / 25 + n / 125;
	cout << zero;
    return 0;
}



