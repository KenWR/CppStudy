## INDEX

- [CPP 04](#cpp-04)
	- [Description](#description)
	- [Concepts](#concepts)
		- [Object slicing](#object-slicing)

---
# CPP 04

## Description

다형성, virtual, interface, abstract class 들에 대해서 배운다   

## Concepts

### Object slicing

다운 캐스팅시 reference나 pointer로 받지 않고 value로 받게되면 deep copy가 발생하게 되어 다형성이 생기지 않을 뿐더러 base만 복사될뿐 derived 객체는 복사가 이루어지지 않게 된다   

이렇게 객체가 잘리는 것은 꽤나 위험하며 여러가지 문제가 생길 수 있기에 왠만해서는 객체를 전달받을때 reference나 pointer로 받아야 한다   

