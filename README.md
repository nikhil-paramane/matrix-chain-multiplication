# matrix-chain-multiplication
Matrix chain multiplication is an an optimization problem that can be solved using dynamic programming. Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. 
The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.

There are many options because matrix multiplication is associative. In other words, no matter how the product is parenthesized, the result obtained will remain the same. For example, for four matrices A, B, C, and D, we would have:

    ((AB)C)D = (A(BC))D = (AB)(CD) = A((BC)D) = A(B(CD)).

However, the order in which the product is parenthesized affects the number of simple arithmetic operations needed to compute the product, that is the computational complexity. For example, if A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix, then

    computing (AB)C needs (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations, while
    computing A(BC) needs (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
    
    more info: https://en.wikipedia.org/wiki/Matrix_chain_multiplication
    
