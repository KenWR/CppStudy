## INDEX

- [CPP 02](#cpp-02)
	- [Description](#description)
	- [Concepts](#concepts)
		- [Ad-hoc polymorphism(임시 다형성)](#ad-hoc-polymorphism임시-다형성)
		- [Dispatch](#dispatch)
			- [Static Dispatch](#static-dispatch)
			- [Dynamic Dispatch](#dynamic-dispatch)
		- [vtable은 피하고싶고... 상속은 하고 싶고...](#vtable은-피하고싶고-상속은-하고-싶고)
- [참고자료](#참고자료)

---
# CPP 02

## Description

Ad-hoc polymorphism(임시 다형성), 연산자 오버로딩, Orthodox Canonical class form 에 대해 공부한다   

## Concepts

### Ad-hoc polymorphism(임시 다형성)

함수가 여러 유형의 인수에 따라 적용될 수 있는 일종의 다형성이다     
임시다형성은 Dispatch 매커니즘으로 동작한다   

이러한 임시 다형성의 대표적인 예로는 함수 오버로딩과 연산자 오버로딩이 존재한다   

### Dispatch

코드에서 어떤 함수를 실행할지 결정하는 매커니즘    
C++의 다형성에서 정적, 동적 디스패치가 사용되며 기본으로 정적 디스패치가 사용된다   
동적 디스패치를 사용하기 위해서는 virtual 키워드를 사용하면 된다    

#### Static Dispatch

정적 디스패치    

컴파일 타임에 어떤 함수가 호출될지 결정되는 디스패치   

함수 오버로딩, 템플릿의 <T>와 같은 제너릭 타입에 사용된다   

#### Dynamic Dispatch

동적 디스패치     

런타임에 어떤 함수가 호출될지 결정하게 하는 디스패치   
C++의 디스패치는 메소드를 virtual로 선언함으로서 동적 디스패치를 얻을 수 있다   
C++컴파일러가 가상 함수 테이블(vtable)이라는 데이터 구조로 디스패치를 구현하며 주어진 클래스에 대한 이름-구현 매핑을 멤버 함수 포인터 집합으로 정의한다   

이는 vtable조회와 함수 포인터 호출로인해 추가 비용이 발생하게되어 정적 디스패치보다 느리게 동작한다   

### vtable은 피하고싶고... 상속은 하고 싶고...

CRTP(Curiously recurring template pattern) 패턴이 존재하며 기본 클래스가 인터페이스를 노출하고 파생 클래스가 이러한 인터페이스를 구현하는 **컴파일 타임 다형성**을 구현하는데 사용한다고 한다

이는 지금 공부할 단계는 아닌것 같다...

# 참고자료

[임시 다형성](https://en.wikipedia.org/wiki/Ad_hoc_polymorphism)   
[동적 디스패치 피하기](https://sveljko.github.io/cpp_nonvirtual_dyn_disp/)   
[CRTP](https://en.cppreference.com/w/cpp/language/crtp)
