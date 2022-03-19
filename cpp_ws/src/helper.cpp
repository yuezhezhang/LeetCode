#include <iostream>
#include <string>
#include <vector>

template <typename T>
void info(std::vector<T> vector)
{   
    int length = vector.size();
    if (length == 0) 
    {
        std::cout << "The length of the vector is 0!" << std::endl;
    }
    else if (length == 1) 
    {
        std::cout << "The vector is: [" << vector[0] << "]" << std::endl;
    }
    else
    {
        std::cout << "The vector is: [";
        for (auto i = 0; i < length - 1; ++i)
            std::cout << vector[i] << ", ";
        std::cout << vector[length-1] << "]" << std::endl;
    }
}

