#include<iostream>
using namespace std;
#define max 15
typedef struct dq
{ int data[max];
  int f,r;
}dq;

class func
{
public:
void init(dq *p)
{ p->f=p->r=-1;
}

int empty(dq *p)
{  if(p->r==-1)
   return(1);
   return(0);
}

int full(dq *p	)
{ if(p->f==(p->r+1)%max)
  return(1);
  return(0);
}

void enque_r(dq *p,int x)
{  if(p->r==-1)
   {  p->r=p->f=0;
      p->data[p->r]=x;
   }
   else
   { p->r=(p->r+1)%max;
     p->data[p->r]=x;
   }
}

void enque_f(dq *p,int x)
{  if(p->r==-1)
   {  p->r=p->f=0;
      p->data[p->r]=x;
   }
   else
   { p->f=(p->f-1+max)%max;
     p->data[p->f]=x;
   }
} 

int deque_f(dq *p)
{  int x;
   x=p->data[p->f];
   if(p->r==p->f)
   { p->r=p->f=-1;
   }
   else
   { p->f=(p->f+1)%max;
   }
   return(x);
}

int deque_r(dq *p)
{  int x;
   x=p->data[p->r];
   if(p->r==p->f)
   { p->r=p->f=-1;
   }
   else
   { p->r=(p->r-1+max)%max;
   }
   return(x);
}

void display(dq *p)
{  int i=p->f;
   while(i!=p->r)
   { cout<<p->data[i]<<" ";
     i=(i+1)%max;
   }
   cout<<p->data[i]<<" ";
}

}f;

int main()
{  dq p;
   int x,c,i;
   char a;
   f.init(&p);
   do
   {
   cout<<"menu\n1 insert(front)\n2 insert(rear) \n3 delete(front)\n4 delete(rear)\n5 display\n";
   cin>>c;
   switch(c)
   { case 1: 
               if(!f.full(&p))
               { cout<<"enter element to be added in front of queue"<<endl;
                 cin>>x;
                 f.enque_f(&p,x);
      	       }
               else
     		cout<<"full";
     		break;
     case 2: 
               if(!f.full(&p))
               { cout<<"enter element to be added in rear of queue"<<endl;
                 cin>>x;
                 f.enque_r(&p,x);
      	       }
               else
     		cout<<"full";
     		break;		
     		
     case 3:
     		if(!f.empty(&p))
     		{  x=f.deque_f(&p);
       		   cout<<"element deleted from the front is "<<x<<endl;
     		}
     		else
     		cout<<"empty";
     		break;
    
     case 4:
     		if(!f.empty(&p))
     		{  x=f.deque_r(&p);
       		   cout<<"element deleted from the rear is "<<x<<endl;
     		}
     		else
     		cout<<"empty";
     		break;
     
     case 5:
               cout<<"queue is ";
               f.display(&p);
               cout<<endl;
               break;
               
     default: cout<<"wrong choice";
   }
     
   cout<<"wanna do again(y if yes) ";
   cin>>a;
   }while(a=='y'||a=='Y');
   cout<<endl;
   return(0);
 }  
