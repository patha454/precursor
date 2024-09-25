#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
// clang-format off
// #include "cmocka.h" must follow its required cstdlib includes
#include "cmocka.h"
// clang-format on

#include "colour.h"

static void test_pc_colour_normal(void** state)
{
    (void)state;
    const uint8_t red = 123;
    const uint8_t green = 33;
    const uint8_t blue = 184;
    pc_colour_t colour = PcColour(red, green, blue);
    assert_int_equal(colour.red, red);
    assert_int_equal(colour.green, green);
    assert_int_equal(colour.blue, blue);
}

static void test_pc_colour_black(void** state)
{
    (void)state;
    const uint8_t red = 0;
    const uint8_t green = 0;
    const uint8_t blue = 0;
    pc_colour_t colour = PcColour(red, green, blue);
    assert_int_equal(colour.red, red);
    assert_int_equal(colour.green, green);
    assert_int_equal(colour.blue, blue);
}

static void test_pc_colour_white(void** state)
{
    (void)state;
    const uint8_t red = 255;
    const uint8_t green = 255;
    const uint8_t blue = 255;
    pc_colour_t colour = PcColour(red, green, blue);
    assert_int_equal(colour.red, red);
    assert_int_equal(colour.green, green);
    assert_int_equal(colour.blue, blue);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_pc_colour_normal),
        cmocka_unit_test(test_pc_colour_black),
        cmocka_unit_test(test_pc_colour_white),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
