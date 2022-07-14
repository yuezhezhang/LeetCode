# Object Oriented Programming

## [Dot operator and arrow operator](https://stackoverflow.com/questions/4113365/what-does-mean-in-c)
* Dot operator (.) is used to access a member function or member variable of an object through **a regular variable or reference**.
    ```
    std::string s = "abc";
    std::cout << s.length() << std::endl;
    ```
* Arrow operator (->) is used to access a member function or member variable of an object through **a pointer**.
  ```
  std::string* s = new std::string("abc");
  std::cout << s->length() << std::endl;
  std::cout << (*s).length() << std::endl;
  ```