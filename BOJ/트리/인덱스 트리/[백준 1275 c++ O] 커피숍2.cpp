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
[백준 1275 c++ O] 커피숍2
문제: 
접근: 세그, 인덱스드트리 -> 반복적인 구간합 구하기, 노드값 업데이트
시간복잡도: 
풀이1: 인덱스드 트리
    //1.입력
    //2.인덱스드트리 초기화
    //범위 크기 체크
    //3.트리 구간합 구하기
    //4.트리 업데이트
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 날 수 있다.
*/
#define MAX_N 100010 
#define MAX_TREE 2097152 // 2^21
int n, q;
long long ori[MAX_N];
int base = 1;
long long tree[MAX_TREE];
int x, y, a, b;

void init() {
    while (base < MAX_N) base *= 2;
    for (int i = 0; i < n; i++) tree[base + i] = ori[i];
    for (int i = base + n; i < MAX_TREE; i++) tree[i] = 0; // 합의 항등원인 0을 채운다
    for (int i = base - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

long long query(int from, int to) {
    from += base; to += base;

    long long res = 0;
    while (from <= to) {
        if (from % 2 == 1) res = res + tree[from++]; // 시작인덱스가 오른자식이면 -> 더해주고 오른 부모로 올라가기
        if (to % 2 == 0) res = res + tree[to--]; // 끝인덱스가 왼자식이면 -> 더해주고 왼 부모로 올라가기

        from /= 2; to /= 2;
    }
    return res;
}

void update(int idx, int val) {
    idx += base;
    tree[idx] = val;

    while ((idx /= 2) > 0) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // 조상노드까지 왼자식+오른자식 값 갱신
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> ori[i];
    }
    //2.인덱스드트리 초기화
    init();
    //범위 크기 체크
    //3.트리 구간합 구하기
    //4.트리 업데이트
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout<< query(x - 1, y - 1)<<'\n';
        update(a - 1, b);
    }
    return 0;
}
