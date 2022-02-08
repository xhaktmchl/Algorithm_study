#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 02 V] N명 이동
풀이: 구현 이동,완탐
  //1.배열입력
  //2.t번 k명의 사람들 이동
  //각 사람들 d방향으로 f만큼 이동
  //좌표검사
  // 이동 후 사람 좌표 갱신
  //3.t번 이동한 후 각 사람의 좌표 출력
시간복잡도: O(k*f*t)= 100*100*100=100만 
*/
#define MAX 110
int n,m,k,T;
int x[MAX],y[MAX],d[MAX],f[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열입력
  cin>>n>>m>>k>>T;
  for(int i=1;i<=k;i++){
    cin>>y[i]>>x[i]>>d[i]>>f[i];
  }
  //2.t번 k명의 사람들 이동
  for(int t=0;t<T;t++){
    //각 사람들 d방향으로 f만큼 이동
    for(int i=1;i<=k;i++){
      if(d[i]==0){//상
        for(int j=1;j<=f[i];j++){
          if(y[i]-j<1){//좌표검사
            y[i]=y[i]-j+1;
            break;
          } 
          if(j==f[i]){// 이동 후 사람 좌표 갱신
            y[i]=y[i]-j;
          }
        }
      }
      if(d[i]==1){//하
        for(int j=1;j<=f[i];j++){
          if(y[i]+j>n){
            y[i]=y[i]+j-1;
            break;
          } 
          if(j==f[i]){
            y[i]=y[i]+j;
          }
        }
      }
      if(d[i]==2){//좌
        for(int j=1;j<=f[i];j++){
          if(x[i]-j<1){
            x[i]=x[i]-j+1;
            break;
          } 
          if(j==f[i]){
            x[i]=x[i]-j;
          }
        }
      }
      if(d[i]==3){//우
        for(int j=1;j<=f[i];j++){
          if(x[i]+j>m){
            x[i]=x[i]+j-1;
            break;
          } 
          if(j==f[i]){
            x[i]=x[i]+j;
          }
        }
      }
    }
  }
  //3.t번 이동한 후 각 사람의 좌표 출력
  for(int i=1;i<=k;i++){
    cout<<y[i]<<" "<<x[i]<<'\n';
  }
  return 0;
}
