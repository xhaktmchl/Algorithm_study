#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 17352 c++ O] 여러분의 다리가 되어 드리겠습니다! 
접근: 유니온 파인드-> 같은 집합으로 모두 유니온 -> 
접근2: bfs-> 모두 간선 연결 후 방문하지 않는 노드 찾기 -> 풀어보진 않음
시간복잡도: 
풀이1: 유니온 파인드
    //1.입력
    // 부모 배열 초기화
    //2.유니온: n-2개의 간선 연결
    //3.파인드: 1번 노드부터 같은 집합인지 탐색
    //출력:같은 집합 아닌 것 있으면 두 노드 출력
*/
int n,n1,n2;
int par[300000 + 10];

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);
    par[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    // 부모 배열 초기화
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    //2.유니온: n-2개의 간선 연결
    for (int i = 0; i < n-2; i++) {
        cin >> n1 >> n2;
        uni(n1, n2);
    }
    //3.파인드: 1번 노드부터 같은 집합인지 탐색
    //출력:같은 집합 아닌 것 있으면 두 노드 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (fin(i) != fin(j)) {
                cout << i << " " << j << '\n';
                return 0;
            }
        }
    }
    return 0;
}
