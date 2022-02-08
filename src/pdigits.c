#include <stdio.h>



/**
 * function: ls_digit
 * desc: returns the char for the least significant digit 
 *       of x when x is represented in base "base".
 * precondition:  base <= 10
 *
 * TODO:  modify so that a base as large as 36 can be handled.
 *        The digits/symbols used for a base > 10 will follow
 *        the notation used for hexidecimal representation:
 *
 *          digits 0..9 -> chars '0' ... '9'
 *          digits 10..35 -> chars 'A'...'Z'
 */
static char ls_digit(unsigned int x, unsigned int base) {

    return '0' + (x % base);

}


/**
* function:  pdigitsR
* description:  prints the given unsigned int x
*		in the given base (sometimes called the "radix").
*
*		Precondition:  base value 2..10 is assumed to be
*		in the range 2..10.  Since this is a "helper function"
*		and is expected to be called only by the "wrapper"
*		function pdigits, the checking of this property is 
*		left to the wrapper function.
*		
*		Digits are printed in the "natural" order -- 
*		most-significant digit first.
*
*		This is achieved recursively;  The capital "R" in 
*		the function name reminds the author of this fact, 
*		and also that it is a "helper function" called by a
*		"wrapper function" pdigits.
*	
*		Note that no newline is printed here (but
*		the wrapper function does).
*
*		A good exercise:  extend the allowable values
*		for the radix to be as large as 36.
*
*		Why 36?  Because the idea used in HEX (base-16) can be
*		extended naturally up to base-36 since there are
*		26 letters in the alphabet to work with in addition to
*		the digits 0..9.
*
*		[Recall that HEX uses A-F for "digits" 10-16]
*/
static void pdigitsR(unsigned int x, unsigned int base) {
    char lsd;  // the the least-significant digit of x as a character.

    lsd = ls_digit(x, base);
    if(x < base) {  // only one digit to print
                    //   (base case!)
        putchar(lsd);
    }
    else {
        pdigitsR(x/base, base);
        putchar(lsd);
    }

}

/**
* Function:  pdigits
* Description:  prints x in MSD-to-LSD order according to the
*		given base.
*
*		Only base values in the range 2..10 are supported.
*
*		This is a "wrapper function"; the "real work" is
*		done by pdigitsR.
*/
void pdigits(unsigned int x, unsigned int base) { 

    if(base < 2){
        fprintf(stderr, "error:  pdigits: base %u invalid\n", base);
        return;
    }
    // TODO:  once you have modified ls_digit to allow a base as large as 
    //   36, modify this condition accordingly
    if(base > 10){
        fprintf(stderr, "error:  pdigits: base %u not currently supported\n", base);

        return;
    }

    pdigitsR(x, base);
    putchar('\n');
}

		



  
