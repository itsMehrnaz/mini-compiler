**Hi**

i have a problem at the first place to just bring up the first simple Calculator Compiler and i found out it's because of the concept that it is not clear enough to me, that's why i decided to explain them here for everyone who has the same problem

Node *root = expr(); this means to read the whole program and made the AST tree 

now let's pretend that this is our input:   3 + 4 * 2 {



    at first we call expr()
    this function will read a mul first than mul() execute  {

        **Node *expr() {
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
    
}**


** Node *mul() {
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
} **

** Node *primary() {
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
    
    
} **


    }

    than as you see mul() will be called :  Node *node = primary(); => which it means to read the most simple one first.(sth like number or parenthesis)
}

so now we have our first Token which is number **3**
as you can relize in primary() the next line is about to return new_num(3); 
so now we have node = 3 

>Node *new_num(int val) {
>    Node *n  = calloc(1, sizeof(Node));
>    n->kind = ND_NUM;
>    n->val = val;
>    return n;
>}

>if you wonder what is calloc for read here :)

