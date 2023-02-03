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
[백준 3020 c++ X] 개똥벌레 
문제: 
접근: 세그, 인덱스드트리 -> 
시간복잡도: logn
풀이1: 인덱스드 트리
    //1.입력
    //2.인덱스드트리 초기화
    //3.트리 업데이트: 구간에 종유, 석순 갯수 추가
    //3.트리 쿼리: 원본배열에서 갯수 제일 적은 것, 구간의 수
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 날 수 있다.
*/
#define MAX 1<<19
#define MAX_TREE 1<<20
typedef long long ll;
int n, h,ob;
int offset = 1;// << 19; // 2^19
ll tree[MAX_TREE];

void init() {
    while (offset < MAX) offset *= 2;
}

void update(int from, int to) {
    from += offset-1; to += offset-1;

    while (from <= to) {
        if (from % 2 == 1) tree[from++] += 1;
        if (to % 2 == 0) tree[to--] += 1;

        from /= 2; to /= 2;
    }
}

int query(int idx) {
    idx += offset - 1; // 높이는 1부터 시작이지만 트리원본배열은 0 부터 시작
    
    int res = 0;
    res += tree[idx];
    while ((idx /= 2) > 0) {
        res += tree[idx];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> h;
    //2.인덱스드트리 초기화
    init();
    //3.트리 업데이트: 구간에 종유, 석순 갯수 추가
    
    for (int i = 0; i < n; i++) {
        cin >> ob;
        if (i % 2 == 0) { //석순
            update(1, ob);
        }
        else { // 종유석
            update(h - ob + 1, h);
        }
    }
    //3.트리 쿼리: 원본배열에서 갯수 제일 적은 것, 구간의 수
    int minN = 500001;
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        int cur = query(i);
        if (cur < minN) {
            minN = cur;
            cnt = 1;
        }
        else {
            if (cur == minN) cnt++;
        }
    }
    cout << minN << " " << cnt << '\n';
    return 0;
}
