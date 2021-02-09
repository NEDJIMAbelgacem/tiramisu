#include <iostream>

int main()
{
    int res = 0;
    for (int i = 0; i < 2000; ++i)
    {
        res += i;
    }
    std::cout << res << std::endl;
}