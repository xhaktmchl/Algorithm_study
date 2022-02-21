#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch21 SKM 06 V] 수영장 청소
풀이: 구현,완탐
//몇번째 테케
//1.수영장 배열입력
// t번째 테케 할 차례 -> 초기화 
//2.완탐 재귀: 벨브를 회전하는 모든 경우의 수 만들기
//각 경우의 수 마다 벨브 회전키기고
//물퍼짐
//최소 청소면적 구하기
시간복잡도: O(4^5*n*m)=1000*100
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n,m,T;
int a[15][15],b[15][15];
int dir[6][4]={
  //상우하좌
  {0,0,0,0},
  {1,0,0,0},
  {1,0,1,0},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,1}
};
int dx[]={0,1,0,-1}; // 상우하좌
int dy[]={-1,0,1,0};
int result=0;
int resultMin=0;
int valCnt=0,cnt=0;
int valNum;

int rotates[15];

//완탐 재귀:밸브 회전 
//1.기저조건: 모든 밸브의 회전횟수가 정해지면 
//그 회전경우로 밸브 회전시킴
//물 퍼짐
//청소해야하는 면적 구하기
//최솟값 갱신
//중단
//2.재귀:0~3번 회전값 저장 후 다음 밸브 재귀 
void re(int idx){
  if(idx>=valCnt){//1.기저조건: 모든 밸브의 회전횟수가 정해지면
    // a배열 b에 복사
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        b[i][j]=a[i][j];
      }
    }
    //그 회전경우로 밸브 회전시킴
    cnt=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(b[i][j]>=1 && b[i][j]<=5){// 수도꼭지 찾으면
          cnt++;
          valNum=b[i][j];
          
          //회전
          int myDir[4]={0,};
          for(int p=0;p<4;p++) myDir[p]=dir[valNum][p];
          for(int p=0;p<rotates[cnt-1];p++){
            int tp=myDir[3];
            for(int q=3;q>=1;q--){
              myDir[q]=myDir[q-1];
            }
            myDir[0]=tp;
          }
          //물 퍼짐
          for(int p=0;p<4;p++){
            if(myDir[p]==1){// 방향이 맞으면
              int row=i;
              int col=j;
              while(1){// 끝까지 물 퍼짐
                row+=dy[p];
                col+=dx[p];
                
                if(row<1 || row>n || col<1 || col>m){break;}// 범위조건
                if(b[row][col]==6){break;} // 장애물 중단
                if(b[row][col]==0){// 빈 곳에만 물 퍼짐
                  b[row][col]=8;
                }
              }
            }
            
          }
         
          
        }
      }
    }
    //청소해야하는 면적 구하기
    result=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(b[i][j]==0){
          result++;
        }
      }
    }
    //최솟값 갱신
    if(resultMin> result){
      resultMin = min(resultMin,result);
    }
    
    return; //중단
  }
  
  //2.재귀:0~3번 회전값 저장 후 다음 밸브 재귀
  for(int i=0;i<4;i++){
    rotates[idx]=i;
    re(idx+1);
  }
}


int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수영장 배열입력
  cin>>T;
  for(int t=1;t<=T;t++){// t번째 테케 할 차례 -> 초기화 
    // 초기화
    valCnt=0;
    resultMin=987987987;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>a[i][j];
        if(a[i][j]>=1 && a[i][j]<=5){valCnt++;}
      }
    }
    re(0);
    cout<<"#"<<t<<" "<<resultMin<<'\n';
  }
  return 0;
}
