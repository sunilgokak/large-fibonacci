/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

/* Author Sunil Gokak */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 1000
#define MAX_DIGITS 64

typedef enum { FALSE, TRUE } bool;
typedef struct ULONG_LONG {
    unsigned long long msb[MAX_DIGITS];
    unsigned long long lsb[MAX_DIGITS];
    bool flag;
} ULONG_LONG;

static ULONG_LONG cache[MAX] = {0};

 bool plus(ULONG_LONG *x1, ULONG_LONG *x2, ULONG_LONG *xans)
 {
     int i = 0;
     int sum = 0, carry = 0;
     bool status = FALSE;
     for (i=0; i < MAX_DIGITS; i++)
     {
         sum = (x1->lsb[i] + x2->lsb[i] + carry) % 10 ;
         carry = (x1->lsb[i] + x2->lsb[i] + carry) / 10;
         xans->lsb[i] = sum;
     }

    for (i=0; i < MAX_DIGITS; i++)
     {
         sum = (x1->msb[i] + x2->msb[i] + carry) % 10 ;
         carry = (x1->msb[i] + x2->msb[i] + carry) / 10;
         xans->msb[i] = sum;
     }
     

     if (carry != 1) {
         status = TRUE;
     }
     return (status);
 }
 
bool in_cache(int n, ULONG_LONG *xans)
{
    bool status  = TRUE;
    if ((n < MAX) && (cache[n].flag == 1)) {
        *xans = cache[n];
   } else {
       status = FALSE;
   }
   return status;
}


void convert_msb_to_number(ULONG_LONG *xans)
{
    int i = 0;
    
    bool num_has_started = FALSE;
    for (i = MAX_DIGITS -1  ; i >= 0; i--)
    {
        if (xans->msb[i] != 0 ) {
            num_has_started = TRUE;
        }

        if (!num_has_started &&  xans->msb[i] == 0 ) {
            continue;
        }
        printf("%u", xans->msb[i]);
    }
}

void convert_lsb_to_number(ULONG_LONG *xans)
{
    int i = 0;
    bool num_has_started = FALSE;
    for (i = MAX_DIGITS -1  ; i >= 0; i--)
    {
        if (xans->lsb[i] != 0 ) {
            num_has_started = TRUE;
        }

        if (!num_has_started &&  xans->lsb[i] == 0 ) {
            continue;
        }
        printf("%u", xans->lsb[i]);
    }
}




ULONG_LONG  fib(int n, bool *status)
{
 ULONG_LONG xans = {0};
 ULONG_LONG x1 = {0};
 ULONG_LONG x2 = {0};
 if (n ==1) {
      xans.lsb[0] = 1;
    } else  if (n > 1) {
        if (!in_cache(n, &xans)) { 
          // ans = fib(n-2) + fib(n-1);
         x2 = fib(n-2, status);
         x1 = fib(n-1, status);
         *status = plus(&x2, &x1, &xans);
    
         if (*status) {
            cache[n] = xans;
            cache[n].flag = 1;
            printf("\n Cache Miss:: Addition successful. Answer fib(%u) Added to cache", n);
        } else {
            printf("\n Cache Miss:: Addition overflowed at level %u. Error flag updated in answer", n);
        }
    } else {
        xans = cache[n];
        printf("\n fib(%u) Found In cache", n);
    }
 } 
 return xans;
}

int main()
{
    bool status = FALSE;
    ULONG_LONG xans;
    memset(cache, 0, MAX*sizeof(ULONG_LONG));
    int n = 6, i = 0;
    xans = fib(615, &status );
    if (status == TRUE) {
        convert_msb_to_number(&xans);
        convert_lsb_to_number(&xans);
    } else {
        printf("\noverflowed\n");
    }
    return 0;
}
