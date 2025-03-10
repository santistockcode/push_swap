#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "../include/push_swap.h"

// void test_error_syntax() {
//     char *str1 = "12345";
//     assert(error_syntax(str1) == true);

//     char *str2 = "1 2 3 4 5";
//     assert(error_syntax(str2) == true);

//     char *str3 = "1-2-3-4-5";
//     assert(error_syntax(str3) == true);

//     char *str4 = "1- 2- 3- 4- 5";
//     assert(error_syntax(str4) == true);

//     char *str5 = "-1-2-3-4-5";
//     assert(error_syntax(str5) == true);

//     char *str6 = "-1 -2 -3 -4 -5";
//     assert(error_syntax(str6) == true);

//     char *str7 = "1 2 3 4 5 ";
//     assert(error_syntax(str7) == true);

//     char *str8 = " 1 2 3 4 5";
//     assert(error_syntax(str8) == true);

//     char *str9 = "1 2 3 4 5a";
//     assert(error_syntax(str9) == false);

//     char *str10 = "1 2 3 4 5-";
//     assert(error_syntax(str10) == false);

//     char *str11 = "1 2 3 4 5- ";
//     assert(error_syntax(str11) == false);

//     char *str12 = "1 2 3 4 5-6";
//     assert(error_syntax(str12) == false);

//     char *str13 = "1 2 3 4 5- 6";
//     assert(error_syntax(str13) == false);
// }

// void test_error_duplicates() {
//     char *argv1[] = {"1", "2", "3", "4", "5", NULL};
//     assert(error_duplicates(argv1) == false);

//     char *argv2[] = {"1", "2", "3", "4", "5", "1", NULL};
//     assert(error_duplicates(argv2) == true);

//     char *argv3[] = {"1", "2", "3", "4", "5", "5", NULL};
//     assert(error_duplicates(argv3) == true);

//     char *argv4[] = {"1", "2", "3", "4", "4", "5", NULL};
//     assert(error_duplicates(argv4) == true);

//     char *argv5[] = {"1", "2", "3", "3", "4", "5", NULL};
//     assert(error_duplicates(argv5) == true);

//     char *argv6[] = {"1", "2", "2", "3", "4", "5", NULL};
//     assert(error_duplicates(argv6) == true);
// }

// void test_free_argv() {
//     char *string = "1 2 3 4 5";
//     char    **result = ft_split_ps(string);
//     free_argv(result);
//     assert(result == NULL);
// }

void test_ft_split_ps() {

    // char *empty_string = "";
    // char **result = ft_split_ps(empty_string);
    // assert(*result == NULL);
    // free(result);

    // char *string = "1 2 3 4 5";
    // result = ft_split_ps(string);
    // assert(strcmp(result[0], "1") == 0);
    // assert(strcmp(result[1], "2") == 0);
    // assert(strcmp(result[2], "3") == 0);
    // assert(strcmp(result[3], "4") == 0);
    // assert(strcmp(result[4], "5") == 0);
    // assert(result[5] == NULL);
    // free(result[0]);
    // free(result[1]);
    // free(result[2]);
    // free(result[3]);
    // free(result[4]);
    // free(result);

    // char *string = "1  2  3    4      5";
    // char **result = ft_split_ps(string);
    // assert(strcmp(result[0], "1") == 0);
    // assert(strcmp(result[1], "2") == 0);
    // assert(strcmp(result[2], "3") == 0);
    // assert(strcmp(result[3], "4") == 0);
    // assert(strcmp(result[4], "5") == 0);
    // assert(result[5] == NULL);
    // free(result[0]);
    // free(result[1]);
    // free(result[2]);
    // free(result[3]);
    // free(result[4]);
    // free(result);

    // char *string = "1 2 3 4 5 ";
    // char **result = ft_split_ps(string);
    // assert(strcmp(result[0], "1") == 0);
    // assert(strcmp(result[1], "2") == 0);
    // assert(strcmp(result[2], "3") == 0);
    // assert(strcmp(result[3], "4") == 0);
    // assert(strcmp(result[4], "5") == 0);
    // assert(result[5] == NULL);
    // free(result[0]);
    // free(result[1]);
    // free(result[2]);
    // free(result[3]);
    // free(result[4]);
    // free(result);

    char *string = " 1 2 3 4 5";
    char **result = ft_split_ps(string);
    assert(strcmp(result[0], "1") == 0);
    assert(strcmp(result[1], "2") == 0);
    assert(strcmp(result[2], "3") == 0);
    assert(strcmp(result[3], "4") == 0);
    assert(strcmp(result[4], "5") == 0);
    assert(result[5] == NULL);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result[3]);
    free(result[4]);
    free(result);

    // and so on
}

int main(void) {
    test_ft_split_ps();
    // test_error_syntax();
    // test_error_duplicates();  
    // test_free_argv();
    return (0);
}