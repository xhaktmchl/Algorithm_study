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
[백준 2243 c++ X] 사탕상자
문제: 
접근: 세그, 인덱스드트리 -> 반복적인 구간합 구하기, 노드값 업데이트
시간복잡도: 
풀이1: 인덱스드 트리
    //1.입력
    //2.인덱스드트리 초기화-트리를 입력받으면서 진행하기 때문에 없어도 됨
    //3.쿼리:트리 b번째 사탕의 맛 구하기
    //4.트리 업데이트
주의: *= 표현을 썻다가 연산도중 스택 오버플로우가 날 수 있다.
*/
#define MAX_TREE 1<<21 // 2^21 :offset의 2배
typedef long long ll;
int offset = 1 << 20; // 2^20 : 사탕맛의 최대 범위 백만을 넘는 가장 작은 2의 제곱수
int n, a, b, c;
ll tree[MAX_TREE];

void update(int idx, int cnt) {
    idx += offset-1; // 트리에서 원본배열의 시작 인덱스는 0 부터 시작해서 -1
    tree[idx] += cnt; // 사탕맛의 갯수 갱신

    while ((idx /= 2) > 0) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

ll query(int rank, int idx) {
    //1) 기저: 트리에서 원본 배열의 순서를 찾은 경우
    if (idx >= offset) {
        update(idx - offset+1, -1); // 찾은 사탕맛 하나 차감, idx-offset+1에서 +1이유는 트리에서 사탕맛이1부터 시작
        return idx - offset+1;
    }
    //2) 왼자식 트리에 찾는 순서의 사탕맛이 있는 경우
    //3) 오른자식 트리에 찾는 순서의 사탕맛이 있는 경우
    // 찾는 순서 - 자기앞에있는 왼자식 트리의 노드갯수, 오른 자식트리로 이동
    if (rank <= tree[idx * 2]) return query(rank, idx * 2);
    else return query(rank - tree[idx * 2], idx * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    //2.인덱스드트리 초기화-트리를 입력받으면서 진행하기 때문에 없어도 됨
    //3.쿼리:트리 b번째 사탕의 맛 구하기
    //4.트리 업데이트
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) {
            cout<< query(b, 1)<<'\n'; // // id에 해당하는 사탕을 꺼낸다. => b번째 사탕맛을 1번맛루트노드부터 top-down 탐색
        }
        else if (a == 2) {
            cin >> c;
            update(b, c);
        }
    }
    return 0;
}
