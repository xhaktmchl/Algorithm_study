#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 모의고사
// 문제: 3개의 수포자 정답을 정답과 비교해 가장 많이 맞힌 사람 출력(동점자 오름차순 출력)
// 접근: 완전탐색: 각 수포자 정답 배열 만들고 정답배열과 배교
// 풀이: 
// 각 수포자 벡터 생성 및 정답 배열 완성
// 완전탐색으로 정답 갯수 구함
// 정답 오름차순으로 넣기 
// 최대 정답 개수 구하고 1,2,3번 차례로 같은지 검사하고 정답 배열에 넣으면 오름차순으로 정리
// 개념: 벡터.push_back(대입할 대상)

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int c1,c2,c3; // 각 수포자의 정답 카운트 변수
    c1=c2=c3=0;
    vector<int> ar1(10000); // 각 수포자 정답 배열
    vector<int> ar2(10000);
    vector<int> ar3(10000);
    
    // 1번 수포자 정답 배열
     for(int i=0;i<10000;i++){
       if(i%5 == 0){ ar1[i]=1;}
        else if(i%5 == 1){ ar1[i]=2;}
          else if(i%5 == 2){ ar1[i]=3;}
          else if(i%5 == 3){ ar1[i]=4;}
          else if(i%5 == 4){ ar1[i]=5;}
    }
    // 2번 수포자 정답 배열
    for(int i=0;i<10000;i++){
        if(i%2 == 0){ ar2[i]=2; }
        if(i%2 !=0 ){
            if(i%8 == 1){ ar2[i] =1;}
            else if(i%8 == 3){ ar2[i] =3;}
             else if(i%8 == 5){ ar2[i] =4;}
             else if(i%8 == 7){ ar2[i] =5;}
        }
    }
    
    // 3번 수포자 정답 배열
     for(int i=0;i<10000;i++){
       if(i%10 == 0 || i%10 == 1){ ar3[i] = 3;}
        else  if(i%10 == 2 || i%10 == 3){ ar3[i] = 1;}
         else  if(i%10 == 4 || i%10 == 5){ ar3[i] = 2;}
         else  if(i%10 == 6 || i%10 == 7){ ar3[i] = 4;}
         else  if(i%10 == 8 || i%10 == 9){ ar3[i] = 5;}
    }
    // 스포자 1,2,3, 번 각 정답 갯수 확인
    for(int i=0;i<answers.size();i++){
        if(answers[i] == ar1[i]) {c1++; }
        if(answers[i] == ar2[i]){ c2++;}
        if(answers[i] == ar3[i]){ c3++;}
        
    }
    
    // 정답 오름차순으로 넣기 
    // 최대 정답 개수 구하고 1,2,3번 차례로 같은지 검사하고 정답 배열에 넣으면 오름차순으로 정리
    int maxnum = max(max(c1,c2),c3); 
    if(maxnum == c1) { answer.push_back(1);}
    if(maxnum == c2) { answer.push_back(2);}
   if(maxnum == c3) { answer.push_back(3);}
    
    return answer;
}
