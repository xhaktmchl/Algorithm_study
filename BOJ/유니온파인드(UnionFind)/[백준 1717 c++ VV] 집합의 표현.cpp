#include <iostream>
#include <algorithm>
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
[백준 1717 c++ VV] 집합의 표현
접근: 유니온 파인드
시간복잡도: 
풀이1:
    //0.입력
    //1.부모 배열 초기화
    //2.합집합 명령
    //3.find명령
주의: fin메서드에서 경로압축을 하지 않으면 시간초과
*/
int n, m,n1,n2,op;
int par[1000000 + 5];

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); // 경로 압축: 시간단축
}

void uni(int a, int b) { 
    int rootA = fin(a);
    int rootB = fin(b);
    
    par[rootA] = rootB; // a집합을 b집합 자식트리로 합하기
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //0.입력
    cin >> n >> m;
    //1.부모 배열 초기화
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    //2.합집합 명령
    //3.find명령
    for (int i = 0; i < m; i++) {
        cin >> op >> n1 >> n2;

        if (op == 0) {
            uni(n1, n2);
        }
        if (op == 1) {
            if (fin(n1) == fin(n2)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
