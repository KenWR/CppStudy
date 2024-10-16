# Open closed (개방-폐쇄 원칙)

## Description

**SOFTWARE ENTITIES (CLASSES, MODULES, FUNCTIONS, ETC.) SHOULD BE OPEN FOR EXTENSION, BUT CLOSED FOR MODIFICATION.**

소프트웨어 엔터티는 확장을 위해 열려 있어야 하나, 수정에 대해서는 닫혀 있어야 한다   

## Class diagram


## heuristics are real?

객체 지향 설계(OOP)에는 여러가지 휴리스틱이 있다   
e.g.
- 모든 멤버 변수는 private   
- 전역변수는 지양해야한다   
- 런타임 식별(RTTI)는 위험하다   

라는 것들이 있다   
이러한 것들의 출처와 항상 모든 상황에 들어맞는가? 에 대한 의문이 들기 마련이며 이러한 휴리스틱의 기초가되는 설계원칙인 개방-폐쇄 원칙에 대해 자세히 알아보자   

프로그램이 하나의 변경때문에 의존성이 있는 모듈에 연쇄적인 변경이 발생하게 된다면, 그 프로그램은 취약성, 비유연성, 재사용 불가능, 예측 불확실성이라는 나쁜 설계와 관련된 바람직하지 않은 속성들을 나타낸다     
개방-폐쇄 원칙은 이러한 문제를 굉장히 직관적으로 해결한다   
변경이 필요할 때, 기존의 코드를 수정하는 것이 아닌 새로운 코드를 추가하여 확장하는 방식을 사용한다   

그렇기에 개방-폐쇄 원칙은 2가지 주요 속성으로 나뉜다

1. Open For Extension
2. Closed For Modification

1번에서는 새로운 확장을 위하여 추가할 필요가 있으나 2번에서는 기존의 코드는 수정되어서는 안된다고하니 어떻게 보면 이 둘은 상충되는 것으로 보일 수 있다   

하지만 이는 `추상화`를 통해 해결할 수 있다   



[출처](https://web.archive.org/web/20150905081105/http://www.objectmentor.com/resources/articles/ocp.pdf)


