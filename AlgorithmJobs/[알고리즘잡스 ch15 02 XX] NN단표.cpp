#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch15 02 XX] NN단표
풀이: 이진탐색
시간복잡도: O(nlog(n*n))= 10만 이상
*/
int n;
long long k;
//2.찾고자 하는 수 몇 번째 수인지 구하기
//n단 까지 탐색하며 자기보다 작은 갯수 카운트
long long getOrder(long long num){
  long long result=0;
  
  for(long long i=1;i<=n;i++){
    // i단의 제일 큰 숫자보다 큰 경우
    if(i*n < num){ result+=n;}
    // 아닌 경우
    else{
      if(num%i==0){
        result+=(num/i)-1;
      }
      else{ 
        result+=num/i;
      }
    }
    
  }
  return result+1;
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);
  
  //1.수 입력
  cin>>n>>k;
  //2.찾고자 하는 수 몇 번째 수인지 구하기
  long long start=1,end=n*n+1;
  while(start+1<end){
    long long mid = (start+end)/2;
    long long order = getOrder(mid);
    
    if(order <= k){ start=mid;}
    else{ end= mid;}
  }
  //3.출력 
  cout<<start<<'\n';
  return 0;
}
