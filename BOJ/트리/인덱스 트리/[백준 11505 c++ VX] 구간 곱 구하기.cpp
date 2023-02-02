#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 11505 c++ VX] 구간 곱 구하기  
문제: 
접근: 세그, 인덱스드트리 -> 반복적인 구간곱 구하기
시간복잡도: 
풀이1: 인덱스드 트리
    //1.입력
    //2.인덱스드트리 초기화
    //3.트리 업데이트
    //4.트리 구간곱 구하기
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 나면서 계속 틀려서 난감했다.
*/
#define MAX_N 1000000  
#define MAX_TREE 2097152// 2^21, 인덱스 트리의  20뎁스의 리프노드의 개수를 커버
#define BASE 1048576 // 2^20
typedef long long ll;
int MOD = 1000000007;
int n, m, k;
ll ori[MAX_N];
ll tree[MAX_TREE];
ll offset = 1;
int a, b, c;

//1) n이상 중 가장 작은 2의 제곱수 찾기
//2) 찾은 제곱수부터 원본배열 트리에 저장, 뒤에는 1로 초기화
//3) 찾은 제곱수-1 부터 0까지 왼자식*오른자식 값 저장
void init() {
    while (offset < MAX_N) offset *= 2;
    for (int i = 0; i < n; i++) tree[offset + i] = ori[i];
    for (int i = offset+n; i < MAX_TREE; i++) tree[i] = 1;
    for (int i = offset - 1; i > 0; i--) tree[i] = tree[i * 2] * tree[i * 2 + 1] % MOD;
}

//1) 제곱수부터 시작
//2) 값 수정
//3) 조상노드로 올라가며 왼자식*오른자식 값 갱신
void update(int idx, int val) {
    idx += offset;
    tree[idx] = val;
    while ((idx/=2) > 0) {
        tree[idx] = tree[idx * 2] * tree[idx * 2 + 1]%MOD;
    }
}

//1) 트리노드부터 시작
//2) 트리 구간의 시작인덱스가 홀수일 때: 곱하고 오른 부모로 올라가기
//3) 트리 구간의 끝 인덱스가 짝수일 때: 곱하고 왼 부모로 올라가기
//구간곱 반환
int query(int from, int to) {
    from += offset; to += offset;

    ll res=1; // 구갑곱이어서 1부터 시작
    while (from <= to) {
        if (from % 2 == 1) { // 오른자식이면
            //res *= tree[from++] % MOD;// 주의: 이렇게 하면 틀린 값 나옴
            res = res * tree[from++] % MOD;
        }
        if (to % 2 == 0) { //왼자식이면
            res = res * tree[to--] % MOD;
        }

        from /= 2; to /= 2;
    }
    return (int)res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> ori[i];
    }
    //2.인덱스드트리 초기화
    init();
    //3.트리 업데이트
    //4.트리 구간곱 구하기
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b-1,c);
        if (a == 2) cout << (int)query(b-1, c-1) << '\n';
    }
    return 0;
}
