# Algorithm_study
알고리즘 이론 및 문제풀이

- 사용언어: c++ 또는 python 이용
사용 사이트 :
- 백준
- 프로그래머스




vector
-insert()
-clear
-push_back()
-erase()
-a.brgin()
-a.end()

vector<int> a;
vector<int> a(3); // 000123 
vector<string> a(3);
a.front(); : 맨앞 원소 반환
a.back(); : 

#string

*내림차순 정렬
sort(a.begin(),a.end(),greater<int>());

#pair
a.first()
a.second()

bool compare()
{
return a>b;
}
sort(a.begin(),a.end(),compare)
if(a.second(),b.second())return a.second()<b.secodn()


max(a,v)

인트배열에서 최대값 뽑기
max_element(a.begin(),a.end());
min_element()

string a ; stoi(a): 문자열 숫자로
to_string() : 숫자를 문자열로

부르트포스
: 모든 경우의 수 다 하는것
1543
3040
1057


이상철

#string 객체
-cin : scanf("%s" 와 같은 기능
-getline(cin,str) : gets 와 같은 기능
-getline(cin,str,'a') : a 문자 앞까지만 입력

-char 형 이력 getline(cin,a[10]))

#스트링 메소드
*stoi(문자열) : 문자열만 정수로 변환(문자 하나 안됨)
 -부호 같이 변환 해줌
* stoll(str) : 문자열만 longlong형으로 변환
*stod(문자열)

*to_string(문자열) : 수를 문자열로
*문자열.find(문자나 문자열) : 찾는 문자나 문자열 처음 주소반환

#헷갈린 부분
-문자열+"sdf" 가능
sqrt(n) : 루트 

* 단항연산자 : 조건 ? 맞을경우 : 틀릴경우
- a==3 ? d : s ;


if(*str.find() == string ::npos)
{cout<<true;
 : 찾는것을 못찾으면 npos 반환 


1920 : 수행시간 중요

2583 : 너비,깊이우선탬색 잘 모르겠음
10815 : 탐색
3758 : 구조체로 해야되나? 배열로 하다가 순위 정하는곳에서 막힘 조건이 너무 많아

2839: Q)수를 나누어주는 경우의 수 어떻게 나눠?




bool compare(string a, string b) // 문자열 길이순, 사전순
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
	{
		return a < b;
	}

	
}
int main()
{
	vector<string> a;
	string str;
	string tp;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		a.push_back(str);
	}
	
	sort(a.begin(), a.end(), compare); // 문자열 정렬

	for (int i = 0; i < n; i++)
	{
		if (tp == a[i]) { continue; } // 같은문자 건너뛰기
		cout << a[i]; if (i >= n - 1) {
			break;
		} printf("\n");
		tp = a[i];
	}
	
	return 0;
}

=================================================

*이진탐색문제에서 cin,cout 이 scanf,printf 보다 속도 느려져 시간초과 남 

# 이진탐색문제 해결
1.이진탐색 직접 구현
2. binary_search(시작주소,마지막 다음주소, 찾을 데이타) : 이진탐색 메소드

최소공배수=두수의 곱/최대공약수

#스택
s.push
s.pop 
s.top
s.empty

*스택 비어있을때 top 쓰면 에러남 -> 비어있을경우 따로 처리

*벡터 vector<int> v(3) 소괄호임

* vector<int> a; //a=NULL; 
- 이경우 push_back 사용
* vector<int> a(2); // a={0,0}
- cin>>a[1]; 으로 사용


 * cin.tie(0); cin.sync_with_stdio(0);
   cout.tie(0); cout.sync_with_stdio(0);

1018(체스칠하기)  : 맞는것 같은데 백준 틀림( 반례찾아)
1966 : 문제가 이상함 해석이 잘못된 듯 ( 우선순위, 큐 이용)
2805 : 처음에 완전탐색으로 햇지만 시간초과 이분탐색 이용하라는데 이해안감 (mid 검색 할때 안멈추고해야함)


=========================================================
*큐,스텍 원소 유무 확인시 empty,size 메소드 써야 오류 안남

백준1874 문제이해가 안됨

* 소수찾기: 에라토스테네스의 체 (2부터 소수이면 그의 배수 배열에 0으로 저장시켜서 건너뜀)


*queue<pair<int,int>> q;
q.front().first;
q.front().second
* pririty_que<int> 우선순위큐


*행렬 문제에서 (행+열) 이 홀짝 구분해서 구분
=========================================================
11726 : 문제 출력 설명 잘못 나옴, ㅣ보나치 (DP)
9095 결과값만=> 삼중 점화식=> DP 
1003(DP) 피보나치 ->동적계획
* 자료형 초과하면 맥준 틀림
: 벡터 페어로도 풀 수 있다.



cout<<  << endl 백준 엔드 안썻다고 틀리다 나옴

201101=================================================

1074 Z : 재귀과정이 이해가 잘 안감
* pow(숫자,제곱근) : 숫자의 n승
1764 듣보잡 : // 비주얼에서는 답 뜨는데 백준에선 틀림 이유를 모르겠음
11399 atm : 정렬뒤 합구함 쉬움

201107============================================

1463 1로 만들기(다이나믹 플밍): 작은수 부터 최소의 경우 구하면서 구함
1931 회의실 배정(그리디): 왜 그리디인지 모르겟음// 회의 끝나는 시간이 키포인트
11047 동전 0:(그리디알고리즘) 큰 수부터 작은수를 더하면 최소갯수 구함



201115=======================================

1541
2579 계단오르기 : 처음에 점화식만 잘찾ㅈ으면 돼
11279 최대힙 : 우선순위큐 자료형으로 바로풀 수 있다.
우선순위큐 자료형이 있다
* priority_queue<int> 
* queue.push()
* queue.pop();
* top();


201121=======================================

1927 최소힙 :  최소힙은 우선순위 자료형 ㅆ는ㄴ데 처음 생성시 주의
priority_queue<int,vector<int>,greater<int>> min_heap; 이해가 잘 안감

9461 파도반 수열: 삼각형 덧붙히는 것 => 동적계획법 
주의: 출력값 맞고 점화식도 맞았는데 틀림 나와서 점화식 배열 자료형 longlong하니깐 맞음



210102======================================

2292 벌집문제
*1012 // 유기농 배추 
// 접근: 기본 인접행렬로 할라 했으나 안됌
// 주의: 이차배열 자체를 인젖해열로 두고 방문배열도 이차배열 자체로 해야함
// 인접=> 깊이우선

1260 dfsbfs: 기본 깊이,너비우선탐색 정점은 1부터 시작 주의
2606 // 바이러스
// 접근: 그래프인데 탐색이므로 깊이우선탐색 이용
// 정점 1부터가 편함
1697 
// 숨바꼭질
// 탐색인건 알겠는데 왜 너비우선인지 잘 모르겠음
// pair 를 이용해 위치와 시간 저장
// pair 함수 좀 봐둘 것
7576

42서울


210109 ==========================================

7576
// 7576 토마토 
// 배열에 최소일수 탐색 -> 너비우선 예상
// 처음에 토마토 여러개 일 경우 어떻게 탐색 시작할 지 헤맴
// 배열 입력할 때 큐에 삽입
11724
// 연결요소의 개수
// 연결 요소의 개수 = 구역 나누기 = 깊이우선
// 무방향 그래프 -> 일차원배열 깊이우선
11727
//11727 2xn 타일링2
// 2*n 경우의 수 -> DP -> 점화식
// 하지만 처음에 점화식 규칙을 못 찾아서 헤멤
// ***질문: 점화식 구성할 때 10007 을 나누는 이유를 모르겠음
2630
// 2630 색종이 만들기
// 처음에 너비우선 생각 -> 아님
// 계속해서 4분할 -> 재귀 (분할 정복)
// 분할 하면서 종이 갯수 세기
2667
// 단지번호 붙히기
// 배열에 탐색인데 뭉쳐있는 단지 구별이므로 깊이우선 예상
// 붙은 숫자 입력 scanf("%1d",&tp);
2178
// 미로 탐색
// 배열에 최소이동이므로 bfs 로 생각
// bfs 사방 행렬 구현해서 하기
//q.push(make_pair(N, M));  =  q.push({N,M}); // {} 하면 pair 형 바로됨


210117==============================================

11403
// 11403 경로 찾기 
// 접근: 그래프,경로 => 깊이우선,너비우선 가능
// 풀이: 나는 깊이우선 선택
// 질문: i에서 i로 가는 선이 없는데 출력은 왜 1로 되는거지 이해않감
// 답: 제자리 루프가 아니라 다른데 거쳐가는 것!
// 질문2: 모든 풀이가 중간에 인접행렬 자체를 바꾸면서 진행하는데 따로 만들어야 되는거 아닌가 궁금함
// 주의: 각 정점 깊이우선 때마다 방문배열 초기화 해야함
// 주의: memset 백준에서 컴파일 에서나서 fill 함수 씀

// fill(시작주소, 끝주소,채우는 값)

7569
// 7569 토마토
// 행렬에 최소시간-> 너비우선 예상
// 3차원 배열을 오랜만에 다뤄서 헤멤
// 7576 토마토 문제 상위 버전
10026
// 10026 적록색약
// 행렬 구역의 수세기 -> dfs,bfs 둘다가능
// dfs 사용함
// 정상인과 적록색약 따로 하는것에서 조금 애먹음
// dfs 처음 점 방문하는 경우 구역세는 것 에서 제외시켜서 계속 틀림 
18870
//18870번 좌표압축
// 문제접근: 좌표압축을 처음 접해서 이론 먼저 봄
// 좌표압축이란 결국 데이터 축소하기 위해 좌표를 압축한것
// 좌표압축위해 중복제거해야 하는 과정에서 erase나 unique 함수 생소
함수
- lower_bound
- unique()
- resize
- erase
11723
// 비트마스크 이해가 안감
#include <iostream>
#include <string>
using namespace std;
 
int M, num, BIT;
string input;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> M;
    while (M--)
    {
        input.clear();
        cin >> input;
        if (input == "add")
        {
            cin >> num;
            BIT |= (1 << num);
        }
        else if (input == "remove")
        {
            cin >> num;
            BIT &= ~(1 << num);
        }
        else if (input == "check")
        {
            cin >> num;
            if (BIT & (1 << num))    cout << 1 << '\n';
            else    cout << 0 << '\n';
        }
        else if (input == "toggle")
        {
            cin >> num;
            BIT ^= (1 << num);
        }
        else if (input == "all")
        {
            BIT = (1 << 21) - 1;
        }
        else if (input == "empty")
        {
            BIT = 0;
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////




20210126============================================

1620
// [백준 1620 c++] 나는야 포켓몬 마스터 이다솜
// 접근: 문자열 저장후 문자나 인덱스로 참조 => 벡터에 string 형 저장하고 find로 탐색
// 하지만 시간초과 
// 풀이: 벡터에 string 저장, map에 저장후 해싱기법으로 인덱스 log(1)
// 개념: stoi(문자열) : 문자열을 숫자로(string형 가능) 
// 개념: string 자료형은 == 원소나 문자열 바교나 참조 가능하지만 원소를 바꿀 순 없다
// 개념: find(시작주소,끝주소,찾는값) : 반환값이 iterator라 길이 구하려면 -v.begin()해야함
// 개념: map<key자료형,value자료형> : map[key] = value 값 나옴

1107
// [백준 1107 c++] 리모컨 
// 접근: 채널보다 큰수중에 최소차이,채널보다 작은 수 중에 최소차이, 100에서 ++버튼으로 최소차이 
// 중 최소값 찾으려 했으나 저건이 넘 많아지
// 풀이: 그래서 0부터 1000000까지 탐색하며 최소차이이며 고장난 버튼 없는지 검사함
// 주의: 채널과 최소차이는 채널버튼 누르는것 까지 더해야 한다
// 개념: abs() : 절댓값 
1676
// 백준 1676번 팩토리얼 0의 개수
// 접급1: 팩토리얼값 구하고 문자열로 변환 후 뒤에서부터 계산
// 접근2: 팩토리얼값 구한 뒤 mod이용해서 숫자 뒤에서 부터 차례로 
// 접근이 다 시간초과나서 틀리는듯
// 풀이: 소인수 분해 결과 2*5 가 10으로 0이 나오므로 2와5의 개수중 작은것이 0의 개수이다
// 그런데 5의개수가 2의 개수보단 항상 작으므로 5의 개수를 구한다
// 5의 개수를 구하는데 5,25,125 를 나눈 몫을 합한것이 5의 개수
// 주의: string 자료형은 각 인덱스 값 못뽑아오는 듯
1780
// 백준 1780번 종이의 개수
// 접근: 백준 다른4분할 문제랑 비슷하다고 생각하고 분할정복 생각함
// 풀이: 분할정복 재귀를 이용해 각 구역에서 탐색하다 숫자 다르면 9분할 함
// 주의: 분할할 때 인덱스 조심

7662
// [백준 7662 c++] 이중 우선순위 큐
// 접근: 이중 우선순위 큐-> 데크나 priority_que 맥스힙 민힙 해서 할라했으나 원소 삭제하는 데에서 막힘
// 접근2: AVL트리 자료형 set 이용해서 함 근데 중복이 안됨
// 접근 3: multiset 은 같은 균형잡힌 이진트리인데 중복허용
// 풀이: multiset 이용해서 삽입시 자동 정렬, 삭제시 최대최소가 맨앞,맨뒤 원소
// 주의: set 최신화 하는거 못보고 계속 틀림
// 주의: end() 주소로 계산할 때 -1안됨 -> 따로 변수로 저장하고 계산
// 주의: 마지막 cout할 때 <<'\n' 안해주면 백준 틀림!!!
// 개념: multiset<int> ,set<int>
// auto 자료형 자동 할당

20210130==============================================
7개 완전탐색
> 2309번: 일곱 난쟁이

// [백준 2309 c++] 일곱 난쟁이
// 접근: 난쟁이 키의 합 = 100 인 경우는 9명중 두명의 키를 뺀 값
// 접근: 두명의 합의 키를 구하려면 완전탐색 해야함
// 풀이: 벡터에 저장후 정렬하고 완전탐색으로 100 이되는 경우가 있으면 출력후 중단
// 개념: 합을 일일이 구할 수도 있지만 accumulate(v.begin(), v.end(), 합 초기값); 으로 구할 수 있음 

> 2231번: 분해합
// [백준 2231 c++] 분해합
// 접근: 최소 생성자의 조건을 생각해보니 99999일때가 최소값이라 생각해보니 문자열 탐색 오버스텍
// 풀이: 0부터 차례로 완전탐색 하면서 만족하는 값 출력
// 개념: to_string

> 3085번: 사탕 게임
// [백준 3085 c++] 사탕 게임
// 접근 사탕을 인접을 어떻게 바꾸는지 의미가 애매해서 헤멧지만 가로와 세로끼리만 바꾼다
// 풀이: 완전탐색으로 가로,세로 교환할 때 각 사탕의 최대개수 중 큰 수를 출력
// 개념: swap(board[i][j], board[i][j+1]); string 객체의 원소를 바꿀 수 있다

> 10448번: 유레카 이론
// [백준 10448 c++] 유레카 이론
// 접근: 3개의 합으로 되는지 아닌지만 구별 -> 3중 반복문으로 완전탐색
// 하지만 4중 반복으로 해야 모든 테스트 케이스를 돌 수 있다. 
// 풀이: 런타임 초과 날까봐 t의 최대값이 1000=i(i+1)/2 를 이용 500 까지만 반복하게 함
// 

> 2503번: 숫자 야구
// [백준 2503 c++] 숫자 야구
// 접근: 처음엔 맞는 조건을 바로찾는 알고리즘을 생각했으나 너무 복잡
// 접근2: 그래서 123부터 987 까지 완점탐색으로 찾기
// 풀이: 숫자는 문자열로 받은 다음 123부터 주어진 조검에 모두 맞으면 정답의 개수 증가
// 주의 : 중복있는 수자 예외처리 않하면 틀림

> 1018번: 체스판 다시 칠하기
// [백준 1018 c++] 체스판 다시 칠하기
// 접근: 탐색하면서 바뀌는 칸의 수를 세야 한다.

// 풀이: 완전탐색으로 8*8 영역 나누고, 
//나눈 영역에서 첫번째 칸이 검은색/ 흰색일 경우 나누어서 최소값 비교
// 풀이2: 바둑판 2가지 경우 미리 해싱으로 배열에 저장해놓고 비교하면 2중for문으로 가능

> 1182번: 부분집합의 합 (★)
====================================
5. 그리디 알고리즘 추천 문제
다음 포스팅부터 그리디 알고리즘에 대한 문제를 풀이할 예정이다.

풀이할 문제 목록은 다음과 같다. (수록된 모든 문제는 백준 온라인 저지 사이트의 문제이다.)

 

11047번 동전 0

2875번 대회 Or 인턴

10610번 30

1783번 병든 나이트  *****

11000번 강의실 배정

1931번 회의실 배정

11399번 ATM

2217번 로프

13458번 시험감독

1946번 신입 사원
// [백준 1946 c++] 신입 사원 
// 접근: 한 테스트에 대해 이중반복 완점탐색으로 신입사원의 수를 하려 했으나 시간초과
// 접근2: 서류점수에 대해 정렬을 시키면  뒤에등수에 있는 사람은 면접점수가 앞에 있는 사람보다 무조건 앞의 등수여야됨
// 풀이: 벡터에 페어형을 이용해 점수를 한번에 저장
// 정렬시키고 면접점수에 대해 기준 검사

4796번 캠핑
// [백준 4796 c++] 캠핑 
// 접근: 최대의 캠핑 이용 -> 최대가 되는  경우를 찾아보자 -> 그리디
// 풀이: 최대이용 날 = (휴가 /  캠핑운영)*캠핑이용 + 나머지 이용 가능한 날(2가지 경우)


1541번 잃어버린 괄호

12845번 모두의 마블
// [백준 12845 c++] 모두의 마블
// 접근: 그리디는 눈치챈 다음 최대를 구하는 것이므로 최대값이 가장 많이 중복이 되어야 한다고 생각
// 풀이: 결국 더하는 과정의 결과값은 처음에 최대값에서 시작하면 최댓값은 n-2번 더하고 나머지 총 합을 더하면 최대값

2873번 롤러코스터

1744번 수 묶기

1700번 멀티탭 스케줄링

1969번 DNA


20210206======================================
14501 O
// [백준 14501 c++] 퇴사 
// 접근: 완전탐색으로 최대경우를 조사 -> 그때그때 더해지는 금액의 개수가 달라져서 단순 반복문으로 힘듦-> dfs로 구현
// 풀이: 2차 배열에 저장하고 깊이우선 탐색으로 최대값 저장
// 주의: 다음 넘어갈 인덱스 n까지 않하면 마지막 인자 검사 못함

9663 X
// [백준 9663 c++] N-Queen
// 접근: 2중 반복 완전탐색으로 퀸의 놓을 수 있는 위치 저장해 가며 놓기 -> 너무 오래걸릴듯
// 접근2: dfs를 이용하여 퀸의 경우를 조사하는데 백트래킹을 통해 경우의 수를 줄인다 
// 풀이: 놓는 퀸의 위치를 저장 후 백트래킹을 해서 경우의 수를 줄이고 dfs 이용

14888
// [백준 14888 c++] 연산자 끼워넣기 V
// 접근: 2중 반복 완전탐색으로 할려 했으나 경우의 수가 많아서 런타임 초과 예상
//접근2: dfs이용한 완전탐색 을 해서 모든 경우의 수 구하는 것이 효과적이라 생각 -> 연산자 개수조건 걸어서 백트래킹 사용
// 풀이: 연산자 배열과 숫자배열 저장한 후 

14502 
// [백준 14502 c++ V] 연구소  
// 접근: 바이러스 퍼뜨림-> 탐색-> dfs/bfs
// 풀이: dfs로 벽세우기
// 벽 세웠으면 dfs로 바이러스 퍼뜨리기
// 그 상태에서 안전영역 dfs로 탐색
// 개념: 	vector<vector<int>> v(n,vector<int>(m)); // 2차벡터 선언
// 개념: vector<vector<int>> &v 이차벡터 주소표시


14889
// [백준 14889 c++ V] 스타트와 링크
// 접근: n 명 중 팀 인원 정하기 -> dfs 탐색
// 풀이: dfs탐색으로 팀인원 뽑기
// 팀인원 다 뽑고 각 팀의 포인트 계산
// 각 팀의 능력치 차이 계산하고 최소값 최신화
// 주의: dfs 탐색 시 방문 않 한 곳만 들르는 조건 빼서 처음에 헤멤

////////////////////////////////////////////////////////////////////////////////


20210222=============================================

17413
// [백준 17413 c++ V] 단어 뒤집기 2
// 문제: 문자열을 받고 괄호 안의 것이 아니면 단어마다 뒤집어서 출력
// 접근: 단어를 뒤집는다 -> 스텍 이용
// 풀이: 문자열을 getline으로 받고 
// 괄호 안 일때와 바깥일 경우 inverse 가 1 일때는 스텍에 저장, 0 일때는 그냥 출력
// 개념: getline(cin, s); 공백포함 문자열 입력(gets와 같은 느낌)
5525
10988
// [백준 10988  c++ O] 팰린드롬인지 확인하기
// 문제: 거꾸로 해도 같은 문자열인 팰린드롬인지 확인하기
// 접근: 완전탐색으로 문자열의 앞뒤에서 서로 비교
// 풀이: 반복문으로 앞뒤 동시비교하며 팰린드롬이 아니면 0출력
11656
// [백준 11656  c++ v] 접미사 배열
// 문제: 한 문자열에 해당하는 모든 접미사를 정렬시키고 출력
// 접근: substr함수로 각 접미사를 벡터에 저장
// 풀이: 문자열 입력 받고
// substr함수로 각 접미사 벡터에 저장
// 벡터 정렬
// 출력
// 개념: string.substr(시작인덱스,끝 인덱스) : 해당하는 부분만 복사


20210307================================================
4963
// [백준 4963 c++ VO] 섬의 개수
// 문제: 배열 영역을 탐색하여 섬의 개수를 구하는 dfs,bfs 문제
// 접근: 대각선까지 섬의 영역으로 보아서 8방향 탐색, 기본 dfs로 접근
// 접근2: bfs로 
// 풀이: 그래프 입력 받고
// 완전 dfs 로 8방향 탐색하며 섬의 개수 출력
// 방문,그래프 배열 초기화
// 개념: memset(visited, 채우는 값, sizeof(visited)); 배열을 한번에 초기화 시킴

2468
// [백준 2468 c++ VO] 안전 영역 
// 접근: 비의 높이보다 큰 블록만 탐색 -> dfs나 bfs 
// 풀이: dfs로 완전탐색하며 안전한 구역의 개수 찾기
// 주의: 비가 오지 않을 경우도 생각해야 해서 안전구역은 항상 1 이상
// 개념: fill_n(일차원 배열,원소개수 , 채울 값);  fill_n은 한 행씩 채우지만 
// 개념: memset(배열,값,원소개수); memset은 모든 원소 한번에 초기화 가능

2583
// [백준 2583  c++ OO] 영역 구하기
// 문제: 배열에서 직사각형을 제외한 영역의 개수와 영격 원소의 개수를 정렬시켜 구하는 문제
// 접근: 기본 dfs 로 완전탐색
// 풀이: 배열 입력받고
// 기본 완전탐색 dfs 하면서 영역의 개수세고 벡터에 저장
// 영역원소의 개수는 벡터에 저장 후 정렬

20210314===================================================

1325
// 문제: 컴퓨터를 노드라 생각하면 가장 많은 노드 탐색하는 컴퓨터 번호 오름차순으로 출력
// 가장 기본 그래프 탐색 문제
// a가 b 신뢰 = b->a 로의 단일방향 엣지를 의미
// 접근1: 컴퓨터를 노드라 생각하면 각 노드에서의 dfs로 탐색 개수 구함
// 풀이: 각 노드에서의 기본 dfs
// 컴퓨터의 수가 최대값보다 크면 check벡터 clear후 저장
// 컴퓨터의 수가 최댓값과 같으면 check벡터에 추가
// 벡터정렬 후 출력
//  컴퓨터 번호 1부터 시작

2644
// [백준 2644 c++ VV] 촌수계산
// 문제: 가족 구성원 사이의 촌수 계산 ,가족을 노드라 하고 찾고자 하는 가족의 촌수 계산하고 없으면 -1출력 탐색 문제
// 가족 관계는 양방향 그래프라 생각해야 함
// 접근1: 가족을 노드라 하고 기본 인접행렬 그래프 dfs탐색 , 인접행렬은 벡터로 구현
// 풀이: 가족관계 벡터 인접행렬에 저장
// 찾고자 하는 가족노드에서 dfs 시작하고
// 다른 풀이들은 dfs함수에서 visited 노드 초기화 않해주는데 여러 경로 존재할 시 초기화 해야한다고 생각해서 해줌
// 목표 가족 찾으면 뎁스 저장 후 출력

1743
// 문제: 배열중 인접해있는 음식물의 크기의 합이 가장 큰 음식물의 크기를 출력
// 접근: 4방향인접하면 하나의 음식물로 본다 -> 기본 dfs 탐색
// 풀이: 배열의 크기와 음식물 위치 입력
// 기본 완전탐색 dfs 
// 음식물의 최대크기 최신화
// 음식물 최대크기 출력

2668
답은 나오는데 재귀부분 시간초과
싸이클 유형


20210322=============================================

1149
// [백준 1149 c++ V] RGB거리
// 문제: 각 집마다 서로다른 규칙을 따른 색의 비용의 최소값을 구하는 문제
// 접근1: 재귀 dp로 최소값 구하려 생각 -> 안풀림
// 접근2: 작은 단위인 1번째 부터 빨초파 인 경우 각 그때의 최소값 더해가기
// 풀이: 첫번째 집 비용 입력
// 반복문으로 다음 집부터 빨간색이면 전의 집은 초,파 중 최소비용인 경우의 합 저장
// 처음 집의 색이 빨초파 인 3가지 경우중 최소비용 출력

2579
// [백준 2579 c++ VV] 계단 오르기
// 문제: dp 문제 -> 규칙에 따라 한칸 또는 2칸씩 오르며 계단의 합의 최댓값 구하기
// 접근1: 재귀 dp로 모든 경우의 수 -> 시간초과 날 것 같에서 않함
// 접근2: dp 초기값 구하고 규칙있는 부분 점화식 구해서 그때그때의 최댓값 저장하며 n까지의 최댓값 저장 
// 풀이: dp 인덱스 2 까지 최댓값 저장
// 3인겍스 부터 오를 수 있는 방법은 2가지
// 점화식 세워서 각 인덱스의 최댓값 저장
// n 의 최댓값 출력
1932
// 답 나오는데 시간초과
2156
// [백준 2156 c++ V] 포도주 시식
// 문제: 연속 3개를 마시지 않으면서 n개의 포도주를 마셔서 포도주 합의 최댓값 구하기
// 접근1: dp로 점화식 구하고 그때그때의 최댓값 저장
// 풀이: 포도주 입력
// n번째 포도주합의 최댓값
// 1. n번째 마시지 않고 dp[i - 1]
// 2. n 번째 마시고 n-1 번 마시고 n-3 까지 최댓값 더하기
// 3. n번째 마시고 n-2 까지 최댓값 더하기
// 3가지중 최댓값 dp에 저장
// 주의: n이 1이나 2인경우 조건 생각해야 함
// 개념: 3개 이상 비교 max({1,2,3}) 중괄호로 이용


20200329============================================

10844
// [백준 10844 c++ V] 쉬운 계단 수 
// 문제: n 자리의 계단 수의 개수를 1000000000로 나눈 나머지를 구하는 문제
// 접근1: 직접 갯수 세서 개수간의 규칙으로 점화식 찾으려 했으나 못찾음
// 점근2: n-1 의 계단수와 n의 계단수의 규칙 찾으려 함 
// 풀이: n자리의 1의 자리가 0인 계단수 : n-1자리의 1의 자리수가 0 또는 2인 계단수의 합
// 식으로 표현 1<= L <=8 dp[n][L] = dp[n-1][L-1]+dp[n-1][L+1]
// n의 1의 자리수가 0 일 때는 1 밖에 안됨 : dp[n][0] =dp[n-1][1]
// n의 1의 자리수가 9 일 때는 8 밖에 안됨 : dp[n][9] =dp[n-1][8]
// 이차원 dp 배열에 n 자리의 L로 끝나는 계단 수의 개수 저장
// 주의: dp값이 커서 long long 자료형 써야 됨
// 주의: 출력에 1000000000 으로 나눈 나머지를 출력해야 하는데 dp 과정중에도 1000000000을 나눈 나머지를 저장해야 답 맞음 -> 이해 안감
// 질문: 출력에 1000000000 으로 나눈 나머지를 출력해야 하는데 dp 과정중에도 1000000000을 나눈 나머지를 저장해야 답 맞음 -> 이해 안감
// 1~9 : 9
// 10 12 21 23 ... 87 89 98 : 17

11053
// [백준 11053 c++ V] 가장 긴 증가하는 부분 수열
// 문제: 가장 긴 증가하는 부분수열(오름차순의 부분수열)의 길이를 구하는 문제
// 접근1: 브루트포스로 큰 수 나올 때마다 카운트해서 최대값 찾으려 생각-> 시간초과 예상으로 안함
// 점근2: dp를 이용해 각 자리마다 나오는 증가하는 부분수열의 최대값 저장 
// 풀이: 1일때는 모두가 1이므로 각 초기 dp[i]는 1
// 처음 인덱스부터 현재검사하는 인덱스 까지 현재검사하는 원소값보다 작으면 dp값 비교해서 최대값으로 최신화
// 계속 최신화 하며 현재 검사하는 인덳까지 가면 dp 값이 곧 부분수열의 길이랑 같음

11052
// [백준 11052 c++ V] 카드 구매하기
// 문제: n 개의 카드를 구매할 때 비용의 최댓값 구하기
// 접근1: 카드 n개를 살 때의 최댓값은
//카드 n - 1개를 살 때의 최댓값 + 1번째 카드
//카드 n - 2개를 살 때의 최댓값 + 2번째 카드 ...계속
//카드 0개를 살 때의 최댓값 + n번째 카드 중 최댓값 .
// 결국 n 개를 살 때 카드의 합이 n이되는 조합들 중 최댓값을 dp 에 저장하고
// dp[0] 부터 차례로 저장해나가야 함
// 풀이: 
// 주의: n번째 dp는 카들 조합들중 최대이므로 이중 반복문이어야 함

2193
// [백준 2193 c++ V] 이친수 
// 문제: n 자리 이친수의 개수 구하기 
// 접근1: 이친수의 맨 끝 자리가 0이면 다음 수 2개, 1이면 다음수 1개
// 점근2: 전화식으로 표현을 잘 못해서 각 dp 값의 규칙 찾으려 함
// 풀이: dp[0] ,dp[1]값은 고정,
// dp 점화식 dp[n] = dp[n-1]+dp[n-2] 으로 dp 배열 구함
// 주의: dp값이 인덱스가 90이어도 숫자가 커서 long long 자료형 써야 됨


20210405==========================================

9184
// [백준 9184 c++ O] 신나는 함수 실행
// 문제: 입력값에 따라 주어진 재귀함수가 시간초과가 나지않는 코드 짜기
// 접근1: 재귀 시간 단축 -> dp로 함수 반환값 dp배열에 저장하며 반환
// 풀이: 주어진 대로 재귀함수를 작성한다
// 반환할 때 저장이 된 코드이면 dp 배열 바로 반환
// 저장이 않되어있으면 dp 배열에 재귀값 저장하며 반환

11054
// [백준 11054 c++ O] 가장 긴 바이토닉 부분 수열
// 문제: 한 원소를 기점으로 양쪽에서 가장 긴 증가하는 부분수열(오름차순의 부분수열)의 길이를 구하는 문제
// 점근1: dp를 이용해 각 자리마다 나오는 증가하는 부분수열의 최대값 저장 왼쪽 오른쪽 부터 각 dp 구하고 그것의 합이 dp값
// 풀이: 왼쪽부터 오른쪽 부터 dp 2차원 배열을 생성
// 각 자리의 dp는 초기값 1
// 왼쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 오른쪽부터 가장 긴 증가하는 부분수열 dp 저장
// 각 dp의 2개 원소 값의 최댓값을 구함
// 주의: 왼,오른 중복되서 최댓값 -1 해야함
9251

// [백준 9251 c++ *] LCS
// 문제: LCS(가장 긴 공통 부분수열)의 길이를 구하는 문제 
// 점근:  잘 이해 안감
// 풀이: 같은 문자일 때는 이전 까지의 dp +1
// 다른 문자일 때는 왼쪽,위 중 큰값 dp 저장
// 점화식 : 같은 문자 dp[i][j] = dp[i - 1][j - 1]+1
// 다른 문자 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

12865
// [백준 12856 c++ &] 평범한 배낭
// 문제: 가방에 넣을 수 있는 무게대비 최대 가치를 구하는 문제
// 접근:  재귀로 모든 경우의 수 탐색 -> 시간초과 예상 안함
// 접근2: dp
// 풀이: 
// dp[i-1][j]// 기존 탐색했던 물건들로만 j를 만드는 것 //가방에 넣을수 있는지 없는지
// dp[i-1][j-w[i]] 기존 탐색했던 물건들로 무게j-w[i]를 만들고 현재 물건을 가방에 넣는  경우// 가방에 넣을 수 있으면 넣는것과 안넣는것중 가치 큰값 저잦ㅇ

20210510============================================

14500
// [백준 14500 c++ O] 테트로미노
// 문제: 가능한 5종류의 칸의 합 중 테트로미노 각 칸의 합의 최대값 구하기
// 접근:  칸의 개수 4개 -> depth가 4인 dfs 생각 ->  근데 ㅗㅓㅏㅜ 는 dfs로 탐색 불가능한 모양 이어서 따로 계산 
// 풀이: 
// 뎁스가4 인 완전탐색 dfs로 테트로 미노의 최댓값 갱신
// ㅏㅓㅗㅜ 모양은 중심칸의 인덱스 조건 걸고 각자 계산 후 최댓값 갱신
// 최댓값 출력
// 주의 : dfs 에 memset으로 visited 배열 초기화 하면 시간초과 -> 그냥 다시 0 대입

2504
// [백준 2504 c++ X] 괄호의 값 
// 문제:  괄호식이 맞는지 검사하고 규칙에 따라 결과값 출력
// 접근:  괄호 검사하며 계산숫자를 스택에 넣어가며 -> 조건문 너무 많음
// 접근2: 계산 식을 써보면은 분배법칙에 따라 곱해지는 결과값이 결국엔 그때그때 () 쌍만 보ㄴ면 됨 
// 풀이: 
// ( [ 나올때마다 tp 값2,3 곱해줌
// 식 에러처리 먼저 해야 함
// ) ] 나올떼마다 값 더해주고 tp/ 2,3 해줌
// 결국 전개된 숫자식과 같음
// 마지막 예외 때문에 에러처리 한번 더 해야함
1748
// [백준 1748 c++ V] 수 이어 쓰기 1
// 문제: 이어진 수의 총 자릿수 구하기
// 접근:  문자열로 직접 수 만들어서 자릿수 구하기 -> 시간초과 
// 접근2: 수학 규칙성 찾기
// 풀이: 
// 각 자릿수 일때 길이합 구하기
// 총 자릿수 합 = 같은자리 (끝수 - 첫수+1)*자릿수
// 예) (99-10+1)*2 = 180
5567
// [백준 5567 c++ V] 결혼식 
// 문제:  그래프 로 이어진 상근이 친구의 친구등 까지  명 수 세기
// 접근:  인접리스트 양방향 그래프로 bfs 탐색
// 특이점: dfs에서 depth를 이용하는 문제
// 풀이: 
// 인접리스트 양방향 그래프 입력
// bfs 탐색으로 상근이 친구 탐색하며 방문배열과 친구배열 최신화
// 최신화된 친구배열을 이용해 이접리스트 탐색하며 친구의 친구 탐색하며 방문처리
// 방문배열 탐색해서 동기의 수 출력
// 풀이2:
// dfs로 1(상근)부터 시작하는 것만 dfs 탐색 

20210518==============================================

음양더하기 
내적
약수의 개수와 덧셈
두 개 뽑아서 더하기
3진법 뒤집기

체육복
// [프로그래머스 c++ V] 체육복
// 문제: 도난당한 사람이 여분의 옷을 빌려 체육시간에 나가는 총 인원수 구하기
// 접근:  최대 명수 -> 그리디 또는 dp -> 그리디로 선택
// 풀이: 
// 옷의 개수를 나타내는 배열에 모두 1개씩 추가
// 여분의 옷 추가
// 도난당한 학생 옷 감소
// 반복문으로 도난당한 앞사람 여분옷 있으면 빌리기
// 도난당한 뒷사람 여분옷 있으면 빌리기
// 총 체육참가 학생수 출력

소수만들기 O

폰켓몬
// [프로그래머스 c++ O] 폰켓몬
// 문제: 포켓몬을 n개 중 n/2개 뽑았을 때 서로 다른 종류의 최대값 구하기
// 접근:  구현-> n개중 서로다른 개수 구하고 최대값을 n/2가 넘어가는지 아닌지 검사 
// 풀이: 
// 벡터 정렬 후 중복원소 제거
// 서로다른 종류의 개수 구하고 ㅇn/2 보다 큰지 아닌지 검사
// 종류의 최댓값 출력
// 개념:
// v.erase(시작주고, 끝주소)
// unique(시작 주소, v.end()) : 연속으로 반복되는 원소를 제외한 값 뒤로 보내고 반복되는 원소의 시작주소 반환
// 벡터의 중복값 제거 : 정렬 후 -> erase(unique(v.begin(),v.end()),v.end());
// 풀이 2:
// 해시 이용해서 종류의 개수 배열에 저장

크레인인형뽑기
// [프로그래머스 c++ V] 크레인 인형뽑기 게임
// 문제: 인형을 뽑아 바구니에 연속해서 같은 것이 쌓이면 제거한고 제거된 인형의 총 개수 구하기
// 접근:  
// 풀이: 
// 뽑는 열 반복문
// 뽑는 열 위부터 인형 탐색
// 인형 있고(0이 아니면) 바구니 중복 안되면 바구니 팝 하고 제거인형+=2
// 인형 있고 바구니 중복 아니면 푸쉬 
// 뽑은 위치에 0 대입

20210523==========================================

신규 아이디 추천
// [프로그래머스 c++ V] 신규 아이디 추천
// 문제: 주어진 7단계 조건을 탐색하며 문자열 처리
// 접근:  조건문 구현 ->
// 풀이: 7단계 조건문 구현
// 주의: 2단계에서 특수문자인 경우는 인덱스 안넘어가야 됨 (반복문에 i++없음)
// 개념: 문자열.erase(주소) : 해당 주소만 삭제
// 개념: 문자열.erase(시작주소, 끝주소) : 해당 주소범위 삭제


로또의 최고 순위와 최저 순위
// [프로그래머스 c++ V] 로또의 최고 순위와 최저 순위
// 문제: 0은 모르는 번호라 하고 6개의 번호 중 로또번호의 일치갯수를 구해서 최저순위와 최고순위를 구하는 문제
// 접근:  조건문 구현 -> 최고순위=일치번호 갯수+0의 갯수 , 최저=일치번호갯수
// 풀이: 
// 찍은 번호 탐색으로 0의 갯수와 일치하는 번호의 갯수 구함
// 최고순위=일치번호 갯수+0의 갯수 , 최저=일치번호갯수로 정답에 대입
// 개념: find(배열.begin(),배열.end(),찾는 값) : 찾고자 하는 것의 위치 반환,없으면 end()반환 , 헤더#include <algorithm>


키패드 누르기
// [프로그래머스 c++ O] 키패드 누르기
// 문제: 키패드 번호의 위치에 따라서 왼손으로 누를지 오른손으로 누를지 저장 후 반환 
// 왼쪽 번호는 왼손
// 오른 번호는 오른손
// 가운데 번호는 거리가 가까운 손으로 거리가 같으면 주 손으로 누른다
// 접근:  일일이 조건문 구현 -> 키패드 번호를 행렬 인덱스 배열로 저장 해놓은 다음 x축거리 + y축거리
// 0~9까지는 해당 인덱스, *=10,#=11 인덱스로 저장
// 풀이: 
// 왼쪽번호 누르는 경우
// 오른번호 누르는 경우
// 가운데 번호 누르는 경우 거리측정:  절댓값(x축거리) + 절댓값(y축거리)
// 거리 같은 경우 오른손잡이인 경우 / 왼손잡이 경우
// 개념: abs(숫자) :절댓값 , 헤더:#include <cmath>


[1차] 비밀지도
// [프로그래머스 c++ O] 비밀지도
// 문제: 두 개의 지도의 벽과 공백을 십진수->이진수 해독 후 하나의 지도로 합쳐서 비밀지도 해석 후 문자열 출력
// 접근:  2개의 지도를 해석해서 벽은1 공백은 0으로 1개의 지도배열 합침 -> 비밀지도배열 해석
// 풀이: 
// 2차 비밀지도 배열 0으로 초기화
// 지도1, 지도2 각각 십진수->이진수 변환하며 1인 경우 비밀지도1 대입
// 합쳐진 비밀지도 반복문 탐색하며 1인 경우 tp 스트링에 추가
// 한 행이 완성되면 정답 스트링에 tp추가
// 개념: memset(배열,원소,크기sizeof(배열)) , 헤더#include <cstring>


[1차]다트게임

// [프로그래머스 c++ O] 다트게임
// 문제: 주어진 문자에 따라 계산을 하고 모든 수의 합을 출력
// 접근: 문자 하나씩 탐색하며 조건문 
// 풀이: 
// 1.숫자인 경우 숫자를 저장해 놓고 10인경우 10넣어주고 인덱스 건너뛰기
// 2.보너스 D,T 인 경우 pow(a,b) 를 이용해 제곱
// 3.보너스 * 인 경우 첫 원소인지 아닌지 구별 후2배 곱 , 첫 번째 숫자는 해다 숫자만 아니면 해당숫자와 그 전 숫자까지 2배
// 4. 보너스 # 인 경우 해당 원소만 -1 곱
// 개념: pow(밑, 제곱승) , 헤더#include <cmath> // pow 안 쓰고 숫자 저장 후 n*n 해도 됨(삽질 한 듯)



20210623==================================

조이스틱  
큰 수 만들기  
구명보트  
// [프로그래머스 c++ V] 구명보트
// 문제: 최대 2 명씩 태우는 보트를 이용해서 사람들을 운반했을 때 이용하는 배의 최소갯수 구하기
// 접근1: 최소-> 그리디/dp : 최대값 + 수용되는 범위의 최댓값 <= 한계 가 배의 최소갯수  // 정확도는 맞으나 시간초과
// 접근2 : 최소 = 최대값 + 최소값 <= 한계 가 배의 최소갯수 // 이 경우가 왜 배의 최소갯수인지 이해 안됨???
// 풀이: 
// 사람 몸무게 정렬
// 벡터의 앞뒤부터가 최대 최소니까 최대+최소 <= 한계 인경우 앞 인덱스 증가(2명 태우기)
// 최대+최소 > 한계 인 경우 는 최댁값 1명만 태우기
// 개념: 벡터.pop_back(대입할 대상)
	

모의고사   
	
소수찾기   
// [프로그래머스 c++ V] 소수 찾기
// 문제: 숫자가 나열된 문자열 입력 받으면 문자열 속 숫자로 만들 수 있는 수 중 소수의 갯수 구하기
// 접근: 소수찾기->에라토스테네스의 체 / 1,2,3,..자릿수의 수 어쩧게 탐색? => next_permutation() 와 substr으로 각 수열의 모든 자릿수 탐색
// 풀이: 
// next_permutation() 으로 모든 수열 탐색하기 위해 문자열 정렬
// 반복문에서 substr으로 각 수열일 경우 1,2,3,... 자리의 수 추출 후 정수로 변환
// 추출된 수 소수판별후 소수이면 해쉬배열에 1대입
// 배열탐색으로 소수의 갯수 구하기
// 개념: 
// next_permutation(numbers.begin(),numbers.end()) : 작은 수부터 다음 수열로 증가하다 끝나면 false반환
// stoi(문자열) : 문자열을 정수로 반환
// 문자열.substr(부분문자열 시작 인덱스,부분문자열 길이) : [pos, pos + count) 범위의 문자열 추출
// 주의:
// 에라토스테네스의 체 에서 0,1 예외조건 
	
	
카펫
// [프로그래머스 c++ O] 카펫
// 문제: 갈색,노란색 타일의 갯수가 주어졌을 때 조건에 만족하는 카펫의 가로,세로 길이 구하기
// 접근: 가로의 길이를 완전탐색하며 조건에 맞는 가로,세로 구하기
// 풀이: 
// 가로길이는 갈색타일의 갯수보다는 무조건 작으므로 가로의 길이가 갈색갯수부터 작아지며 반복문 탐색
// 해당 가로길이가 전체타일갯수과 나누어 떨어지면
// 가로 >= 세로 조건
// 세로>=3 조건
// 실제 노란 카펫의 갯수가 맞는지 확인
// 모든 조건 만족되면 가로,세로길이 정답벡터에 푸쉬
// 주의: 실제 노란 카펫의 갯수가 맞는지 확인 조건
	
	
20210702================================================================  
완주하지 못한 선수  
전화번호 목록  
위장  
k번째 수  
가장 큰 수  
H-Index  
	
20210725===============================================================  
타겟 넘버  
카카오프렌즈 컬러링북  
단체사진 찍기  

	
20210827================================  
[뼈대문제] 백준 10828번. 스택  
[뼈대문제] 백준 10845번. 큐     
[뼈대문제] 백준 10866번. 덱  
1966  
1158  
3986  
12789  
	
20210903=================================
11725  
1991  
5639  
11279  
1927    

20210912====================================  
1주차 : 배열, 스택, 큐  
2주차 : 트리 + BST  
3주차 : dfs, bfs  
  
남은거 :  
그래프 + DFS + BFS (+ 최단거리)  
힙:  
정렬:  
백트래킹:  
DF:  
분할정복:  
	  
[뼈대문제] 프로그래머스. 네트워크  
*유사문제: 벡준 2606번. 바이러스  
프로그래머스. 타겟 넘버  
백준 1697. 숨바꼭질  
프로그래머스. 여행경로  
	
20210916====================================    
1주차 : 배열, 스택, 큐     
2주차 : 트리 + BST    
3주차 : dfs, bfs    
    
남은거 :    
그래프 + DFS + BFS (+ 최단거리)    
힙:    
정렬:    
백트래킹:    
DF:    
분할정복:    
	  
백준  
(완전탐색)  
- 9095 1, 2, 3 더하기  
- 10448	유레카 이론  
- 15649 N과 M  
  
(분할 정복)  
- 1780 종이의 개수     
- 2630 색종이 만들기  
- 1992 쿼드트리  
	  
20210923=========================================      
1주차 : 배열, 스택, 큐  
2주차 : 트리 + BST  
3주차 : 그래프 + DFS + BFS (+ 최단거리)  
4주차 : 완전탐색(재귀), 분할정복  
5주차 : dp  
  
남은거 :  
힙  
정렬  
백트래킹     
  	
퇴사 2 (🥈실버 2티어)  
점프 (🥈실버 2티어)  
1, 2, 3 더하기 4 (🥈실버 1티어)  
기타리스트 (🥈실버 1티어)  
크리보드 (🥈실버 1티어)  
BOJ 거리 (🥈실버 1티어)  
