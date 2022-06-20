# Queue

### Constructors
Queue - Initializes a new instance of the Queue class that is empty and has the default initial capacity.

### Methods
[void enqueue(const T& item)](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L21) - Adds an element to the end of the Queue.<br>
[T& dequeue()](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L26) - Removes and returns the element at the beginning of the Queue.<br>
[T& peek()](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L38) - Returns the element at the beginning of the Queue without removing it.<br>
[bool contains(const T& item)](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L48) - Determines whether an element is in the Queue.<br>
[bool is_empty() const](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L53) - Returns _true_ if the Queue doesn't include elements; otherwise, _false_.<br>
[int count() const](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L58) - Gets the number of elements contained in the Queue.<br>
[void clear()](https://github.com/marcelochaves95/collections/blob/865a1772eee2fd0d986550cf9ad1b87c3235365e/src/queue.h#L63) - Removes all elements from the Queue.<br>
