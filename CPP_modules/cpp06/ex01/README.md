## INDEX

- [ex01](#ex01)
  - [Description](#description)

---
# ex01

## Description

그 어떤 사용자도 초기화할 수 없는 Serializer 클래스를 생성하라.

추가적으로 두개의 static 메소드들을 추가하라.   

`uintptr_t serialize(Data* ptr);`   
Data 구조체의 Pointer를 uintptr_t로 변환하는 함수.   

`Data* deserialize(uintptr_t raw);`   
uintptr_t을 다시 Data 구조체의 Pointer로 변환하는 함수.   

Data 구조체는 임의로 만들어라 (비어있어서는 안된다).

전체적으로 프로그램의 동작은 다음과 같이 이루어져야 한다.   

```
Input Data Pointer → serialize()
        =                   ↓
Output Data Pointer ← deserialize()
```

**Solution:**   
reinterpret_cast 를 사용하는 문제다.
reinterpret_cast는 인자로 받은 타입을 그대로 유지하면서, 원래의 비트 패턴을 새로운 타입으로 해석하도록 하는 캐스팅 연산자이다.   
메모리 해석 방식만 변경되며, 데이터 자체는 변형되지 않는다.   
