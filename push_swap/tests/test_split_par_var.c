#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "../include/push_swap.h"

void test_error_syntax() {
    char *str1 = "12345";
    assert(error_syntax(str1) == true);

    char *str2 = "-15";
    assert(error_syntax(str2) == true);

    char *str3 = "1";
    assert(error_syntax(str3) == true);

    char *str4 = "0";
    assert(error_syntax(str4) == true);

    char *str5 = "-523456789";
    assert(error_syntax(str5) == true);

    char *str6 = "0563246798";
    assert(error_syntax(str6) == true);

    char *str7 = "0";
    assert(error_syntax(str7) == true);

    char *str9 = "5a";
    assert(error_syntax(str9) == false);

    char *str10 = " 5-";
    assert(error_syntax(str10) == false);

    char *str11 = "-2345678 ";
    assert(error_syntax(str11) == false);

    char *str12 = "-6345678+";
    assert(error_syntax(str12) == false);

    char *str13 = "1.6";
    assert(error_syntax(str13) == false);
    
}


void test_valid_input() {
    char *args1[] = {"1", "2", "3", "4", "5", NULL};
    assert(valid_input_and_list(args1) == 1);

    char *args2[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
    assert(valid_input_and_list(args2) == 1);

    char *args3[] = {"1", "2", "3", "4", "5", "5", NULL};
    assert(valid_input_and_list(args3) == 0);

    char *args4[] = {"1", "2", "3", "4", "5", "1", NULL};
    assert(valid_input_and_list(args4) == 0);

    char *args5[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "10", NULL};
    assert(valid_input_and_list(args5) == 0);

    char *args6[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", NULL};
    assert(valid_input_and_list(args6) == 0);

    char *args7[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "0", NULL};
    assert(valid_input_and_list(args7) == 1);

    char *args8[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "-1", NULL};
    assert(valid_input_and_list(args8) == 1);

    char *args9[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "2147483647", NULL};
    assert(valid_input_and_list(args9) == 1);

    char *args10[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "-2147483648", NULL};
    assert(valid_input_and_list(args10) == 1);

    char *args11[] = {"1", "2", "3a", "4", "5", "6", "7", "8", "9", "10", "2147483648", NULL};
    assert(valid_input_and_list(args11) == 0);

    char *args12[] = {"1", "922337203685477522", "3", "4", "5", "6", "7", "8", "9", "10", "-2147483649", NULL};
    assert(valid_input_and_list(args12) == 0);

    char *args13[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "9223372036854775807", NULL};
    assert(valid_input_and_list(args13) == 0);
}

void test_ft_split_ps() {

    char *string = "1 2  ";
    char **result = ft_split_ps(string);
    assert(strcmp(result[0], "1") == 0);
    assert(strcmp(result[1], "2") == 0);
    assert(result[2]  == NULL);
    free(result[0]);
    free(result[1]);
    free(result);

    // and so on
}

void test_ft_atol() {
    char *str1 = "12345";
    assert(ft_atol(str1) == atol(str1));

    char *str2 = "-15";
    assert(ft_atol(str2) == atol(str2));

    char *str3 = "1";
    assert(ft_atol(str3) == atol(str3));

    char *str4 = "0";
    assert(ft_atol(str4) == atol(str4));

    char *str5 = "-523456789";
    assert(ft_atol(str5) == atol(str5));

    char *str6 = "0563246798";
    assert(ft_atol(str6) == atol(str6));

    char *str7 = "0";
    assert(ft_atol(str7) == atol(str7));

    char *str10 = "5a";
    assert(ft_atol(str10) == atol(str10));

    char *str11 = " 5-";
    assert(ft_atol(str11) == atol(str11));

    char *str12 = "-2345678 ";
    assert(ft_atol(str12) == atol(str12));

    char *str13 = "-6345678+";
    assert(ft_atol(str13) == atol(str13));

    char *str14 = "1.6";
    assert(ft_atol(str14) == atol(str14));

    char *str15 = "9223372036854775807"; // Maximum long value
    assert(ft_atol(str15) == atol(str15));

    char *str16 = "-9223372036854775808"; // Minimum long value
    assert(ft_atol(str16) == atol(str16));
    
}

int main(void) {
    test_ft_split_ps();
    test_error_syntax();
    test_ft_atol();
    // test_valid_input();  
    return (0);
}