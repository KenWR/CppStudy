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

