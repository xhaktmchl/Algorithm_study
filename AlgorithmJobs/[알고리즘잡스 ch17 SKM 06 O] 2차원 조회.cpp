#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 06 O] 2차원 조회
풀이: 완탐
  //1.배열입력
  //2.완탐으로 탐색
  //상하좌우 일치하는지 검사
  //일치하면 1 ,불일치하면 0
  //3.출력:결과배열
시간복잡도: O(n*m)=10000 
*/
#define MAX 110
int n,m;
int a[MAX][MAX];
int answer[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){// 경계처리를 위해 1~n까지 저장
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  
  //2.완탐으로 탐색
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      //상하좌우 일치하는지 검사
       //일치하면 1 ,불일치하면 0
      if(i>1 && a[i][j]==a[i-1][j]){//상
        answer[i][j]=1;
      }
      if(i<n && a[i][j]==a[i+1][j]){//하
        answer[i][j]=1;
      }//좌
      if(j>1 && a[i][j] == a[i][j-1]){
        answer[i][j]=1;
      }
      //우
      if(j<m && a[i][j]==a[i][j+1]){
        answer[i][j]=1;
      }
    }
  }
  //3.출력:결과배열
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<answer[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
