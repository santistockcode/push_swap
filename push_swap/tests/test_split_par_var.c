#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "../include/push_swap.h"

void test_error_syntax() {
    char *str1 = "12345";
    assert(error_syntax(str1) == false);

    char *str2 = "-15";
    assert(error_syntax(str2) == false);

    char *str3 = "1";
    assert(error_syntax(str3) == false);

    char *str4 = "0";
    assert(error_syntax(str4) == false);

    char *str5 = "-523456789";
    assert(error_syntax(str5) == false);

    char *str6 = "0563246798";
    assert(error_syntax(str6) == false);

    char *str7 = "0";
    assert(error_syntax(str7) == false);

    char *str9 = "5a";
    assert(error_syntax(str9) == true);

    char *str10 = " 5-";
    assert(error_syntax(str10) == true);

    char *str11 = "-2345678 ";
    assert(error_syntax(str11) == true);

    char *str12 = "-6345678+";
    assert(error_syntax(str12) == true);

    char *str13 = "1.6";
    assert(error_syntax(str13) == true);
    
}


void test_valid_input_and_list() {

    char *args1[] = {"1", "2", "3", "4", "5", NULL};
    t_list *list1 = valid_input_and_list(args1);
    assert(list1 != NULL);
    t_list *current = list1;
    int i = 0;
    while (current != NULL && i < 5) {
        t_number *number = (t_number *)current->content;
        assert(number->value == i + 1);
        assert(number->index == i);
        current = current->next;
    }

    char *args2[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
    t_list *list2 = valid_input_and_list(args2);
    assert(list2 != NULL);
    current = list2;
    i = 0;
    while (current != NULL && i < 10) {
        t_number *number = (t_number *)current->content;
        assert(number->value == i + 1);
        assert(number->index == i);
        current = current->next;
    }

    char *arg3[] = {"-10", "-9", "-8", "-7", "-6", "-5", "-4", "-3", "-2", "-1", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
    t_list *list3 = valid_input_and_list(arg3);
    assert(list3 != NULL);
    current = list3;
    i = -10;
    while (current != NULL && i < 11) {
        t_number *number = (t_number *)current->content;
        assert(number->value == i);
        assert(number->index == i + 10);
        current = current->next;
        i++;
    }
    
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