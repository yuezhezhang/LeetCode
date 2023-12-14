## String
```
string = 'abdjjjcee'
even_str = string[::2]
odd_str = string[1::2]
str_list = list(string)
ascii_num = ord('a') # expect a character
char = chr(ascii_num)
if 'a' < 'b':
    print('Yes')
for i in string:
    print(i)  # print every character
print(int('a', 16)) # 10  # change character to a number in hex
print(int('0011', 2)) # convert a string to a number
print(bin(10)) # '0b1010' convert a number to a string in binary
print(bin(7))  # '0b111'
bin(7)[2:].rjust(4, 0') # '0111'
print(hex(10)) # '0xa' convert a number to a string in hex
reverse_str = string[::-1]
upp_str = string.upper()
```

## List and Array
```
# Print elements in a list in one row
a = [1, 2, 3, 4]
print(*a) # 1 2 3 4
# Print lists separated by commas
print(*a, sep = ", ")
# Print lists in different rows
print(*a, sep='\n')
```

## Regular Expression
* See [docs](https://docs.python.org/zh-cn/3/library/re.html#regular-expression-objects) and [this](https://www.runoob.com/python/python-reg-expressions.html)
* To check a character within range：
  ```
  import re
  if re.search(r'[0-9A-Fa-f]', x):
     pass
  ```

## Algorithms
* Sorting algorithm, see [docs](https://www.runoob.com/w3cnote/ten-sorting-algorithm.html)
  ```
  students = [('john', 'A', 15), ('jane', 'B', 12), ('dave', 'B', 10)]
  sorted(students, key=lambda s: s[2])            # 按年龄排序
  # [('dave', 'B', 10), ('jane', 'B', 12), ('john', 'A', 15)]
     
  sorted(students, key=lambda s: s[2], reverse=True)       # 按降序
  # [('john', 'A', 15), ('jane', 'B', 12), ('dave', 'B', 10)]
  ```
* Bubble sort
  ```
  new_str = sorted(string) # return a list

  def sort_str(string):
    n = len(string)
    new_str = ''
    str_list = list(string)
    for i in range(n):
        for j in range(i+1, n):
            if str_list[i] > str_list[j]:
                str_list[i], str_list[j] = str_list[j], str_list[i]
        new_str += str_list[i]
    return new_str
  ```
