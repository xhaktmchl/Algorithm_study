#include <iostream>
using namespace std;
/*
[알고리즘잡스 part5 OO] bingo
풀이1: 완탐
시간복잡도: O(n^4)=5^4
주의: 빙고 5개로 착각해서 시간 걸림
*/
#define MAX 6
int a[MAX][MAX],b[MAX][MAX],bingo=0,order=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  for(int i=0;i<5;i++){ // 빙고배열 입력
    for(int j=0;j<5;j++){
      cin>>a[i][j];
    }
  }
  // 부르는 수자 입력
  for(int i=0;i<5;i++){ // 빙고배열 입력
    for(int j=0;j<5;j++){
      order++;
      int num; 
      cin>>num;
      
      // 숫자의 위치 탐색
      for(int k=0;k<5;k++){
        for(int q=0;q<5;q++){
          if(a[k][q] == num){
            b[k][q] = 1; // x 표시
          }
        }
      }
      
      int bingoCnt=0;
      // 가로빙고 탐색
      for(int k=0;k<5;k++){
        int cnt=0;
        for(int q=0;q<5;q++){
          if(b[k][q] == 1){cnt++;}  
        }
        if(cnt==5){ bingoCnt++;} // 연속 5개면 1줄 빙고
      }
      // 세로빙고 탐색
      for(int k=0;k<5;k++){
        int cnt=0;
        for(int q=0;q<5;q++){
          if(b[q][k] == 1){cnt++;}  
        }
        if(cnt==5){ bingoCnt++;} // 연속 5개면 1줄 빙고
      }
      // 오른 대각선 빙고탐색
      if(b[4][0]==1 && b[3][1]==1 && b[2][2]==1 && b[1][3]==1 && b[0][4]==1){
        bingoCnt++;
      }
      // 왼 대각선 빙고탐색
      if(b[0][0]==1 && b[1][1]==1 && b[2][2]==1 && b[3][3]==1 && b[4][4]==1){
        bingoCnt++;
      }
      
      // 빙고3개면 순서 저장 및 종료
        if(bingoCnt>=3) {
          cout<<order<<'\n';
          return 0;
        }
    }
  }
  return 0;
}
