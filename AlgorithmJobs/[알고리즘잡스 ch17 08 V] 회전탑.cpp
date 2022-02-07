#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
[알고리즘잡스 ch17 SKM 08 V] 회전탑
풀이: 구현,완탐
  //1.회전배열 입력
  //2.회전명령 입력
  //3.층수의 배수 배열 찾아서 d방향으로 c칸 밀기
  // 시계방향=오른 밀기
  // 반시계방향=왼 밀기
  // 경계처리를 위한 패딩
      //상하-1 패패딩
      //좌우 양 끝으로 패딩
  // answer배열에 ar배열 복사
  //4.밀기 완료 후 같은 원소있나 탐색
  //있으면 지워주기
  //없으면 평균 구해서 작은것 +1, 큰것-1
  // 바뀐배열 ar에 저저장
  //5.출력:회전판 숫자들의 합
시간복잡도: O(n*m*c)= 50^3
*/
#define MAX 60
int T,n,m,k,a,c,d;
int ar[MAX][MAX];
int answer[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.회전배열 입력
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>ar[i][j];
        
      }
    }
    //2.회전명령 입력
    for(int i=0;i<k;i++){
      cin>>a>>d>>c;
      //3.층수의 배수 배열 찾아서 d방향으로 c칸 밀기
      for(int j=a;j<=n;j+=a){
        if(d==0){// 시계방향=오른 밀기
          for(int q=0;q<c;q++){
            int tp=ar[j][m];// 오른 끝 수 저장
            for(int p=m-1;p>=1;p--){
              ar[j][p+1]=ar[j][p];
            }
            ar[j][1]=tp;
          }
          
        }
        if(d==1){// 반시계방향=왼 밀기
          for(int q=0;q<c;q++){
            int tp=ar[j][1];// 왼 끝 수 저장
            for(int p=1;p<m;p++){
              ar[j][p]=ar[j][p+1];
            }
            ar[j][m]=tp;
          }
          
        }
      }
      // 경계처리를 위한 패딩
      //상하-1 패패딩
      for(int j=1;j<=m;j++){
        ar[0][j]=-1;
        ar[n+1][j]=-1;
      }
      //좌우 양 끝으로 패딩
      for(int j=1;j<=n;j++){
        ar[j][0]=ar[j][m];
        ar[j][m+1]=ar[j][1];
      }
      
      // answer배열에 ar배열 복사
      for(int j=0;j<=n+1;j++){
        for(int p=0;p<=m+1;p++){
          answer[j][p]=ar[j][p];
        }
      }
      //4.밀기 완료 후 같은 원소있나 탐색
      //있으면 지워주기
      bool ok=1;
      int sum=0;
      for(int j=1;j<=n;j++){
        for(int p=1;p<=m;p++){
          if(ar[j][p]!=0 && (ar[j][p]==ar[j-1][p] || ar[j][p]==ar[j+1][p] || ar[j][p]==ar[j][p-1] || ar[j][p]==ar[j][p+1])){
            answer[j][p]=0;
            ok=0;
          }
          
        }
      }
      //없으면 평균 구해서 작은것 +1, 큰것-1
      int cnt=0;
      if(ok==1){
        for(int j=1;j<=n;j++){
          for(int p=1;p<=m;p++){
            if(answer[j][p]!=0){
              sum+=ar[j][p];
              cnt++;
            }
            
          }
        }
        int avg=sum/cnt;
        //cout<<"avg"<<avg<<'\n';
        for(int j=1;j<=n;j++){
          for(int p=1;p<=m;p++){
            if(answer[j][p]==0){continue;}
            if(answer[j][p]<avg){
              answer[j][p]+=1;
            }
            else if(answer[j][p]>avg){
              answer[j][p]-=1;
            }
          }
        }
        
      }
      
      // 바뀐배열 ar에 저저장
      for(int j=1;j<=n;j++){
        for(int p=1;p<=m;p++){
          ar[j][p]=answer[j][p];
        }
      }
    }
    
    
    //5.출력:회전판 숫자들의 합
    int resultSum=0;
    for(int j=1;j<=n;j++){
      for(int p=1;p<=m;p++){
        
        resultSum+=ar[j][p];
      }
    }
    cout<<"#"<<t<<" "<<resultSum<<'\n';
  }
  return 0;
}
