#include<iostream>
using namespace std;
#define max 15

typedef struct q
{ int data[max];
  int f,r;
}q;

class func
{
public:
void init(q *p)
{ p->f=p->r=-1;
}

int empty(q *p)
{  if(p->r==-1)
   return(1);
   return(0);
}

int full(q *p	)
{ if(p->r==max-1)
  return(1);
  return(0);
}

void enque(q *p,int x)
{  if(p->r==-1)
   {  p->r=p->f=0;
      p->data[p->r]=x;
   }
   else
   { p->r=p->r+1;
     p->data[p->r]=x;
   }
}

int deque(q *p)
{  int x;
   x=p->data[p->f];
   if(p->r==p->f)
   { p->r=p->f=-1;
   }
   else
   { p->f=p->f+1;
   }
   return(x);
}

void display(q *p)
{ for(int i=p->f;i<=p->r;i++)
  { cout<<p->data[i]<<" ";
  }
}

}f;

int main()
{  q p;
   int x,c,i;
   char a;
   f.init(&p);
   do
   {
   cout<<"menu\n1 create \n2 insert\n3 delete\n4 display\n";
   cin>>c;
   switch(c)
   { case 1:
               cout<<"create queue\n";
               cout<<"enter total no. of elements of queue ";
               cin>>i;
               for(int j=0;j<i;j++)
               {  if(!f.full(&p))
                  { cout<<"enter element "<<j+1<<endl;
                    cin>>x;
                    f.enque(&p,x);
      	          }
                  else
     		  {cout<<"full";
     		    break;
     		  }
     	       }
     	       break;
   
     case 2: 
               if(!f.full(&p))
               { cout<<"enter element to be added in queue"<<endl;
                 cin>>x;
                 f.enque(&p,x);
      	       }
               else
     		cout<<"full";
     		break;
     case 3:
     		if(!f.empty(&p))
     		{  x=f.deque(&p);
       		   cout<<"element deleted is "<<x<<endl;
     		}
     		else
     		cout<<"empty";
     		break;
     		
     case 4:
               cout<<"queue is ";
               f.display(&p);
               cout<<endl;
               break;
               
     default: cout<<"wrong choice"<<endl;
   }
     
   cout<<"wanna do again(y if yes) ";
   cin>>a;
   }while(a=='y'||a=='Y');
   cout<<endl;
   return(0);
 }  
