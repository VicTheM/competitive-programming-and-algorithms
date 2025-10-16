#include "../all.h"

/*
DATA STRUCTURE
---------------

We will use a linked list structure to represent snowflakes 
that has likelyhood of being he same. store all the different linked
list in an array and compare only between snowflakes in a linked list 

ALGORITHM
----------------
1. Get the snowflakes from standard input
2. Pass them to a hashing function
3. Insert into an array based on the hashcode, if collission append to the linked list
4. Iterate through array and compare snowflakes in same bucket
5. Print appopraite statement and finish
*/

#define MAX_SNOW 100000
#define SNOW_SIZE 6

/**
 * snowflake_node: linked list structure of a snow
 * @snow: the snowflake
 * @next: pointer to another snowflake node
 */
typedef struct snowflake_node {
    int snow[SNOW_SIZE];
    struct snowflake_node* next;
} snowflake_node;


/**
 * sumCode: Hash function for snowflakes.
 * @snow: list of ints containing snow integers
 * @len: Size of snow
 * Description: It computes the sum, since snowflake of
 * same sum code is possible to be identical. this takes into
 * acount the number of MAX_SNOW array
 * 
 * Return: The hashcode
 */
int sumCode(int snow[], int len) {
    return ((snow[0] + snow[1] + snow[2] + snow[3] \
    + snow[4] + snow[5]) % MAX_SNOW);
}

/**
 * compare_right: compare snowflakes rightwards
 */
int compare_right(snowflake_node *s1, snowflake_node* s2) {
    int fail;
    for (int start = 0; start < SNOW_SIZE; start++) {
        fail = 0;
        for (int offset = 0; offset < SNOW_SIZE; offset++) {
            if (s1->snow[offset] != s2->snow[(start+offset) % SNOW_SIZE]) {
                fail = 1;
                break;
            }
        }
        if (fail == 0) {
            return (1);
        }
    }

    return 0;
}

int compare_left(snowflake_node *s1, snowflake_node* s2) {
    int fail;
    int idx;
    for (int start = 0; start < SNOW_SIZE; start++) {
        fail = 0;
        for (int offset = 0; offset < SNOW_SIZE; offset++) {
            idx = start - offset;
            if (idx < 0) {
                idx += SNOW_SIZE;
            }
            if (s1->snow[offset] != s2->snow[idx]) {
                fail = 1;
                break;
            }
        }
        if (fail == 0) {
            return (1);
        }
    }
    return (0);
}

void compare_flakes(snowflake_node* bucket[], int len) {
    snowflake_node *s1, *s2;
    for (int i = 0; i < len; i++) {
        s1 = bucket[i];
        // printf("comparing flakes...\n");
        while(s1 != NULL) {
            s2 = s1->next;
            while (s2 != NULL) {
                if(compare_right(s1, s2) == 1 || compare_left(s1, s2) == 1) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                s2 = s2->next;
            }
            s1 = s1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
}


int main(void) {
    static snowflake_node* buckets[MAX_SNOW] = {NULL};
    snowflake_node* snow;
    int n, m, code;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        /* Create snowflakes*/
        snow = malloc(sizeof(snowflake_node));
        for (int j = 0; j < SNOW_SIZE; j++) {
            scanf("%d", &snow->snow[j]);
        }

        /* Arrange snowflake into appopraite bucket*/
        code = sumCode(snow->snow, SNOW_SIZE);
        snow->next = buckets[code];
        buckets[code] = snow;
    }

    /* Compare and find snow flakes identicals */
    compare_flakes(buckets, MAX_SNOW);
    return 0;
}