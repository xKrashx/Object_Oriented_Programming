Typically, once operator< is provided, the other relational operators are implemented in terms of operator<.

```c++
bool operator< (const X& lhs, const X& rhs){ /* do actual comparison */ }
bool operator> (const X& lhs, const X& rhs){ return rhs < lhs; }
bool operator<=(const X& lhs, const X& rhs){ return !(lhs > rhs); }
bool operator>=(const X& lhs, const X& rhs){ return !(lhs < rhs); }
```

Likewise, the inequality operator is typically implemented in terms of operator==:

```c++
bool operator==(const X& lhs, const X& rhs){ /* do actual comparison */ }
bool operator!=(const X& lhs, const X& rhs){ return !(lhs == rhs); }
```