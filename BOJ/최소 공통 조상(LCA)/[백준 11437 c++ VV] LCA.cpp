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
[백준 11437 c++ VV] LCA
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
int n,n1,n2,node,m;
vector<int> al[100005]; // 노드의 갯수*2
int depth[100005];
bool visit[100005];
int par[100005][17]; // n번 노드의 2^17-1번째 조상까지 확인 가능

void makeTree(int root) {
    queue<int> q;
    q.push(root); 
    depth[root] = 1; 

    while (!q.empty()) {
        node = q.front();
        q.pop();

        // 인접 자식 노드 탐색
        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            int nn = al[node][i];
            if (depth[nn] !=0 ) continue;

            q.push(nn); 
            depth[nn] = depth[node] + 1;
            par[nn][0] = node; // 바로 위 부모
        }
    }
}

void filPar() {
    for (int k = 1; k < 17; k++) {
        for (int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
}

void lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);//(1)a의 깊이를 더 깊은 것으로
    //(2)두 노드의 깊이를 같게
    for (int i = 16; i >=0; i--) { // 2^i승씩 올라가기
        if (depth[par[a][i]] >= depth[b]) {
            a = par[a][i];
        }
    }

    if (a == b) {
        cout << a << '\n';
        return;
    }

    //(3)공통조상이 같기 전까지 루트노드부터 탐색
    for (int i = 16; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    //(4)바로 위의 부모가 최소 공통 조상
    cout << par[a][0] << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //양방향 인접 리스트
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> n1 >> n2;
        al[n1].push_back(n2); 
        al[n2].push_back(n1);
    }
    //2.LCA-sparseTable 방법
    //1)bfs로 트리의 깊이 저장
    makeTree(1);
    //2)부모배열 dp로 채우기(sparsetable)
    //par[i][k] = par[par[i][k-1]][k-1]
    filPar();
    //3)lca query
    //(1)a의 깊이를 더 깊은 것으로
    //(2)두 노드의 깊이를 같게
    //(3)공통조상이 같기 전까지 루트노드부터 탐색
    //(4)바로 위의 부모가 최소 공통 조상
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        lca(n1, n2);
    }
    return 0;
}
