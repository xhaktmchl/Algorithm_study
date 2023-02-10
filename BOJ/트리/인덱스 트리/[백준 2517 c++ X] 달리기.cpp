#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 2517 c++ X] 달리기
문제:
접근: 세그, 인덱스드트리 -> 반복적인 구간합 구하기, 노드값 업데이트
시간복잡도:
풀이1: 인덱스드 트리
    //1.입력
    //2.정렬: 플레이어 구조체배열 스피드 내림차순
    //2.인덱스트트리-정의: 대표값은 자기자신보다 앞에있는 스피드가 좋은 사람들의 수
    //1)트리초기화-여기선 생략
    //2)트리 업데이트
    //3)트리 쿼리
    //4.출력
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 날 수 있다.
*/
#define MAX 1<<19
#define MAX_TREE 1<<20
struct player {
    int speed;
    int idx;
};
int n;
player ori[MAX];
long long tree[MAX_TREE];
int offset = 1 << 19;
long long ans[MAX];

bool cmp(player a, player b) {
    if (a.speed > b.speed) return true;
    else return false;
}

void update(int  idx) {
    idx += offset - 1;
    tree[idx] = 1; // 1더해주기
    while ((idx /= 2) > 0) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

long long query(int from, int to) {
    from += offset - 1; to += offset - 1;

    long long res = 0;
    while (from <= to) {
        if (from % 2 == 1) res = res + tree[from++];
        if (to % 2 == 0) res = res + tree[to--];

        from /= 2; to /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    //2.정렬: 플레이어 구조체배열 스피드 내림차순
    for (int i = 1; i <= n; i++) {
        cin >> ori[i].speed;
        ori[i].idx = i;
    }
    sort(ori + 1, ori + n+1, cmp);
    //2.인덱스트트리-정의: 대표값은 자기자신보다 앞에있는 스피드가 좋은 사람들의 수
    //1)트리초기화-여기선 생략
    //2)트리 업데이트
    //3)트리 쿼리
    //4.출력
    for (int i = 1; i <= n; i++) {
        update(ori[i].idx);
        ans[ori[i].idx] = query(1,ori[i].idx);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
