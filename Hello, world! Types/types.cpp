
#include <iostream>
#include <iomanip> // std::boolalpha
#include <climits> // INT_MIN, INT_MAX (<limits.h>)
#include <cfloat>  // FLT_MIN, FLT_MAX (<float.h>)
#include <limits>  // std::numeric_limits

int main()
{
    // Variables and constants.

    int intVariable = 1; // 0xA; 054;
    std::cout << "int: " << sizeof(intVariable) << std::endl; // 4 (32) - platform-dependent
    // -2 ^ (N - 1) ... 2 ^ (N - 1) - 1
    // -2147483648 ... 2147483647


    long int longIntVariable = 1L;
    std::cout << "long: " << sizeof(longIntVariable) << std::endl; /* 4 (32)
    -2 ^ (N - 1) ... 2 ^ (N - 1) - 1
    -2147483648 ... 2147483647 */


    long long int longLongIntVariable = 1LL;
    std::cout << "long long: " << sizeof(longLongIntVariable) << std::endl; // 8 (64)           
    // -2 ^ (N - 1) ... 2 ^ (N - 1) - 1
    // -9223372036854775808 ... 9223372036854775807


    short int shortIntVariable = 1;
    std::cout << "short: " << sizeof(shortIntVariable) << std::endl; // 2 (16)
    // -2 ^ (N - 1) ... 2 ^ (N - 1) - 1
    // -32768 ... 32767


    // 1 ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long)


    unsigned int unsignedIntVariable = 1U;
    std::cout << "unsigned: " << sizeof(unsignedIntVariable) << std::endl; // 4 (32)
    // 0 ... 2 ^ N - 1
    // 0 ... 4294967295


    // sizeof(X) ≡ sizeof(signed X) ≡ sizeof(unsigned X)


    // ...


    char charVariable = 'A';
    std::cout << "char: " << sizeof(charVariable) << std::endl; // 1 (8)
    // -2 ^ (N - 1) ... 2 ^ (N - 1) - 1
    // -128 ... 127
    // Or:
    // 0 ... 2 ^ N - 1
    // 0 ... 255


    unsigned char unsignedCharVariable = 'A';
    std::cout << "unsigned char: " << sizeof(unsignedCharVariable) << std::endl; // 1 (8)
    // 0 ... 2 ^ N - 1
    // 0 ... 255


    wchar_t wchar_tVariable = L'A';
    std::cout << "whar_t: " << sizeof(wchar_tVariable) << std::endl; // 2 (16)
    

    // sizeof(char) ≤ sizeof(wchar_t) ≤ sizeof(long)


    bool boolVariable = true; // false
    std::cout << "bool: " << sizeof(boolVariable) << std::endl; // 1 (8)


    float floatVariable = 1.0f; // 1.0F, .5f, 5.7e-3f
    std::cout << "float: " << sizeof(floatVariable) << std::endl; // 4 (32)
    // max ≈ 3,4 × 10^38
    
    
    double doubleVariable = 1.0;
    std::cout << "double: " << sizeof(doubleVariable) << std::endl; // 8 (64)
    // max ≈ 1,8 × 10^308


    long double longDoubleVariable = 1.0L;
    std::cout << "long double: " << sizeof(longDoubleVariable) << std::endl; // 16 (128)


    // sizeof(float) ≤ sizeof(double) ≤ sizeof(long double)


    const int speedOfLight = 299792458; // int const


    // Implicit and explicit typecasting.

    int term1 = 2;
    float term2 = 2.5f;
    float sum = term1 + term2;
    std::cout << "2 + 2.5f = " << sum << std::endl; // 4.5


    signed signedVariable = 320;
    unsigned unsignedVariable = 150u;
    unsigned unsignedResult = signedVariable + unsignedVariable;
    std::cout << "signed + unsigned == signed? "
        << std::boolalpha // <iomanip>
        << std::numeric_limits<decltype(signedVariable + unsignedVariable)>::is_signed << std::endl; // false


    int numerator = 1, denominator = 2;
    // int numerator = 1;
    // int denominator = 2;
    float result = numerator / denominator;
    std::cout << "1 / 2 = " << result << std::endl; // 0

    result = (float)numerator / (float)denominator;
    std::cout << "(float)1 / (float)2 = " << result << std::endl; // 0.5

    result = float(numerator) / float(denominator);
    std::cout << "float(1) / float(2) = " << result << std::endl; // 0.5

    result = static_cast<float>(numerator) / static_cast<float>(denominator);
    std::cout << "static_cast<float>(1) / static_cast<float>(2) = " << result << std::endl; // 0.5


    // Type aliases.

    typedef unsigned int uint;
    uint foo; // unsigned int foo;


    // Limits.

    // <climits>
    std::cout << "min int (C) = " << INT_MIN << std::endl;
    std::cout << "max int (C) = " << INT_MAX << std::endl;
    // <limits>
    std::cout << "min int (C++) = " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "max int (C++) = " << std::numeric_limits<int>::max() << std::endl;

    // <cfloat>
    std::cout << "min float (C) = " << FLT_MIN << std::endl;
    std::cout << "max float (C) = " << FLT_MAX << std::endl;
    // <limits>
    std::cout << "min float (C++) = " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "max float (C++) = " << std::numeric_limits<float>::max() << std::endl;
    

    // 1
    // 00000000 00000000 00000000 00000001

    // 25
    // 00000000 00000000 00000000 00011001

    // 2147483647
    // 01111111 11111111 11111111 11111111

    // -1
    // 00000000 00000000 00000000 00000001 - unsigned value
    // 11111111 11111111 11111111 11111110 - inverted bits
    // 11111111 11111111 11111111 11111111 - 2’s complement

    // -25
    // 00000000 00000000 00000000 00011001
    // 11111111 11111111 11111111 11100110
    // 11111111 11111111 11111111 11100111

    // -2147483648
    // 10000000 00000000 00000000 00000000
    // 01111111 11111111 11111111 11111111
    // 10000000 00000000 00000000 00000000


    // 7 + (-5) = 2
    
    // 00000000 00000000 00000000 00000111 = 7

    // 00000000 00000000 00000000 00000101
    // 11111111 11111111 11111111 11111010
    // 11111111 11111111 11111111 11111011 = -5

    // 00000000 00000000 00000000 00000111 = 7
    //+11111111 11111111 11111111 11111011 = -5
    // -----------------------------------
    // 00000000 00000000 00000000 00000010 = 2


    // unsigned
    // 4294967295 = 2 ^ 32 - 1
    // 11111111 11111111 11111111 11111111

    // 2147483648 = 2 ^ 31
    // 10000000 00000000 00000000 00000000

    return 0;
}
