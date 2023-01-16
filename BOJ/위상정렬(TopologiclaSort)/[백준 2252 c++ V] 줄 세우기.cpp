#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <vector>
#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 2252 c++ V] 줄 세우기
접근: DAG ->> 위상 정렬
인접리스트로 그래프 저장
indgree 배열 저장
위상정렬-> bfs처럼 이용
시간복잡도: 
풀이:
    //1.입력
    //인접 리스트 저장
    //indgree 배열 저장
    //2.위상 정렬
    */
int n, m,a,b;
int nn;
vector<int> gr[32000 + 10];
int indegree[32000 + 10];
vector<int> result;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        //인접 리스트 저장
        //indgree 배열 저장
        gr[a].push_back(b);
        indegree[b] += 1;
    }
}

void topologicalSort() {

    queue<int> q;
    
    //진입차수==0인 노드들 모두 푸쉬
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) q.push(i);
    }
    // 인접 리스트 탐색하고
    // 진입차수==0인 노드들 계속 찾아서 푸쉬
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node); // 방문한 노드 저장

        int size = gr[node].size();
        for (int i = 0; i < size; i++) {
            nn = gr[node][i];

            indegree[nn] -= 1;
            if (indegree[nn] == 0) q.push(nn);  
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    input();
    
    //2.위상 정렬
    //1) indgree==0 인 노드에서 인접 리스트 탐색
    //인접 리스트 indegree--
    //2) 다시 indegree==0인 노드에서 시작 반복
    topologicalSort();
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
