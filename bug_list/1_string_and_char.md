# String and char
## Change a string to a vector of chars:
```
std::string word = "hello";
std::vector<char> vector_word(word.begin(), word.end()); 
```

## Change a char to a string vector:
* Use std::string constructor. The constructor `std::string s(size_t n, char c)`,  which fills the string `s` with `n` copies of character `c`.
    ```
    char c = 'A';
    std::string s(1, c);
    std::cout << s << std::endl; 
    ```
* Use `std::string::append` function to append `n` copies of character `c`.
    ```
    char c = 'A';
    std::string s;
    s.append(1, c);
    std::cout << s << std::endl;
    ```
* Use `std::string::operator+=` to append a character at the end of the string.
    ```
    char c = 'A';
    std::string s;
    s += c;
    std::cout << s << std::endl;
    ```  
* Use `std::string::operator=` to replace the contents of a string with a single char.
    ```
    char c = 'A';
    std::string s;
    s = c;
    std::cout << s << std::endl;
    ``` 

## [Functions of std::string](https://www.cplusplus.com/reference/string/string/)
* `string::begin\end`: an iterator to the beginning or end of the string.
    ```
    std::string str ("Test string");
    for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
        std::cout << *it;
    std::cout << '\n';
    ```
* `string::length\size`: return length of string, in terms of bytes.
* `string::operator+=`: append additional characters at the end of its current value:
* `string::append`: append strings or consecutive chars at the end.
* `string::push_back`: append a **char** to the end of the string.
* `string::pop_back`: delete last character.
* `string::erase`: erase part of the string using **position** or **iterator**.
* `string::empty`: test if string is empty.
* `string::find`: find **content** in string. Searches the string for the first occurrence of the sequence specified by its arguments. Return the position of the first character of the first match. If no matches were found, the function returns `string::npos`. When `pos` is specified, the search only includes characters at or after position `pos`, ignoring any possible occurrences before `pos`.
    ```
    std::string str ("There are two needles in this haystack with needles.");
    std::string str2 ("needle");

    std::size_t found = str.find(str2);
    if (found!=std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n'; // 14

    found=str.find("needles are small",found+1,6);
    if (found!=std::string::npos)
        std::cout << "second 'needle' found at: " << found << '\n'; // 44
    ```
* `string::find_first_of`: find **character** in string. Searches the string for the first character that matches **any** of the characters specified in its arguments. Return the position of the first character that matches.
    ```
    std::string str ("Please, replace the vowels in this sentence by asterisks.");
    std::size_t found = str.find_first_of("aeiou");
    while (found!=std::string::npos)
    {
        str[found]='*';
        found=str.find_first_of("aeiou",found+1);
    }

    std::cout << str << '\n';
    // Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.
    ```