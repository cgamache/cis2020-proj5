# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

struct loopscope {
    struct sem_rec *breaks;
    struct sem_rec *conts;
};

struct gotonode {
    char *id;
    int place;
};

struct labelnode {
    char *id;
    int place;
};

int functype;
struct gotonode gotos[50];
struct labelnode labels[50];
struct loopscope *looptop;
int numblabels = 0;
int numgotos = 0;
int numlabelids = 0;
int numlabels = 0;
int relexpr;
struct loopscope scopestk[50];
int looplevel;
int quadgen;

/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
   fprintf(stderr, "sem: backpatch not implemented\n");
}

/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
   extern int lineno;
   skip();
   printf("bgnstmt %d\n",lineno);
}

/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
   fprintf(stderr, "sem: call not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
   fprintf(stderr, "sem: ccand not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
   int l1 = ++numblabels;
   printf("bt t%d B%d\n", e->s_place, l1);
   int l2 = ++numblabels;
   printf("br B%d\n", l2);
   return node(0,0,node(l1,0,NULL,NULL),node(l2,0,NULL,NULL));
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
   fprintf(stderr, "sem: ccnot not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
   fprintf(stderr, "sem: ccor not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x)
{
   int t = nexttemp();
   printf("t%d := %s\n",t,x);
   //todo determine doubleness?
   return node(t,T_INT,NULL,NULL);
}

/*
 * dobreak - break statement
 */
void dobreak()
{
   fprintf(stderr, "sem: dobreak not implemented\n");
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
   fprintf(stderr, "sem: docontinue not implemented\n");
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
   fprintf(stderr, "sem: dodo not implemented\n");
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
   fprintf(stderr, "sem: dofor not implemented\n");
}

/*
 * dogoto - goto statement
 */
void dogoto(char *id)
{
   fprintf(stderr, "sem: dogoto not implemented\n");
}

/*
 * doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
   printf("B%d=L%d\n",++numgotos,m1);
   printf("B%d=L%d\n",++numgotos,m2);
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
   fprintf(stderr, "sem: doifelse not implemented\n");
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{
   printf("ret%c t%d\n",(e->s_mode & T_DOUBLE) ? 'f' : 'i', e->s_place);
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{
   fprintf(stderr, "sem: dowhile not implemented\n");
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
   fprintf(stderr, "sem: endloopscope not implemented\n");
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
   struct sem_rec * s = l;
   while (s->back.s_link != NULL) {
      s = s->back.s_link;
   }
   s->back.s_link=e;
   s->back.s_true=e;
   return l;
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p)
{
   extern char formaltypes[];
   extern char localtypes[];
   printf("func %s\n",p->i_name);
   char * t = formaltypes + p->i_offset;
   int i;
   for (i = 0; i < strlen(t); i++) {
     printf("formal %d\n",(t[i] == 'i') ? 4 : 8); 
   }
   char * l = localtypes + p->i_offset;
   for (i = 0; i < strlen(l); i++) {
     printf("localloc %d\n",(l[i] == 'i') ? 4 : 8);
   }
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id)
{
   struct id_entry *p;
   p = install(id,0);
   p->i_type = t;
   p->i_scope = GLOBAL;
   p->i_defined = 1;
   enterblock();
   return p;
}

/*
 * ftail - end of function body
 */
void ftail()
{
  leaveblock();
  printf("fend\n");
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   extern int level;
   struct id_entry * p = lookup(x, 0);
   int t = nexttemp();
   if (p  != NULL && p->i_blevel <= level) {
     switch (p->i_scope) {
       case PARAM:
         printf("t%d := param %d\n",t,p->i_offset);
         break;
       case LOCAL:
         printf("t%d := local %d\n",t,p->i_offset);
         break;
     }
     return node(t,p->i_type,NULL,NULL);
   } else {
     printf("t%d := global %s\n",t,x);
     return node(t,T_PROC,NULL,NULL);
   }
}

/*
 * sindex - subscript
 */
struct sem_rec *sindex(struct sem_rec *x, struct sem_rec *i)
{
   fprintf(stderr, "sem: sindex not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
   /* you may assume the maximum number of C label declarations is 50 */
   fprintf(stderr, "sem: labeldcl not implemented\n");
}

/*
 * m - generate label and return next temporary number
 */
int m()
{
   if (numlabels == 49) {
      printf("too many labels\n");
      exit(1);
   }
   printf("label L%d\n", ++numlabels);
   return numlabels;
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
   fprintf(stderr, "sem: n not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
  int t = nexttemp();
  //good spot for gen?
  printf("t%d := %s%c t%d\n",t,op,(y->s_mode & T_DOUBLE) ? 'f' : 'i',y->s_place);
  return node(t,y->s_mode,NULL,NULL); 
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: op2 not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: opb not implemented\n");
   return ((struct sem_rec *) NULL);
}

struct sem_rec * cast(struct sem_rec * y, int m) {
   if (m > y->s_mode) {
      int t = nexttemp();
      printf("t%d := cv%c t%d\n",t,(m & T_DOUBLE) ? 'f' : 'i',y->s_place);
      return node(t,m,NULL,NULL);
   } else {
      return y;
   }
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   int t;
   if (x->s_mode != y->s_mode) {
     x = cast(x,(x->s_mode > y->s_mode) ? x->s_mode : y->s_mode);
     y = cast(y,(x->s_mode > y->s_mode) ? x->s_mode : y->s_mode);
   }
   t = nexttemp();
   printf("t%d := t%d %s%c t%d\n",t,x->s_place,op,(x->s_mode & T_DOUBLE) ? 'f' : 'i',y->s_place);   
   return ccexpr(node(t,x->s_mode,NULL,NULL));
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
   int t;
   if (x->s_mode != y->s_mode) {
     x = cast(x,(x->s_mode > y->s_mode) ? x->s_mode : y->s_mode);
     y = cast(y,(x->s_mode > y->s_mode) ? x->s_mode : y->s_mode);
   }
   //good spot for gen?
   if (x->s_mode & T_ADDR) {
      t = nexttemp();   
      printf("t%d := @%c t%d",t,(x->s_mode & T_DOUBLE) ? 'f' : 'i',x->s_place);
      x = node(t,(x->s_mode & T_DOUBLE) ? T_DOUBLE : T_INT,NULL,NULL);
   }
   if (y->s_mode & T_ADDR) {
      t = nexttemp();   
      printf("t%d := @%c t%d",t,(y->s_mode & T_DOUBLE) ? 'f' : 'i',y->s_place);
      y = node(t,(y->s_mode & T_DOUBLE) ? T_DOUBLE : T_INT,NULL,NULL);
   }
   t = nexttemp();
   printf("t%d := t%d =%c t%d\n",t,x->s_place,(x->s_mode & T_DOUBLE) ? 'f' : 'i',y->s_place);
   return node(t,x->s_place,NULL,NULL);
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
   /* you may assume the maximum number of loops in a loop nest is 50 */
   fprintf(stderr, "sem: startloopscope not implemented\n");
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
   fprintf(stderr, "sem: string not implemented\n");
   return ((struct sem_rec *) NULL);
}
