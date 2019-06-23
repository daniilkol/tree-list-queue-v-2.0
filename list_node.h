#include "student_list.h"
class list_node: public student_list
{
    friend class tree;
private:
    list_node *next;
    list_node *down;
public:
    list_node(){next=down=0;}
    int operator<(list_node&a)
    {
        int k=*get_head()<*(a.get_head());
        //cout <<"k1= "<< k << endl;
        return k;
        //return strcmp(get_head()->get_head()->get_name(),a.get_head()->get_head()->get_name())>0;
    }
    int cmp(list_node*a)
    {
        int k=this->get_head()->cmp(a->get_head());
        return k;
    }
    void print(int k=0)
    {
        if(k>2) return;
        if(!this) return;
        if(next) next->print(k);
        if(down) down->print(k+1);
        student_list::print(k);
    }
    list_node&operator=(const list_node&i)
    {
        *((student_list*)this)=i;
        next=i.next;
        down=i.down;
        return *this;
    }
    list_node* add(list_node *x)
    {
        if(!this) return x;
        if(this->cmp(x)>0) {next=next->add(x);return this;}
        else {down=down->add(x);return this;}
        return this;
    }
    list_node* get_down(){return down;}
    list_node* get_next(){return next;}
    void del()
    {
        if(!this) return ;
        if(next) next->del();
        if(down) down->del();
        this->delall();
        delete this;
    }
};

