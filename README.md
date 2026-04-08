# Stack-Queue

Refactored a previous queue implementation to improve memory safety, simplify logic, and better follow C++ design principles.

## Refactor Notes

### Memory Management
- Replaced raw pointers (`LLStack*`) with object composition (`LLStack`)
- Removed manual destructor calls and relied on RAII
- Fixed memory leaks caused by improper `new`/`delete` usage

### Data Structure Design
- Changed `pop()` return type from `Node*` to `int` to avoid exposing internal structure
- Reduced direct manipulation of node pointers
- Improved separation of concerns between stack and queue

### Logic and Efficiency
- Eliminated unnecessary pop/push cycles for printing
- Simplified logic by removing redundant conditionals
- Streamlined enqueue/dequeue using standard two-stack approach

### Error Handling
- Replaced inconsistent error handling (`NULL`, `-1`, prints) with `std::runtime_error`
- Added centralized exception handling in `main`

### Code Quality
- Removed unnecessary use of `this->`
- Standardized naming conventions
- Updated `NULL` to `nullptr`
- Reduced unnecessary variables and branching
- Improved readability and structure

## Key Concepts
- Stack and queue implementations
- Queue using two stacks (FIFO behavior)
- Dynamic memory management
- RAII (tying resource cleanup to object lifetime so C++ automatically manages it for you)
- Exception handling
- Refactoring and code improvement

## How to Run
```bash
g++ refactored_version.cpp -o refactored_version
./refactored_version
