## INDEX

- [CPP 03](#cpp-03)
	- [Description](#description)
	- [Concepts](#concepts)
	- [Implement](#implement)
		- [Inheritance](#inheritance)
		- [protected](#protected)
		- [override](#override)
		- [ia a / has a](#ia-a--has-a)
		- [virtual](#virtual)
		- [polymorphism](#polymorphism)
		- [VTable](#vtable)
		- [Pure virtual function](#pure-virtual-function)
		- [Abstract class](#abstract-class)
		- [Multiple inheritance](#multiple-inheritance)
			- [다이아몬드 상속](#다이아몬드-상속)
			- [bridge pattern](#bridge-pattern)
			- [nested generalization](#nested-generalization)
- [참고자료](#참고자료)

---
# CPP 03

## Description

Inheritance, 상속을 다루어 보자

## Concepts

## Implement

상속에서 파생 클래스의 생성자가 먼저 호출되나 파생 클래스가 기본 클래스의  생성자를  호출하게되어 기본 클래스의 생성자가 먼저 동작하고 그 이후에 파생 클래스의 생성자가 동작한다        

생성자의 호출순서와 실행순서는 일치하지 않는다   

생성자는 객체 자신만을 초기화 해야 한다!   

상속시 파생형식 생성자에서 부모 멤버를 초기화 하는 것은 잘못된것    
(만일 파생형식 클래스가 초기화를 할때에는 이미 부모가 초기화가 이루어지고 난 이후이다 그렇기에 값이 변경이되나 이는 큰 실수를 초래할 수 있게 된다   
만일 private 멤버 변수라면 바꾸지 못하기도 하다)   

메소드가 일반형식이면 접근형식을 따르고 virtual이면 실형식을 따른다      
(A* pData = new B; 라고 했을때, 특정함수가 파생클래스에서 재정의 되었다고 가정해보자   
이 때, 해당 기본클래스의 함수가 일반형식이면 A형식을 따르고 virtual이면 B형식을 따른다)

![Alt text](<스크린샷 2024-10-15 오후 4.49.01.png>)    

![Alt text](<스크린샷 2024-10-15 오후 4.32.51.png>)     

![called by framework](<스크린샷 2024-10-15 오후 5.17.23.png>)   

가상함수 - 기반 클래스에서 확장 클래스를 호출하는 방식, 미래를 호출한다!   


![Alt text](<스크린샷 2024-10-15 오후 5.23.23.png>)   
레거시 코드와 현재 코드의 순서를 잘 맞춰야함   
두개의 코드가 공존하게 된다   
혹은 overwrite할 수 있다   
이는 모두 확장을 하는것이다   
재정의는 곧 확장이다 하지만 늘어나기만하고 줄어들지는 않는다   

[다시볼 필요가있음](https://www.youtube.com/watch?v=1W4CkEMajQs&list=PLXvgR_grOs1DFOWF65X0Zqnd_264x41u-&index=22)   

A* pData = new B;  여기서 소멸자 호출하면 릭이 남 왜냐하면 A소멸자는 호출되는데 B 소멸자는 호출이 안되어서   
그래서 virtual키워드를 넣어줘야 함   

### Inheritance

### protected

### override

### ia a / has a

### virtual

소멸자 처리

### polymorphism

### VTable



### Pure virtual function


### Abstract class


### Multiple inheritance

#### 다이아몬드 상속

#### bridge pattern

#### nested generalization

# 참고자료

[다중상속의 사용](https://isocpp.org/wiki/faq/ multiple-inheritance#virtual-inheritance-where)   

[모두의 코드](https://modoocode.com/category/C++)   


