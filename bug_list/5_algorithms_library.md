
# [Algorithms Library](https://en.cppreference.com/w/cpp/algorithm)
## std::find, std::find_if
* ` find(InputIt first, InputIt last, const T& value)` returns an iterator to the first element in the range [first, last) that are equal to `value`.
    ```
    std::vector<int> v{1, 2, 3, 4};
    int n1 = 3;
    int n2 = 5;
 
    auto result1 = std::find(begin(v), end(v), n1);
    auto result2 = std::find(begin(v), end(v), n2);
 
    (result1 != std::end(v))
        ? std::cout << "v contains " << n1 << '\n'
        : std::cout << "v does not contain " << n1 << '\n';
 
    (result2 != std::end(v))
        ? std::cout << "v contains " << n2 << '\n'
        : std::cout << "v does not contain " << n2 << '\n';

    ```
* `find_if(InputIt first, InputIt last, UnaryPredicate p)` returns an iterator to the first element in the range [first, last) for which predicate `p` returns `true`.
    ```
    std::vector<int> v{1, 2, 3, 4};
    auto is_even = [](int i){ return i%2 == 0; };

    auto result3 = std::find_if(begin(v), end(v), is_even);
 
    (result3 != std::end(v))
        ? std::cout << "v contains an even number: " << *result3 << '\n'
        : std::cout << "v does not contain even numbers\n";
    ```

## std::count, std::count_if
* ` count(InputIt first, InputIt last, const T& value)` returns the number of elements in the range [first, last) that are equal to `value`.
    ```
    // For string
    std::string s = "C++,Java";
    char ch = '+';
 
    int count = std::count(s.begin(), s.end(), ch);
    // output: 2

    // For vector (vector has no member function count)
    std::vector<int> v = {1, 2, 2, 4, 5, 6, 8, 2, 2};
    std::cout << std::count(v.begin(), v.end(), 2) << std::endl;

    //output: 4
    ```
* `count_if(InputIt first, InputIt last, UnaryPredicate p)` returns the number of elements in the range [first, last) for which predicate `p` returns `true`. ps. unary operation is an operation with only one operand.
    ```
    std::string s = "abcdefg";
    int num = std::count_if(s.begin(), s.end(), [](char i){return i > 'd';});
    std::cout << "char greater than d: " << num << std::endl;

    // use a lambda expression to count elements divisible by 4.
    std::vector<int> v = {1, 2, 2, 4, 5, 6, 8, 2, 2};
    int count_div4 = std::count_if(v.begin(), v.end(), [](int i){return i % 4 == 0;});
    std::cout << "numbers divisible by four: " << count_div4 << '\n';
    ```
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