## INDEX

- [CPP\_01: EX\_03](#cpp_01-ex_03)
  - [Description](#description)
  - [Concepts](#concepts)
    - [references](#references)
    - [기본생성자 제거](#기본생성자-제거)
    - [멤버 함수 뒤에 붙는 const](#멤버-함수-뒤에-붙는-const)

---
# CPP_01: EX_03

## Description

참조형과 포인터의 차이를 묻는 것이다

이 차이는 아주 간단한데 참조형은 선언과 동시에 값이 할당되어야 하는 반면 포인터의 경우에는 값이 없더라도 쓰레기값이 기본적으로 들어가 있으며 추후에 nullptr로 값이 없음을 선언할 수 있다는 점에서 차이가 있다   

## Concepts

### references

&, 참조자    

`pointer`에 어느정도 제약이 주어져있는 형식으로 대표적인 차이로는 `nullptr`이 들어갈 수 있고 없고가 있다   
또한 참조자는 선언시에 할당이 이루어져야 하므로 잘못된 주소값이 전달될 일이 없어 `pointer`에 비해 안전하다   
그렇기에 `pointer`를 피하고 참조자를 통한 전달을 통해 불필요한 값의 복사와 유효한 주소값을 전달받기 위해 참조자를 사용하는것이 좋다    
하지만 만일 `nullptr`이 있어야 하는 경우가 있다면 그때는 `pointer`를 사용하면 된다  


### 기본생성자 제거

```C++
(1)	
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT, Traits>&
    getline( std::basic_istream<CharT, Traits>& input,
             std::basic_string<CharT, Traits, Allocator>& str, CharT delim );

(2)	(since C++11)
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT, Traits>&
    getline( std::basic_istream<CharT, Traits>&& input,
             std::basic_string<CharT, Traits, Allocator>& str, CharT delim );

(3)	
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT, Traits>&
    getline( std::basic_istream<CharT, Traits>& input,
             std::basic_string<CharT, Traits, Allocator>& str );

(4)	(since C++11)
template< class CharT, class Traits, class Allocator >
std::basic_istream<CharT, Traits>&
    getline( std::basic_istream<CharT, Traits>&& input,
             std::basic_string<CharT, Traits, Allocator>& str );
```
 
암시적으로 선언되거나 명시적으로 기본값을 가지는 기본생성자는 다음 조건 중 하나를 만족하는 경우 C++11 이후 부터 `delete`로 정의된다   
**C++11 이전에는 `private`에 기본생성자를 정의함으로서 삭제했다**   

조건:
1. T가 union이고, 모든 멤버 변수가 const 한정자(혹은 다차원 배열)인 경우   
2. T가 클래스이며, 모든 익명 union 멤버가 const 한정자(혹은 다차원 배열) 인 경우   
3. T가 기본값을 제공하지 않는 참조형 비정적 데이터 멤버를 가지고 있는 경우 (since C++11)   
4. T가 const 한정자(혹은 다차원 배열) 의 비정적 비 변형 비 정수 기본 생성 가능 데이터 멤버를 가지고 있는 경우   
5. T가 클래스 타입 M(혹은 다차원 배열) 의 잠재적으로 생성된 서브 객체를 가지고 있으며, 다음 조건 중 하나를 만족하는 경우   
	- M의 소멸자가 삭제되었거나(since C++11) 기본 생성자에서 접근할 수 없는 경우   
	- 다음 조건을 모두 만족하는 경우   
    	- 서브 객체가 기본 초기화를 가진 비정적 데이터 멤버가 아닌 경우   
    	- 서브 객체가 기본 초기화를 가진 다른 비정적 데이터 멤버가 있는 유니언의 변형 멤버가 아닌경우(since C++11)   
  	- M의 기본생성자를 찾기 위한 오버로드 해석에서 사용 가능한 후보가 없는 경우, 또는 서브 객체가 유니언의 변형 멤버일 때 비트 복사가 아닌 비트 복사방지(선택된 비-사소한(non-trivial) 생성자)가 선택된 경우   

사용자 정의 생성자가 없고 암시적으로 선언된 기본 생성자가 사소하지 않은 경우, `delete` 키워드를 사용하여 암시적으로 정의된 기본 생성자의 자동 생성을 막을 수 있다 (since C++11)


### 멤버 함수 뒤에 붙는 const

```c++
void    foo( void ) const;
```

멤버 함수의 뒤에 const가 붙는것은 함수가 호출되는 객체의 메모리를 변경하지 않는 `read-only` 함수임을 지정한다   
만일 멤버 변수에 `mutable`로 선언되어 있는 경우 상수 멤버 함수 내에서도 그 값을 변경할 수 있다   


