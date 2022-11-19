#include<iostream>
using namespace std;

typedef struct node
{  int prn;
   char name[50];
   struct node *next;
}node;

class func
{ node *head;
  public:
  func()
  {  
     head=NULL;
  }
  void create(int n);
  void print();
  void insert_start();
  void insert_end();
  void insert_middle(int );
  void delete_start();
  void delete_end();
  void delete_middle(int );
  int no();
  void reverse();
  void concatenate(func &f);
};

int main()
{ int n,m,c,count;
  int a,key;
  func f;
  func q;
  a=1;
  do
  {
  cout<<"1 creation of list\n2 printing of list\n3 addition of president\n4 addition of secratory\n5 addition of member\n6 deletion of president\n7 deletion of secratory\n8 deletion of members\n9 total no. of members\n10 reverse of list\n11 concatination of two lists\nENTER YOUR CHOISE\n";
  cin>>c;
  switch(c)
  { case 1:  cout<<"enter no. of members inserted (inculding president and  secratory)\n";
             cin>>n;
             f.create(n);
             break;

    case 2: f.print();
            break;
  
    case 3: f.insert_start();
            break;

    case 4: f.insert_end();
            break;
 
    case 5: cout<<"enter the prn after which the member should be added\n";
            cin>>key;
            f.insert_middle(key);
            break;

    case 6: f.delete_start();
            break; 
   
    case 7: f.delete_end();
            break;

    case 8: cout<<"enter the prn of member which should be deleted\n";
            cin>>key;
            f.delete_middle(key);
            break;

    case 9: count=f.no();
            cout<<"total no of members are "<<count<<endl;
            break;
 
    case 10:  f.reverse();
              break;

    case 11:  cout<<"create list 1\n";
              cout<<"enter no. of members inserted (inculding president and  secratory)\n";
              cin>>n;
              f.create(n);
              cout<<"create list 2\n";
              cout<<"enter no. of members inserted (inculding president and  secratory)\n";
              cin>>m;
              q.create(m);
              f.concatenate(q);
              f.print();
              break;
                 
     default: cout<<"wrong no. entered\n";
  }

  cout<<"enter 1 to do again??\n";
  cin>>a;
  }while(a==1);

  return(0);
}

void func::create(int n)
{ node *p;
  cout<<"enter elements to be entered (prn and name)\n";
  head=new node;
  cin>>(head->prn)>>(head->name);
  head->next=NULL;
  p=head;
  for(int i=1;i<n;i++)
  { p->next=new node;
    p=p->next;
    cin>>(p->prn)>>(p->name);
    p->next=NULL;
  }
}

void func::print()
{  cout<<"elements are\n";
   node *p;
   p=head;
   while(p!=NULL)
   { cout<<"prn="<<(p->prn)<<" name="<<(p->name)<<"\n";
     p=p->next;
   }
}

void func::insert_start()
{ node *p;
  cout<<"enter elements to be entered (prn and name)\n";
  p=new node;
  cin>>(p->prn)>>(p->name);
  p->next=NULL;
  if(head==NULL)
  { head=p;
  }
  else
  { p->next=head;
    head=p;
  }
}

void func::insert_end()
{ node *q;
  node *p;
  cout<<"enter elements to be entered (prn and name)\n";
  p=new node;
  cin>>(p->prn)>>(p->name);
  p->next=NULL;
  if(head==NULL)
  { head=p;
  }
  else
  { q=head;
    while(q->next!=NULL)
    { q=q->next;
    }
    q->next=p;
  }
}

void func::insert_middle(int key)
{ node *q;
  node *p;
  cout<<"enter elements to be entered (prn and name)\n";
  p=new node;
  cin>>(p->prn)>>(p->name);
  p->next=NULL;
  if(head==NULL)
  { head=p;
  }
  else
  { q=head;
    while(key!=q->prn&&q!=NULL)
    { q=q->next;
    }
    if(q!=NULL)
    {
    p->next=q->next;
    q->next=p;
    }
  }
}

void func::delete_start()
{  node *p;
   if(head->next==NULL)
   { delete head;
     head=NULL;
   }
   else if(head!=NULL)   
   {
      p=head;
      head=head->next;
      delete p;
   }
}

void func::delete_end()
{  node *p,*q;
   if(head->next==NULL)
   { delete head;
     head=NULL;
   }
   else if(head!=NULL)
   {  p=head;
      while((p->next)->next!=NULL)
      { p=p->next;
      }
      q=p->next;
      delete q;
      p->next=NULL;
   }
}
      
void func::delete_middle(int key)
{ node *p,*q;
  if(key==head->prn)
  {  p=head;
     head=head->next;
     delete p;
  }
  else
  { p=head;
    while(key!=(p->next)->prn&&p->next!=NULL)
    { p=p->next;
    }
    q=p->next;
    p->next=q->next;
    delete q;
  }
}

int func::no()
{  int i;
   node *p;
   p=head;
   i=0;
   while(p!=NULL)
   { i++;
     p=p->next;
   }
   return(i);
}


void func::concatenate(func &q)
{   node *p;
    if(head==NULL)
    head=q.head;
    p=head;
    while(p->next!=NULL)
    p=p->next;
    p->next=q.head;
}

void func::reverse()
{  node *p,*q,*r;
   p=NULL;
   q=head;
   r=q->next;
   while(q!=NULL)
   { q->next=p;
     p=q;
     q=r;
     if(r!=NULL)
     r=r->next;
   }
   head=p;
   }


