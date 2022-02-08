#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
/*
[알고리즘잡스 ch18 SKM 05 V] 칸 확산
풀이: 구현,완탐
  //1.배역입력
  //3.완탐으로 t번 1~k거리의 좌표들의 합 임시 배열에 저장 
  //4.a배열 최신화/
  //5.출력 배열
시간복잡도: O(n*m*k*k*t)= 10000*10
*/
#define MAX 110
int n,m,k,T;
int a[MAX][MAX];
int tpa[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배역입력
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
      tpa[i][j] = a[i][j];
    }
  }
  cin>>T;
  //3.완탐으로 t번 1~k거리의 좌표들의 합 임시 배열에 저장 
  for(int t=0;t<T;t++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        //1이상 k거리 이하에있는 모든 좌표의 값 더하기
        for(int p=i-k;p<=i+k;p++){
          for(int q=j-k;q<=j+k;q++){
            // 범위검사
            if(p<1 || p>n || q<1 || q>m){continue;}
            
            if(abs(i-p)+abs(j-q) <=k &&abs(i-p)+abs(j-q) >=1 ){
              tpa[i][j]+=a[p][q];
            }
          }
        }
      }
    }//4.a배열 최신화/
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        a[i][j] = tpa[i][j];
      }
    }
  }
  //5.출력 배열
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cout<<a[i][j]<<" ";
      }cout<<'\n';
    }
  return 0;
}
