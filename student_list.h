#include "queue_node.h"
class student_list
{
private:
    queue_node*head;
    queue_node*curr;
public:
    student_list(){head=0;curr=0;}
    ~student_list()
    {
        while(head!=0)
        {
            queue_node* tmp=head->next;
            delete head;
            head=tmp;
        }
    }
    void delall(){this->~student_list();}
    void del()
    {
        queue_node *p=head;
        head=head->next;
        p->next=0;
        p->delall();
        delete p;
    }
    void add(queue_node&a)
    {

           if(head!=0)
           {
               a.next=curr->next;
               curr->next=&a;
               goto_next();
           }
           else head=curr=&a;

    }
    void delelement()
    {
        if(curr!=head)
        {
            queue_node* tmp=head;
            while(tmp->next!=curr)
                tmp=tmp->next;
            if(tmp->next)tmp->next=tmp->next->next;
		tmp=tmp->next;
		curr->~student_queue();
		delete curr;
		curr=tmp;


        } else
        {
           queue_node* tmp;
           tmp=head->next;
		//head->~student_queue();
		delete head;
           head=tmp;

        }
    }
    void goto_next(){if(curr->next)curr=curr->next;else return;}
    void goto_head(){if(!empty()) curr=head;}
    queue_node* get_head() {return head;}
    queue_node* get_curr(){if(!empty()) return curr;}
    bool empty(){if(head) return false; return true;}
    /*int read(const char*name,student_list&a)
    {
        FILE *fp;
        int i=0;
        char b[1000];
        int c;
        student_node* q;
        if(!(fp=fopen(name,"r"))) return -1;
        if(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node;
            q->init(b,c);
            a.add(*q);
            i++;
        }
        else{fclose(fp);return -3;}
        while(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node;
            q->init(b,c);
            a.add(*q);
            i++;
        }
        if(feof(fp))
            {
                fclose(fp);
                return -2;
            }
        fclose(fp);
        return i;
    }*/
    /*void print(student_list &a)
    {
        student_node* tmp=head;
        while(tmp!=0)
        {
            printf("%s %d\n",tmp->get_name(),tmp->get_value());
            tmp=tmp->next;
        }
    }*/
    int read(FILE* fp, int n2=1, int n3=1)
    {
        queue_node* node;
        for(int i=0;i<n2;i++)
        {
            node=new queue_node;
            if(node->read(fp,n3)) add(*node);
            else return -1;
            if(empty()) del();
        }

        return 1;
    }
    void print(int lvl=0)
    {
        queue_node*p;
        int l=0;
        if(!head) {return;}
        p=head;
        for(int i=0;i<lvl;i++) printf("    ");
        printf("|");
        printf("---------LIST--------\n");
        while(p)
        {
            if(l>2){for(int i=0;i<lvl;i++) printf("    ");
            printf("|....\n");
            return;
        }
            //for(int i=0;i<lvl;i++) cout << "  ";
           // cout << "|";
            p->print(lvl+1);
            p=p->next;
            l++;
        }
        for(int i=0;i<lvl;i++) printf("    ");
        printf("|");
        printf("---------LIST--------\n");
    }
    void print_tail()
    {
        queue_node* tmp=head;
        while (tmp->next)
            tmp=tmp->next;
        tmp->print();
    }
    /*void print(int s=0)
    {
        queue_node* tmp=head;
        int tab=0,k=0;
        while(tmp!=0&&k<3)
        {
            if(k>0)
            for(int i=0;i<s-1;i++) printf("                    ");
            tmp->print(tab,s);
            tmp=tmp->next;
            tab++;
            k++;
        }
    }*/
    void menu()
    {
        int key;
        printf("-1. Info\n");
        printf("0. Quit\n");
        printf("1. Print List\n");
        printf("2. Print Tail\n");
        printf("3. Go To Next\n");
        printf("4. Go To Head\n");
        printf("5. Print Current\n");
        printf("6. Menu Of Current\n");
        printf("7. Delete Current\n");
        printf("8. Add New Student\n");
        goto_head();
        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
            switch (key)
            {
                case -1:
                        printf("0. Quit\n");
                        printf("1. Print List\n");
                        printf("2. Print Tail\n");
                        printf("3. Go To Next\n");
                        printf("4. Go To Head\n");
                        printf("5. Print Current\n");
                        printf("6. Menu Of Current\n");
                        printf("7. Delete Current\n");
                        printf("8. Add New Student\n");
                        break;
                case 0:
                     return;
                case 1:
                     if(!empty())
                        print();
                     else printf("Sorry, List is already empty\n");
                     break;
                case 2:
                     if(!empty())
                        print_tail();
                     else printf("Sorry, List is already empty\n");
                     break;
                case 3:
                     if(!empty())
                        {
                            if(curr->next)
                                curr=curr->next;
                            else printf("There is no next\n");
                        }
                        else printf("Sorry, List is already empty\n");
                        break;
                case 4:
                     if(!empty())
                        goto_head();
                     else printf("Sorry, List is already empty\n");
                     break;
                case 5:
                     if(!empty())
                        {
                            if(!curr->empty())
                                curr->print();
                        }
                        else printf("Sorry, List is already empty\n");
                        break;
                case 6:
                     if(!empty())
                        {
                            printf("Commands For Current:\n");
                            curr->menu();
                        }
                        else printf("Sorry, List is already empty\n");
                        break;
                case 7:
                     if(!empty())
                        {
                            if(!curr->empty())
                            {
                                if(curr==head)
                                {
                                   delelement();
                                   curr=head;
                                }
                                else
                                {
                                   if(curr->next==0)
                                   {
                                      delelement();
                                      goto_head();
                                      while(curr->next)
                                      curr=curr->next;
                                   }
                                   else delelement();
                                }

                            }
                            else printf("Sorry,current is already empty\n");
                        }
                        else printf("Sorry, List is already empty\n");
                        break;
                case 8:
                    printf("Input student:");
                    read(stdin);
                    break;
                /*case 7:
                     if(!empty())
                        delete_list();
                     else printf("Sorry, List is already empty\n");
                     break;*/
                default:
                     printf("Command is undefined\n");
                     break;
            }
        }
    }
};

