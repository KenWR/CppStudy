
**“동적 배열”** 로도 불리는 `std::vector`는 C++에서 가장 손쉽게 쓸 수 있는 **시퀀스 컨테이너(sequence container)** 이다.     
그러나 **“편리하다”**는 이유만으로 벡터를 남용해선 안 된다.   

C++은 저수준 성능과 제어력을 유지하면서도 고수준 추상화(객체지향, 제네릭 등)를 지원하는 범용 언어다.    
따라서 우리는 언제나 **성능·최적화**를 염두에 두어야 하고, 그 첫걸음이 바로 **불필요한 _힙 할당_ 과 _복사_ 를 피하는 것** 이다.        
## `std::vector` 를 꼭 사용해야 하나?

`std::vector`는 기본적으로 **힙(Heap) 메모리**를 사용하는 **컨테이너 클래스**다.  
즉, **동적 할당**이 발생한다는 뜻이다.   

동적으로 크기가 변하는 데이터를 배열처럼 다뤄야 한다면 `std::vector`는 훌륭한 도구다.  
그러나 **크기가 고정된 데이터**를 다루는 경우라면, `std::array`를 사용해 **불필요한 힙 할당**을 피하는 편이 낫다.   

## Allocation
### `push_back()`의 함정

`std::vector`는 **용량(capacity)이 부족해지면 새 버퍼를 힙에 재할당**하고 기존 요소를 모두 복사한 뒤, 옛 버퍼를 해제한다.       

```cpp
#include <vector>
#include <iostream>
#include <cstdlib>

static int s_AllocationCount = 0;

// allocate
void* operator new(std::size_t size)
{
    std::cout << "Allocated: " << size << " bytes\n";
    ++s_AllocationCount;
    return std::malloc(size);
}

// deallocate (C++11/14/17)
void operator delete(void* ptr) noexcept            { std::free(ptr); }
void operator delete(void* ptr, std::size_t) noexcept { std::free(ptr); }
void operator delete(void* ptr, std::align_val_t) noexcept { std::free(ptr); }

int main()
{
    std::vector<int> vec;
    std::cout << "sizeof(int) = " << sizeof(int) << " bytes\n";

    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }

    std::cout << "Allocation count: " << s_AllocationCount << '\n';
}
```

```c++
sizeof(int) = 4 bytes
Allocated: 4 bytes
Allocated: 8 bytes
Allocated: 16 bytes
Allocated: 32 bytes
Allocation count: 4

```


4번이나 힙 메모리 할당을 하는 것이 보이는가?   
출력을 보면 어떠한 방식으로 할당과 해제가 발생했는지 알 수 있다.    
1. 0 → 4bytes (1개)      
2. 4bytes → 8 bytes (2개)       
3. 8bytes -> 16 bytes (3개)         
4. 16bytes (4개)      
5. 16 bytes -> 32 bytes (5개)     

### 불필요한 재할당을 줄이는 두 가지 방법

| 방법              | 코드                         | 특성                                                      |
| --------------- | -------------------------- | ------------------------------------------------------- |
| **선언 시 크기 지정**  | `std::vector<int> vec(5);` | `size == capacity == 5`<br>5개의 `int`가 **곧바로 존재**(기본 생성) |
| **용량만 미리 확보**   | `vec.reserve(5);`          | `size == 0`, `capacity == 5`<br>**할당만** 하고 아직 요소 없음     |
| **크기·용량 동시 변경** | `vec.resize(5);`           | `size == capacity == 5`<br>추가 영역을 기본 생성자로 **채움**        |


## Copy

### `push_back()` 보다 `emplace_back() (c++ 11)` 을 써야 하는 이유

```c++
#include <vector>
#include <iostream>

static int s_CopyCount = 0;

struct Data {
    int value_ = 0;
  
    Data() { std::cout << "Data constructed\n"; };
    Data(int value) : value_(value) { std::cout << "Data constructed\n"; };
    Data(const Data& other) : value_(other.value_) {
        s_CopyCount++;
        std::cout << "Data copied\n";
    }
    constexpr Data& operator=(const Data& other) = default;
};

int main() {
    std::vector<Data> vec;
    vec.reserve(5);

    for (int i = 0; i < 5; ++i) {
        vec.push_back(Data(i));
        // vec.emplace_back(i);
    }
  
    std::cout << "Copy count: " << s_CopyCount << '\n';
    
    return 0;
}
```

`push_back()` 사용 시
```bash
Data constructed
Data copied
Data constructed
Data copied
Data constructed
Data copied
Data constructed
Data copied
Data constructed
Data copied
Copy count: 5
```

`emplace_back()` 사용 시
```bash
Data constructed
Data constructed
Data constructed
Data constructed
Data constructed
Copy count: 0
```

`push_back`는 **이미 완성된 객체**를 벡터 내부로 _옮겨_ 담는 함수다.     
따라서 호출 시점에 먼저 `Data` 임시 객체가 생성되고, 그 객체가 벡터에 **복사(또는 이동)** 되어 들어간다.   

반면 `emplace_back`은 `Data`가 받을 **인자만 전달**받아, 벡터의 버퍼 공간에서 곧바로 `Data` 객체를 **직접 생성**한다.     
즉, 중간 임시 객체가 없으므로 **추가 복사·이동이 발생하지 않는다**.     

### 사실 `emplace_back()` 은 굉장히 위험하다

`push_back()`은 암시적 형변환을 통해 임시 객체를 생성하고 벡터 내부에 복사를 한다.    
`emplace_back()`은 내부적으로 **데이터의 생성자를 직접 호출하여 객체를 생성**하지만, **암시적 변환에는 매우 엄격하기 때문에**  생성자가 모호하게 오버로딩되어 있거나, 전달된 인자가 **정확하게 생성자와 일치하지 않으면 컴파일 오류가 발생할 수 있다.**       



#### Move semantics

이동 의미론을 지원하는 이동 생성자와 이동 연산자를 활용하면, `push_back()`도 `emplace_back()`과 동일하게 **복사 없이** 요소를 추가할 수 있다.   
```c++
vec.push_back(std::move(i));
```
이처럼 **Move semantics**를 통해 복사를 최소화할 수 있으며, 결과적으로 `emplace_back()`과 유사한 성능을 낼 수 있다.      

### 결론

따라서 일상적인 상황에서는 **`push_back()`을 기본으로 사용**하고, **이동 의미론을 사용할 수 없는 상황**이나, **알고리즘적으로 `emplace_back()`이 더 높은 성능을 유도할 수 있는 경우에만** `emplace_back()`을 선택적으로 사용하는 것이 더 안전하다.   

## 추가적으로…

### `const &`는 기초적인 최적화다   
- **`const`**     
  *객체를 수정하지 않겠다*는 명시적인 약속이다.     
  컴파일러는 “읽기 전용”임을 알고 **불필요한 쓰기-방어 코드**를 제거할 수 있다.    
- **`&`(Lvalue reference)**     
  객체 자체를 복사하지 않고 **주소(포인터) 크기**만큼의 값만 전달한다.     
  특히 대용량 컨테이너나 구조체를 인자로 받을 때 **복사 비용**을 획기적으로 줄여 준다.   

두 키워드를 결합하면 함수 시그니처가 아래처럼 된다.   

```c++
const std::vector<T>& vec;
```

요약하자면, 벡터의 **전체 데이터를 건드리지 않고**(const)  **단 하나의 참조**(주소)만 전달(&)해 성능 저하 없이 안전하게 접근할 수 있다.    

_위의 `emplace_back()` 에 사용한 copy 횟수를 세는 예제에 const, & 를 하나씩 떼고 붙여가며 다른 함수에 매개변수로 전달해보면 얼마나 중요한지 알게 될 것이다._