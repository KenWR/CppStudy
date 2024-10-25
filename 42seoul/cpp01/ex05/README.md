## INDEX

- [CPP\_01: EX\_05](#cpp_01-ex_05)
  - [Description](#description)
  - [Implement](#implement)
  - [Concepts](#concepts)
    - [pointers to members](#pointers-to-members)

---
# CPP_01: EX_05

## Description

각 단계에 따른 출력을 구현하는 것이다   

## Implement

if else문을 최소한으로 사용하면서 pointers to members를 사용하라고 하였다  

코드에서 `typedef void (Harl::*pointer_to_function)(void);`를 사용하여 멤버 함수 포인터 타입을 정의했다   

이를 통해 동일한 형식을 가지는 `debug`, `info`, `warning`, `error` 네가지 멤버 함수를 하나의 배열로 관리하여 입력받은 `level`값에 따라 적절한 함수를 동적으로 호출할 수 있게 하였다

## Concepts

### pointers to members

포인터 선언은 선언자가 아래의 형태를 가지는 단순 선언을 의미한다

`* attr(선택적) cv(선택적) 선언자`   
`nested-name-specifier * attr(선택적) cv(선택적) 선언자`  

- nested-name-specifier: 이름의 시퀀스와 범위 해석 연산자 ::의 조합을 나타낸다   
- attr: (C++11부터) 속성의 목록
- cv: const/volatile 자격 지정자로, 선언되는 포인터에 적용된다 (지정된 타입이 아니라)
- 선언자: 참조 선언자 이외의 선언자로, 참조에 대한 포인터는 존재하지 않는다   
  대신 포인터에 대한 포인터가 허용된다

```c++
S* D; 		// 일반적인 pointer 선언
S C::* D;	// 멤버 포인터 선언
```

클래스 C의 비정적 멤버 객체 m에 대한 포인터의 표현식은 다음과 같다

```c++
&C::m
// &(C::m)	// 포인터 형성 x
// &m		// 포인터 형성 x
```

이러한 멤버 포인터는 `operator.*` or `operator->*`의 우측 피연산자로 사용될 수 있다   

이에따른 사용법과 예제로는 [data member](../test/PointersToMembersData.cpp)와 [function member](../test/PointersToMembersFunction.cpp)를 통해 확인할 수 있다   

