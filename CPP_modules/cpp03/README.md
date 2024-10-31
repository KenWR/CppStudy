## INDEX

- [CPP 03](#cpp-03)
	- [Description](#description)
	- [Concepts](#concepts)
	- [Implement](#implement)
		- [Inheritance](#inheritance)
			- [상속을 왜 사용할까?](#상속을-왜-사용할까)
			- [ia a, has a](#ia-a-has-a)
			- [파생 클래스의 생성, 소멸 순서](#파생-클래스의-생성-소멸-순서)
		- [name / function hiding](#name--function-hiding)
		- [protected](#protected)
		- [override](#override)
		- [polymorphism](#polymorphism)
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

**상속, 相續**
*뒤를 잇는 일.*

CPP에서의 정의는 다른 객체를 결합하고 연결하여 새 객체를 만드는 것과는 달리 상속은 다른 객체의 속성과 동작을 그대로 이어받은 다음 이를 확장하거나 특수화하여 새로운 객체를 만드는것을 의미한다   

이러한 상속은 컴퓨터를 생각해보면된다   
처음 폰 노이만이 설계한 컴퓨터를 기반(Base)으로부터 확장하고 특수화 하여 여러 종류의 컴퓨터들이 파생(Derived)되어 나오게 된 것을 생각을 하면 잘 이해가 갈 것이다   

당장의 CPP도 C로부터 대부분의 기능을 물려받은 것을 보면 이는 상속받았다고 볼 수 있다   

상속을 통한 관계를 다이어그램으로 표현하면 다음과 같다   

![inheritanceUML](../../images/inheritanceUML.png)

여기서 ClapTrap 클래스를 Parent, Base, Super 클래스라고 하며 ScavTrap 클래스를 Child, Derived, Sub 클래스라고 한다   

#### 상속을 왜 사용할까?

파생 클래스에서 기본 클래스의 정보를 다시 정의할 필요가 없게되며 이는 곧 코드의 재사용을 쉽게 만들어주는 것이다   

#### ia a, has a

객체간의 관계를 표현하는데에 있어 두가지로 나뉜다   
특정 객체의 일부로 객체가 구현되는 `has-a`, 상속을 통한 `is-a` 관계가 있다   

ScavTrap은 ClapTrap이다   
여우는 동물이다   

이는 모두 `is-a` 관계라고 볼 수 있다   


#### 파생 클래스의 생성, 소멸 순서

파생 클래스를 인스턴스화 하면서 일반적인 다른 클래스와는 내부적으로 다르게 구현이 이루어진다   

Base -> Derived 의 순서로 기본생성자를 사용하여 생성이 이루어진다   

chain 상속이 이루어져 있는 경우에는 항상 가장 기본 클래스를 먼저 생성하게 된다   

```c++
#include <iostream>

class A {
public:
    A() {
        std::cout << "A\n";
    }
};

class B: public A {
public:
    B() {
        std::cout << "B\n";
    }
};

class C: public B {
public:
    C() {
        std::cout << "C\n";
    }
};

class D: public C {
public:
    D() {
        std::cout << "D\n";
    }
};

int main(void) {
	D derived;
}
```

출력

```bash
A
B
C
D
```

상속이 이루어지면서 메모리에 적재되는 순서를 보면 이해가 쉬울 것이다   

![inheritanceMem](../../images/inheritanceMem.png)

일반클래스가 인스턴스화될 때의 순서     
1. 메모리 할당     
2. 객체의 생성자 호출 및 멤버 초기화     
3. 생성자 본문 실행

파생클래스가 인스턴스화될 때의 순서     
1. 기본 + 파생 메모리 할당     
2. 파생 생성자 호출    
3. 기본 생성자 호출 및 기본 클래스 초기화     
4. 파생 클래스 초기화     
5. 파생 클래스 생성자 본문 실행     

적절한 메모리를 할당해주고 생성자는 파생 클래스가 먼저 호출이 되나 초기화나 실행은 기본 클래스가 먼저 동작을하여 순서대로 클래스들을 할당된 메모리에 적재를 해주는 것이다    

### name / function hiding

### protected

### override






소멸자 처리

### polymorphism


### Multiple inheritance

#### 다이아몬드 상속

#### bridge pattern

#### nested generalization

# 참고자료

[다중상속의 사용](https://isocpp.org/wiki/faq/ multiple-inheritance#virtual-inheritance-where)   

[모두의 코드](https://modoocode.com/category/C++)   



