#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch21 SKM 03 O] 수영장 청소 - C
풀이: 구현,완탐
  //1.수영장 배열입력
  //2.완탐: k번째 수도꼭지를 T회 회전, 
  //1~5번에 해당하는 수도꼭지 물 퍼지기
  //1번
  //2번
  //3번
  //4번
  //5번
  //범위검사, 장애물 만나면 중지
  //물 퍼지는 영역 카운트
  //3.출력
시간복잡도: O(n*m)=5*5
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m,K,T;
int a[10][10];
int cnt=0;
int result=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수영장 배열입력
  cin>>n>>m>>K>>T;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐: k번째 수도꼭지를 T회 회전, 
  //1~5번에 해당하는 수도꼭지 물 퍼지기
  //1번
  //2번
  //3번
  //4번
  //5번
  //범위검사, 장애물 만나면 중지
  //물 퍼지는 영역 카운트
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]>=1 && a[i][j]<=5){cnt++;}
      if(cnt==K){
        if(a[i][j]==1){
          if(T==0){// 0회전
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
          }
          else if(T==1){//1회전
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==2){//2회전
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
          }
          else if(T==3){//3회전
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
        }
        else if(a[i][j]==2){
          if(T==0 || T==2){//0또는 2회전
            for(int p=i-1;p>=1;p--){//상
              if(p<1 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
          }
          else if(T==1 || T==3){//1또는 3회전
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
        }
        else if(a[i][j]==3){
          if(T==0){// 0회전
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==1){
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
          }
          else if(T==2){
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0)a[p][j]=8;
            }
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==3){
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
          }
          
        }
        else if(a[i][j]==4){
          if(T==0){
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==1){
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==2){
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
          else if(T==3){
            for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
          }
        }
        else if(a[i][j]==5){
          for(int p=i-1;p>=1;p--){// 상 방향
              if(p<=0 || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=i+1;p<=n;p++){// 하 방향
              if(p>n || a[p][j]==6){break;}
              if(a[p][j]==0) a[p][j]=8;
            }
            for(int p=j-1;p>=1;p--){// 좌 방향
              if(p<1 || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
            for(int p=j+1;p<=m;p++){// 우 방향
              if(p>m || a[i][p]==6){break;}
              if(a[i][p]==0) a[i][p]=8;
            }
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]==8){
        result++;
      }
    }
  }
  //3.출력
  cout<<result<<'\n';
  return 0;
}
