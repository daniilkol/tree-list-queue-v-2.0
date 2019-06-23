#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20
class student
{
private:
    char*name;
    int value;
public:
    student(const char*in=0,int iv=0);
    student(const student&i);
    ~student();
    void delall(){this->~student();}
    student& operator=(const student&rhs);
    int get_value()const{return value;}
    const char* get_name()const {return (const char*)name;}
    int operator<(const student&b)const;
    void swaps(student&b);
    int init(const char*in=0,int iv=0);
    void print(int lvl=0)
    {
        for(int i=0;i<lvl;i++)
            printf("  ");
        printf("%s %d\n",name,value);
    }
    int read(FILE*fp)
    {
        char buf[1000];
        int n;
        if(fscanf(fp,"%s%d",buf,&n)!=2)
            return 0;
        init(buf,n);
        return 1;
    }
};
