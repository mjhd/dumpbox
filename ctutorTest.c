#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char a)
{
    write(1, &a, 1);
}

void ft_printnum(int val, int length)
{
    int output[length];
    int value;
    int num;
    int i;

    i = length;
    if(val <= 0)
        ft_putchar((val == 0) ? '0' : '-');
    value = (val < 0) ? (val * -1) : val;
    while(i-- > 0) {
        num = value % 10;
        output[i + 1] = num;
        value -= num;
        value /= 10;
    }
    while(++i < length)
    {
        ft_putchar((output[i + 1] + '0'));
    }
    ft_putchar('\n');
}

void ft_putnbr(int val)
{
    int value;
    int num;
    int length;

    value = (val < 0) ? (val * -1) : val;
    length = 0;
    while(value > 0)
    {
        num = value % 10;
        value -= num;
        value /= 10;
        length++;
    }
    ft_printnum(val, length);
}

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i++]);
    }
    ft_putchar('\n');
}

void *ft_memalloc(size_t size)
{
    //ft_putnbr((int)size);
    void *pnt;
    pnt = malloc((int)size);
    return pnt;
}

char *ft_returnnum(int val, int length)
{
    int len = length + ((val < 0) ? 1 : 0);
    char *output = (char*)ft_memalloc(sizeof(char) * (len + 1));
    int value;
    int num;
    int i;

    output[len] = '\0';
    i = len;

    value = (val < 0) ? (val * -1) : val;
    while(i-- > ((val < 0) ? 1 : 0)) {
        num = value % 10;
        output[i] = num + '0';
        value -= num;
        value /= 10;
    }
    output[i + 1] = (val < 0) ? '-' : output[i + 1];
    return output;
}

char *ft_itoa(int val)
{
    int value;
    int num;
    int length;

    if(val == 0)
        return "0";
    value = (val < 0) ? (val * -1) : val;
    length = 0;
    while(value > 0)
    {
        num = value % 10;
        value -= num;
        value /= 10;
        length++;
    }
    return ft_returnnum(val, length);
}


int main() {

    ft_putstr(ft_itoa(126));
    return 0;
}





/*

#include <stdio.h>
#include <string.h>

int		ft_strlen(char const *str)
{
    int length;

    length = -1;
    while(str[++length] != '\0');

    return length;
}

char    *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    const char *pnt;
    int i;

    pnt = NULL;
    while (*haystack && (int)n - 1)
    {
        i = 0;
        if(*haystack == needle[i] && pnt == NULL)
            pnt = (ft_strlen(needle) > (int)n) ? NULL : haystack;
        n--;
        while(pnt != NULL && *haystack == needle[i] && needle[i])
        {
            if(*++haystack != needle[++i] && needle[i] != '\0')
            {
                pnt = NULL;
                haystack--;
            }
            if(needle[i] == '\0' && pnt != NULL)
                return (char *)pnt;
        }
        haystack++;
    }

    return NULL;
}


int main() {

    const char *str = "don't eat poop";
    const char *sub = "op";

    printf("%s\n", ft_strnstr(str, sub, 14));
    //printf("%s\n", ft_strrchr(str, 'o'));
    return 0;
}





 // -------------------------------------------------------------------A DIFFERNT TEST ::

 // ----- Show difference between assembly output: src[i++] vs *src++

#include <stddef.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
  char *str = (char *)malloc(sizeof(char) * 12);
  strcpy(str,"This is a s\0");

int i;

  i = 0;
  while(str[i++]);
  while(*str++);
  return 0;
}


 // --------------------------------------------------------------------SAME TEST - BETTER FOR PYTHON TUTOR VISUALIZER ::

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *str = (char *)malloc(sizeof(char) * 12);
  strcpy(str,"This is a s\0");

  int i;

  i = 0;
  while(str[i++])
    printf("%d", i - 1);
  printf("\n\n");

  while(*str++)
    printf("%s\n", (str - 1));

  return 0;
}


 // ---------------------------------------------------------------------------------STRSPLIT TEST SETUP ::

 #include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_strncpy(char *dst, const char *src, size_t len)
{
    int i;

    i = -1;
    while (src[++i] && i < (int)len)
        dst[i] = src[i];
    dst[i] = '\0';

    return dst;
}

char    *ft_strnew(size_t size)
{
    char *str;
    str = (char *)malloc((int)size + 1);
    str[size] = '\0';

    return str;
}

char **ft_strspliter(char const *s, char c, int strlen, int subcount)
{
    int i;
    int start;
    int count = strlen;
    char **list = malloc(sizeof(char **) * (subcount + 1));

    list[subcount] = (char *)('\0');
    while(subcount--)
    {
        while(*(s - 1) == c)
          s--;
        i = 0;
        while(strlen-- && *(--s) != c)
            i++;
        strlen++;
        list[subcount] = ft_strnew(i);
        i = 0;
    }

    return list;
}

char **ft_strsplit(char const *s, char c)
{
    int subcount;
    int strlen;
    int bigstrlen;
    char **rtnpnt;

    bigstrlen = 0;
    subcount = 0;
    strlen = 0;
    while(*s == c)
          s++;
    while(*s && ++strlen && ++bigstrlen)
    {
        subcount += (!(*s) || *(++s) == c) ? 1 : 0;
        while(*s == c && bigstrlen++)
          s++;
    }
    subcount += (!*s && subcount && *(s - 1) != c) ? 1 : 0;
    rtnpnt = ft_strspliter(s, c, strlen, subcount);
    s -= bigstrlen;
    while(*rtnpnt)
    {
        strlen = 0;
        while(*s != c && *s)
            rtnpnt[0][strlen++] = *s++;
        while(*s == c && s++);
        rtnpnt++;
    }
    rtnpnt -= subcount;

    return rtnpnt;
}

int main() {
    const char *str = "don't eat poop";
    char **strArr = ft_strsplit(str, ' ');

    //const char *str = "*hello*fellow***students*";
    //char **strArr = ft_strsplit(str, '*');

    return 0;
}






--------------- OTHER SHIT!! -------------------------------------------------




#include <stdlib.h>

void    fucky(char *c)
{
        *c += 2;
}

void ft_striter(char *s, void (*f)(char *))
{
    while(*s)
        f(s++);
}

int main() {
  char *str = (char *)malloc(sizeof(char) * 15);
  strcpy(str, "don't eat poop");
  ft_striter(str, fucky);

  return 0;
}







------------------- LIST LIST ATT # 1 -------------!!!!!!!!!!!!-----------------

typedef struct list
{
  char value;
  struct list *next;
} list;

int main() {
  struct list sampleNode;
  struct list mylist = {'l', &sampleNode};
  return 0;
}


------------------- LIST LIST ATT # 2 -------------!!!!!!!!!!!!-----------------



#include <stdlib.h>

typedef struct list
{
  char value;
  struct list *next;
} list;

void listmaker(char c, struct list *mylist)
{
  struct list *newNode = (struct list *)malloc(sizeof(struct list));
  while((int)(*mylist).next)
    mylist = (*mylist).next;
  (*newNode).value = c;
  (*newNode).next = '\0';
  (*mylist).next = newNode;

}

int main() {
  struct list *mylist;
  struct list sampleNode;
  struct list sampleNode2;
  sampleNode.value = 'f';
  sampleNode.next = &sampleNode2;
  sampleNode2.next = '\0';
  mylist = &sampleNode;

  //mylist = '\0';
  listmaker('l', mylist);
  return 0;
}



 -------------------------------------------------------SUPERMEGA - FIRST SERIOUS LEGIT ATTEMPT :: ---------------------



 #include <stdlib.h>

typedef struct list
{
  char value;
  struct list *next;
} list;

void listmaker(char c, struct list *mylist)
{
  void **pnt;
  struct list *newNode;

  newNode = (struct list *)malloc(sizeof(struct list));
  (*newNode).value = c;
  (*newNode).next = '\0';
  pnt = mylist;
  if(!(*pnt))
    *pnt = newNode;
  else
    pnt = &((*mylist).next);
  mylist = pnt;
  while((*mylist).next)
  {
    mylist = pnt;
    pnt = (*mylist).next;
  }
  (*mylist).next = newNode;
}

int main() {
  struct list *mylist;
  struct list sampleNode;
  struct list sampleNode2;
  sampleNode.value = 'f';
  sampleNode2.value = 'j';
  sampleNode.next = &sampleNode2;
  sampleNode2.next = '\0';
  mylist = &sampleNode;

  //mylist = '\0';
  listmaker('l', &mylist);
  return 0;
}




--------!!!!!----------------!!!!!!!!!!! FIRST LINK LIST 42 LIBFT SUCCESS -> ft_lstnew (for pytutor) ---------------

#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *pnt;

	pnt = (t_list *)malloc(sizeof(t_list));
	memcpy(&(*pnt).content, &content, content_size);
	memcpy(&(*pnt).content_size, &content_size, sizeof(size_t));
	(*pnt).next = 0;
	return pnt;
}

int main() {

  char c = 'l';
  const void *value = &c;
  t_list *mylist;

  mylist = ft_lstnew(value, sizeof(char *));
  return 0;
}















!!!--------------------- lstadd_end!!!!!!!!!!!!!!!!!!!!!!!!!-----------------------------------



#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

void ft_lstadd_end(t_list **alst, t_list *new_link)
{
  while((int)((*(*alst)).next))
    alst = &((*(*alst)).next);
  ((*(*alst)).next) = &(*new_link);
}

void ft_lstadd(t_list **alst, t_list *new_link)
{
  ((*new_link).next) = &(*(*alst));
  (*alst) = &(*new_link);
}

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *pnt;

	pnt = (t_list *)malloc(sizeof(t_list));
	memcpy(&(*pnt).content, &content, sizeof(void *));
	memcpy(&(*pnt).content_size, &content_size, sizeof(size_t));
	(*pnt).next = 0;
	return pnt;
}

int main() {

  int l = 'l';
  char v = 'v';
  char n = 'n';
  char x = 'x';
  const void *value1 = &l;
  const void *value2 = &v;
  const void *value3 = &n;
  const void *value4 = &x;
  t_list *mylist;

  mylist = ft_lstnew(value1, sizeof(int));
  ft_lstadd(&mylist, ft_lstnew(value2, sizeof(char)));
  ft_lstadd(&mylist, ft_lstnew(value3, sizeof(char)));
  ft_lstadd_end(&mylist, ft_lstnew(value4, sizeof(char)));
  ft_lstadd(&mylist, ft_lstnew(value3, sizeof(char)));
  return 0;
}































FFFFFFUUUUUUUUCCCCCCCKKKKKKKKKKKSSSSSSSSSSHHHHHHHIIIIIIIIIIIIIITTTTTTTT ------------------------------






#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct  s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
}   t_list;

void ft_linkdel(void *pnt, size_t size)
{
  free(pnt);
}

void ft_linkprint(t_list *list)
{
  printf("%c\n", (*list).content);
}


void  ft_lstadd_end(t_list **alst, t_list *new_link)
{
    while((int)((*(*alst)).next))
        alst = &((*(*alst)).next);
    ((*(*alst)).next) = &(*new_link);
}

void  ft_lstadd(t_list **alst, t_list *new_link)
{
    ((*new_link).next) = &(*(*alst));
    (*alst) = &(*new_link);
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    void *content;
    size_t size;
    content = (*(*alst)).content;
    size = (*(*alst)).content_size;
    ft_linkdel(content, size);
    free(*alst);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    void *link;
	  void *content;
    size_t size;

    while((*alst))
    {
      link = (*alst);
      ft_linkdel((*(*alst)).content, (*(*alst)).content_size);
      (*alst) = (*(*alst)).next;
      free(link);
    }
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
  while(lst)
    {
      ft_linkprint((*lst).content);
      lst = (*lst).next;
    }
}

t_list  *ft_lstnew(void const *content, size_t content_size)
{
    t_list *pnt;

    pnt = (t_list *)malloc(sizeof(t_list));
    memcpy(&(*pnt).content, &content, sizeof(void *));
    memcpy(&(*pnt).content_size, &content_size, sizeof(size_t));
    (*pnt).next = 0;
    return pnt;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *oldlist;
    t_list *newlist;

    oldlist = &(*lst);
    newlist = ft_lstnew((((f)(lst))->content), ((f)(lst))->content_size);
    while((int)((*oldlist).next))
    {
        (*oldlist) = (*(*oldlist).next);
        ft_lstadd_end(&newlist, ft_lstnew(((f)(oldlist))->content, ((f)(oldlist))->content_size));
    }
    return newlist;
}


t_list  *shitlook(char content, t_list **alst)
{
    t_list  *shitlink;
    shitlink = (*alst);
    char *c;
    c = &(*(*shitlink).content);
    //printf("%c\n", (*c));
    while(((*shitlink).content_size) != sizeof(char) || (*c) != content)
{
shitlink = &(*(*shitlink).next);
c = &(*(*shitlink).content);
}

return shitlink;
}

t_list  *ft_addone(t_list *elem)
{
    return ft_lstnew((*elem).content, (*elem).content_size);
}

t_list  *ft_modlst(t_list *elem)
{
    char *c;
    void *src;

    c = (char *)malloc(sizeof(char));
    src = &(*(*elem).content);
    c = memcpy(c, src, 1);
    (*c) += 2;
    return ft_lstnew(c, (*elem).content_size);
}

int main()
{
    char *l;
    char *v;
    char *n;
    char *x;
    l = (char *)malloc(sizeof(char));
    *l = 'l';
    //v = (char *)malloc(sizeof(char));
    //*v = 'v';
    n = (char *)malloc(sizeof(char));
    *n = 'n';
    x = (char *)malloc(sizeof(char));
    *x = 'x';
    const void *value1 = l;
    //const void *value2 = v;
    const void *value3 = n;
    const void *value4 = x;
    t_list *mylist;
    mylist = ft_lstnew(value1, sizeof(char));
    //ft_lstadd(&mylist, ft_lstnew(value2, sizeof(char)));
    ft_lstadd(&mylist, ft_lstnew(value3, sizeof(char)));
    ft_lstadd(&mylist, ft_lstnew(value4, sizeof(char)));
    //t_list *shitresponse = (shitlook('n', &mylist));
    //ft_lstdel(&shitresponse, ft_linkdel);
    //ft_lstiter(mylist, ft_linkadd);
    t_list *newlist;
    //newlist = ft_lstmap(mylist, ft_addone);
    newlist = ft_lstmap(mylist, ft_modlst);
    ft_lstiter(newlist, ft_linkprint);
    return 0;
}






*/