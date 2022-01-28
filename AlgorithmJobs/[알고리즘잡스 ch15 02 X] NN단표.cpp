#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch15 02 X] NN단표
풀이: 이진탐색
시간복잡도: O(nlog(n*n))= 10만 이상
*/
#define MAX 100010
int n;
long long k;

//2.찾고자 하는 수가 몇번째인지 구하기
long long getOrder(long long x){
  long long result=0;
  
  for(long long i=1;i<=n;i++){
    // i단의 제일 큰 숫자가 보다 큰 경우
    if(i*n < x){
      result+= n;
    }
    // 아닌 경우
    else{
      if(x%i==0){
        result+= (x/i)-1;
      }
      else {result+= x/i;}
    }
    
  }
  return result+1;
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  //1. 수 입력
  cin>>n>>k;
  // 2.찾고자 하는 수가 몇번째인지 구하기
  long long start=1,end=n*n+1;
  while(start+1 < end){
    
    long long mid = (start+end)/2;
    long long myOrder = getOrder(mid);
    
    if(myOrder <= k){ start = mid;}
    else { end = mid;}
  }
  
  cout<<start<<'\n';
  return 0;
}
