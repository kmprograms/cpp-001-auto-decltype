#include <iostream>
#include <type_traits>

struct AppValue
{
    int value() const
    {
        return v_;
    }

    int &value_r()
    {
        return v_;
    }

    const int &value_cr() const
    {
        return v_;
    }

    int v_{};
};

struct AppValue2
{
    auto value() const
    {
        return v_;
    }

    auto &value_r()
    {
        return v_;
    }

    auto &value_cr() const
    {
        return v_;
    }

    int v_{};
};

struct AppValue3
{
    auto value() const
    {
        return v_;
    }

    decltype(auto) value_wrapper() const
    {
        return value();
    }

    auto &value_r()
    {
        return v_;
    }

    decltype(auto) value_r_wrapper()
    {
        return value_r();
    }

    auto &value_cr() const
    {
        return v_;
    }

    int v_{};
};

int main()
{
    std::cout << "----------------------- [ 1 ] -----------------------" << std::endl;
    AppValue av1;
    av1.v_ = 10;
    std::cout << av1.value() << std::endl;
    std::cout << av1.value_r() << std::endl;
    std::cout << av1.value_cr() << std::endl;

    std::cout << "----------------------- [ 2 ] -----------------------" << std::endl;
    AppValue2 av2;
    av2.v_ = 10;
    std::cout << av2.value() << std::endl;
    std::cout << av2.value_r() << std::endl;
    std::cout << av2.value_cr() << std::endl;

    std::cout << "----------------------- [ 3 ] -----------------------" << std::endl;
    AppValue3 av3;
    av3.v_ = 10;
    std::cout << av3.value_wrapper() << std::endl;
    std::cout << av3.value_r_wrapper() << std::endl;

    std::cout << std::is_same<decltype(av3.value_wrapper()), int>::value << std::endl;
    std::cout << std::is_same<decltype(av3.value_r_wrapper()), int &>::value << std::endl;

    return 0;
}
