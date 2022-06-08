#include <stdio.h>	/* fprintf, printf */
#include <stdlib.h>	/* strtol */
#include <math.h>	/* fmin, fmax */
#include <string.h>	/* strtok */

static int get_integer_count(int* n);
static int get_integer_list(const int n, int* list);
static int get_min_from_list(const int list[], const int n, int* ret_val);
static int get_max_from_list(const int list[], const int n, int* ret_val);
static int get_sum_of_list(const int list[], const int n, int* ret_val);
static int input_data(int list[], int* n);
static int min_max_sum(const int list[], const int n, int* min, int* max, int* sum);
static void put_min_max_sum(const int min, const int max, const int sum);

int main()
{
    int list[100];
    int status = 0;
    int n = 0;
    int min = 0, max = 0, sum = 0;

    status = input_data(list, &n);
    if (0 != status) {
        exit (1);
    }

    status = min_max_sum(list, n, &min, &max, &sum);
    if (0 != status) {
        exit (1);
    }
    
    put_min_max_sum(min, max, sum);

    return 0;
}

static int input_data(int list[], int* n)
{
    if (NULL == list || NULL == n) {
        return 1;
    }

    if (get_integer_count(n)) {
        return 1;
    }

    if (get_integer_list(*n, list)) {
        return 1;
    }

    return 0;
}

static int min_max_sum(const int list[], const int n, int* min, int* max, int* sum) {
    
    int status = 0;

    if (NULL == min || NULL == max || NULL == sum) {
        return 1;
    }

    status = get_min_from_list(list, n, min); 
    if (0 != status) {
        fprintf(stderr, "failed that get min value");
        return 1;
    }

    status = get_max_from_list(list, n, max);
    if (0 != status) {
        fprintf(stderr, "failed that get max value");
        return 1;
    }

    status = get_sum_of_list(list,n, sum);
    if (0 != status) {
        fprintf(stderr, "failed that get sum value");
        return 1;
    }

    return 0;
}

static void put_min_max_sum(const int min, const int max, const int sum)
{
    printf("%d %d %d\n", min, max, sum);
    return;
}

static int get_integer_count(int* n)
{
    char t[10] = {0};
    int check = 0;

    if (NULL == n) {
        return 1;
    }

    fgets(t, 10, stdin);
    check = atoi(t);
    if (0 > check || 10000 < check) {
        return 1;
    }

    *n = check;

    return 0;
}

static int get_integer_list(const int n, int list[])
{
    char t[100] = {0};
    char *tmp;
    int i = 0;
    int check = 0;

    if (NULL == list) {
        return 1;
    }

    fgets(t, 100, stdin);
    tmp = strtok(t, " ");
    check = atoi(tmp);
    if (-1000000 > check || 1000000 < check) {
        return 1;
    }
    list[0] = check;
    for (i = 1; i < n; i++) {
        tmp = strtok(NULL, " ");
        check = atoi(tmp);
        if (-1000000 > check || 1000000 < check) {
            return 1;
        }
        list[i] = check;
    }

    return 0;
}
  
static int get_min_from_list(const int list[], const int n, int* ret_val)
{
    int min;
    int i = 0;

    if (NULL == ret_val) {
        return 1;
    }

    min = list[0];
    for (i = 1; i < n; i++) {
        if (min > list[i])
            min = list[i];
    }

    *ret_val = min;

    return 0;
}

static int get_max_from_list(const int list[], const int n, int* ret_val)
{
    int max;
    int i = 0;

    if (NULL == ret_val) {
        return 1;
    }

    max = list[0];
    for (i = 1; i < n; i++) {
        if (max < list[i])
            max = list[i];
    }

    *ret_val = max;

    return 0;
}

static int get_sum_of_list(const int list[], const int n, int* ret_val)
{
    int sum = 0;
    int i = 0;

    if (NULL == ret_val) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        sum += list[i];
    }

    *ret_val = sum;

    return 0;
}