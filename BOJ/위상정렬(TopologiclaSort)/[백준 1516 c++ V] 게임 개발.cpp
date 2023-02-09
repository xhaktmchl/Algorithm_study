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
[백준 1516 c++ V] 게임 개발
문제: 
접근: DAG, 정해진 순서, 답이 여러개 -> 위상 정렬
시간복잡도: O(n+m)
풀이:
    //1.입력: 건물 시간, 인접리스트
    //인디그리배열 갱신
    //2.위상정렬-bfs방법
    //1)인디그리==0인 모든 노드 푸쉬
    //2)bfs로 인디그리==0인 노드계속 푸쉬
    // 동시에 선행되어 지어지는 건물들 중 최대시간으로 갱신
    //3.출력
*/
int n,a,node,nn;
vector<int> al[505];
long long time[505];
long long oritime[505];
int indeg[505];
vector<int> res;
bool isCycle;

void topol() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i); res.push_back(i);
            time[i] = oritime[i];
        }
    }

    while (!q.empty()) {
        node = q.front();
        q.pop();

        int size = al[node].size();
        for (int i = 0; i < size; i++) {
            nn = al[node][i];
            indeg[nn]--;

            time[nn] = max(time[nn], time[node] + oritime[nn]); // 동시에 선행되어 지어지는 건물들 중 최대시간으로 갱신
            if (indeg[nn] == 0) {
                q.push(nn);  res.push_back(i);
            }
        }
    }

    if (res.size() == n) {
        isCycle = false;
    }
    else isCycle = true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력: 건물 시간, 인접리스트
    //인디그리배열 갱신
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> oritime[i];
        while (1) {
            cin >> a;
            if (a == -1) break;
            al[a].push_back(i);
            indeg[i] += 1;
        }
    }
    //2.위상정렬-bfs방법
    //1)인디그리==0인 모든 노드 푸쉬
    //2)bfs로 인디그리==0인 노드계속 푸쉬
    topol();
    //3.출력
    if (!isCycle) {
        for (int i = 1; i <= n; i++) cout << time[i] << '\n';
    }
    return 0;
}
