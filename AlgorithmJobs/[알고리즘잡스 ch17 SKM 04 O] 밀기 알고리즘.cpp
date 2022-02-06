#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 04 O] 밀기 알고리즘
풀이: 완탐
  //1.수열입력
  //2.q번 질문
  ////3.x=1이면 f번 배열 오른방향 y칸 밀기
  //4.x=2이면 번 배열 왼방향 y칸 밀기
  //5.밀린배열 출력
시간복잡도: O(m*y)=100만??? 테스트 케이스 반복도 포함하는지 헷갈림 
*/
#define MAX 1010
int n,m,q;
int a[MAX][MAX];
int f,x,y;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수열입력
  cin>>n>>m>>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];

    }
  }
  //2.q번 질문
  for(int i=0;i<q;i++){
    cin>>f>>x>>y;
    ////3.x=1이면 f번 배열 오른방향 y칸 밀기
    if(x==1){
      for(int j=0;j<y;j++){
        int tp=a[f][m-1];
        for(int p=m-1;p>=0;p--){
          a[f][p]=a[f][p-1];
        }a[f][0]=tp;
      }
    }
    //4.x=2이면 번 배열 왼방향 y칸 밀기
    if(x==2){
      for(int j=0;j<y;j++){
        int tp=a[f][0];
        for(int p=0;p<m;p++){
          a[f][p]=a[f][p+1];
        }a[f][m-1]=tp;
      }
    }
    //5.밀린배열 출력
    for(int j=0;j<m;j++){
      cout<<a[f][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
