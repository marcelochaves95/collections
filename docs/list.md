# List

## template <class T> class List
### Constructors:
List<class T> - Initializes a new instance of the List<class T> class that is empty and has the default initial capacity.

### Methods:
void add(const T& item) - Adds an element to the end of the List<class T>.
void remove(const T& item) - Removes the first occurrence of a specific object from the List<class T>.
bool contains(const T& item) - Determines whether an element is in the List<class T>.
bool is_empty() const - Returns true if the List<class T> doesn't include elements; otherwise, false.
T& first() const - Returns the first element of the List<class T>.
T& last() const - Returns the last element of the List<class T>.
int count() const - Returns the number of elements in the List<class T>.
void clear() - Removes all elements from the List<class T>.
