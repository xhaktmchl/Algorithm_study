#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 5014 c++ V] 스타트링크 
문제:
접근: 
시간복잡도: O(nlogn)
풀이:
    //1.입력
    //2.예외:
    //3.bfs:
    //1)큐
    //2)반복
    //(1)프론트,팝
    //(2)업,다운 이동
    //4.출력:
*/
/*

*/
int f, s, g, u, d,nn;
bool visit[1000005];
int dd[2];
int dist[1000005];
bool isPossible = 0;

void bfs(int node) {
    
    queue<int> q;
    q.push(node); visit[node] = 1;
    dist[node] = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            nn = node + dd[i];

            if (nn<1 || nn>f) continue;// 범위검사
            if (!visit[nn]) {//방문 안했으면 
                if (nn == g) { // 목적지 도착했을 때
                    dist[nn] = dist[node] + 1;
                    isPossible = 1;
                    return;
                }
                //다음으로 이동
                q.push(nn); visit[nn] = 1;
                dist[nn] = dist[node] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> f >> s >> g >> u >> d;
    dd[0] = u;
    dd[1] = d*-1;
    
    //2.예외: 시작점이 같은 경우
    if (s == g) {
        cout << 0 << '\n';
        return 0;
    }
    //3.bfs: 
    //1)큐
    //2)반복
    //(1)프론트,팝
    //(2)업,다운 이동
    bfs(s);
    //4.출력:
    if (isPossible) {
        cout << dist[g] << '\n';
    }
    else cout << "use the stairs" << '\n';
    return 0;
}
