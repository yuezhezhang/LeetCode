# [Vector](https://www.cplusplus.com/reference/vector/vector/)
Vectors are sequence containers representing arrays that can change in size.
## Container properties
* linear sequence
* dynamic array
* allocator-aware

## Functions of vector
* `vector::begin\end`: return an iterator pointing to the first or last element in the vector.
    ```
    std::vector<int> myvector = {1, 2, 3, 4};

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';  
    ```
* `vector::size`: return the number of elements in the vector.
* vector has no member **find**. 
* `vector::erase`: remove from the vector using an iterator pointing to a single element ot a range of elements, which is similar to **string::erase**.
* `vector::push_back`: add a new element at the end of the vector.
* `vector::pop_back`: remove the last element in the vector.
* `vector::empty`: test whether vector is empty.
  ```
  std::vector<int> myvector = {1, 2, 3, 4};
  int sum (0);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
  ```
* `vector::clear`: remove all elements from container, leaving size 0.

vector remove can delete all the elments with sam value

[Efficient ways to erase duplicates and sort a vector](https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector)
* Just using vector, sort + unique (`std::unique` only removes duplicate elements if they're neighbours: you have to sort the vector first before it will work as you intend.)
  ```
  std::sort( vec.begin(), vec.end() );
  vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
  ```
* Convert to set(manually)
  ```
  std::set<int> s;
  unsigned size = vec.size();
  for( unsigned i = 0; i < size; ++i ) s.insert( vec[i] );
  vec.assign( s.begin(), s.end() );
  ```
* Convert to set(using constructor)
  ```
  std::set<int> s( vec.begin(), vec.end() );
  vec.assign( s.begin(), s.end() );
  ```
* **Summary**: when the number of duplicates is large enough, it's actually faster to convert to a set and then dump the data back into a vector. And for some reason, doing the set conversion manually seems to be faster than using the set constructor.