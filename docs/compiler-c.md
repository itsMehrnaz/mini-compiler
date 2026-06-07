**Hi**

i have a problem at the first place to just bring up the first simple Calculator Compiler and i found out it's because of the concept that it is not clear enough to me, that's why i decided to explain them here for everyone who has the same problem

Node *root = expr(); this means to read the whole program and made the AST tree 

now let's pretend that this is our input:   3 + 5 * 2 


<!--
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
-->

```
cur_tok is on 3
  └─ term() is called
       └─ primary() reads number 3
       └─ next_token()  <- cur_tok moves to +
       └─ term() sees +, not my job, returns

cur_tok is on +
  └─ expr() sees +, enters the loop
  └─ kind = ND_ADD
  └─ next_token()  <- cur_tok moves to 5

cur_tok is on 5
  └─ term() is called again
       └─ primary() reads number 5
       └─ next_token()  <- cur_tok moves to *
       └─ term() sees *, this IS my job!
       └─ next_token()  <- cur_tok moves to 2
       └─ primary() reads number 2
       └─ builds ND_MUL node with lhs=5 and rhs=2
       └─ returns
```


<img src="/docs/ast_tree_3_plus_5_mul_2.svg" alt="AST tree">



**Lexer**

>Input is a text string like "3 + 5 * 2"
>Reads it character by character
>Converts each piece into a token
>A token is a struct with two fields: kind and value
>kind is the type of token like TOK_PLUS or TOK_NUMBER
>value is only filled for numbers
>cur_tok always points to the current token
>next_token() moves cur_tok one step forward

**Parser**

>Takes tokens and builds an AST tree
>Each priority level has its own function
>expr() is responsible for + and -
>term() is responsible for * and /
>primary() is responsible for numbers and parentheses
>Each function first calls the higher priority function
>This makes * get evaluated before +

**AST**

>A tree where each node is a Node struct
>Each Node has four fields: kind, lhs, rhs, val
>kind is the type of node like ND_ADD or ND_NUM
>lhs and rhs are pointers to child nodes
>val is only filled for ND_NUM
>Nodes are built in the heap using calloc
>calloc zeros all fields so no garbage remains

**Memory**

>Stack is for regular variables and pointers
>Heap is for AST nodes
>malloc gives memory but does not clear it
>calloc gives memory and zeros it
>Each node accesses its fields using ->