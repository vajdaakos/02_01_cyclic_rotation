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
    res.N = N;
    if(N==K || K==0 || N == 0)
    {
        res.A = (int*)malloc( N* sizeof(int));
        memcpy(res.A,A,N*sizeof(int));
    }
    else
    {
        res.A = (int*)malloc( N* sizeof(int));

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

//This solutioin won't pass codility check, because it is changing the original array!
struct Results solution2(int A[], int N, int K)
{
    struct Results res;
    res.N = N;
    res.A = A;
    if(!(N==K || K==0 || N == 0))
    {
        int realrotation = K%N;
        int not_overflows = N-realrotation;
        int overflow_array[100];

        memcpy(overflow_array,A+not_overflows,realrotation*sizeof(int));
        memcpy(res.A+(realrotation),A,not_overflows*sizeof(int));
        memcpy(res.A,overflow_array,realrotation*sizeof(int));
    }
    return res;
}



void setUp(void) 
{
    printf("\nUnity Test started.\n");
}

void tearDown(void) 
{
    printf("\nUnity Test ended.\n");
}
void ciclic_rotation(void) {

    //1 rotation
    int in1[]  = {3, 8, 9, 7, 6};
    int exp1[] = {6, 3, 8, 9, 7};

    struct Results res1_1 = solution(in1, 5, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp1, res1_1.A,5);
    free(res1_1.A);
   
    struct Results res2_1 = solution2(in1, 5, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp1, res2_1.A,5);

    //2 rotations
    int in2[]  = {3, 8, 9, 7, 6};
    int exp2[] = {7, 6, 3, 8, 9};

    struct Results res1_2 = solution(in2, 5, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp2, res1_2.A,5);
    free(res1_2.A);

    struct Results res2_2 = solution2(in2, 5, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp2, res2_2.A,5);

    //3 rotations
    int in3[]  = {3, 8, 9, 7, 6};
    int exp3[] = {9, 7, 6, 3, 8};

    struct Results res1_3 = solution(in3, 5, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp3, res1_3.A,5);
    free(res1_3.A);

    struct Results res2_3 = solution2(in3, 5, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp3, res2_3.A,5);

    //4 rotations
    int in4[]  = {3, 8, 9, 7, 6};
    int exp4[] = {8, 9, 7, 6, 3};

    struct Results res1_4 = solution(in4, 5, 4);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp4, res1_4.A,5);
    free(res1_4.A);

    struct Results res2_4 = solution2(in4, 5, 4);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp4, res2_4.A,5);

    //5 rotations
    int in5[]  = {3, 8, 9, 7, 6};
    int exp5[] = {3, 8, 9, 7, 6};

    struct Results res1_5 = solution(in5, 5, 5);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp5, res1_5.A,5);
    free(res1_5.A);

    struct Results res2_5 = solution2(in5, 5, 5);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp5, res2_5.A,5);

    //6 rotation
    int in6[]  = {3, 8, 9, 7, 6};
    int exp6[] = {6, 3, 8, 9, 7};
    struct Results res1_6 = solution(in6, 5, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp6, res1_6.A,5);;
    free(res1_6.A);

    struct Results res2_6 = solution2(in6, 5, 6);
    TEST_ASSERT_EQUAL_INT_ARRAY( exp6, res2_6.A,5);

}



int main()
{

    UNITY_BEGIN();
    RUN_TEST(ciclic_rotation);
    return UNITY_END();
}
