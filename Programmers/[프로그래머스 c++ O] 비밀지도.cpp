#include <string>
#include <vector>
#include <cstring>

using namespace std;
// [���α׷��ӽ� c++ O] �������
// ����: �� ���� ������ ���� ������ ������->������ �ص� �� �ϳ��� ������ ���ļ� ������� �ؼ� �� ���ڿ� ���
// ����:  2���� ������ �ؼ��ؼ� ����1 ������ 0���� 1���� �����迭 ��ħ -> ��������迭 �ؼ�
// Ǯ��: 
// 2�� ������� �迭 0���� �ʱ�ȭ
// ����1, ����2 ���� ������->������ ��ȯ�ϸ� 1�� ��� �������1 ����
// ������ ������� �ݺ��� Ž���ϸ� 1�� ��� tp ��Ʈ���� �߰�
// �� ���� �ϼ��Ǹ� ���� ��Ʈ���� tp�߰�
// ����: memset(�迭,����,ũ��sizeof(�迭)) , ���#include <cstring>

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int maps[n][n];
    memset(maps, 0, sizeof(maps));

    // arr1
    for (int i = 0; i < n; i++) {
        // ������ -> ������
        int c = 0;
        while (arr1[i] > 0) {
            if (arr1[i] % 2 == 1) { maps[i][n - 1 - c] = arr1[i] % 2; }
            arr1[i] /= 2; c++;
        }
    }

    // arr2
    for (int i = 0; i < n; i++) {
        // ������ -> ������
        int c = 0;
        while (arr2[i] > 0) {
            if (arr2[i] % 2 == 1) { maps[i][n - 1 - c] = arr2[i] % 2; }
            arr2[i] /= 2; c++;
        }
    }

    // �ϼ��� ������� �ص�
    for (int i = 0; i < n; i++) {
        string tp;
        for (int j = 0; j < n; j++) {
            if (maps[i][j] == 1) { tp.push_back('#'); }
            else { tp.push_back(' '); }
        }
        // �ؼ��� �� �� ���ڿ� Ǫ��
        answer.push_back(tp);
    }
    return answer;
}