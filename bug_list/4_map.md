# [Map](https://www.cplusplus.com/reference/map/map/)
Maps are associative containers that store elements formed by a combination of a `key value` and a `mapped value`, following a specific order. 

In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key.

Map containers are generally slower than`unordered_map` containers to access individual elements by their `key`, but they allow the direct iteration on subsets based on their order.

Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion

The mapped values in a map can be accessed directly by their corresponding key using the `bracket operator`.

## Properties
* Unique keys: No two elements in the container can have equivalent keys.
* Orderd: The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
* For std::unordered_map, the unordered containers organize their elements using hash tables that allow for fast access to elements by their key.

## Functions
* map::begin\end: return iterator to begining ot end.
    ```
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // output
    a => 200
    b => 100
    c => 300
    ```
* map::find:  
  `iterator find (const key_type& k);`

  search the container for an element with a `key` equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
  ```
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  // output
  elements in mymap:
  a => 50
  c => 150
  d => 200
  ```
* map::count

   `size_type count (const key_type& k) const;`
    
    Count elements with a specific key and return the number of matches.

    ```
    std::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
        std::cout << " is an element of mymap.\n";
        else 
        std::cout << " is not an element of mymap.\n";
    }
    
    // output
    a is an element of mymap.
    b is not an element of mymap.
    c is an element of mymap.
    d is not an element of mymap.
    e is not an element of mymap.
    f is an element of mymap.
    g is not an element of mymap.
    ```

* map::erase
  ```
  (1) void erase (iterator position);
  (2) size_type erase (const key_type& k);
  (3) void erase (iterator first, iterator last);
  ```
  Removes from the map container either a single element or a range of elements ([first,last)).
  ```
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show contents:
  for (auto it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  
  for(const auto& elem : mymap){
      std::cout << elem.first << " => " << elem.second << "\n";
  }

  // output
  a => 10
  d => 40
  ```
## [Vector of maps](https://www.geeksforgeeks.org/vector-of-maps-in-c-with-examples/)
It can be used to store the frequencies of different characters in a string.

Syntax:
* Vector of Ordered Map:
  ```
  vector<map<datatype, datatype> > VM;
  ```
* Vector of Unordered map:
  ```
  vector<unordered_map<datatype, datatype> > VUM;
  ```
Code:
```
// C++ program to demonstrate the use
// of vector of maps
#include <bits/stdc++.h>
using namespace std;

// Function to count frequency
// up to each index
void findOccurences(string s)
{
	// Vector of map
	vector<map<char, int> > mp(s.length());

	// Traverse the string s
	for (int i = 0; i < s.length(); i++) {

		// Update the frequency
		for (int j = 0; j <= i; j++) {
			mp[i][s[j]]++;
		}
	}

	// Print the vector of map
	for (int i = 0; i < s.length(); i++) {

		cout << "Frequency upto "
			<< "position " << i + 1
			<< endl;

		// Traverse the map
		for (auto x : mp[i])
			cout << x.first << "-"
				<< x.second << endl;
	}
}

// Driver Code
int main()
{
	// Input string S
	string S = "geeks";

	// Function Call
	findOccurences(S);

	return 0;
}
```
Output:
```
Frequency upto position 1
g-1
Frequency upto position 2
e-1
g-1
Frequency upto position 3
e-2
g-1
Frequency upto position 4
e-2
g-1
k-1
Frequency upto position 5
e-2
g-1
k-1
s-1
```

## Some Tips
*  If a key does not exist in a map, it will return 0 using bracket, and there is no error.
    ```
    std::map<char,int> mymap;
    mymap['b'] = 100;
    std::cout << mymap['c'] << std::endl; 

    // output: 0
    ```