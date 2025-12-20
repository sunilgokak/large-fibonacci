📘 Fibonacci Calculator with Arbitrary Precision (C)

Author: Sunil Gokak
Language: C
Purpose:
This project computes large Fibonacci numbers using custom arbitrary-precision arithmetic, memoization (caching), and overflow detection.

🔍 Overview

Standard C data types (int, long long) overflow quickly for large Fibonacci numbers.
This program overcomes that limitation by:

Representing numbers as arrays of digits

Splitting numbers into MSB and LSB segments

Using manual addition with carry

Implementing memoization for fast Fibonacci computation

It can compute very large Fibonacci values such as fib(615).

🧱 Key Features

✅ Arbitrary-precision integer arithmetic

✅ Recursive Fibonacci with caching

✅ Overflow detection

✅ Efficient digit-by-digit addition

✅ Clear separation of MSB and LSB storage

🧩 Data Structures
ULONG_LONG

Represents a large integer using two digit arrays.

typedef struct ULONG_LONG {
    unsigned long long msb[MAX_DIGITS];
    unsigned long long lsb[MAX_DIGITS];
    bool flag;
} ULONG_LONG;

Field	Description
msb	Most significant digits
lsb	Least significant digits
flag	Cache validity flag
⚙️ Constants
#define MAX 1000
#define MAX_DIGITS 64

Constant	Description
MAX	Maximum Fibonacci cache size
MAX_DIGITS	Digits per MSB/LSB segment
🧠 Cache Mechanism
static ULONG_LONG cache[MAX];


Stores previously computed Fibonacci values

Avoids repeated calculations

Improves performance from exponential → linear

➕ Arbitrary Precision Addition
plus()

Adds two large numbers digit-by-digit.

bool plus(ULONG_LONG *x1, ULONG_LONG *x2, ULONG_LONG *xans);


Returns:

TRUE → Addition successful

FALSE → Overflow detected

Process:

Add LSB digits with carry

Continue into MSB

Detect overflow via final carry

🗃️ Cache Lookup
in_cache()
bool in_cache(int n, ULONG_LONG *xans);


Checks if fib(n) already exists

Copies cached value if found

🔢 Number Conversion (Output)
convert_msb_to_number()

Prints the most significant digits (skipping leading zeros)

convert_lsb_to_number()

Prints the least significant digits

Together they reconstruct the full Fibonacci number.

🔁 Fibonacci Implementation
fib()
ULONG_LONG fib(int n, bool *status);


Logic:

Base case: fib(1) = 1

Recursive case:
fib(n) = fib(n-1) + fib(n-2)

Uses caching to prevent recomputation

Detects overflow via status

🚀 Program Flow
main()
 └── fib(615)
      ├── cache lookup
      ├── recursive calls
      ├── arbitrary precision addition
      └── cache storage
 └── print result

▶️ How to Compile & Run
gcc fibonacci.c -o fibonacci
./fibonacci

🧪 Sample Output (Truncated)
Cache Miss:: Addition successful. Answer fib(6) Added to cache
Cache Miss:: Addition successful. Answer fib(7) Added to cache
...
