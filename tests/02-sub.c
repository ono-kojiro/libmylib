#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

#include <check.h>

START_TEST(test_mylib_sub)
{
  int got, expected;
  expected = 1;
  got = mylib_sub(3, 2);
  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *mylib_suite(void)
{
  Suite *s;
  TCase *tc;

  s = suite_create("MyLib");
  tc = tcase_create("Basic");

  tcase_add_test(tc, test_mylib_sub);
  suite_add_tcase(s, tc);

  return s;
}

int main(int argc, char **argv)
{
  int ok;
  int ng;

  Suite *s;
  SRunner *sr;

  s = mylib_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  ng = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (ng == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

