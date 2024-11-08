## INDEX

- [CPP 04](#cpp-04)
	- [Description](#description)
	- [Concepts](#concepts)
	- [Problem](#problem)

---
# CPP 04

## Description

virtual 키워드로 함수를 override하여 다형성을 구현하라   

## Concepts

## Problem

아주 기이한 문제를 만나게 되었다   

Base 클래스의 소멸자에 virtual 키워드가 없고 Derived 클래스의 소멸자에만 virtual 키워드가 생기면 double free가 발생하게 된다   
이를 해결하기위해 debugger도 사용해보고 최대한 알아보려했으나 아직 알아내지 못했다   

현재 알아낸 정보로는 Derived 클래스의 virtual 소멸자에 대하여 VTable이 생성되었다 라는 것 뿐이다   
이에대한 상관관계가 있을지 없을지는 모른다   


예제는 아래에 있다   
***E.G.***   
```c++
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type_;

public:
	
	WrongAnimal() : type_("")
	{
		std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
	}

	WrongAnimal(const std::string& type) : type_(type)
	{
		std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
	}

	WrongAnimal(const WrongAnimal& copy) : type_(copy.type_)
	{
		std::cout << "\033[33mWrongAnimal copy constructor works done\033[0m" << std::endl;
	}

	WrongAnimal& operator=(const WrongAnimal& src)
	{
		std::cout << "\033[33mWrongAnimal align operator works done\033[0m" << std::endl;

		if (this == &src) return *this;

		this->type_ = src.type_;

		return *this;
	}

	// no virtual destructor
	~WrongAnimal()
	{
		std::cout << "\033[33mWrongAnimal destructor works done\033[0m" << std::endl;
	}

	void makeSound() const
	{
		std::cout << "Grrrr..." << std::endl;
	}

	std::string getType() const
	{
		return this->type_;
	}
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat() : WrongAnimal("WrongCat")
	{
		std::cout << "\033[33mWrongCat constructor works done\033[0m" << std::endl;
	}

	WrongCat(const WrongCat& copy) : WrongAnimal(copy.getType())
	{
		std::cout << "\033[33mWrongCat copy constructor works done\033[0m" << std::endl;
	}

	WrongCat& operator=(const WrongCat& src)
	{
		std::cout << "\033[33mWrongCat align operator works done\033[0m" << std::endl;

		if (this == &src) return *this;

		this->type_ = src.type_;

		return *this;
	}

	// something wrong in this virtual destructor
	virtual ~WrongCat()
	{
		std::cout << "\033[33mWrongCat destructor works done\033[0m" << std::endl;
	}


	void makeSound() const
	{
		std::cout << "Yaooooong" << std::endl;
	}

};

int main()
{
	WrongAnimal* wj = new WrongCat();

	std::cout << wj->getType() << std::endl;
	wj->makeSound();

	delete wj;	// pointer being freed was not allocated

	return 0;
}

```
