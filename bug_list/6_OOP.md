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

## Argument passing
### Pass by value
```
int i = 1;           // first variable i=1
int j = addOne(i);   // second variable j=2 (i=1 still)

int addOne(int a)    // third variable a (copy of i)
{
    return a+1       // copy result a+1 to variable j on return  
}
```
`int function(int data)`
* Function receives a copy of the original data
* For large `data` a huge amount of temporal memory is needed
* Modifications of `data` inside have no effect outside
* Could use pass-by-value for passing fundamental data types and enumerators, e.g. `void PrintDayOfTheWeek(int day) {}`
### Pass by reference
```
int i = 1;           // first variable i=1
int j = addOne(i);   // second variable j=2 (i=1 still)

int addOne(const int& a)    // constant reference to a
{
    return a+1       // copy result a+1 to variable j on return  
}
```
`void function(int& data)`
* Function receives a reference to the original data
* No copy of `data` is created (better performance for large data)
* Modifications of `data` inside the function have effect outside
* Multiple parameters can be changed at a time, e.g. `void function(int& data1, int& data2, int& data3)`
* To prevent modification of `data` but still enable efficient passing of arguments use `void function(const int& data)`
* could use pass-by-reference in most cases using **const** to prevent data modification
### Pass by address, pointer
```
int i = 1;           // first variable i=1
int j = addOne(&i);   // second variable j=2 (i=1 still)

int addOne(int* a)    // address of variable a
{
    return *a+1       // copy result *a+1 to variable j on return  
}
```
`void function(int* data)`
* Function receives the address where data is stored in memory
* The address is passed by value, so you cannot change the address but you can change th#include <iostream>

using namespace std;

class Vehicle {
  public:
    int age;
    Vehicle(int age): age(age){};
    void PrintAge(){
        cout<<age<<endl;
    };
};

class Honda : public Vehicle{
    public:
        Honda(int age) : Vehicle(age){};
};

// Honda::Honda(int age) : Vehicle(age){};
class NewHonda : public Honda{
    public:
        NewHonda(int age);
        // NewHonda(int age) : Honda(age){};
};

NewHonda::NewHonda(int age) : Honda(age){};

int main()
{
    cout<<"Hello World"<<endl;
    
    Vehicle vehicle(8);
    vehicle.PrintAge();
    
    Honda honda(9);
    honda.PrintAge();
    
    NewHonda newhonda(12);
    newhonda.PrintAge();

    return 0;
}
e dereferenced data behind it 
* No copy of `data` is created (better performance for large data)
* Modifications of `data` inside the function have effect outside
* To prevent modifications of `data` but still enable efficient passing of arguments use `void function(const int* data)`
* Could use pass-by-address for built-in arrays using **const** to prevent data modification
    ```
    double sum(const int* array, int length)
    {
        double s = 0;
        for (auto i=0; i<length; i++)
            s += array[i];
        return s;
    }

    int array[5] = {1, 2, 3, 4, 5};
    std::cout << sum(array, 5) >> std::endl;
    ```
## Inheritance
### Constructor
```
#include <iostream>

using namespace std;

class Vehicle {
  public:
    int age;
    Vehicle(int age): age(age){};
    void PrintAge(){
        cout<<age<<endl;
    };
};

class Honda : public Vehicle{
    public:
        Honda(int age) : Vehicle(age){};
};

// Honda::Honda(int age) : Vehicle(age){};
class NewHonda : public Honda{
    public:
        NewHonda(int age);
        // NewHonda(int age) : Honda(age){};
};

NewHonda::NewHonda(int age) : Honda(age){};

int main()
{
    cout<<"Hello World"<<endl;
    
    Vehicle vehicle(8);
    vehicle.PrintAge();
    
    Honda honda(9);
    honda.PrintAge();
    
    NewHonda newhonda(12);
    newhonda.PrintAge();

    return 0;
}

```
    
## Class
### [Initialization of data members in the class](https://stackoverflow.com/questions/11490988/c-compile-time-error-expected-identifier-before-numeric-constant)
* We can initialize the data members at the point of declaration , but not with `()` brackets
 ```
class Foo {
    vector<string> name = vector<string>(5);
    vector<int> val{vector<int>(5,0)};
};
 ```
* or declare them first and initialize them later e.g. in a constructor
```
class Foo {
    vector<string> name;
    vector<int> val;
 public:
    Foo() : name(5), val(5,0) {}
};
```
