## INDEX

- [EX 02](#ex-02)
	- [Description](#description)

---
# EX 02

## TODO

현재 작성된 포드 존슨은 잘못된 포드존슨이다.
이진 삽입시에 최대 비교횟수는 `2^n - 1` 을 넘어갈 때에 1회씩 증가하게 되는데 위 코드는 승자들을 먼저 순서대로 삽입하고 승자들이 삽입된 main chain에 패자들을 역순으로 `이진 삽입` 을 하게 되는데 여기서 승자들을 다 넣고 `이진 삽입`을 한번이라도 하는 순간 위의 최대 비교횟수를 넘어서게 된다.

포드 존슨의 의의는 `2^n - 1`라는 최대 비교횟수를 넘어서는 구간을 유지하며 패자들을 최대한 삽입할 수 있도록 하여 최대 비교횟수를 최대한으로 줄인 것인데 여기서는 그렇지 못하게 된다.

그렇기에 우리는 패자들을 삽입할 시에 승자가 삽입된 위치를 기억하고 승자의 인덱스에서 -1 한 위치까지 `이진 삽입`을 시도해야 뒤에 있을 모든 패자들이 `2^n - 1` 이라는 최대 비교횟수를 넘어서지 않는 한도 내에서 계속해서 삽입이 가능한 것이다.

## Description

프로그램 이름은 `PmergeMe` 이다.   
프로그램은 오직 연속된 양수만을 허용해야 한다.    
merge-insert 방식의 정렬 알고리즘으로 연속된 양수를 정렬해야 한다.   

Ford-Johnson algorithm을 이용하라.
`Art Of Computer Programming, Vol.3.` 에 정의 되어 있으므로 확인하라.

프로그램에 에러가 발생시 에러 메시지를 출력해야 한다.

코드에 최소 2개의 컨테이너를 사용해야하며 적어도 3000개의 서로다른 정수를 다룰수 있어야 한다.   

각 컨테이너에 따라 알고리즘을 구현해야 하기에 제네릭 함수를 사용하지 않는 것을 권장한다.   

여기 출력에 관한 가이드라인이 있다.   
- 첫 번째 줄: 정렬되지 않은 연속된 양수   
- 두 번째 줄: 정렬된 연속된 양수   
- 세 번째 줄: 첫 번째 컨테이너가 정렬하는데에 걸린 시간   
- 네 번째 줄: 두 번째 컨테이너가 정렬하는데에 걸린 시간   

시간 표시 형식은 자유지만, 단번에 알아보기 쉽게 작성되어야 한다.   

**e.g.:**
```bash
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
```

The indication of the time is deliberately strange in this example.
Of course you have to indicate the time used to perform all your
operations, both the sorting part and the data management part.
