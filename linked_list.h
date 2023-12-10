struct node
{
int id;
char name[25];
char pos[25];
struct node*next;
};
struct node* add(struct node*,int *,char*,char*);
struct node* del(struct node*,int*,int);
void search(struct node*,int);
void list(struct node*);
