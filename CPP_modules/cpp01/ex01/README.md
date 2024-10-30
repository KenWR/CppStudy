## INDEX

- [CPP\_01: EX\_01](#cpp_01-ex_01)
	- [Description](#description)
	- [Concepts](#concepts)
		- [Memory allocation](#memory-allocation)
		- [heap 그리고 stack](#heap-그리고-stack)
		- [배열 할당](#배열-할당)
		- [해제](#해제)

---
# CPP_01: EX_01

## Description

배열을 Heap영역에 할당하고 해제하는 방법에 대해 다룬다   

## Concepts

### Memory allocation

C에서는 `alloc` 과 `free` 함수를 통한 메모리 할당, 해제가 있었다면 C++에서는 `new`, `delete` 연산자를 통한 할당, 해제가 존재한다

### heap 그리고 stack

heap은 `new`로 할당하며 `delete`로 해제해야 한다
C에서의 `alloc`과 `free`와 유사하다

stack은 해당 선언부, 즉 선언된 함수 내에서 해당 scope를 벗어날때 소멸자가 자동으로 호출되어 사라진다


재미있는 [stack](https://www.openwall.com/lists/oss-security/2017/06/19/1)의 취약점

### 배열 할당

동적 메모리는 `new` 연산자를 통해 할당된다   
하나 이상의 요소가 필요한 경우 대괄호`[]` 안에 그 수를 지정한다   
그리고 할당된 메모리 블록의 시작 부분에 대한 포인터를 반환한다   

컴퓨터 메모리는 제한된 자원이기에, 모든 메모리 요청이 성공적으로 처리된다는 보장이 없다   
그렇기에 C++에서는 메모리 할당이 성공했는지 확인할 수 있는 두 가지 표준 메커니즘을 제공한다   
1. Exception    
	할당 실패시 `bad_alloc` 타입의 예외가 발생   
2. nothrow   
	예외를 발생시키지 않고 new가 nullptr을 반환한다   
	<new> 헤더에 선언된 특별한 객체인 nothrow를 new의 인자로 전달하여 사용한다    
	```c++
	foo = new (nothrow) int[5];
	```
	   

### 해제

동적 메모리는 `delete` 연산자를 통해 해제된다
하나 이상의 요소를 가진 메모리를 해제하려면 `delete` 연산자 뒤에 대괄호`[]`를 추가해야한다

`delete`로 전달되는 값은 `new`로 할당된 메모리 블록이거나 `nullptr`이어야 하며 `nullptr`인 경우 `delete`는 아무런 동작도 하지 않는다   

---

이 모든 과정의 메모리 layout은 `heap`에서 동작한다   

C 언어에서의 `alloc`과 `free`가 `<cstdlib>` 헤더에 정의되어있으며 C++에서 사용이 가능하나, `new`로 할당된 메모리 블록과는 호환되지 않으므로 이들 함수와 혼용하여 사용하면 안된다

[cplusplus](https://cplusplus.com/doc/tutorial/dynamic/)     

