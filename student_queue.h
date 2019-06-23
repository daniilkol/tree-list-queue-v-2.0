#include "student_node.h"
class student_queue
{
private:
    student_node* head;
    student_node* tail;
public:
    student_queue(){head=0;tail=0;}
    ~student_queue()
    {
        student_node* tmp=head;
        while(tmp!=0)
        {
            tmp=head->next;
            delete head;
            head=tmp;
        }
    }
    void delall(){this->~student_queue();}
    void add (student_node&a)
    {

         if(head!=0)
         {
             a.next=0;
             tail->next=&a;
             tail=&a;
         } else head=tail=&a;
    }
    student_node* get_head(){return head;}
    /*int read(const char*name,student_queue& a)
    {
        FILE *fp;
        char b[1000];
        int c;
        student_node* q;
        if(!(fp=fopen(name,"r"))) return -1;
        if(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        else{fclose(fp);return -3;}

        while(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        if(!feof(fp))
            {
                fclose(fp);
                return -2;
            }
        fclose(fp);
         return 1;
    }*/
    int read(FILE* fp,int n3=1)
    {
        student_node* node;
        for(int i=0;i<n3;i++)
        {
            node=new student_node;
            if(node->read(fp))
            add(*node);
            else return -1;
        }
        return 1;

    }
    void print(int lvl=0)
    {
        student_node *p;
        int l=0;
        if(!head) return;
        for(int i=0;i<lvl-1;i++) printf("    ");
        printf("|");
        printf("================QUEUE==============\n");
        p=head;
        while(p!=tail)
            {
                for(int i=0;i<lvl-1;i++) printf("    ");
                printf("|");
                p->print(lvl);
                p=p->next;
                l++;
                if(l>5)
                {
                    for(int i=0;i<lvl-1;i++)
                     printf("    ");
                    printf("|");
                    printf("....\n");
                    return;
                }

            }
        for(int i=0;i<lvl-1;i++) printf("    ");
        printf("|");
        p->print(lvl);
        for(int i=0;i<lvl-1;i++) printf("    ");
        printf("|");
        printf("================QUEUE==============\n");
    }
    void print_head()
    {
        if(!head) return;
        head->print();
    }
    void print_tail()
    {
        if(!head) return;
        tail->print();
    }
    bool empty(){if(head) return false; return true;}
    /*void print()
    {
       student_node* tmp=head;
       while(tmp!=0)
       {
           printf("%s %d\n",tmp->get_name(),tmp->get_value());
           tmp=tmp->next;
       }
    }*/
    void del()
    {
        if(head!=0)
        {
            student_node* tmp=head;
            printf("Element <%s %d> is out\n",tmp->get_name(),tmp->get_value());
            head=head->next;
            delete tmp;
        }
    }
    int size ()
    {
       student_node* tmp=head;
       int i=0;
       while(tmp)
       {
           i++;
           tmp=tmp->next;
       }
       return i;
    }
    void menu()
    {
        int key;
        printf("0. Quit\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Size of queue\n");
        printf("4. Print head of queue\n");
        printf("5. Print tail of queue\n");
        printf("6. Print queue\n");
        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
            switch (key)
            {
                case -1:
                     printf("0. Quit\n");
                     printf("1. Add element\n");
                     printf("2. Delete element\n");
                     printf("3. Size of queue\n");
                     printf("4. Print head of queue\n");
                     printf("5. Print tail of queue\n");
                     printf("6. Print queue\n");
                     break;
                case 0:
                     return;
                case 1:
                    {
                        char b[1000];
                        int c;
                        printf("Input student:");
                        scanf("%s%d",b,&c);
                        student_node *tmp=new student_node(b,c);
                        add(*tmp);
                        break;
                    }
                case 2: if(!empty()) del(); else printf("Sorry, queue is already empty\n"); break;
                case 3: {int c=size(); printf("Size is equal to:%d\n",c); break;}
                case 4: if(!empty()) print_head();else printf("Sorry, queue is already empty\n");  break;
                case 5: if(!empty()) print_tail();else printf("Sorry, queue is already empty\n"); break;
                case 6: if(!empty()) print();else printf("Sorry, queue is already empty\n"); break;
                default: printf("Command is undefined\n");break;
            }
        }

    }
};


