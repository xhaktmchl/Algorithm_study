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
[백준 2042 c++ VO] 구간합구하기
문제:
접근: 세그, 인덱스드트리 -> 반복적인 구간합 구하기
시간복잡도:
풀이1: 인덱스드 트리
    //1.입력
    //2.인덱스드 트리 초기화
    //1)n보다 크거나 같은 수중 가장 작은 2의 제곱수 구하기
    //2) 찾은 제곱수부터 원래 배열 채우기, 뒤에는 0으로 채우기
    //3) 트리 왼쪽 배열 채우기: 찾은 제곱수-1 부터 0까지 왼자식+오른자식 합 저장 tree[i] = tree[i*2]+tree[i*2+1]

    //3.트리 업데이트
    //1) 트리 인덱스부터 시작
    //2) 숫자 업데이트
    //3) 변경된 숫자 조상 부모들 탐색하며 모두 왼자식+오른자식으로 업데이트

    //4.트리 쿼리: 구간의 합
    //1) 트리의 인덱스로 이동
    //트리구간의 시작과 끝이 역전되기 전 까지 반복
    //2) 시작 인덱스 노드가 오른자식일때 == 트리 구간의 시작이 홀수번째 일 때: 더하고 오른부모로 올라감
    //3)  끝인덱스 노드가 왼자식일때 == 트리 구간의 끝이 짝수일때: 더하고 왼 부모로 올라감
    //구간합 반환
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 날 수 있다.
*/
#define MAX 1 << 20 // 2^20 : 100만보다 큰 수중 가장 작은 2의 제곱수
#define MAX_TREE 1 << 21 // 2^21 : offset의 2배
typedef long long ll;
int n, m, k;
ll ori[MAX];
ll tree[MAX_TREE];
ll offset = 1;
ll a, b, c;


void init() {
    while (offset < n) offset *= 2;
    for (int i = 0; i < n; i++) tree[offset + i] = ori[i];
    for (int i = n; i < offset; i++) tree[offset + i] = 0; // 덧셈의 항등원0
    for (int i = offset - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
}


void update(int idx, ll val) {
    idx += offset - 1; // 수는 1부터이나 트리 배열의 시작은 0부터
    tree[idx] = val;
    while ((idx /= 2) > 0) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

ll query(int from, int to) {
    from += offset - 1; to += offset - 1; // 수는 1부터이나 트리 배열의 시작은 0부터
    
    ll res = 0;
    while (from <= to) {
        if (from % 2 == 1) res += tree[from++]; //시작 인덱스 노드가 오른자식일때
        if (to % 2 == 0) res += tree[to--]; // 끝인덱스 노드가 왼자식일때

        from /= 2; to /= 2;
    }
    return res;
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
    //4.트리 쿼리: 구간의 합
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else if (a == 2) cout << query(b, c) << '\n';
    }
    return 0;
}
