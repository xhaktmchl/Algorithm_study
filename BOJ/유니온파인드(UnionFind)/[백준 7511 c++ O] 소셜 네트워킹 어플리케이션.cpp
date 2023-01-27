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
[백준 7511 c++ O] 소셜 네트워킹 어플리케이션
접근: bfs: 간선을 추가하고 bfs로 친구인지 아닌지 확인 -> 시간초과 예상
접근2: 유니온파인드: 간선추가하면서 유니온 -> 파인드로 같은 집합인지 확인
시간복잡도:
풀이1:
    //1.테케, 입력
    //2.유니온:친구 간선 추가
    //부모님 배열 초기화
    //같은 집합 아니면 유니온
    //3.파인드: 같은 집합이면 1, 아니면 0
*/
int T,n, uCnt,fCnt,n1,n2;
int par[1000000 + 5];

void init() {
    for (int i = 0; i < n; i++) par[i] = i;
}

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
    //1.테케, 입력
    cin >> T;
    for (int t = 1; t <= T; t++) {
        //2.유니온:친구 간선 추가
        //부모님 배열 초기화
        cin >> n;
        init();
        
        //같은 집합 아니면 유니온
        cin >> uCnt;
        for (int i = 0; i < uCnt; i++) {
            cin >> n1 >> n2;
            if (fin(n1) != fin(n2)) uni(n1, n2);
        }
        //3.파인드: 같은 집합이면 1, 아니면 0
        cin >> fCnt;
        cout << "Scenario "<<t<<":" << '\n';
        for (int i = 0; i < fCnt; i++) {
            cin >> n1 >> n2;
            if (fin(n1) == fin(n2)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }cout << '\n';
    }
    return 0;
}  
