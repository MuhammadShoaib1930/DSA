#include <iostream>
#include <vector>
using namespace std;
/**
 * The function determines whether a given number is even or odd.
 *
 * @param a The parameter "a" is an integer representing the number to be checked for evenness or
 * oddness.
 */
void evenOdd(int a)
{
    if (a & 1 == 1)
        cout << "The given number " << a << " is Odd. " << endl;
    else
        cout << "The given number " << a << " is Even. " << endl;
}
/**
 * The swap function uses bitwise XOR operations to swap the values of two integers.
 *
 * @param a The first parameter is a reference to an integer variable named "a".
 * @param b The above code snippet defines a function named "swap" that takes two integer parameters,
 * "a" and "b". The function swaps the values of "a" and "b" using bitwise XOR operations.
 */
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
/**
 * The function "findBit" checks the value of a specific bit position in an integer.
 *
 * @param a The variable "a" represents the number for which we want to find the value of a specific
 * bit.
 * @param pos The "pos" parameter represents the position of the bit that we want to find in the number
 * "a".
 */
void findBit(int a, int pos)
{
    int bitmask = a >> pos;
    if ((bitmask & 1) == 1)
        cout << "The " << pos << " bit of " << a << " is 1." << endl;
    else
        cout << "The " << pos << " bit of " << a << " is 0." << endl;
}
/**
 * The function sets a specific bit at a given position in an integer and prints the result.
 *
 * @param a The variable "a" represents the number on which the bit is to be set.
 * @param pos The "pos" parameter represents the position of the bit that needs to be set in the
 * integer "a".
 */
void setbit(int a, int pos)
{
    int masking = 1 << pos;
    masking = masking | a;
    cout << "The " << pos << " bit set of " << masking << "." << endl;
}
/**
 * The clearBit function clears a specific bit at a given position in an integer.
 *
 * @param a The variable "a" represents the number from which we want to clear a specific bit.
 * @param pos The "pos" parameter represents the position of the bit that needs to be cleared in the
 * integer "a".
 */
void clearBit(int a, int pos)
{
    int masking = 1 << pos;
    masking = masking ^ a;
    cout << "The " << pos << " bit clear of " << masking << "." << endl;
}
/**
 * The above code contains two functions, one to change a specific bit in an integer and another to
 * count the number of set bits in an integer.
 *
 * @param a The parameter "a" represents an integer value.
 * @param pos The "pos" parameter in the "changeBitSetClear" function represents the position of the
 * bit that needs to be changed in the integer "a". It is used to determine whether the bit should be
 * set or cleared.
 */
void changeBitSetClear(int a, int pos)
{
    int masking = a >> pos;
    if ((masking & 1) == 1)
        clearBit(a, pos);
    else
        setbit(a, pos);
}
/**
 * The function calculates the number of set bits in a given integer.
 *
 * @param a The parameter "a" is an integer value for which we want to count the number of set bits.
 *
 * @return the count of set bits in the input integer 'a'.
 */
int totalSetBit(int a)
{
    int masking = a;
    int cont = 0;
    while (masking != 0)
    {
        if (masking & 1 == 1)
        {
            cont++;
        }
        masking = masking >> 1;
    }
    cout << "The set bit of " << a << " is " << cont << ".\n";
    return cont;
}
/**
 * The function "changeBit" returns the number of bits that need to be changed in order to convert
 * integer a to integer b.
 *
 * @param a An integer value representing the first number.
 * @param b The parameter "b" is an integer value.
 *
 * @return the total number of set bits in the result of performing a bitwise XOR operation between the
 * integers a and b.
 */
int changeBit(int a, int b)
{
    return totalSetBit(a ^ b);
}
/**
 * The function calculates the number of set bits in the binary representation of a given integer.
 *
 * @param n The parameter "n" is an integer value that represents the number for which we want to
 * calculate the number of set bits (i.e., the number of 1s) in its binary representation.
 *
 * @return the number of set bits (or 1s) in the binary representation of the input number 'n'.
 */
int formula(int n)
{
    int cont = 0;
    int masking = n;
    while (masking >= 1)
    {
        cont++;
        masking = masking & (masking - 1);
    }
    return cont;
}
/**
 * The function "findNonRepeated" takes in a vector of integers and returns the non-repeated element in
 * the vector using the XOR operation.
 *
 * @param arr A vector of integers containing the elements to be checked for non-repeated values.
 *
 * @return the non-repeated element in the given vector.
 */
int findNonRepeated(vector<int> arr)
{
    int result = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
        cout << i << " , ";
    }
    cout << endl;
    return result;
}
/**
 * The function finds two non-repeated numbers in an array using bitwise XOR operations.
 *
 * @param arr The arr parameter is a vector of integers that contains the elements of the array.
 * @param n The parameter `n` represents the size of the input array `arr`.
 */
void findTwoNonRepeated(vector<int> arr, int n)
{
    int allXor = 0;
    for (int i = 0; i < n; i++)
    {
        allXor = allXor ^ arr[i];
    }
    int pos = 0;
    int temp = allXor;
    while (!(temp & 1))
    {
        temp = temp >> 1;
        pos++;
    }
    int a = allXor;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >> pos == 1)
            a = a ^ arr[i];
    }
    int b = allXor ^ a;
    cout << a << " " << b;
}
// int findNonRepeatedTimes(vector<int> arr, int K = 0)
// {
//     return 0;
// }
/**
 * The factorial function calculates the factorial of a given number, but returns 0 if the number is
 * greater than or equal to 13.
 *
 * @param n The parameter `n` in the `factorial` function represents the number for which we want to
 * calculate the factorial.
 *
 * @return the factorial of the input number 'n'.
 */
int factorial(int n)
{
    if (n >= 13)
        return 0;
    int res = 1;
    for (int i = n; i > 0 && i != 0; i--)
    {
        res *= i;
    }
    return res;
}
/**
 * The function calculates the number of trailing zeros in the factorial of a given number.
 *
 * @param n The parameter "n" represents the number for which we want to calculate the number of
 * trailing zeros in its factorial.
 *
 * @return the number of trailing zeros in the factorial of the given number 'n'.
 */
int trailingZerosFactorial(int n)
{
    int result = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        result += n / i;
    }
    return result;
}
/**
 * The function checks if a given number is a palindrome or not.
 *
 * @param n The parameter "n" is an integer representing the number to check for palindrome.
 *
 * @return The function isPalindromeNumber returns a boolean value. It returns true if the given number
 * is a palindrome, and false otherwise.
 */
bool isPalindromeNumber(int n)
{
    int temp = n;
    int reversNumber = 0;
    while (temp > 0)
    {
        if (reversNumber == 0)
            reversNumber = (temp % 10);
        else
            reversNumber = (reversNumber * 10) + (temp % 10);
        temp /= 10;
    }
    if (reversNumber == n)
        return true;
    else
        return false;
}
/**
 * The function uses the Sieve of Eratosthenes algorithm to generate a vector of boolean values
 * indicating whether each number up to n is prime or not.
 *
 * @param n The parameter `n` represents the upper limit of the range for which we want to find prime
 * numbers.
 *
 * @return The function `sieveOfEratoSthenes` returns a vector of boolean values. Each element in the
 * vector represents whether the corresponding index is a prime number or not.
 */
vector<bool> sieveOfEratoSthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    return isPrime;
}
/**
 * The above function calculates the greatest common divisor (GCD) of two numbers using recursion.
 *
 * @param a The first number for which we want to find the greatest common divisor (GCD).
 * @param b The parameter "b" represents the second number for which we want to find the greatest
 * common divisor (GCD).
 *
 * @return the greatest common divisor (GCD) of the two input integers, 'a' and 'b'.
 */
int gcd(int a, int b)
{
    // GCD and HCF both same
    return (a % b == 0) ? b : gcd(b, a % b);
}
/**
 * The function "fastPower" calculates the result of raising a number "a" to the power of "b" using a
 * fast exponentiation algorithm.
 *
 * @param a The base number, which will be raised to the power of b.
 * @param b The parameter "b" represents the exponent to which "a" is raised.
 *
 * @return the result of raising the number 'a' to the power of 'b'.
 */
int fastPower(int a, int b)
{
    // Modulo arithmetics
    int res = 1;
    while (b > 0)
    {
        if (b & 1 != 0)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}
/**
 * The function "fastPower" calculates the result of raising a number "a" to the power of "b" modulo
 * "n" efficiently.
 *
 * @param a The base number.
 * @param b The parameter "b" represents the exponent in the power operation.
 * @param n The parameter `n` represents the modulus. It is used in modulo arithmetic to calculate the
 * remainder of a division operation. In this case, it is used to calculate the remainder of the
 * intermediate results during the exponentiation process.
 *
 * @return the result of the fast power calculation, which is stored in the variable "res".
 */
long fastPower(long a, long b, long n)
{
    // Modulo arithmetics
    long res = 1;
    while (b > 0)
    {
        if ((b & 1) != 0)
            res = (res * a % b) % n;
        a = (a % n * a % n) % n;
        b = b >> 1;
        cout << "hi ";
    }
    return res;
}
/**
 * The function calculates the sum of natural numbers up to a given number using recursion.
 *
 * @param n The parameter "n" represents the number up to which we want to find the sum of natural
 * numbers.
 *
 * @return the sum of natural numbers up to the given number 'n'.
 */
int sumOfNaturalNo(int n)
{
    // Three steps of recursion
    // 1, Find the base case
    // 2, Find the relation between the problem and subproblem
    // 3, Generalize the relation
    return (n <= 0) ? 0 : n + sumOfNaturalNo(n - 1);
}
// Find the number of ways in mXn matrix.
/**
 * The function calculates the number of ways to reach the bottom-right cell of a matrix of size m x n,
 * moving only right or down.
 *
 * @param m The number of rows in the matrix.
 * @param n The number of rows in the matrix.
 *
 * @return the number of ways to reach the bottom-right cell of a matrix of size m x n, starting from
 * the top-left cell.
 */
int numberWaysMatrix(int m, int n)
{
    return (m == 1 || n == 1) ? 1 : numberWaysMatrix(m - 1, n) + numberWaysMatrix(m, n - 1);
}
/**
 * The function "jos" implements the Josephus problem, which determines the position of the last person
 * remaining after repeatedly eliminating every k-th person in a circle of n people.
 *
 * @param n The parameter "n" represents the number of people in the circle.
 * @param k The parameter "k" represents the step size or the number of people to be skipped in the
 * game.
 *
 * @return the position of the last remaining person in a Josephus problem.
 */
int jos(int n, int k)
{
    return (n == 1) ? 0 : (jos(n - 1, k) + k) % n;
}
/**
 * The function checks if a given string is a palindrome by recursively comparing characters from the
 * start and end of the string.
 *
 * @param s The string that we want to check if it is a palindrome.
 * @param l The parameter "l" represents the left index of the substring being checked for palindrome.
 * @param r The parameter "r" represents the right index of the substring being checked for palindrome.
 *
 * @return The function isPalindromeString returns a boolean value.
 */
bool isPalindromeString(string s, int l, int r)
{
    if (l >= r)
        return true;
    if (s[l] != s[r])
        return false;
    return isPalindromeString(s, l + 1, r - 1);
}
int main()
{
    return 0;
}