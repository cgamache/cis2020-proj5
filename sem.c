# include <stdio.h>
# include <strings.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

extern int level;

void ie(struct id_entry * i) {
  if (i != NULL) {
    printf("link[%d] name[%s] type[%d] blevel[%d] defined[%d] width[%d] scope[%d] offset[%d]\n",
        i->i_link,
        i->i_name,
        i->i_type,
        i->i_blevel,
        i->i_defined,
        i->i_width,
        i->i_scope,
        i->i_offset
        );
  } else {
    printf("id_entry is null\n");
  }
}

void iea(struct id_entry * i) {
  ie(i);
  struct id_entry * n = i->i_link;
  while(n != NULL) {
	ie(n);
	n = n->i_link;
  }
}

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
   fprintf(stderr, "sem: ccexpr not implemented\n");
   return ((struct sem_rec *) NULL);
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
   fprintf(stderr, "sem: con not implemented\n");
   return ((struct sem_rec *) NULL);
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
   fprintf(stderr, "sem: doif not implemented\n");
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
   fprintf(stderr, "sem: doret not implemented\n");
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
   
   l->back.s_link=e;
   l->back.s_true=e; 
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
   //iea(p);   
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
   //return ((struct id_entry *)NULL);
}

/*
 * ftail - end of function body
 */
void ftail()
{
  leaveblock();
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   struct id_entry * i = lookup(x,level);
   char * scope;
   int t = nexttemp();
   switch (i->i_scope) {
     case GLOBAL:
       scope = "global";
       break;
     case PARAM:
       scope = "param";
       break;
     case LOCAL:
       scope = "local";
       break;
   }
   printf("t%d := %s %d\n",t,scope,i->i_offset);
   return node(t,T_ADDR+i->i_type,NULL,NULL);
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
   fprintf(stderr, "sem: m not implemented\n");
   return (0);
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
  int b = y->s_mode & ~(T_ADDR);
  char c;
  switch (b) {
    case T_INT:
      c = 'i';
    break;
    case T_DOUBLE:
      c = 'f';
    break;
  }
  printf("t%d := %s%c t%d\n",t,op,c,y->s_place);
  return node(t,b,NULL,NULL);  
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

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: rel not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: set not implemented\n");
   return ((struct sem_rec *) NULL);
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
   int t = nexttemp();
   printf("t%d := %s\n",t,s);
   return node(t,T_STR,NULL,NULL);
}
