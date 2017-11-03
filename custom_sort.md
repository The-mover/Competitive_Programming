## Custom sorting function

To have an output like the following example a vector sort with custom  
cmp funtion can be used

```c++
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if( a.first == b.first )
        return a.second > b.second;
    return a.first < b.first;
}
```

### input

2 3  
1 6  
1 7  
3 1  

### output

1 7  
1 6  
2 3  
3 1  
