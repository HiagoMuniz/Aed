int fatorial( int number);
long long int dfs( int* vec, int size );

int numOfWays(int* nums, int numsSize) {

    // implement the pascal triangle right here;
    int** lines = malloc( sizeof( *int ) * numsSize );
    for ( int i = 0; i < lines; i++){
        line[i] = malloc( sizeof(int) * i + 1); // i dont remember how to dynamic alloc an array of arrays
    }



    return (dfs(nums, numsSize) - 1) % (1000000007);
}

long long int dfs( int* vec, int size ){
    if ( size < 3 )
        return 1;

    int root = vec[0]; 
    int mid = (size - 1) / 2;
    int *rightNodes = malloc( sizeof(int) * (mid +1) );
    int *leftNodes = malloc( sizeof(int) * (mid +1) );
    int right = 0;
    int left = 0;

    for ( int i = 1; i < size; i++){
        if ( nums[i] > nums[0]){
            rightNodes[right++] = nums[i];
        }else{
            leftNodes[left++] = nums[i];
        }
    }


    long long int leftPath = dfs(leftNodes, left);
    long long int rightPath = dfs(rightNodes, right);

    return ( leftPath * rightPath ) *  ; // multiply her to the matrix[size -1][left];

}

// i does not this for nothing in this solution; But maybe in other solutions it can be used
// and the funtion its also wrong
int fatorial( int number){
    if ( number == 1 )
        return number;

    return fatorial( number -1 ) * number;
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