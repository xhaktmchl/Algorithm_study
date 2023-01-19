#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 11505 c++ V] 구간 곱 구하기
접근1: 
인덱스트리 -> 항상 완전이진트리로 구현해라 -> 현재 풀이
세그트리 -> 이것도 풀이 가능
시간복잡도: 
풀이: 
*/
const int MOD = 1000000007;
const int SIZE = 2097152; // 2^21, 인덱스 트리의  20뎁스의 리프노드의 개수를 커버
const int BASE = 1048576; // 2^20
long long ITree[SIZE]; // 인덱스트리

int n, m, k; // N: 배열사이즈, M:변경횟수, k: 구간곱연산횟수

void update(int b,int c) {
    // 리프노드에 b번째 숫자 c로 업데이트
    b += BASE;
    ITree[b] = c;
    // 그 위로 다시 모두 곱셈 진행
    while ((b /= 2) > 0) {
        ITree[b] = ITree[b * 2] * ITree[b * 2 + 1] % MOD;
    }
}

int calc(int b, int c) {
    b += BASE; c += BASE; // 리프노드에서 b,c번째 수
    long long tp = 1;
    
    //구간곱 구하기
    while (b <= c) {
        if (b % 2 == 1) { // b가 오른쪽 자식이면, 한칸 오른 자식으로 이동
            tp = tp * ITree[b++] % MOD;
        }
        b /= 2; // 부모방향으로 이동
        if (c % 2 == 0) { // c가 왼 자식이면, 한칸 왼쪽 자식으로 이동
            tp = tp * ITree[c--] % MOD;
        }
        c /= 2; // 부모방향으로 이동
    }
    return (int)tp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);

    cin >> n >> m >> k;
    //1.완전이진트리를 인덱스트리로 채우기
    for (int i = BASE + 1; i <= BASE + n; i++) { // 리프노드로 저장
        cin >> ITree[i];
    }
    for (int i = BASE + n + 1; i < SIZE; i++) { // 리프노드 남는부분 곱셈의 항등원인 1로 패딩
        ITree[i] = 1;
    }

    for (int i = BASE - 1; i > 0; i--) { // 인덱스트리 곱으로 초기화
        ITree[i] = ITree[i * 2] * ITree[i * 2 + 1]% MOD; // 왼자식* 오른자식
    }

    //2.구간변경, 구간 곱 연산
    int s = m + k;
    for (int i = 0; i < s; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) { // b번지의 값을 c로 변경
            update(b, c);
        }
        else { // b~c까지의 구간곱 출력
            cout << (int)calc(b, c) << '\n';
        }
    }
    return 0;
}
