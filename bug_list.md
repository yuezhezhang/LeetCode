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

## Functions of std::string
ref: `https://www.cplusplus.com/reference/vector/vector/`

# Vector
vector has no member find
vector erase element by index, cannot by value
vector remove can delete all the elments with sam value