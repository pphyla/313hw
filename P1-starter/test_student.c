/*
 * test_student.c -- CS 313 P1: your three hand-derived tests.
 *
 * Name:
 *
 * Write three tests. Each one pushes (and maybe pops) some values, then
 * checks the copy count with CHECK_COPIES(s, N), where N is a number
 * YOU worked out by hand before running anything. Show your work in a
 * comment above the check. You may add CHECK(...) lines for anything else.
 *
 * The autograder runs your tests against the instructor's stack. A test
 * passes if all its checks pass there and it has at least one
 * CHECK_COPIES with N >= 1. So a wrong hand count fails the test.
 *
 * Suggested tests:
 *   1. Push a small number of values (at least 4) and trace every growth.
 *   2. Push a number of values just past a power of 2, such as 17 or 33.
 *   3. Mix pushes and pops so that the stack grows, shrinks in size (the
 *      capacity never shrinks), and grows again.
 *
 * Worked example (not one of your three):
 *
 *   Stack *s = stack_create();
 *   stack_push(s, 10);     // capacity 1, size 1, no growth
 *   stack_push(s, 20);     // full: grow 1 -> 2, copy 1 element
 *   CHECK_COPIES(s, 1);
 *   stack_destroy(s);
 *
 * Build and run against your own stack.c:  make test
 */
#include "check.h"

void student_test_1(void) {
    Stack *s = stack_create();
    /* TODO */

    for (int i = 0; i < 5; i++) {
        CHECK(stack_push(s, i * 10));
    }

    /*
     * Hand calculation:
     * Push 1: capacity 1, no copies
     * Push 2: grow 1 -> 2, copy 1
     * Push 3: grow 2 -> 4, copy 2
     * Push 4: no growth
     * Push 5: grow 4 -> 8, copy 4
     *
     * Total copies = 1 + 2 + 4 = 7
     */
    CHECK_COPIES(s, 7);
    CHECK(stack_size(s) == 5);
    CHECK(s->capacity == 8);

    stack_destroy(s);
}

void student_test_2(void) {
    Stack *s = stack_create();
    /* TODO */

    for (int i = 0; i < 17; i++) {
        CHECK(stack_push(s, i));
    }

    /*
     * Hand calculation:
     * Growth 1 -> 2:   1 copy
     * Growth 2 -> 4:   2 copies
     * Growth 4 -> 8:   4 copies
     * Growth 8 -> 16:  8 copies
     * Growth 16 -> 32: 16 copies
     *
     * Total copies = 1 + 2 + 4 + 8 + 16 = 31
     */
    CHECK_COPIES(s, 31);
    CHECK(stack_size(s) == 17);
    CHECK(s->capacity == 32);

    stack_destroy(s);
}

void student_test_3(void) {
    Stack *s = stack_create();
    /* TODO */

    int value;

    // Push 5 elements, growing capacity to 8.
    for (int i = 0; i < 5; i++) {
        CHECK(stack_push(s, i));
    }

    /*
     * Hand calculation:
     * Growth 1 -> 2: 1 copy
     * Growth 2 -> 4: 2 copies
     * Growth 4 -> 8: 4 copies
     *
     * Total copies = 1 + 2 + 4 = 7
     */
    CHECK_COPIES(s, 7);

    // Pop 3 elements. Capacity stays at 8.
    for (int i = 0; i < 3; i++) {
        CHECK(stack_pop(s, &value));
    }

    CHECK(stack_size(s) == 2);
    CHECK(s->capacity == 8);

    // Push 7 more elements, forcing growth to 16.
    for (int i = 0; i < 7; i++) {
        CHECK(stack_push(s, i + 100));
    }

    /*
     * Hand calculation:
     * Previous copies = 7
     * After popping, size = 2, capacity = 8
     * First 6 pushes fill capacity 8.
     * Seventh push grows 8 -> 16, copying 8.
     *
     * Total copies = 7 + 8 = 15
     */
    CHECK_COPIES(s, 15);
    CHECK(stack_size(s) == 9);
    CHECK(s->capacity == 16);

    stack_destroy(s);
}
