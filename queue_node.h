#include "student_queue.h"
class queue_node: public student_queue
{
    friend class student_list;
private:
    queue_node *next;
public:
    queue_node() {next=0;}
    queue_node (const queue_node&i) {next=i.next;}
    queue_node&operator= (const queue_node&i)
    {
        *((student_queue*)this)=i;
        next=i.next;
        return *this;
    }
    int operator<(queue_node&a)
    {
        int k=*get_head()<a.get_head();
        return k;
    }
    int cmp(queue_node*a)
    {
        int k=this->get_head()->cmp(a->get_head());
        return k;
    }
    queue_node* get_next() const {return next;}
};
