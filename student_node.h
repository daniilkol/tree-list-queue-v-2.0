#include "student.h"
class student_node: public student
{
    friend class student_queue;
private:
    student_node *next;
public:
    student_node(const char*in=0,int iv=0): student(in,iv){next=0;}
    student_node(const student_node&i):student(i){next=i.next;}
    student_node&operator=(const student_node&i)
    {
        *((student*)this)=i;
        next=i.next;
        return *this;
    }
    void init(char*in=0,int iv=0)
    {
        student::init(in,iv);
        next=0;
        delete [] in;
        iv=0;
    }
    int operator<(student_node*p)
    {
        return this->student::operator<(*p);
    }
    int cmp(student_node*a)
    {
        int k=this->student::operator<(*a);
        return k;
    }
    void swaps(student_node&a)
    {
        student::swaps(a);
    }
    student_node* get_next() const {return next;}
};
