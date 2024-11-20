## INDEX

- [CPP 04](#cpp-04)
	- [Description](#description)
	- [Concepts](#concepts)
		- [virtual](#virtual)
			- [소멸자 가상화](#소멸자-가상화)

---
# CPP 04

## Description

Brain 클래스 자원을 관리하는 Animal 객체와 그를 derive 하는 Dog, Cat 객체를 관리하라    

메모리 누수가 나서는 안된다   

## Concepts

### virtual

Base 클래스에서 Derived 클래스가 함수를 재정의(override)할 수 있도록 사용하는 키워드로 다형성을 구현하는데 사용된다   

일반적으로 Base 클래스의 함수 앞에 붙으며 해당 가상 함수가 호출될 때 가상 함수는 런타임에 가상함수 테이블(VTable)에서 호출할 함수를 결정한다   
그렇기에 Derived에 Base에 있는 가상함수를 재정의했다면 어느걸 호출해도 Derived의 override된 함수가 호출된다   

#### 소멸자 가상화

이러한 특성은 소멸자에도 적용이 된다   

예시를 한번 보자   

**E.G.**
```c++
#include "iostream"

class Base 
{
public:
	Base() { std::cout << "Base::Base()" << std::endl; }
	~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived::Derived()" << std::endl; }
	~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

int main(void)
{
	Base* base = new Derived;
	delete base;
}
```

**output**
```bash
Base::Base()
Derived::Derived()
Base::~Base()
```

소멸자 호출시 Base의 범위에 있는 소멸자만 호출되는 것을 볼 수 있다   
하지만 애초에 생성될때 Derived로 생성이 되었기에 뒤에 남아있는 Derived의 메모리 영역은 홀로 남게 되며 만일 객체가 직접 자원을 관리하고 있다면 이는 메모리 누수로 이어지게 된다   

![vd](../../../images/vd.png)    

`Base::~Base()`   

![vd2](../../../images/vd2.png)   

해결방법으로 Base의 소멸자에 virtual 키워드를 줌으로서 Derived 클래스의 소멸자가 먼저 호출되도록 한다   

```c++
#include "iostream"

class Base 
{
public:
	Base() { std::cout << "Base::Base()" << std::endl; }
	virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived::Derived()" << std::endl; }
	~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

int main(void)
{
	Base* base = new Derived;
	delete base;
}
```

**output**
```bash
Base::Base()
Derived::Derived()
Derived::~Derived()
Base::~Base()
```
