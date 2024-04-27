# OOP with C++ (and more)
#### Spring, 2023
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 1

### Due: 11:59 p.m., 8 March 2023 WED

### Purpose of this assignment:

Practice for the basic functions and unit tests.

### Problems:
You have learned how to write unit tests and simple functions. For this assignment, you have to write and test some more basic functions for vector!

Please implement the following functions:

- inner_product()
- is_zero_vector()
- vector_length()

You've practiced `inner_product` in the class, please implement it and write the unit tests.

The function `is_zero_vector` should return `true` if all elements in the input vector are 0, otherwise return `false`. 

The function `vector_length` should return vector length in double, the formula of vector length is:

![](./formula.png)

You can use the `sqrt` method in `<cmath>` library.
https://cplusplus.com/reference/cmath/sqrt/

**score:**
- Implement of function:  
    1. inner_product   ( 5% )  
    1. is_zero_vector  ( 10% ) 
    1. vector_length   ( 10% ) 
- Unit tests:
    - inner_product
        1. 2-dimension vector dot 2-dimension vector ( 5% )
        1. Invalid Dimension input should throw exception ( 5% )
    - is_zero_vector
        1. test 2-dimension zero vector ( 5% )
        1. test 2-dimension non-zero vector ( 5% )
        1. Invalid Dimension input should throw exception ( 5% )
    - vector_length
        1. test 2-dimension vector length ( 5% )
        1. Invalid Dimension input should throw exception ( 5% )
- TA's tests ( 40% )  

***Note:***
- Functions should throw exception when dimension is less than 0 or equal to 0.
- You may use `ASSERT_EQ`, `ASSERT_NEAR`, and `ASSERT_ANY_THROW` to verify the functions.
- Please implement the code reasonbly.

