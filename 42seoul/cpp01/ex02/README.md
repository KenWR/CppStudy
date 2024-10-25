## INDEX

- [CPP\_01: EX\_02](#cpp_01-ex_02)
	- [Description](#description)
	- [Concepts](#concepts)
		- [references](#references)

---
# CPP_01: EX_02

## Description

레퍼런스(&) 선언방식에 대해 배운다

## Concepts

### references

&, 참조자    

`pointer`에 어느정도 제약이 주어져있는 형식으로 대표적인 차이로는 `nullptr`이 들어갈 수 있고 없고가 있다   
또한 참조자는 선언시에 할당이 이루어져야 하므로 잘못된 주소값이 전달될 일이 없어 `pointer`에 비해 안전하다   
그렇기에 `pointer`를 피하고 참조자를 통한 전달을 통해 불필요한 값의 복사와 유효한 주소값을 전달받기 위해 참조자를 사용하는것이 좋다    
하지만 만일 `nullptr`이 있어야 하는 경우가 있다면 그때는 `pointer`를 사용하면 된다   
