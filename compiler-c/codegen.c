#include "ast.h"


void gen(Node *node) {
    if (node->kind == ND_NUM) {
        printf("    mov rax, %d\n", node->val);
        return;
    }

    gen(node->lhs);
    printf("    push rax\n");
    gen(node->rhs);
    printf("    pop rbx\n");

    switch (node->kind) {
        case ND_ADD:
            printf("    add rax, rbx\n");
            break;
        case ND_SUB:
            printf("    sub rax, rbx\n");
            break;
        case ND_MUL:
            printf("    imul rax, rbx\n");
            break;
        case ND_DIV:
            printf("    cqo\n");
            printf("    idiv rbx\n");
            break;
    }
}
