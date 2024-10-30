## INDEX

- [CPP\_01: EX\_05](#cpp_01-ex_05)
  - [Description](#description)
  - [Implement](#implement)
  - [Concepts](#concepts)
    - [pointers to members](#pointers-to-members)
      - [그래서 이건 어디에 사용되나?](#그래서-이건-어디에-사용되나)

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

#### 그래서 이건 어디에 사용되나?

일반적으로 함수 포인터는 정적 함수에만 사용이 가능하다는 한계가 있다   
왜 이런 한계가 있느냐고 묻는다면 일반적으로 멤버 함수는 this 포인터가 필요하기 때문에 자신의 객체를 숨겨진 인자로서 전달받아야 하는데 함수 포인터로는 코드의 시작 주소만 저장하고 이러한 숨겨진 인자를 처리할 방법이 없기 때문에 객체에 묶여있지 않고 this 포인터가 필요 없는 정적 멤버 함수에만 사용이 가능한 것이다   

그렇기에 해당 한계를 극복하기 위해 pointers to members라는 추가적인 기능을 제공한다   

이렇게 각 객체의 멤버들을 포인터로 사용하여 다른 객체로부터 호출이 되거나 callback 함수로 특정 객체의 멤버를 호출 할 수 있는 등의 유연성을 제공할 수 있게 되었다   

**E.G.**
```c++
#include <iostream>

class MyClass {
public:
	static void memberStaticFunction() {
		std::cout << "Member static function" << std::endl;
	}

  void memberFunction() {
    std::cout << "Member function" << std::endl;
  }
};

int main() {
  MyClass obj;

  // 멤버 함수는 this 포인터를 필요로하기에 숨겨진 인자로 자신의 객체를 전달 받는다
  obj.memberFunction(); // == memberFunction(&obj);

	// 일반 멤버 함수 포인터로 정적 멤버 함수 선언 및 초기화
	void (*ptr1)() = &MyClass::memberStaticFunction;
	// 일반 멤버 함수 포인터로 멤버 함수 선언 및 초기화 불가능
	// void (*ptr2)() = &MyClass::memberFunction;


  // pointer to member function으로 정적 멤버 함수 선언 및 초기화 불가능
	// void (MyClass::*ptr3)() = &MyClass::memberStaticFunction;
	// pointer to member function으로 정적 멤버 함수 선언 및 초기화
  void (MyClass::*ptr4)() = &MyClass::memberFunction;

  // 멤버 함수 호출 (객체와 함께 호출해야 함)
	ptr1();	// 출력: Member static function
  (obj.*ptr4)();	// 출력: Member function

    return 0;
}
```
