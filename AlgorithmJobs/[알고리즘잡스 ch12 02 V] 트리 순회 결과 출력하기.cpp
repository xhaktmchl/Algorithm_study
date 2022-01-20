#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch12 02 V] 트리 순회 결과 출력하기
풀이: dfs
//1.2차원 그래프 입력
//2.반복 완탐으로 각 위치에서 집 있고 방문 안했으면 dfs
//3.단지 수, 각 단지의 집 수 오름차순출력
시간복잡도: O(V+E)= 
*/
#define MAX 30
int n,cntGroup=0,cntHome=0;
int graph[MAX][MAX];
bool visit[MAX][MAX];
int dx[] ={0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<int> cnt;

void dfs(int row,int col){
  //방문처리
  visit[row][col] = 1; cntHome++;
  
  // 4방향 인접 노드 탐색
  for(int i=0;i<4;i++){
    int curRow = row+dy[i];
    int curCol = col+dx[i];
    // 예외처리: 범위검사
    if(curRow<0 || curRow>=n || curCol<0 || curCol>=n){continue;}
    if(visit[curRow][curCol]== 0 && graph[curRow][curCol]==1){// 방문x, 집 있으면 
      dfs(curRow,curCol);
    }
  }
  
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.2차원 그래프 입력
  cin>>n;
  for(int i=0;i<n;i++){
    string num; cin>>num;
    for(int j=0;j<n;j++){
      graph[i][j]=num[j]-'0';
    }
  }
  
  //2.반복 완탐으로 각 위치에서 집 있고 방문 안했으면 dfs
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(visit[i][j] == 0 && graph[i][j]==1){//집 있고 방문 안했으면 dfs
        dfs(i,j);
        cntGroup++;// 단지 수
        cnt.push_back(cntHome);// 집 수
        cntHome=0;
      }
    }
  }
  //3.단지 수, 각 단지의 집 수 오름차순출력
  cout<<cntGroup<<'\n';
  sort(cnt.begin(),cnt.end());
  for(int i=0;i<cnt.size();i++){
    cout<<cnt[i]<<'\n';
  }
  return 0;
}
