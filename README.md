# Generic Programming

This is a basic Linear search program, made while learning generic programming in C++.

Generic programming means getting your program independent of various data types, containers or custom comparisons. The program is a linear search, which searches a Book (given Book), in a library of Books, and returns the position(index) ,of the Book(if the Book being searched is already present), else returns "BOOK NOT PRESENT".

**Linear Search :**

```cpp
//fit-forward iterator(independence of the container).
//t-data type of the data stored(independence of the data type).
//c-for comparison(custom,(here) on the basis of name).
template<class fit,class t,class c>
fit search(fit start,fit end,t key,c C)
{
  while(start!=end)
  {
    if(C(*start,key))
      return start;
    start++;
  }
  return end;
}
```
