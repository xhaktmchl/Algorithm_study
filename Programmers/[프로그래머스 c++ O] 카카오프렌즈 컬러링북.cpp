#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
// [프로그래머스 c++ O] 카카오프렌즈 컬러링북
// 문제: 그림의 각 영역의 갯수와 가장 큰 영역의 사이즈를 구하라
// 접근: 이차원 그래프-> dfs,bfs -> 영역의 갯수:dfs 이용
// 시간복잡도: O()
// 풀이: 
// 프로그래머스에선 방문배열 초기화 해야 함
// 이차 반복으로 방문하지 않은 정점에서 dfs탐색
// 영역의 갯수 , 최대 영역 사이즈 출력
#define MAX 101
int M,N;
int cnt=0;
int visited[MAX][MAX];
vector<vector<int>> graph;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

//dfs
void dfs(int row,int col){
    visited[row][col] =1; // 방문처리
    cnt++;
    // 4방면 탐색
    for(int i=0;i<4;i++){
        int nrow = row+ dy[i];
        int ncol = col+ dx[i];
        // 범위검사
        if(nrow <0 || nrow >=M || ncol<0 || ncol>=N){continue;}
        if(visited[nrow][ncol] == 0 && graph[nrow][ncol] == graph[row][col]){ // 방문 검사
            dfs(nrow,ncol);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(visited,0,sizeof(visited)); //주의: 전역 배열 초기화 안하면 틀림
    
    graph = picture;
    M = m; // 주의: 전역변수인 것 초기화 안 해주고 dfs함수에서 사용해서 계속 틀려서 시간 걸림
    N = n; 
    // 모든 정점에서 dfs
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0 && picture[i][j] != 0){
                cnt=0;
                dfs(i,j);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area,cnt);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
