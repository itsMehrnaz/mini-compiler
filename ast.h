typedef enum {
    ND_NUM,
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV
} Nodekind;

typedef struct Node
{
    Nodekind kind;
    struct Node *lhs;
    struct Node *rhs;
    int val;
    
} Node;
