#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
// clang-format off
// #include "cmocka.h" must follow its required cstdlib includes
#include "cmocka.h"
// clang-format on

#include "colour.h"

static void test_pc_colour(void** state)
{
    (void)state;
    const uint8_t red = 123;
    const uint8_t green = 33;
    const uint8_t blue = 255;
    pc_colour_t colour = PcColour(red, green, blue);
    assert_int_equal(colour.red, red);
    assert_int_equal(colour.green, green);
    assert_int_equal(colour.blue, blue);
}

/* A test case that does nothing and succeeds. */
static void null_test_success(void** state) { (void)state; /* unused */ }
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_pc_colour),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
