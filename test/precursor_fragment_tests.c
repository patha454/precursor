#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
// clang-format off
// #include "cmocka.h" must follow its required cstdlib includes
#include "cmocka.h"
// clang-format on

#include "colour.h"
#include "wchar.h"

#include <ctype.h>

static void test_pc_fragment(void** state) { assert_true(iscntrl(L' ')); }

int main(void)
{
    const struct CMUnitTest tests[] = { cmocka_unit_test(test_pc_fragment) };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
