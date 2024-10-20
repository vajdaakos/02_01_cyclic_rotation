#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unity.h"

struct Results {
  int * A;
  int N; // Length of the array
};


struct Results solution(int A[], int N, int K)
{
    struct Results res;
    if(N == 0)
    {
        res.A = NULL;
        res.N = 0;
    }
    else
    {
        res.A = (int*)malloc( N* sizeof(int));
        res.N = N;
        int realrotation = K%N;
        int not_overflows = N-realrotation;
        int* overflow_array = malloc(realrotation*sizeof(int));

        memcpy(overflow_array,A+not_overflows,realrotation*sizeof(int));
        memcpy(res.A+(realrotation),A,not_overflows*sizeof(int));
        memcpy(res.A,overflow_array,realrotation*sizeof(int));
        free(overflow_array);
    }
    return res;

}



void setUp(void) 
{
    printf("Unity Test started. %d\n", 19%5);
}

void tearDown(void) 
{
    printf("Unity Test ended.\n");
}
void ciclic_rotation(void) {
    int exp[] = {9, 7, 6, 3, 8};
    int in[]  = {3, 8, 9, 7, 6};
    struct Results res = solution(in, 5, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp, res.A,5);
    free(res.A);
}



int main()
{

    UNITY_BEGIN();
    //RUN_TEST(binary_gap_test);
    RUN_TEST(ciclic_rotation);
    return UNITY_END();
}
