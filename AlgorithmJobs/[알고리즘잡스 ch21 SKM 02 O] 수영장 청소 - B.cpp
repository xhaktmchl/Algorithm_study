#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;
/*
[알고리즘잡스 ch21 SKM 02 O] 수영장 청소 - B
풀이: 구현,완탐
  //1.배열입력
  //2.완탐
  //1~5수도꼭지 찾으면 물줄기 퍼짐
  //1번
  //2번
  //3번
  //4번
  //5번
  //장애물, 또는 범위 검사 , 중단
  //3.출력: 
시간복잡도: O(n*m)=5*5
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m;
int a[10][10];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.배열입력
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐
  //1~5수도꼭지 찾으면 물줄기 퍼짐
  //1번
  //2번
  //3번
  //4번
  //5번
  //장애물, 또는 범위 검사 , 중단
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]==1){
        for(int p=i-1;p>=1;p--){// 상 방향
          if(p<=0 || a[p][j]==6){break;}
          a[p][j]=8;
        }
      }
      else if(a[i][j]==2){
        for(int p=i-1;p>=1;p--){// 상 방향
          if(p<=0 || a[p][j]==6){break;}
          a[p][j]=8;
        }
        for(int p=i+1;p<=n;p++){//하
          if(p>n || a[p][j]==6){break;}
          a[p][j]=8;
        }
      }
      else if(a[i][j]==3){
        for(int p=i-1;p>=1;p--){// 상 방향
          if(p<=0 || a[p][j]==6){break;}
          a[p][j]=8;
        }
        for(int p=j+1;p<=m;p++){//우
          if(p>m || a[i][p]==6){break;}
          a[i][p]=8;
        }
      }
      else if(a[i][j]==4){
        for(int p=i-1;p>=1;p--){// 상 방향
          if(p<=0 || a[p][j]==6){break;}
          a[p][j]=8;
        }
        for(int p=j-1;p>=1;p--){// 좌
          if(p<=0 || a[i][p]==6){break;}
          a[i][p]=8;
        }
        for(int p=j+1;p<=m;p++){//우
          if(p>m || a[i][p]==6){break;}
          a[i][p]=8;
        }
      }
      else if(a[i][j]==5){
        for(int p=i-1;p>=1;p--){// 상 방향
          if(p<=0 || a[p][j]==6){break;}
          a[p][j]=8;
        }
        for(int p=i+1;p<=n;p++){//하
          if(p>n || a[p][j]==6){break;}
          a[p][j]=8;
        }
        for(int p=j-1;p>=1;p--){// 좌
          if(p<=0 || a[i][p]==6){break;}
          a[i][p]=8;
        }
        for(int p=j+1;p<=m;p++){//우
          if(p>m || a[i][p]==6){break;}
          a[i][p]=8;
        }
      }
    }
  }
  //3.출력: 
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j]<<" ";
    }cout<<'\n';
  }
  return 0;
}
