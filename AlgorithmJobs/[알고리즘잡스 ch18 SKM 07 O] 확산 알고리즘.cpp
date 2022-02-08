#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 SKM 07 O] 확산 알고리즘
풀이: 구현,완탐
  //1.배열입력
  //2.완탐으로 각 좌표에서 확산
  //거리가1이상k이하인 좌표 완탐 하면서 2 k2 + 2 k + 1 로 나눈 목값 더해주고 
  // 원래 원소값 에서 빼준다
  //3.배열 갱신
  //4.출력 
시간복잡도: O(n*m*n*m*t)= 5*5*5*5*3 
*/
#define MAX 50
int n,m,k,T;
int a[MAX][MAX];
int tpa[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열입력
  cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
      tpa[i][j]=a[i][j];
    }
  }
  cin>>T;
  
  for(int t=0;t<T;t++){
    //2.완탐으로 각 좌표에서 확산
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int cnt=0;
        //거리가1이상k이하인 좌표 완탐 하면서 
        for(int p=i-k;p<=i+k;p++){
          for(int q=j-k;q<=j+k;q++){
            if(p<0 || p>=n || q<0 || q>=m){continue;}//범위 조건
            if(abs(i-p)+abs(j-q)>=1 && abs(i-p)+abs(j-q)<=k){
              int sub = a[i][j]/(2*k*k+2*k+1); //2 k2 + 2 k + 1 로 나눈 목값 더해주고
              tpa[p][q]+= sub;
              tpa[i][j]-=sub;// 원래 원소값 에서 빼준다
            }
          }
        }
        
      }
    }
    //3.배열 갱신
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        a[i][j]=tpa[i][j];
      }
    }
  }
  //4.출력 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
