## INDEX

- [CPP\_01](#cpp_01)
	- [Description](#description)
	- [Concepts](#concepts)
		- [references](#references)
		- [getter\&setter 작성법](#gettersetter-작성법)
		- [왜 getter\&setter를 사용할까?](#왜-gettersetter를-사용할까)
- [참고 자료](#참고-자료)

---
# CPP_01

## Description

이번 과제에서는 메모리 할당 방식과 Pointer to members라는 멤버객체에 대한 포인터를 선언하는 방식, 레퍼런스(&), switch문에 대해 배운다

## Concepts

### getter&setter 작성법

```c++
class Foo
{
private:
    X x_;

public:
    void set_x(const X& value)
    {
        x_ = value;
    }

    const X& get_x() const
    {
        return x_;
    }
};
```

일반적으로 value를 전달하는 것은 불필요한 복사가 일어나기에 성능면에서 좋지 않다   
reference 형식으로 받아오는 것이 불필요한 복사를 방지하고 성능면에 이점을 둘 수 있다   
이는 const 한정자에도 적용되는데 기본적으로 받아오는 parameter는 const reference를 명시적으로 넣고 내부 값을 변경하려고 할 때 const를 떼어내는 편이 좋다   

### 왜 getter&setter를 사용할까?

Effective C++ 에서 모든 멤버 변수들을 private에 선언하고 이를 getter/setter로 접근하는것이 좋다고 하는데 이는 다음과같은 이유가있다

1. 문법적 일관성
2. 멤버 변수의 접근성에 대한 정교한 제어
	멤버 변수에 대해 read-only, write-only와 같은 세부적인 접근 제어를 할 수 있다   
3. 캡슐화
	클래스의 불변속성   
	스레딩 동기화   


---

# 참고 자료

[CPP coreguideline](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)



