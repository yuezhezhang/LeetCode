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