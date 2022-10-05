/* 
 * author : Atul Bharadwaj
 * 
 * bits.c - Source file
 *
 */


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
