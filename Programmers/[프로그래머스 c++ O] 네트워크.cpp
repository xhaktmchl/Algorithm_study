#include <string>
#include <vector>
using namespace std;
// [프로그래머스 c++ O] 네트워크
// 문제: 컴퓨터들의 네트워크 갯수 구하기 = 그래프의 연결요소 구하기
// 접근: 그래프의 연결요소 구하기 -> dfs 
// 시간복잡도: O(정점+ 간선의 갯수) = n+ (n-1)*n/2 
// 풀이: 
// 1차원 노드완탐 방문 하지 않았으면 -> dfs, 네트워크갯수 증가
// dfs에서 방문처리,자신노드예외, 방문하지 않고 간선있으면 해당노드와 연결된 모든 노드 탐색
#define MAX 201
bool visit[MAX]; // 방문배열
int nn;

void dfs(int node,vector<vector<int>> computers){
    visit[node]= 1; 
    //해당노드와 연결된 모든 노드 탐색
    for(int i=0;i<nn;i++){
        if(node == i) continue; // 자기자신노드 예외
        if(!visit[i] && computers[node][i] == 1){ // 방문, 간선검사
            dfs(i,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    nn = n;
    // 1차원 노드완탐
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i,computers);
            cnt++; // 네트워크 증가
        }
    }
    return answer=cnt;
}
