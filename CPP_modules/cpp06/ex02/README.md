## INDEX

- [ex02](#ex02)
  - [Description](#description)

---
# ex02
 

## Description

virtual Destructor만 가지고 있는 Base 클래스를 구현하라.     

Base 클래스를 상속하는 클래스 A, B, C 를 구현하라.     

3가지 함수를 구현하라.         

`Base * generate(void);`   
A, B, C 셋 중 하나의 인스턴스를 Base pointer로 반환하는 메소드.     

`void identify(Base* p);`   
어떤 객체인지 출력하는 메소드.   

`void identify(Base& p);`   
어떤 객체인지 출력하는 메소드.    
이 메소드 내부에서 포인터를 사용하는 것은 금지된다     


`typeinfo` 헤더는 금지된다.   


**Solution:**   
dynamic_cast를 사용하는 문제이다.   

dynamic_cast는 상속 계층 구조를 따라 클래스에 대한 포인터와 참조를 위, 아래, 옆으로 안전하게 변환하기 위해 사용한다.   

포인터 변환 실패 시 nullptr 반환하며 참조 변환 실패 시 std::bad_cast 예외가 발생한다.    

RTTI를 사용하는 dynamic_cast 대신에 static_cast를 다운 캐스트에 사용하면 런타임 검사를 피할 수 있으나 객체가 확실히 Derived인 것이 보장될 수 있는 경우에만 안전하다!   
그렇기에 dynamic_cast는 남발하면 성능적으로 좋지 않지만 안전한 다운 캐스팅을 하기 위해서 사용된다.   
