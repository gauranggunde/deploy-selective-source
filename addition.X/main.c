#include "operation.h"
#include <stdbool.h>
#include <stdio.h>
#include <xc.h>
#include <stdint.h>

bool TEST_Operation1(void)
{
    const int expected_result = 2;
    int result = operation(1,1);
    
    if( result == expected_result )
    {
        return true;
    }
    
    printf("TEST_Operation1 FAILED: result(%i), expected(%i)\r\n", result, expected_result);
    return false;
}

bool (*tests[])(void) = 
{
    &TEST_Operation1
};

int main(void)
{
    uint16_t tests_passed = 0;
    uint16_t current_test;
    const uint16_t total_tests = sizeof(tests)/sizeof(bool (*)(void));
    
    for(current_test = 0; current_test < total_tests; current_test++)
    {
        tests_passed += tests[current_test]();
    }
    
    printf("RESULTS - tests run(%i), tests passed(%i), tests failed(%i)\r\n", total_tests, tests_passed, total_tests-tests_passed);
    
    return 0;
}
