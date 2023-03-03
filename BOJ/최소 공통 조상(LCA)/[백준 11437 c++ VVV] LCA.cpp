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
[백준 11437 c++ VVV] LCA
문제:
접근:
시간복잡도: O(nm) = 50000*10000 5억이라 안될줄 알았는데 되서 궁금증이 생김
풀이: 최소 공통 조상-> LCA기본
    //1.입력
    //2.LCA기본-
    //1) bfs로 트리의 뎁스, 부모배열 저장
    //2) 두 노드의 뎁스를 같게 만들기
    //3) 하나씩 올라가며 최소 공통 조상 찾기
풀이2: 최소 공통 조상-> LCA-sparsetable 방식 -> 시간 단축
    //1.입력
    //양방향 인접 리스트
    //2.LCA-sparseTable 방법
    //1)bfs로 트리의 깊이 저장
    //2)부모배열 dp로 채우기(sparsetable)
    //par[i][k] = par[par[i][k-1]][k-1]
    //3)lca query
    //(1)a의 깊이를 더 깊은 것으로
    //(2)두 노드의 깊이를 같게
    //(3)공통조상이 같기 전까지 루트부터 탐색
    //(4)바로 위의 부모가 최소 공통 조상
*/
/*
풀이1 복습
*/
int n,a,b, n1, n2, m, node;
vector<int> al[100001]; // 인접 리스트, 트리의 노드수는 5만의보다 큰 2^k승 개는 있어야 함.
int depth[100001];
int par[100001];

void make_tree(int root) {
    
    queue<int> q;
    q.push(root);
    depth[root] = 1;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        // 인접 자식노드 탐색
        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            int nn = al[node][i];
            if (depth[nn] != 0) continue; // 예외:방문하지 않은 것만 
            
            q.push(nn);
            depth[nn] = depth[node] + 1;
            par[nn] = node;
        }
    }
}

void lca(int a, int b) {

    if (depth[a] < depth[b]) swap(a, b); // a의 깊이가 무조건 깊도록

    while (depth[a] != depth[b]) { // a와 b의 깊이를 같게 만들기
        a = par[a];
    }

    while (a != b) { // 둘이 하나씩 올라가며 검사
        a = par[a];
        b = par[b];
    }
    cout << a << '\n'; // lca출력
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    //2.LCA기본
    //1)bfs로 트리의 뎁스, 부모배열 저장
    make_tree(1);
    //2)두 노드의 뎁스를 같게
    //3)하나씩 올라가며 최소 공통 조상 탐색
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        lca(n1, n2);
    }
    return 0;
}
