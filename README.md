# Constant keyword in C++

It is quite confusing all these const keywords is putting in front of, behind pointers, objects. To clearify all these const.

## 1. Constant Expression
 constexpr  meaning The value of the variable is set during compile time only. No runtime reassignment.
   Example

```cpp
constexpr int NUMROWS = 5;
```


## 2. Constant object pointer. The word const is infront of type char *
```cpp
 const char *constData = "constant";
```
This position of const means constant object, meaning that the pointer can point to new address, but at the address it pointed to cannot change value
### Example 
```cpp    
    const char *constData = "constant"; 
    printf("%s: %p\n", constData,(void *)constData);
    #if 0
       strcpy(constData, "Can I do this? ");// NO!
       printf("%s: %p\n", constData,(void *)constData);
    #else
       constData = "updated constant";  // allow
       printf("%s: %p\n", constData,(void *)constData);
    #endif
```
#### Result:
constant: 0x5588fb2b3007
updated constant: 0x5588fb2b3018


 The compiler outputs error for code inside #if 0 condition. It allow compilation for code insdie #else condtion. 
This shows that the const infront of const char * means that the value in the address pointed by the pointer cannot be changed, hence the name constant object.
The Result: also show that the const object pointer can point to new memory address. Thus the pointer itself is not constant.

### Another example
```cpp   
    const int *constIntData;
    int a = 3, b =4, *not_constIntData;    
    constIntData = &a;
    a =4;
    #if 0
    constIntData = (int *)malloc(sizeof(b));
    memcpy(constIntData, &b, sizeof(b));
    #else
    not_constIntData = (int *)malloc(sizeof(b));
    memcpy(not_constIntData, &b, sizeof(int));
    #endif
```
 The compiler outputs error for code inside #if 0 condition. It allow compilation for code insdie #else condtion. 
This shows that the const infront of const char * means that the value in the address pointed by the pointer cannot be changed, hence the name constant object.


## 3. Constant pointer: The word const is just right behind the type char *
Reference
```cpp
char *const constPtrString = regularString;
```
### Example  
```cpp
// Define, allocate, load simple strings using strcpy()
char *regularString = new char[36]; // sized for str below
strcpy(regularString, "I am a modifiable string");
char *anotherRegularString = new char[21]; 
strcpy(anotherRegularString, "I am also modifiable");
// Define a const pointer to a string; must be initialized
char *const constPtrString = regularString; // Ok
// You may not modify a const pointer to point elsewhere
// constPtrString = anotherRegularString;  // No! 
// But you may change the data which you point to
strcpy(constPtrString, "I can change the value"); // Yes
```

This is the opposite of the 2. 
Now the pointer is fixed to the memory address first initialized. The value inside that address can be changed.
This is quite similar to reference, except that pointer still need -> to dereference and enter the value, while reference use dot .

### Another example

```cpp
char *const constPtrString = regularString;
is equals to 
char &constPtrString = regularString;

Reference must be with already defined memory block. No reference with malloc. 
const pointer can be malloced.


char *const constPtrTryMalloc = (char *)malloc(10);
strcpy(constPtrTryMalloc,"Test1 Test2");
printf("%s",constPtrTryMalloc);
```

#### Result: Test1 Test2



## 4. - constant pointers to constant objects and constant reference
### Constant Pointer

```cpp
const char *const constStringandPtr = regularString; // Ok 
// Trying to change the pointer or the data is illegal
constStringandPtr = anotherRegularString; // No! Can't modify address                                          
strcpy(constStringandPtr, "Nope"); // No! Can't modify data
```

### Constant Reference 

```cpp
const MyClass& mc;
```
is equals to 
```cpp
const MyClass * const mc; 
```


## 5. Constant function; Place const at the end of function definition
```cpp
void funct() const;
void funct() const { return data_; }
```


This means that the function will not modify the member object. Therefore we only interest in functions inside class/struct here. In other words, methods.
It is meaningless to have const function for normal function that are not member function.

One might see quite confusing function declaration like this

```cpp
const T& data() const { return data_; }
```

It means const reference of type T is the output of the constant member function.

 

