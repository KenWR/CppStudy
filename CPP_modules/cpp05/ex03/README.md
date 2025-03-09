## INDEX

- [ex03](#ex03)
  - [Description](#description)

---
# ex03

## Description

bureaucrat 대신 서류를 작성해주는 intern 클래스를 구현하라.   


intern은 이름, 등급도 없으며 특별한 특징도 없다.   
오직 하나의 기능, 서류의 name과 서류의 target을 인자로 받는 `makeForm()` 함수를 가지고 있다.   
이 함수는 주어진 이름의 Form 객체를 생성하고, 그 객체의 target을 두 번째 매개변수 값으로 초기화한 후, Form 객체의 pointer를 반환하며 `Intern creates <form>` 과 같은 메시지가 출력된다.   
만약 주어진 서류 이름이 존재하지 않는다면, 명확한 오류 메시지를 출력해야 한다.   

예제 (Bender를 대상으로하는 RobotomyRequestForm 생성)   
```cpp
{
  Intern someRandomIntern;
  Form* rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

**solution:**   
intern 클래스의 요소는 다음과 같다.   
  
```cpp
Form *makeForm(const string &name, const string &target)
```    
feature: Form 클래스 생성      
output: Intern creates <form>   

```cpp
class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw;
}
```
description: 주어진 이름에 맞는 Form 클래스가 없는 경우 반환할 예외   
  





