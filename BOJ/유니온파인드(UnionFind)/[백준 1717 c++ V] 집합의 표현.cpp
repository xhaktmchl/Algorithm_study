#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <vector>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 1717 c++ V] 집합의 표현
접근: 유니온 파인드
시간복잡도: 
풀이:
    //1.입력
    //집합 초기화
    //2.유니온
    //3.파인드
*/
int n, m,op,a,b;
int parent[1000000 + 10];

int fin(int node) {
    if (parent[node] == node) return node;
    else return parent[node] = fin(parent[node]); // 경로 압축
}

void unionF(int nodeA, int nodeB) {
    int rootA = fin(nodeA);
    int rootB = fin(nodeB);

    parent[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> n >> m;
    //집합 초기화
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int T = 0; T < m; T++) {
        cin >> op >>a >>b;
        //2.유니온
        if (op == 0) {
            unionF(a, b);
        }
        //3.파인드
        else if (op == 1) {
            if (fin(a) == fin(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
