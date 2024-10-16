### Memory allocation

C에서는 `alloc` 과 `free` 함수를 통한 메모리 할당, 해제가 있었다면 C++에서는 `new`, `delete` 연산자를 통한 할당, 해제가 존재한다

#### 할당

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
	   

#### 해제

동적 메모리는 `delete` 연산자를 통해 해제된다
하나 이상의 요소를 가진 메모리를 해제하려면 `delete` 연산자 뒤에 대괄호`[]`를 추가해야한다

`delete`로 전달되는 값은 `new`로 할당된 메모리 블록이거나 `nullptr`이어야 하며 `nullptr`인 경우 `delete`는 아무런 동작도 하지 않는다   

---

이 모든 과정의 메모리 layout은 `heap`에서 동작한다   

C 언어에서의 `alloc`과 `free`가 `<cstdlib>` 헤더에 정의되어있으며 C++에서 사용이 가능하나, `new`로 할당된 메모리 블록과는 호환되지 않으므로 이들 함수와 혼용하여 사용하면 안된다

[cplusplus](https://cplusplus.com/doc/tutorial/dynamic/)     


### references

&, 참조자    

`pointer`에 어느정도 제약이 주어져있는 형식으로 대표적인 차이로는 `nullptr`이 들어갈 수 있고 없고가 있다   
또한 참조자는 선언시에 할당이 이루어져야 하므로 잘못된 주소값이 전달될 일이 없어 `pointer`에 비해 안전하다   
그렇기에 `pointer`를 피하고 참조자를 통한 전달을 통해 불필요한 값의 복사와 유효한 주소값을 전달받기 위해 참조자를 사용하는것이 좋다    
하지만 만일 `nullptr`이 있어야 하는 경우가 있다면 그때는 `pointer`를 사용하면 된다   


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



[CPP coreguideline](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)



