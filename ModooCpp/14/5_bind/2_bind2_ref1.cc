// 씹어먹는 C ++ - <14. 함수를 객체로! (C++ std::function, std::mem_fn, std::bind)>
// std::bind
// https://modoocode.com/254#page-heading-4
// 레퍼런스를 인자로 받는 함수

#include <functional>
#include <iostream>

struct S {
    int data;
    S(int data) : data(data) {
        std::cout << "일반 생성자 호출!" << std::endl;
    }

    S(const S& s) {
        std::cout << "복사 생성자 호출!" << std::endl;
        data = s.data;
    }

    S(S&& s) {
        std::cout << "이동 생성자 호출!" << std::endl;
        data = s.data;
    }
};

void do_something(S& s1, const S& s2) {
    s1.data = s2.data + 3;
}

int main() {
    S s1(1), s2(2);

    std::cout << "Before : " << s1.data << std::endl;

    // s1 이 그대로 전달된 것이 아니라 s1 의 복사본이 전달됨!
    auto do_something_with_s1 = std::bind(do_something, std::ref(s1), std::placeholders::_1);
    do_something_with_s1(s2);

    std::cout << "After :: " << s1.data << std::endl;
}