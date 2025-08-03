#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int fatorial( int number);
long long int dfs( int* vec, int size );
long long int comb(int n, int k);

long long int modPow(long long int base, long long int exp) { 
    long long int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int numOfWays(int* nums, int numsSize) {
    return (dfs(nums, numsSize) - 1) % MOD;
}

long long int dfs( int* vec, int size ){
    if ( size < 3 )
        return 1;

    int root = vec[0]; 
    int *rightNodes = malloc( sizeof(int) * size );
    int *leftNodes = malloc( sizeof(int) * size );
    int right = 0;
    int left = 0;

    for ( int i = 1; i < size; i++){
        if ( vec[i] > root ){
            rightNodes[right++] = vec[i];
        }else{
            leftNodes[left++] = vec[i];
        }
    }


    long long int leftPath = dfs(leftNodes, left);
    long long int rightPath = dfs(rightNodes, right);

    free(leftNodes);
    free(rightNodes);
    
    return ( ( ( leftPath * rightPath ) % MOD ) * comb(size - 1, left ) ) % MOD ;
}


long long int comb(int n, int k) {
    long long int num = fatorial(n);
    long long int den = (fatorial(k) * fatorial(n - k)) % MOD;
    long long int invDen = modPow(den, MOD - 2);  // aqui
    return (num * invDen) % MOD;
}



// i does not this for nothing in this solution; But maybe in other solutions it can be used
// and the funtion its also wrong
long long int fatorial ( int number ){
    if ( number <= 1 )
        return 1;

    return (fatorial( number -1 ) * number) % MOD;
}

    // IDEAS OF SOLUTIONS

    // the first element dont change! Becouse he is the root.
    // i think thats something with permutation or rotation

    // its not exactly this, but can be part of.
    // how many times i can change the local of the numbers that are greater than my root
    // like, on the size-1, how many different ways i can permutate this numbers.


    // a brute force solution can be "permutating" every number besides the root and then verify;

    // how many times i can permutate the number so...


    // ( (numsSize-1)! / ( amount of number greater than the root ) ) - 1; idk if this make sense, junt an idea


    int main() {
    int nums[] = {3, 4, 5, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = numOfWays(nums, size);

    printf("Número de maneiras diferentes: %d\n", result);
    return 0;
}