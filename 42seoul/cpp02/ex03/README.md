# CPP02 

## EX03

### Description

이 과제는 한 점을뜻하는 Point 클래스를 구현하고 특정 Point가 삼각형안에 존재하는지를 찾는 BSP함수를 구현하는 것이다   

#### BSP

`BSP stands for Binary space partitioning. You are welcome. :)`

BSP란 유클리드 공간을 초평면 상의 블록 집합으로 분할하는 기법이다   
분할하는 과정에서 BSP 트리구조가 생성된다    

이 기법은 DOOM이라는 게임에서 최초로 도입하게 되어 3D공간의 맵을 효율적으로 구성하였다    
이를 통해 게임의 폴리곤 중복을 줄이고 렌더링 성능을 극대화 하여 게임의 최적화에 큰 기여를 하였다    

지금날에는 ray tracing이나 Collision detection에 많이 사용한다   


![BSP](../../../images/BSP.png)

위 그림은 폴리곤을 나누는 최소 단위로 `볼록한 다각형`으로 분할하는 과정을 묘사한 것이다   

BSP 트리 구축의 과정은 다음과 같다   

1. 기준 폴리곤(루트 노드)을 선택한다 (여기서 잘 선택해야 효율적인 트리를 구축할 수 있다)   
2. 선택한 폴리곤의 평면 방정식에 따라 나머지 폴리곤들을 앞, 뒤를 기준으로 리스트를 생성한다         
3. 앞 리스트와 뒤 리스트 각각에서 새로운 기준 폴리곤을 선택하여 앞, 뒤로 분할하여 자식노드를 생성한다   
4. 이 과정을 재귀적으로 반복하여 원하는 기준의 리프노드(폴리곤 형태)를 전부 생성한다   

[이곳](https://en.wikipedia.org/wiki/Binary_space_partitioning)에서 그 과정이 잘 표현되어 있다   

여기서 의문이 생기는 과정이 2가지가 존재한다   

- 앞 리스트와 뒤 리스트에서의 폴리곤을 선택하는 기준이 무엇인가?   
- 폴리곤을 나누면서 나아가는 과정에서 중복되는 서브 트리가 생성되지 않는가?   

이 둘의 답변은 다음과 같다

- 앞 리스트와 뒤 리스트에서의 폴리곤을 선택하는 기준이 무엇인가?  

	ㅌ
	

### 참고 자료

[위키피디아](https://en.wikipedia.org/wiki/Binary_space_partitioning;)
