         REPORT      PESCSE1201801475


INTRODUCTION:

1)Intal can be defined as array of of a large integer where the each individual digit is stored as character in array
2)Integer is generally supported by variables but Intal is allocated by using character array
 The different data types supported in C are:-
	Integer,float,Double,Long int/short int

3)Major applications of intal are
-Large numbers can de dealt easily
-operations can be done with large integers which can't be holded by any data types in C




IMPLEMENTATION:

char* intal_add(const char* intal1, const char* intal2):-In this function ,2 arrays are taken and are reversed  then last digits are iterately added keeping the carry factor later returing added character array

int intal_compare(const char* intal1, const char* intal2):-In this function,we first compare string lengths even if they are same they check individual digits

char* intal_diff(const char* intal1, const char* intal2):-In this function the 2 arrays are taken and are reversed, then last digits are iterately subtracted  keeping the carry factor later returning added character array

char* intal_multiply(const char* intal1, const char* intal2):-In this function the approach is to take each digit of multiplier multiply with multiplicand using nested for loop and return required character array 

char* intal_mod(const char* intal1, const char* intal2):-In this function the approach is to bring the value of intal2 as close as to intal1 then recursively substract the same and later return the required array

char* intal_pow(const char* intal1, unsigned int n):-In this function the approach is to create a array with value 1 and until n is finished in while loop multiply every time with the intal1 and later return the required array

char* intal_gcd(const char* intal1, const char* intal2):-In this function the approach is to follow euclidean algorithm where mod is found out by above approach given untill one of number becomes zero

char* intal_fibonacci(unsigned int n):-In this function the approach is to initial create 2 arrays with values 0 and 1 so that they are the first two fibonacci numbers later until n is in while loop adding and updating intial 2 values 

char* intal_factorial(unsigned int n):-In this function the approach is recursive, where unitll n becomes 1 it keeps on calling funtions and calculation of n*(n-1)*.. 

char* intal_bincoeff(unsigned int n, unsigned int k):-In this function the approach is we create a array of size of product of 2 coeeficient of binomial so that we can store all corresponding values 

int intal_max(char **arr, int n):-In this function the approach is to make a pointer pointing to initil array and a index variabe  and iterating from index 1 to last and if a array bigger is found pointer and index variable is updated.

int intal_min(char **arr, int n):-In this function the approach is to make a pointer pointing to initil array and a index variabe  and iterating from index 1 to last and if a array bigger is found pointer and index variable is updated

int intal_search(char **arr, int n, char* key):- O(n) In this function the approach is ,the key is compared with every large array. if the key is found that index is returned else -1 is returned.

int intal_binsearch(char **arr, int n, char* key):-O(logn) In this function the approach is ,array is sorted and we find key in 2 halfs of arrays recursively.if found index is returned else -1 is returned.

void intal_sort(char **arr, int n):-In this function the approach is using merge sort to sort half and half arrays then merging them together recursively.later the old array is copied to new created sorted array

char* coin_row_problem(char **arr, int n):-In this function ,the approach is to use Dynamic programming 


FUTURE WORK:
1)More functions which could have been added is sorting in decreasing order,square root.

2)If no restriction then these could be used in every basic operation on all types.
