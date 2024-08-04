#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
// clang-format off
// #include "cmocka.h" must follow its required cstdlib includes
#include "cmocka.h"
// clang-format on

/* A test case that does nothing and succeeds. */
static void null_test_success(void** state) { (void)state; /* unused */ }
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
