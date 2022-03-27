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

## std::set_intersection
