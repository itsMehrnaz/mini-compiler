#include <stdio.h>
#include "lexcer.c"
#include "parser.c"
#include "codegen.c"


int main() {
    src = "3 + 4 * 2";  // ورودی فعلاً ثابت

    next(); // توکن اول

    Node *node = expr();

    printf("    .globl main\n");
    printf("main:\n");
    gen(node);
    printf("    ret\n");
}
