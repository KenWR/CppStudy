## INDEX   
- [Description](#description)
		- [RULES](#rules)
		- [ALLOWED \& FORBIDDEN](#allowed--forbidden)
		- [MODULE](#module)
		- [A FEW DESIGN REQUIREMENTS](#a-few-design-requirements)

---

# Description

CPP 과제

C++는 `Class`들이 추가된 C와 같다   
이 CPP과제의 목표는 OOP(객체-지향-프로그래밍)을 소개하기 위해 만들어졌다   
코드를 `c++`로 컴파일하며 `-Wall -Wextra -Werror` 플래그를 사용하며 `-std=c++98` 플래그를 추가해도 코드가 컴파일될 수 있어야 한다   

### RULES

- 클래스 이름은 `UpperCamelCase` 형식을 사용해 작성하라
- 클래스 코드를 포함하는 파일은 항상 클래스 이름에 맞춰져야 한다
- e.g. 클래스이름 == `BrickWall` -> 헤더 파일 이름 `BrickWall.hpp`
- 별도의 명시가 없는 한, 모든 출력 메시지는 줄 바꿈 문자로 끝나야 하며 표준 출력에 표시되어야 한다

### ALLOWED & FORBIDDEN

- 표준 라이브러리의 거의 모든 것을 사용할 수 있다      
	가능하면 c++ 버전을 최대한 사용하는 것이 좋다
- 외부 라이브러리는 사용할 수 없다   
	c++ 11 및 그 이후 버전, Boost 라이브러리도 금지되며 `printf()`, `alloc()`, `free()` 또한 금지된다

### MODULE

- 명시적으로 언급되지 않은 한, `using namespace <ns_name>` 와 `friend` 키워드는 금지한다
- STL은 module 08과 09에서만 사용할 수 있다   
	즉, module 08, 09 이전에는 `vector`, `list`, `map` 등과 같은 컨테이너와 `<algorithm>` 헤더를 포함해야하는 알고리즘을 사용할 수 없다

### A FEW DESIGN REQUIREMENTS

- new 키워드를 통한 메모리 할당시 메모리 누수 방지
- 02 ~ 09까지의 클래스는 명시적으로 달리 언급되지 않는 한, [Orthodox Canonical Form](https://www.artima.com/articles/the-law-of-the-big-two) 으로 설계해야 한다
- 헤더 파일에 함수 구현을 작성하면 안된다
- 각 헤더 파일은 다른 파일에 의존하지 않고 독립적으로 사용될 수 있어야한다   
	따라서 필요한 모든 의존성을 포함해야한다.   
	하지만 중복 포함 문제를 방지하기 위해 `include guard`를 추가해야 한다   
	