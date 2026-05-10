    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>

    typedef enum {
        TOK_NUMBER,
        TOK_PLUS,
        TOK_MINUS,
        TOK_STAR,
        TOK_SLASH,
        TOK_LPAREN,
        TOK_RPAREN,
        TOK_EOF
    } Tokenkind;

    typedef struct {
        Tokenkind kind;
        int value;
    } Token;

    char *src;
    int pos = 0;


    Token next_token() {
        Token tok;

        while (src[pos] == ' ' | src[pos] == '\n')
            pos++;

        char c = src[pos];

        if (isdigit(c)) 
        {
            int val = 0;
            while (isdigit(src[pos]))
            {
                val = val * 10 + (src[pos] - '0');
                pos++; 
            }
            tok.kind = TOK_NUMBER;
            tok.value = val;
            return tok;
            
        }

        if (c == '+') { pos++; tok.kind = TOK_PLUS; return tok; }
        if (c == '*') { pos++; tok.kind = TOK_STAR; return tok; }
        if (c == '/') { pos++; tok.kind = TOK_SLASH; return tok; }
        if (c == '(') { pos++; tok.kind = TOK_LPAREN; return tok; }
        if (c == ')') { pos++; tok.kind = TOK_RPAREN; return tok; }
        if (c == '-') { pos++; tok.kind = TOK_MINUS; return tok; }
        
        tok.kind = TOK_EOF;
        return tok;
        
        
    }