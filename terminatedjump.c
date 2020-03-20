#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

void foo (void);
void bar (void);
void baz (void);

int
main (int argc, char *argv[])
{
    foo();
    bar();


    return 0;
}

void
foo (void)
{
    printf("foo start\n");

    switch (setjmp(env)) {
    case 0:
        printf("foo branch 0\n");
        break;
    case 1:
        printf("foo branch 1\n");
        break;
    }

    printf("foo end\n");
    return;
}

void
bar (void)
{
    printf("bar start\n");

baz();

    printf("bar end\n");
    return;
}

void
baz (void)
{
    printf("baz start\n");

    longjmp(env, 1);

    printf("baz end\n");
    return;
}
