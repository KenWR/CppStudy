## INDEX

- [EX 00](#ex-00)
	- [Description](#description)
	- [Implement](#implement)
	- [Concepts](#concepts)

---
# EX 00

## Description

Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

위 두 예외를 구현하는 것이 목표이다   

두 예외를 함수로 구현을 해야할까?
정답은 `아니다` 이다

C++ 에서 예외는 객체를 기반으로 동작한다   
throw 키워드는 객체를 던지기 때문에, 함수 자체를 예외로 사용할 수 없다   
그렇기에 throw 키워드 뒤에 함수 호출을 넣을 수는 있지만 반환된 값은 객체여야 한다   

또한 C++에서 대부분의 예외처리는 std::exception 기반으로 이루어지기 때문에 Bureaucrat 내부에서 GradeTooHighException과 GradeTooLowException을 각각 클래스로 구현해야한다    



## Implement

## Concepts