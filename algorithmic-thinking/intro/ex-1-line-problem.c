#include "../all.h"
#define MAX_LINES 100

/**
 * shortest_line: The line array
 * @n: size of shortest line
 * 
 * Return: Index of the shortest line
 */
// int shortest_line(int lines[], int n) {
//     int j;
//     int shortest = 0;
//     for (j = 1; j < n; j++) {
//         if (lines[shortest] > lines[j]) {
//             shortest = j;
//         }
//     }
//     return shortest;
// }


/**
 * allocatePeople: arranges @m people into @n lines
 * @lines: An array of the number of people in each line
 * @n: NUmber of different lines of people
 * @m: Number of people coming to join line
 * 
 * Output: Prints the number of people in a line before adding a new person, this is sorted in increasing order
 */
// void allocatePeople(int lines[], int n, int m) {
//     int i, shortest;
//     for (i = 0; i < m; i++) {
//         shortest = shortest_line(lines, n);
//         printf("%d\n", lines[shortest]++);
//     }
//     return;
// }

// int main(void) {
//     int lines[MAX_LINES];
//     int n, m, i;
//     scanf("%d%d", &n, &m);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &lines[i]);
//     }
//     allocatePeople(lines, n, m);
//     return 0;
// }

/**
 * COMMENT
 * ------------------------------------------------------------------
 * This solution works, and it is in time O(n)*n at most, or let us say it goes through
 * the entire lines array every n times. a better way is to go through the array once and
 * sort in increasing order, then for every addition to the beginning of the array, keep
 * moving that line forward till it is no greater than the next line. worst case of this
 * is actually same as before, but best or typical case O(n)
 */

 /* OPTIMIZED SOLUTION */

 int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
 }

 int main(void) {
    int lines[MAX_LINES];
    int n, m, i, j, tmp;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
    }
    
    qsort(lines, n, sizeof(int), compare);
    for (i = 0; i < m; i++) {
        printf("%d\n", lines[0]++);
        j = 1;
        while (j < n && lines[j] < lines[j - 1])
        {
            tmp = lines[j];
            lines[j] = lines[j - 1];
            lines[j - 1] = tmp;
            j++;
        }
        
    }
    return 0;
}
