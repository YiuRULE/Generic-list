/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef _GENERIC_TYPE_LIST
# define _GENERIC_TYPE_LIST

/*
** Useful define for concenate two macros in C
*/
#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##B

/*
** Just an unique token
*/
# define STRING_TYPE ExgSOXJ7r_

/* 
**   define for declare a structure in your code
**   code example :
**   int main(int ac, char **av)
**   {
**     LIST(int) a;
**     a.elem = 42;
**   }
*/
# define LIST(type) M_CONC(STRING_TYPE, type)

/*
**  Define for concat two list
**  code example :
**  int main(int ac, char **av)
**  {
**     list(int) *a = new(sizeof(list(int)));
**     list(int) *b = new(sizeof(list(int)));
**
**     CONCAT(a, b);
**  }
*/
# define CONCAT(list1, list2) (list1->next = list2, list2->prev = list1)

/*
**  Define for going to the next or prev node
**  code example: 
**  int main(int ac, char **av)
**  {
**     LIST(int) *a = malloc(sizeof(LIST(int)));
**     LIST(int) *b = malloc(sizeof(LIST(int)));
**
**     SET_ELEMENT(a, 42);
**     SET_ELEMENT(b, 21);
**     CONCAT(a, b);
**     NEXT(a);
**     printf("%d\n", GET_ELEMENT(a));
**     PREV(a);
**     printf("%d\n", GET_ELEMENT(a));
**  }
*/
# define NEXT(list) (list = ((list) ? list->next : list))
# define PREV(list) (list = ((list) ? list->prev : list))

/*
**  Getter and setter for the list
**  code example:
**  int main(int ac, char **av)
**  {
**     LIST(int) *a = malloc(sizeof(LIST(int)));
**
**     SET_ELEMENT(a, 42);
**     printf("%d\n", GET_ELEMENT(a));
**  }
*/
# define GET_ELEMENT(list) list->elem
# define SET_ELEMENT(list, element) list->elem = element

/*
** Define for create the type
** You must call this define in your global scope before using
** your type.
** code example:
**
** CREATE_TYPE_LIST(int)
**
** int main(int ac, char **av)
** {
**    LIST(int) *a = malloc(sizeof(LIST(int)));
**    // let's rock baby !
** }
*/
# define CREATE_TYPE_LIST(type)						\
  typedef struct M_CONC(STRING_TYPE, type)	       			\
  {									\
    type elem;								\
    struct M_CONC(STRING_TYPE, type) *next;				\
    struct M_CONC(STRING_TYPE, type) *prev;				\
  } M_CONC(STRING_TYPE, type);

#endif