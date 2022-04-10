# Set
Sets are a type of associative containers in which each element has to be unique because the value of the element identifies it. The values are stored in a specific order. 

Search, removal, and insertion operations have logarithmic complexity. Sets are usually implemented as red-black trees.

Sorting is done using the key comparison function Compare. Everywhere the standard library uses the Compare requirements, uniqueness is determined by using the equivalence relation.

## Functions
* set::begin\end: return an interator to the first or following the last element.
  ```
  #include <set>

  //cpp14
  std::set<int> set = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
  std::for_each(set.cbegin(), set.cend(), [](int x) {
      std::cout << x << ' ';
  });
  std::cout << '\n';
  // output 1 2 3 4 5 6 9

  //cpp11 
  std::set<int> set2 = { 3, 1, 4, 1, 5, 2, 6, 5 };
  for (auto iter = set2.begin(); iter !=  set2.cend(); iter++) {
      std::cout << *iter << ' ';
  };
  std::cout << '\n';
  // output 1 2 3 4 5 6
  ```
* set::count: return the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates.
  ```
  std::set<int> t{3, 1, 4, 1, 5};
  std::cout << t.count(1) << ", " << t.count(2) << ".\n";
  // output: 1, 0.
  ```
* set::find: find the element with key equivalent to the key, and return the iterator to the element. If no element is found, return the `end()`
iterator.
  ```
  std::set<int> example = {1, 2, 3, 4};
 
  auto search = example.find(2);
  if (search != example.end()) {
      std::cout << "Found " << (*search) << '\n';
  } else {
      std::cout << "Not found\n";
  }
  // output: Found 2
  ```

## [How to convert a vector to set](https://www.geeksforgeeks.org/how-to-convert-a-vector-to-set-in-c/)
* Using range converter. At first get the vector, and then define a set which copies all elements of the vector using 2 iterators begin and end.
    ```
    std::vector<int> vec = { 1, 2, 3, 1, 1 };

    std::set<int> s(vec.begin(), vec.end());

    std::cout << "Set: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // output 1 2 3
    ```
