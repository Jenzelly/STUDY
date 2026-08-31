# 기본 자료형 (Primitive Data Type)

데이터를 어떻게 표현하느냐가 프로그래밍의 핵심이다.

변수형은 언어가 제공하는 기본형(primitive)으로 정의될 수도 있고, 프로그래머가 직접 정의할 수도 있다.
변수형의 폭은 해당 변수가 메모리에서 차지하는 비트의 크기와 같다.

---

## 비트 연산 예시

```cpp
6 & 4      // AND
1 | 2      // OR
8 >> 1     // Right shift
-16 >> 2   // Arithmetic right shift
1 << 10    // Left shift
~0         // NOT
15 ^ x     // XOR
```

## `<limits>` 주요 함수

```cpp
numeric_limits<int>::min()
numeric_limits<float>::max()
numeric_limits<double>::infinity()
```

> 부동소수점 비교 시 주의 필요!
> 절대/상대 허용오차를 사용하는 것이 적절할 때도 있다.

## `<cmath>` 주요 함수

```cpp
abs(-34)          fabs(-3.14)
ceil(2.17)        floor(3.14)
min(x, -4)        max(3.14, y)
pow(2.71, 3.14)   log(7.12)
sqrt(225)
```

## 정수, 문자, 문자열 간 변환

```cpp
to_string(123)    // 숫자 -> 문자열
stoi("42")        // 문자열 -> 숫자
```

## `<random>` 주요 함수

```cpp
uniform_int_distribution<> dis(1, 6);              // 1~6 사이 정수
uniform_real_distribution<double> dis(1.3, 2.9);   // 1.3~2.9 사이 실수
generate_canonical<double, 10>(gen);               // [0.0, 1.0) 난수 (10비트 정밀도)
```

## 기타

```cpp
swap(x, y)   // 값 교환. vector 같은 복잡한 타입도 가능
```
