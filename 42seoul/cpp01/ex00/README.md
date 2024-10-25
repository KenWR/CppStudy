## INDEX

- [CPP\_01: EX\_00](#cpp_01-ex_00)
	- [Description](#description)
	- [Implement](#implement)
	- [Concepts](#concepts)
		- [Memory allocation](#memory-allocation)
		- [heap 그리고 stack](#heap-그리고-stack)

---
# CPP_01: EX_00

## Description



## Implement

## Concepts

### Memory allocation

C에서는 `alloc` 과 `free` 함수를 통한 메모리 할당, 해제가 있었다면 C++에서는 `new`, `delete` 연산자를 통한 할당, 해제가 존재한다

### heap 그리고 stack

heap은 `new`로 할당하며 `delete`로 해제해야 한다
C에서의 `alloc`과 `free`와 유사하다

stack은 해당 선언부, 즉 선언된 함수 내에서 해당 scope를 벗어날때 소멸자가 자동으로 호출되어 사라진다


재미있는 [stack](https://www.openwall.com/lists/oss-security/2017/06/19/1)의 취약점










