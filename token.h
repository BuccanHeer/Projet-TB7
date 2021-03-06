#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

typedef enum {
    REEL,
    OPERATEUR,
    VAR,
    FONCTION,
    PAR_O,
    PAR_F,
    CONSTANTE,
    ERREUR
} toktype_t;

typedef enum {
    COS, SIN, TAN,
    ARCCOS, ARCSIN, ARCTAN,
    COSH, SINH, TANH,
    SQRT,
    EXP, LN, LOG,
    ABS, ENT, DECIMAL,
    FACTORIEL,
} fonct_t;

typedef enum {
    CST_PI, CST_E
} const_t;


typedef union {
    float reel;
    char operateur;
    fonct_t fonction;
    const_t constante;
} tokval_t;

typedef struct {
    toktype_t type;
    tokval_t valeur;
    int position;
} token_t;

typedef struct tokenarb_st tokenarb_t;
struct tokenarb_st {
    token_t token;
    tokenarb_t* gauche;
    tokenarb_t* droite;
};

typedef struct tokenlist_st tokenlist_t;
struct tokenlist_st {
    token_t token;
    tokenlist_t* suivant;
};


typedef struct {
    float x;
    float y;
} graphpt_t;


#endif // TOKEN_H_INCLUDED
