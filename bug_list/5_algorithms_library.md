# [Algorithms Library](https://en.cppreference.com/w/cpp/algorithm)
## std::find

## std::remove
This method `remove(v.begin(),v.end(),val)` removes all elements which are equal to val and returns an iterator to the new end of that range.
* [For vector](https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/):
    ```
    std::vector<int> v = {10, 20, 20, 30, 30, 40};

    std::vector<int>::iterator new_end = std::remove(v.begin(), v.end(), 20);

    //Prints 10 30 30 40 30 40
    for(int i=0;i<v.size(); i++){
        std::cout << v[i] << " ";
    }

    // 6, the space is not removed
    std::cout << v.size() << std::endl; 
    ```

## [std::set_intersection](https://en.cppreference.com/w/cpp/algorithm/set_intersection)
Find common elements in two sorted ranges [first1, last1) and [first2, last2). If some element is found m times in [first1, last1) and n times in [first2, last2), the first std::min(m, n) elements will be copied from the first range to the destination range. The order of equivalent elements is preserved.

* For integer elements:
    ```
    std::vector<int> v1{7, 5, 5, 5, 6, 7, 8};
    std::vector<int> v2{8, 7, 5, 7, 9, 10, 5};

    // std::sort(v1.begin(), v1.end());
    // std::sort(v2.begin(), v2.end());

    std::vector<int> v_intersection;

    std::set_intersection(v1.begin(), v1.end(),
                        v2.begin(), v2.end(),
                        std::back_inserter(v_intersection));
    for(int n : v_intersection)
        std::cout << n << ' ';
    std::cout << " " << std::endl; 

    // If without sorting, the answer is 8
    // If sorting, the answer is 5 5 7 7 8
    ```

* For char elements, it is also working:
    ```
    std::vector<char> v1{'a', 'b', 'a', 'c'};
    std::vector<char> v2{ 'a', 'c', 'b'};
    // std::sort(v1.begin(), v1.end());
    // std::sort(v2.begin(), v2.end());

    std::vector<char> v_intersection;

    std::set_intersection(v1.begin(), v1.end(),
                        v2.begin(), v2.end(),
                        std::back_inserter(v_intersection));
    for(char n : v_intersection)
        std::cout << n << ' ';
    std::cout << " " << std::endl; 

    // If wihout sorting, the answer is a c
    // If sorting, a b c
    ```

So the function is finding the same consecutive range in two ranges.