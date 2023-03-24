#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
/*
[프로그래머스 42839 c++ VV] 소수 찾기
문제: 숫자가 나열된 문자열 입력 받으면 문자열 속 숫자로 만들 수 있는 수 중 소수의 갯수 구하기
접근: 소수찾기->에라토스테네스의 체 / 1,2,3,..자릿수의 수 어쩧게 탐색? => next_permutation() 와 substr으로 각 수열의 모든 자릿수 탐색
풀이1:
// next_permutation() 으로 모든 수열 탐색하기 위해 문자열 정렬
// 반복문에서 substr으로 각 수열일 경우 1,2,3,... 자리의 수 추출 후 정수로 변환
// 추출된 수 소수판별후 소수이면 해쉬배열에 1대입
// 배열탐색으로 소수의 갯수 구하기
풀이2:
    //1.에라토스체로 소수판별
    //2.정렬
    //3.완탐: 모든 숫자의 경우 탐색
    //1)만약 소수이고 방문하지 않앗으면
    //카운트, 방문처리
개념:
// next_permutation(numbers.begin(),numbers.end()) : 작은 수부터 다음 수열로 증가하다 끝나면 false반환
// stoi(문자열) : 문자열을 정수로 반환
// 문자열.substr(부분문자열 시작 인덱스,부분문자열 길이) : [pos, pos + count) 범위의 문자열 추출
주의:
// 에라토스테네스의 체 에서 0,1 예외조건
*/
int pr[10000005];
int cur, cnt=0;
bool visit[10000005];

// 소수 판별
void eratos(){
    pr[0]=pr[1]=1;
    for(int i=2;i*i<=10000005;i++){      
        for(int j=i+i;j<=10000005;j+=i){
            pr[j]=1;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    //1.에라토스체로 소수판별
    eratos();
    //2.정렬
    sort(numbers.begin(), numbers.end());
    //3.완탐: 모든 숫자의 경우 탐색
    //1)만약 소수이고 방문하지 않앗으면
    //카운트, 방문처리
    do{
        int size = numbers.size();
        for(int i=0;i<size;i++){
            cur = stoi( numbers.substr(0,i+1));
            if(pr[cur]==0 && !visit[cur]){
                cnt++;
                visit[cur]=1;
            }
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer=cnt;
}
