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
[백준 2252 c++ VV] 줄 세우기
문제: 
접근: DAG, 정해진 순서, 답이 여러개 -> 위상 정렬
인접리스트로 그래프 저장
indgree 배열 저장
위상정렬-> bfs처럼 이용
시간복잡도: O(n+m)
풀이:
    //1.입력
    //인접 리스트 저장
    //인디그리배열 저장
    //2.위상정렬-bfs방법
    //1)진입차수==0인 노드들 모두 푸쉬
    //2) bfs로 인디그리==0인 노드 계속 푸쉬
*/
int n, m,a,b,node,nn;
vector<int> al[32005];
int indegree[32005];
bool isCycle = 0;
vector<int> res;

void topol() {
    //1)진입차수==0인 노드들 모두 푸쉬
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i); res.push_back(i);
        }
    }
    //2) bfs로 인디그리==0인 노드 계속 푸쉬
    while (!q.empty()) { 
        node = q.front();
        q.pop();

        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            nn = al[node][i];
            
            indegree[nn]--;
            if (indegree[nn] == 0) {
                q.push(nn);
                res.push_back(nn);
            }
        }
    }

    if (res.size() == n) isCycle = false;
    else isCycle = true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m;
    //인접 리스트 저장
    //인디그리배열 저장
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        al[a].push_back(b);
        indegree[b] += 1;
    }
    //2.위상정렬-bfs방법
    topol();
    if (!isCycle) {
        for (auto i : res) cout << i << " ";
    }
    return 0;
}
