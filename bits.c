/* 
 * CS:APP Data Lab 
 * 
 * Atul Bharadwaj (atulnm2002)
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

//
//On my honor:
//- I have not discussed the C language code in my program with
//anyone other than my instructor or the teaching assistants
//assigned to this course.
//- I have not used C language code obtained from another student,
//or any other unauthorized source, either modified or unmodified.
//- If any C language code or documentation used in my program
//was obtained from an authorized source, such as a text book or
//course notes, that has been clearly noted with a proper citation
//in the comments of my program.
//- I have not designed this program in such a way as to defeat or
//interfere with the normal operation of the Curator System.
// Atul Bharadwaj (atulnm2002)
//

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 * 	 Logic:
 * 		To check bitXor we need to know the Xor gate which takes in two
 *      values and gives output. The output is 1 when there is an odd 
 *      number of trues in the input and the output is 0 when there is 
 *      an even number of trues in the input. 
 *      When we do x and y if one of them is false, x and y is false. For
 *      example 4 is true and 5 is false, so 4 & 5 is false. ~(4 & 5)
 * 		is true. ~4 is false, ~5 is true. So ~4 & ~5 is false. ~(~4 & ~5)
 * 		is true. Now ~(x & y) & ~(~x & ~y) = ~(4 & 5) & ~(~4 & ~5) = 
 * 		true & true = true = 1. Hence we get the desired output.
 */
int bitXor(int x, int y) {
  return ~(x & y) & ~(~x & ~y);
}
//2
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 * 	 Logic:
 * 		x^y represents x xor y. First we put x and y through an xor gate
 * 		to check whether they have even number or odd number of true. For
 * 		example, if x = y, we get ~(x & x) & ~(~x & ~x) = ~x & x = 0.
 * 		After getting that we flip the answer to tell that 1 means that 
 * 		x is equal to y.
 */
int isEqual(int x, int y) {
  return !(x^y);
}
//3
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 * 	 Logic:
 * 		We first create a mask 'a' which stores FF and then we shift it 
 * 		down by n bytes. After we shift it down, we shift down 'c' which
 * 		is the integer that we replace. We shift c by n bytes. Then we take
 * 		the updated mask. First we not it (~) and then we and it (&) with x.
 * 		After that we or it (|) with c since we need to change all the 
 * 		bits in the nth byte as zero. Then we return a.	
 */
int replaceByte(int x, int n, int c) {
  int a = 0xFF << (n << 3);
  c = c << (n << 3);
  a = ((x & ~a)|c);
  return a;
}
//4
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 * 	 Logic:
 * 		I divided the problem into three main parts. Firstly we need the
 * 		2's complement of x to get the negative of x. To do that we simply
 * 		do ~x + 1. Now we OR x with its two's complement. After we do 
 * 		that we shift all the bits to the right by 31 since an integer is
 * 		32 bits. We then get the first bit at the end. This tells us if 
 * 		the number would be 0 or 1. To confirm this we finally & the 
 * 		number with 1. If the number was 1 then it returns 1. Otherwise,
 * 		it returns 0.
 */
int isNonZero(int x) {
	int a = ~x + 1;
	a = (x|a) >> 31;
    return a & 1;
}
