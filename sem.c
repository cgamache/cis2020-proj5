# include <stdio.h>
# include <strings.h>
# include <stdlib.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

int numblabels = 0;
int numlabels = 0;
int numgotos = 0;
int looplevel = 0;
int quadgen = 1;
struct loopscope {
    struct sem_rec *breaks;
    struct sem_rec *conts;
};
struct loopscope scopestk[50];
struct loopscope *looptop;
int laststmt = 0;

/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
   while(p !=NULL) {
      printf("B%d=L%d\n",p->s_place,k);
      //++numgotos;
      p = p->back.s_link;
   }
}

/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
   extern int lineno;
   skip();
   if (laststmt != lineno) {
      laststmt = lineno;
      printf("bgnstmt %d\n",lineno);
   }
}

/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
   int params = 0;
   struct id_entry * p = lookup(f,0);
   if (p == NULL) {
       p = install(f,0);
       p->i_type = T_INT;
       p->i_scope = GLOBAL;
   }
   struct sem_rec * e = args;
   while (e != NULL) {
     gen("arg",NULL,e,e->s_mode);
     e = e->back.s_link;
     params += 1;
   }
   return gen("f",id(f),node(params,NULL,NULL,NULL),p->i_type);
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
   printf("t%d := %s\n",nexttemp(),x);
   //todo determine doubleness?
   return node(currtemp(),T_INT,NULL,NULL);
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
   backpatch(e->back.s_true,m1);
   backpatch(e->s_false,m3);
   //backpatch(NULL,m2);
   endloopscope(m3);
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
   backpatch(e2->back.s_true,m3);
   backpatch(e2->s_false,m4);
   backpatch(n1,m1);
   backpatch(n2,m2);
   endloopscope(m4);
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
   backpatch(e->back.s_true,m1);
   backpatch(e->s_false,m2);
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
   backpatch(e->back.s_true,m1);
   backpatch(e->s_false,m2);
   backpatch(n,m3);
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{
   gen("ret",NULL,e,e->s_mode);
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{
   backpatch(e->back.s_true,m2);
   backpatch(e->s_false,m3);
   backpatch(n,m1);
   //breaks? continues?
   endloopscope(m3);
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
   //backpatch(looptop,m);
   //breaks? continues?
   looplevel -= 1;
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
    return merge(l,e);
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p)
{
   extern char formaltypes[];
   extern char localtypes[];
   extern formalnum;
   extern localnum;

   printf("func %s\n",p->i_name);
   char * t = formaltypes + p->i_offset;
   int i;
   for (i = 0; i < formalnum; i++) {
     printf("formal %d\n",(formaltypes[i] == 'i') ? 4 : 8); 
   }
   char * l = localtypes + p->i_offset;
   for (i = 0; i < localnum; i++) {
     printf("localloc %d\n",(localtypes[i] == 'i') ? 4 : 8);
   }
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id)
{
   extern formalnum;
   extern localnum;
   struct id_entry *p;
   p = install(id,0);
   p->i_type = t;
   p->i_scope = GLOBAL;
   p->i_defined = 1;
   formalnum = 0;
   localnum = 0;
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
   quadgen = 1;
   struct id_entry * p = lookup(x, 0);
   if (p  != NULL && p->i_blevel <= level) {
     switch (p->i_scope) {
       case PARAM:
         printf("t%d := param %d\n",nexttemp(),p->i_offset);
         break;
       case LOCAL:
         printf("t%d := local %d\n",nexttemp(),p->i_offset);
        break;
       case GLOBAL:
         printf("t%d := global %s\n",nexttemp(),x);
        break;
     }     
     return node(currtemp(),T_ADDR | p->i_type,NULL,NULL);
   } else {
     printf("t%d := global %s\n",nexttemp(),x);
     return node(currtemp(),T_PROC,NULL,NULL);
   }   
}

/*
 * sindex - subscript
 */
struct sem_rec *sindex(struct sem_rec *x, struct sem_rec *i)
{
   return gen("[]",x,i,x->s_mode & ~T_ARRAY);
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
   if (quadgen == 1) {
      printf("label L%d\n", ++numlabels);
   }
   quadgen = 0;
   return numlabels;
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
   quadgen = 1;
   printf("br B%d\n", ++numblabels);
   return node(numblabels,0,NULL,NULL);
}

struct sem_rec * cast(struct sem_rec * y, int m) {
   if ((m & ~T_ADDR) > (y->s_mode & ~T_ADDR)) {      
      //good place for gen?
      printf("t%d := cv%c t%d\n",nexttemp(),(m & T_DOUBLE) ? 'f' : 'i',y->s_place);
      return node(currtemp(),m,NULL,NULL);
   } else {
      return y;
   }
}

struct sem_rec *gen(char * op, struct sem_rec * x, struct sem_rec * y, int t) {
   if (strcmp("arg",op) == 0 || strcmp("ret",op) == 0) {
      printf("%s%c t%d\n",op,(t & T_DOUBLE) ? 'f' : 'i', y->s_place);      
      return node(currtemp(),t,NULL,NULL);
   } 
   printf("t%d := ",nexttemp());
   if (strcmp("f",op) == 0) {
      printf("f%c t%d %d\n",(t & T_DOUBLE) ? 'f' : 'i',x->s_place,y->s_place);
      return node(currtemp(),t,NULL,NULL);
   }
   if (x != NULL) {
      printf("t%d ", x->s_place);
   }
   printf("%s%c t%d\n",op,(t & T_DOUBLE) ? 'f' : 'i',y->s_place);
   return node(currtemp(),t,NULL,NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
    return gen(op,NULL,y,y->s_mode);
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
   int m = (x->s_mode > y->s_mode) ? x->s_mode : y->s_mode;
   x = cast(x,m);
   y = cast(y,m);
   gen(op,x,y,m);
   return node(currtemp(),m,NULL,NULL);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: opb not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   int m = (x->s_mode > y->s_mode) ? x->s_mode : y->s_mode;
   x = cast(x,m);
   y = cast(y,m);
   return ccexpr(gen(op,x,y,x->s_mode));
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
   struct sem_rec *z;
   if (strlen(op) == 0) {
      y = cast(y,x->s_mode);
      return gen("=",x,y,y->s_mode);
   } else {
      if (x->s_mode & T_ADDR) {
        z = gen("@",NULL,x,x->s_mode);
      } else {
        z = x;
      }
      y = op2(op, z, y);
      return gen("=",x,y,y->s_mode);
   }
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
   if (looplevel == 50) {
      printf("exceeded max number of loops\n");
      exit(1);
   }
   looplevel += 1;
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
   printf("t%d := %s\n",nexttemp(),s);
   return node(currtemp(),T_STR,NULL,NULL);
}
