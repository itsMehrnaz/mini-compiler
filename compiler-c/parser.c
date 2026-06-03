Token cur;


Node *expr();
Node *mul();
Node *primary();

void next() {
    cur = next_token();
}

Node *new_node(Nodekind kind, Node *lhs, Node *rhs) {
    Node *node = calloc(1, sizeof(Node));
    node->kind = kind;
    node->lhs = lhs;
    node->rhs = rhs;
    return node;
}


Node *new_num(int val) {
    Node *n  = calloc(1, sizeof(Node));
    n->kind = ND_NUM;
    n->val = val;
    return n;
}


Node *expr() {
    Node *node = mul();
    while (cur.kind == TOK_PLUS || cur.kind == TOK_MINUS)
    {
        if (cur.kind == TOK_PLUS)
        {
            next();
            node = new_node(ND_ADD, node, mul());
        } else {
            next();
            node = new_node(ND_SUB, node, mul());
        }
        
    }
    return node;
    
}

Node *mul() {
    Node *node = primary();
    while (cur.kind == TOK_STAR || cur.kind == TOK_SLASH) 
    {
        if (cur.kind == TOK_STAR)
        {
            next();
            node = new_node(ND_MUL, node, primary());
        } else {
            next();
            node = new_node(ND_DIV, node, primary());
        }
        
    }
    return node; 
}


Node *primary() {
    if (cur.kind == TOK_NUMBER)
    {
        int v = cur.value;
        next();
        return new_num(v);
    }

    if (cur.kind == TOK_LPAREN)
    {
        next();
        Node *node = expr();
        next();
        return node;
    }

    printf("unexpected Token");
    exit(1);
    
    
}