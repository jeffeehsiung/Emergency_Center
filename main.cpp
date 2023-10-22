#include <iostream>
#include <string>

int main (argc, char *argv[])
{
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
    return 0;
}
