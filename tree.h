#include "list_node.h"
class tree
{
private:
    list_node *root;
    list_node *curr;
public:
    tree(){root=0;curr=0;}
    ~tree(){root->del();}
    int read(FILE*fp,int n1=1,int n2=1,int n3=1)
    {
        list_node *p,*q;
        if(root)
        {
            q=new list_node();
            p=root->down;
            if(q->read(fp,n2,n3))
                {
                    root->down->add(q);
                    p=p->add(q);
                }
            else return -1;
            root->down=p;
            return 1;
        }
        root=new list_node();
        if(root->read(fp,n2,n3));
        else return -1;
        p=root->down;
        for(int i=1;i<n1;i++)
        {
            q=new list_node();
            if(q->read(fp,n2,n3))
                {
                    root->down->add(q);
                    if(!empty()) p=p->add(q);
                    else delete q;
                }
            else return -1;
        }
        root->down=p;
        curr=root;
        return 1;
    }
    int addbr()
    {
        list_node *q;
        if(!curr) return -1;
        q=new list_node;
        if(q->read(stdin))
        {
            q->next=curr->next;
            curr->next=q;
        }
        else return -1;
        return 1;
    }
    int addch()
    {
        list_node *q;
        if(!curr) return -1;
        q=new list_node;
        if(q->read(stdin))
        {
            q->next=curr->down;
            curr->down=q;
        }
        else return -1;
        return 1;
    }
    list_node* get_curr(){return curr;}
    list_node* get_root(){return root;}
    void goto_down(){if(curr->down)curr=curr->down;else printf("I'm sorry, current element haven't got a down element\n");}
    void goto_next(){if(curr->next)curr=curr->next;else printf("I'm sorry, current element haven't got a next element\n");}
    void goto_root(){if(root) curr=root;}
    bool empty() {if(root) return false; return true;}
    void menu()
    {
        int key;
        printf("-1. Info\n");
        printf("0: Quit\n");
        printf("1: Print Tree\n");
        printf("2: Print Subtree of Current\n");
        printf("3: Print Current\n");
        printf("4: Go To Brother\n");
        printf("5: Go To Child\n");
        printf("6: Go To Root\n");
        printf("7: Delete Tree\n");
        printf("8: Delete Subtree\n");
        printf("9: Delete Brother\n");
        printf("10: Delete Child\n");
        printf("11: Add New Brother\n");
        printf("12: Add New Child\n");
        printf("13: Root Menu\n");
        printf("14: Current Menu\n");
        goto_root();
        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
            switch(key)
            {
            case -1:
                    printf("0: Quit\n");
                    printf("1: Print Tree\n");
                    printf("2: Print Subtree of Current\n");
                    printf("3: Print Current\n");
                    printf("4: Go To Brother\n");
                    printf("5: Go To Child\n");
                    printf("6: Go To Root\n");
                    printf("7: Delete Tree\n");
                    printf("8: Delete Subtree\n");
                    printf("9: Delete Brother\n");
                    printf("10: Delete Child\n");
                    printf("11: Add New Brother\n");
                    printf("12: Add New Child\n");
                    printf("13: Root Menu\n");
                    printf("14: Current Menu\n");
                    break;
            case 0:
                return ;

            case 1:
                    if(!empty())
                        root->print();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 2:
                    if(!empty())
                        curr->print();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 3:
                    if(!empty())
                        curr->student_list::print();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 4:
                    if(!empty())
                        goto_next();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 5:
                    if(!empty())
                        goto_down();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 6:
                    if(!empty())
                        goto_root();
                    else printf("Sorry,Tree is already empty\n");
                    break;
            case 7:
                    printf("$$$$$$$$$$$ DELETED $$$$$$$$$$$\n");
                    root->print();
                    printf("$$$$$$$$$$$ DELETED $$$$$$$$$$$\n");
                    root->del();
                    root=0;
                    curr=0;
                    break;
            case 8:
                    if(!empty())
                    {
                        if(curr->down)
                        {
                            printf("$$$$$$$$$$$ DELETED $$$$$$$$$$$\n");
                            curr->down->print();
                            printf("$$$$$$$$$$$ DELETED $$$$$$$$$$$\n");
                            curr->down->del();
                            curr->down=0;
                        }
                        else printf("Sorry,but this element has not got child\n");
                    }else printf("Sorry,Tree is already empty\n");
                    break;
            case 9:
                {
                    list_node *tmp=0;
                    if(!curr) { printf("Current does not exist\n");break;}
                    if(!curr->next){printf("Current brother does not exist\n");break;}
                    if(curr->next->down)
                    curr->next->down->del();
                    curr->next->student_list::delall();
                    tmp=curr->next->next;
                    delete curr->next;
                    curr->next=tmp;
                    break;
                }
            case 10:
                {
                    list_node *tmp=0;
                    if(!curr){printf("Current does not exist\n");break;}
                    if(!curr->down){printf("Current brother does not exist\n");break;}
                    if(curr->down->down)
                        curr->down->down->del();
                    tmp=curr->down->next;
                    curr->down->student_list::delall();
                    delete curr->down;
                    curr->down=tmp;
                    break;
                }
            case 11:
                    if(!curr) {printf("Current does not exist\n");break;}
                    if(curr==root) {printf("root can't have got a brother\n");break;}
                    printf("Input name and value for student\n");
                    addbr();
                    break;
            case 12:
                    if(!curr) {printf("Current does not exist\n");break;}
                    printf("Input name and value for student\n");
                    addch();
                    break;
            case 13:
                   if(!empty())
                       root->menu();
                   else printf("Sorry,Tree is already empty\n");
                   break;
            case 14:
                   if(!empty())
                       curr->menu();
                   else printf("Sorry,Tree is already empty\n");
                   break;
            default:
                    printf("Command is undefined\n");
                    break;
            }
        }
    }

};
