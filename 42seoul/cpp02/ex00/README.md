[EX00](#ex00)
- [Orthodox Canonical Form](#orthodox-canonical-form)
	- [Description](#description)
- [Rule 3](#rule-3)
	- [Description](#description-1)
	- [what about non-copyable resources](#what-about-non-copyable-resources)
- [Rule 5](#rule-5)
	- [Description](#description-2)
	- [E.G. feat.SEMANTICS](#eg-featsemantics)
- [Rule 0](#rule-0)
	- [Description](#description-3)
	- [소유권?](#소유권)
- [출처](#출처)

---

# EX00 

## Orthodox Canonical Form

### Description

**자원 관리를 안전하고 효율적으로 하기 위한 C++ 설계 철학**

Jim O. Coplien의 Big Three 규칙에 대한 조상으로 전통적인 객체의 복사 및 소멸을 제대로 처리하기 위한 객체 설계 패턴이다   

- 생성자   
- 소멸자   
- 복사 생성자   
- 복사 대입 연산자   

라는 네가지 구성 요소를 정의함으로써, C++ 클래스는 안전하게 리소스를 관리할 수 있게되었다   

## Rule 3

### Description

클래스에 사용자가 정의한 소멸자, 복사 생성자, 복사 할당 연산자가 필요한 경우 이 세 가지를 모두 사용자가 선언하여 관리하여야 한다   

함수를 호축하거나 반환할 때 객체를 값으로 전달하거나, 컨테이너에서 객체를 조작할 때 복사 생성자나 대입 연산자가 호출된다   
하지만 C++에서 해당 멤버 함수들이 정의되지 않았을 때, 컴파일러가 이를 임의로 **생성**하게 되며 이를 **implicitly-defined special member functions(암시적 정의 특별 멤버 함수)**라고 부른다
이렇게 암시적으로 정의된 특별 멤버 함수는 `new` 연산자를 통해 클래스를 메모리에 할당하였을때 자동으로 생성된 복사 생성자는 단순히 메모리 주소만 복사하게 되며 이 경우에는 메모리 자체가 새로 복제되는것이 아닌 두 개의 객체가 동일한 메모리 주소를 가리키게 되면서 소멸자 호출시 이중 해제나 리소스 관리가 제대로 이루어지지 않는 문제가 생길 수 있다   

즉, 리소스를 관리하여야 하는 클래스에서 암시적으로 생성된 복사 생성자나 대입 연산자는 단순히 포인터 값을 복사하고 리소스 자체를 복사하지 않기 때문에, 여러 객체가 동일한 리소스를 참조하게되어 잘못된 동작으로 이어질 수 있다    

### what about non-copyable resources

복사가 불가능한 리소스를 관리하는 클래스의 경우에는 복사 생성자와 대입 연산자를 private에 선언하거나 C++11 이후에는 `= delete`를 선언함으로서 사용 불가능으로 만들어야 한다   

## Rule 5

### Description

사용자 정의 소멸자, 복사 생성자 또는 복사 대입 연산자(`= default` or `= delete`)가 존재하면, 이동 생성자와 이동 대입 연산자를 포함한 다섯 가지 특수 멤버 함수를 모두 선언해야 한다   

이를 다른 말로 풀면 semantics(이동 의미론)가 필요한 클래스는 다섯 가지 특수 멤버 함수를 모두 선언해야 한다는 것이다   
Rule of Three와 달리, 사용자정의 이동 생성자와 이동 대입 연산자를 작성하지 않아도 오류가 발생하지는 않으나, 성능 저하로 이어질 수 있다   

### E.G. feat.SEMANTICS

들어가기 앞서 **lvalue**와 **rvalue**에 대해서 알아야한다    
둘다 메모리에 존재하는 값이나 컴파일러는 객체에 이름이 있는가 없는가에 따라 **lvalue**, **rvalue**로 나뉜다   
**lvalue**는 이름이 있어 다시 참조할 수 있는 객체이며, **rvalue**는 이름이 없는 임시로 생성된 객체로 연산 이후에 사라지는 특성을 가지고 있다   

이러한 **rvalue** 객체로 값을 넘겨 받아 이를 복사해야 할 때, 일반적으로 깊은 복사를 통해 해결을 했었으나 이는 성능적 손해였다   
**rvalue** 객체는 실제로 값이 있고 이름만 없기 때문에, 값을 복사할 필요 없이 포인터만 이동하고, 기존 객체의 포인터를 `nullptr`로 설정하면 불필요한 복사를 피하고 성능을 향상 시킬 수 있게 된다      
이를 `이동 의미론(move-semantics)`라고 부른다   

이 의미론에 부합하는 예제들을 살펴보자

```c++
rule_of_five(rule_of_five&& other) noexcept // IV. move constructor
        : cstring(std::exchange(other.cstring, nullptr))
{
}
```

이동생성자   
여기서 `rule_of_five&& other`는 **rvalue** 참조로, 임시 객체임을 의미한다   
그렇기에 임시객체의 `cstring`의 값을 반환하고, `nullptr`로 설정해주는 `std::exchange`로 자원을 이동하면서 본래의 객체는 빈 상태가 되어 해당 객체의 자원 해제가 이루어지지 않게 되었다   

이는 자원을 `복사` 하는 대신 `포인터 이동`을 통한 최적화를 이루어 낸 것이다   

`noexcept` 라는 키워드는 이 함수가 예외를 던지지 않는다고 보장하는 것이다   
이동 생성자는 예외 안정성을 보장하는 것이 중요한데, 자원을 이동하는 도중 예외가 발생하면 프로그램이 불안정해질 수 있기 때문이다   

```c++
rule_of_five& operator=(rule_of_five&& other) noexcept // V. move assignment
{
	rule_of_five temp(std::move(other));
	std::swap(cstring, temp.cstring);
	return *this;
}
```

이동 할당 연산자   
여기서 `rule_of_five&& other`는 **rvalue** 참조로, 임시 객체임을 의미한다   
`std::move`를 통해 명시적으로 `other`를 **rvalue**로 변환하여 이동 생성자를 호출하도록 한다   
임시 객체 `temp`는 이동 생성자를 통해 `other`의 자원을 `훔쳐`온다   
`other`는 `nullptr`이 되며 `std::swap`을 통해 임시 객체가 가진 자원과 현재 객체의 자원을 교환한다   

결론적으로 `temp`는 `other`객체로부터 `this`가 `temp`로 부터 자원을 가져오게 되는 것이다   

## Rule 0

### Description

사용자 정의 소멸자, 복사/이동 생성자 또는 복사/이동 할당 연산자를 가진 클래스는 반드시 소유권만을 처리해야한다 (이는 단일 책임 원칙에서 따르는 것이다.)    

다른 클래스는 사용자 정의 소멸자, 복사/이동 생성자 또는 복사/이동 할당 연산자를 정의해서는 안 된다.   

처음 보았을때, 이해하기 힘든 문장이다   
이를 쉽게 풀자면 클래스가 소유권을 관리하지 않는 경우 사용자 정의 특수 멤버 함수를 만들기 보다는 암시적으로 컴파일러가 작성하는 기본 제공 함수가 더 안전하고 효율적이라는 것이다   

허나 클래스가 소유권을 가지고 있는 경우 사용자 정의 소멸자, 복사 생성자 및 이동 생성자를 만들어야 할 수 있다   
하지만 이러한 경우에도 모든 특수 멤버 함수를 정의해야하며 가능하면 `= default`로 설정하여 기본동작을 사용하는 편이 좋다   

### 소유권?

객체가 소유권을 가지고 있다는 것은 해당 객체가 자원을 생성하고 해제하는 책임을 지고 있다는 것이다   

--- 

### 출처

[big-two](https://www.artima.com/articles/the-law-of-the-big-two)   

[The-rule-of-three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)   	
