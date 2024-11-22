## INDEX

- [CPP 04](#cpp-04)
	- [Description](#description)
	- [Concepts](#concepts)
		- [순수 가상 함수](#순수-가상-함수)
		- [추상 클래스](#추상-클래스)

---
# CPP 04

## Description

이제는 Animal 클래스가 추상 클래스가 되었다   
그에 맞게 Dog와 Cat을 구현하라

## Concepts

### 순수 가상 함수

구현이 없고 이름만 있는 함수   

```c++
virtual void makeSound() const = 0;
```

함수 처음에 `virtual` 키워드와 끝에 `= 0` 을 넣는다   

이는 함수의 구현을 derived 클래스에게 맡기는 행위가 된다

### 추상 클래스   

순수 가상 함수가 하나라도 있는 클래스   

추상 클래스는 인스턴스화가 불가능하며 derived 클래스에게 구현을 맡기게 된다   

