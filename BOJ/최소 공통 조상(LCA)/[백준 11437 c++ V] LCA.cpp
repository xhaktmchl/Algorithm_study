#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 11437 c++ V] LCA
문제:
접근:
시간복잡도: O(nm) = 50000*10000 5억이라 안될줄 알았는데 되서 궁금증이 생김
풀이: 최소 공통 조상-> LCA기본
    //1.입력
    //2.LCA기본-
    //1) bfs로 트리의 뎁스, 부모배열 저장
    //2) 두 노드의 뎁스를 같게 만들기
    //3) 하나씩 올라가며 최소 공통 조상 찾기
*/
int n,n1,n2,m,node;
vector<int> al[100001]; // 인접 리스트
int depth[100001];
int par[100001];

void makeTree(int root) {

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
            if (depth[nn] != 0) continue; // 방문하지 않은 것만
            
            q.push(nn); 
            depth[nn] = depth[node] + 1; // 깊이 저장
            par[nn] = node; // 부모 저장
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
    for (int i = 0; i < n-1; i++) {
        cin >> n1 >> n2;
        //양방향 인접 리스트
        al[n1].push_back(n2);
        al[n2].push_back(n1);
    }
    
    //2.LCA기본-
    //1) bfs로 뿌리부터 트리의 뎁스, 부모배열 저장
    makeTree(1);
    //2) 두 노드의 뎁스를 같게 만들기
    //3) 하나씩 올라가며 최소 공통 조상 찾기  
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        lca(n1, n2);
    }
    return 0;
}
