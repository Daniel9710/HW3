# HW3: Scheduling Algorithm 구현 실습

scheduling algorithm을 구현하면서, scheduler가 host와 cpu 사이에서 어떤 작업을 수행하는지 이해하고 각 scheduling algorithm 간의 특징과 차이점에 대해 생각해보자.


## 파일 구성
> __src__ : 기본 구현에 필요한 파일들을 모아둔 디렉터리 (참고용)
> 
>> __cpu.h__, __cpu.c__ : cpu 모듈 관련 구현 파일
>> 
>> __host.h__, __host.c__ : host 모듈 관련 구현 파일
>> 
>> __process.h__ : process 구조체 관련 정의 파일
>> 
>> __parser.h__, __parser.c__ : parser 모듈 관련 구현 파일 (실행 파일 실행시 인자 parsing)
>> 
>> __util.h__, __util.c__ : 구현 관련해 사용할 함수 구현 파일
>> 
>> __defs.h__ : 구현 관련해 사용할 정의 구현 파일
>> 
> __traces__ : 시뮬레이션을 진행할 process들을 명세한 파일들을 모아둔 디렉터리
>
> __*.o__ : src에 모아둔 파일들을 object 파일로 미리 컴파일해둔 파일들 (make 사용시 이 파일들을 이용해 컴파일 진행됨)
>
> __scheduler.c__ : scheduler 모듈 관련 구현 파일 __(중점적으로 구현해야할 파일)__ 
> 
> __Makefile__ : 컴파일의 편의를 위해 만든 Makefile
> 
> __scheduler_ans__ : scheduler 모듈 답안 실행파일 __(이 파일의 동작과 똑같이 결과가 나오면 됨)__


## 구현 방법
### scheduler.c에 각 scheduling algorithm (FIFO, SJF, RoudRobin, MFLQ, Guarantee)를 구현한다.
> - 각 scheduling algorithm을 위해 필요한 데이터(ex. 큐)들을 저장하고 사용할 구조체 작성
>> ![struct](https://user-images.githubusercontent.com/44739822/125669568-935db2c1-7ac1-4f60-b2e1-68b1febd59ae.PNG)
> - 각 scheduling algorithm에 대해 시뮬레이션 시작 전에 해야할 initial 작업 구현
>> ![init](https://user-images.githubusercontent.com/44739822/125669561-8b7555ed-4c9a-49f9-9658-900e369fe137.PNG)  
> - 각 scheduling algorithm에 대해 한 cycle마다 수행할 작업 구현
>> ![simulate](https://user-images.githubusercontent.com/44739822/125669567-6ddd0301-8686-4e40-bd17-beddb0157cbc.PNG)
> - 각 scheduling algorithm에 대해 시뮬레이션이 끝나고 해야할 작업 (ex. 동적할당 해제) 작업 구현
>> ![terminate](https://user-images.githubusercontent.com/44739822/125669569-452e351a-6aed-427a-8bbb-31bb8e385785.PNG)

### 추가로 필요한 자료구조, 함수가 있으면 추가한다.
> - 추가할 헤더 파일이 있을 경우 scheduling.c의 해당 부분에 include
>> ![header](https://user-images.githubusercontent.com/44739822/125669552-1719cc92-44c9-4ddd-9370-1808eed81403.png)
> - 추가할 함수가 있을 경우 scheduling.c의 해당 부분에 작성
>> ![function](https://user-images.githubusercontent.com/44739822/125669572-164a05ad-374e-4add-b8b6-f955652f4831.png)
> - 추가할 .c 파일이 있을 경우 Makefile의 해당 부분에 작성
>> ![makefile](https://user-images.githubusercontent.com/44739822/125670175-5d8b11c5-c6a9-4659-9fd8-7593053b1136.png)

### 'make' 명령어를 사용해 컴파일을 완료하면 'schedule'이라는 실행파일을 만들 수 있다.
> ![make](https://user-images.githubusercontent.com/44739822/125670950-a14e998f-13b5-41fc-84c8-e843c81c7b5f.PNG)

### 아래 형식으로 명령을 작성해 테스트한다.
> - FIFO scheduling을 테스트 할 경우
> ~~~Bash
> ./schedule [trace 파일 경로] FIFO
> ~~~

> - SJF scheduling을 테스트 할 경우
> ~~~Bash
> ./schedule [trace 파일 경로] SJF
> ~~~

> - RR scheduling을 테스트 할 경우
> ~~~Bash
> ./schedule [trace 파일 경로] RR [Quantum 크기]
> ~~~

> - MLFQ scheduling을 테스트 할 경우
> ~~~Bash
> ./schedule [trace 파일 경로] MLFQ [URGENT Quantum 크기] [HIGH Quantum 크기] [MID Quantum 크기] [LOW Quantum 크기]
> ~~~

> - GUARANTEE scheduling을 테스트 할 경우
> ~~~Bash
> ./schedule [trace 파일 경로] GUARANTEE [Quantum 크기]
> ~~~  

### schedule_ans에 같은 명령을 테스트하고 결과를 비교한다.
> ![sim_result](https://user-images.githubusercontent.com/44739822/125674135-e1a1011d-f06a-40bf-b54f-cc7beb824a29.png)


## 구현 결과
### - ex 1.
> ~~~Bash
> ./schedule traces/test FIFO
> ~~~
> ![fifo test](https://user-images.githubusercontent.com/44739822/125673308-100557cb-c377-48f2-9768-9e0fad523ae3.PNG)

### - ex 2.
> ~~~Bash
> ./schedule traces/test MLFQ 1 2 3 4
> ~~~

## 구현 시 주의 사항
- 전역변수 사용 x
- src 내부의 코드는 고치지 x
- scheduler.c 내부 코드도 이미 작성되어 있는 부분은 고치지 x