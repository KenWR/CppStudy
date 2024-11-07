## INDEX

- [CPP 03](#cpp-03)
	- [Description](#description)
	- [Concepts](#concepts)
		- [Name hiding](#name-hiding)
			- [컴파일러는 overload된 함수들은 어떻게 찾을까?](#컴파일러는-overload된-함수들은-어떻게-찾을까)
			- [Hiding inherited functionality](#hiding-inherited-functionality)
	- [Implement](#implement)

---
# CPP 03

## Description

Inheritance, 상속을 다루어 보자

## Concepts

### Name hiding

Derived 클래스 객체가 멤버 함수를 호출하게되면 컴파일러는 객체의 런타임 타입에 따라 Derived 클래스 내부에서 먼저 일치하는 함수를 찾고 일치하는 함수가 없다면 상속 체인을 타고 올라가면서 Base 클래스로부터 일치하는 함수를 찾는다   

이러한 특성을 통해 Base 클래스에 있는 함수가 어떠한 접근 제어자로 선언이 되어 있든 Derived 클래스에서 public redefine 할 수 있다 (public 외에도 다른 접근 제어자로 선언할 수 있으며 그 반대로도 가능하다)   

**E.G.**
```c++
#include <iostream>

class Base {
public:
    Base() {};

    void identify() const { std::cout << "Base::identify()" << std::endl; }
};

class Derived: public Base {
public:
    Derived() {};

    void identify() const { std::cout << "Derived::identify()" << std::endl; }
};

int main()
{
    Base base;
    base.identify(); // "Base::identify()"

    Derived derived;
    derived.identify(); // "Derived::identify()"
}
```

이는 다른말로 `Derived::identify()` 가 `Base::identify()` 를 숨겼다(hiding)! 라고 한다   

만약 Base의 `identify()`를 derived에서 호출하고 싶다면 `Base::identify();` 를 derived 내부에서 Base의 `identify()`를 호출할 수 있다

**E.G.**
```c++
class Derived: public Base {
public:
    Derived() {};

    void identify() const { 
		Base::identify(); // "Base::identify()"
		std::cout << "Derived::identify()" << std::endl; 
	}
};
```

Base의 friend 함수의 경우에는 실제로 Base 클래스의 일부가 아니기 때문에 `::` 범위 지정 연산자를 사용하는 것이 불가능 하다   
이는 `static_cast`를 통해 쉽게 해결이 가능하다   

**E.G.**
```c++
class Derived: public Base {
public:
    Derived() {};

    void identify() const { 
		static_cast<Base const&>(*this).identify();
		std::cout << "Derived::identify()" << std::endl; 
	}
};
```

#### 컴파일러는 overload된 함수들은 어떻게 찾을까?

Derived 클래스에 overload된 함수가 존재한다면 그 함수의 원형(매개변수가 일치하는)이 Base에 존재하더라도 Derived의 overload 함수가 호출된다   

이는 다음 예시를 보면 된다   

**E.G.**
```c++
#include <iostream>

class Base {
public:
	void print(int) { std::cout << "Base::print(int)" << std::endl; }
	void print(double) { std::cout << "Base::print(double)" << std::endl; }
	void print(int, double) { std::cout << "Base::print(int, double)" << std::endl; }
};

class Derived: public Base {
public:
	void print(double) { std::cout << "Derived::print(double)" << std::endl; }
};

int main(void) {
	Derived d;
	d.print(5); // "Base::print(double)"
	// d.print(5, 5.0); // it doesn't work
}
```

컴파일러는 Derived에서 이름과 일치하는 함수들을 찾았으므로 더이상 추가로 탐색하지 않는다   
Derived의 print가 Base의 모든 print 함수들을 숨기는 것이다   

여기서 문제가 생기게 된다   
Base에 overload된 함수를 하나만 바꾸려면 모든 함수들도 새로 redefine을 해야 한다는 것이다   
이에 대한 해결책으로는 `using` 키워드를 사용하는 것이다   

**E.G.**
```c++
#include <iostream>

class Base {
public:
	void print(int) { std::cout << "Base::print(int)" << std::endl; }
	void print(double) { std::cout << "Base::print(double)" << std::endl; }
	void print(int, double) { std::cout << "Base::print(int, double)" << std::endl; }
};

class Derived: public Base {
public:
	using Base::print; // using using keywords
	void print(double) { std::cout << "Derived::print(double)" << std::endl; }
};

int main(void) {
	Derived d;
	d.print(5); // "Base::print(int)"
	d.print(5.0); // "Derived::print(double)"
	d.print(5, 5.0); // now, it works! "
}
```

#### Hiding inherited functionality

이전의 `using` 키워드를 통해 Base의 print 함수들을 Derived의 print 함수가 더이상 숨기지 않게 하였다   
using 키워드를 이용해 Base의 public 기능들을 Derived의 private, protected 접근 제어자로 숨기면 어떻게 될까?   

접근하는 주체에 따라 달라진다   
Base로 접근하게 되면 컴파일러는 Base 클래스 내부에서 탐색을하기 때문에 접근이 가능하나, Derived로의 접근은 접근 제어자로 막혀 있어 접근하지 못한다   

**E.G.**
```c++
#include <iostream>

class Base {
public:
	int m_value;

	Base(int value) { m_value = value; }
};

class Derived : public Base {
private:
	using Base::m_value;

public:
	Derived(int value) : Base(value) {}
};

int main(void) {
	Derived derived(7);
	// std::cout << derived.m_value << std::endl; // m_value is private in Derived
	
	// upcasting is fine
	std::cout << static_cast<Base&>(derived).m_value << std::endl; // m_value is public in Base
	// another way to upcasting
	Base& base(derived); 
	std::cout << base.m_value << std::endl; // m_value is public in Base
}
```

이 기법은 Base가 잘못 설계되어 있을때 새로이 Base의 멤버들을 Derived에서 encapsulation 할 때 사용한다  
하지만 Base를 통한 접근시 encapsulation이 깨질 수 있음을 알아야 한다   
그리고 특정 overload된 함수만 접근 제어자를 바꿀 수는 없고 전부 바꾸어야 한다   

만약 기능을 더이상 사용하지 않는다고 하면 delete 키워드를 통해 derived에서 상요되지 않음을 명시할 수 있으나 이 또한 Base로의 접근을 막지는 못한다   

**P.S.**
Base에서 public virtual f()가 Derived에서 override가 되어 있다면... 놀랍게도 Derived::f()가 호출이된다   
이는 런타임에 결정되는 VTable의 특성 때문에 발생한다   

## Implement