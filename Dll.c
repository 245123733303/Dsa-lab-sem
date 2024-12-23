#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
	struct node *prev;

};
struct node *first=NULL,*last=NULL;
int ls=0;
void insertatbeg(int);
void insertatend(int);
void insertatpos(int,int);  
void delfrombeg();
void delfromend();
void delfrompos(int);
void search(int);
void forwarddisplay();
void backwarddisplay();
void main()
{
        int x,ch,pos;
	while(1){
        printf("\n MENU \n======================\n 1.INSERTA AT BEG\n2.INSERTA AT END\n3.INSERTA AT random position\n4.DELETE FROM BEG\n5.DELETE FROM enD\n6.DELETE FROM random position\n7.Search\n8.forwardDISPLAY\n9.BACKWARD DISPLAY10.EXIT\n");
                printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1:printf("enter element");
                               scanf("%d",&x);
                               insertatbeg(x);
                               break;
                        case 2:printf("enter element");
                               scanf("%d",&x);
                               insertatend(x);
                               break;
                        case 3:printf("enter element");
                               scanf("%d",&x);
                              printf("enter position");
                               scanf("%d",&pos);
                               insertatpos(x,pos);
                               break;
                        case 4:delfrombeg();
                              break;
                        case 5:delfromend();
                              break;
                        case 6: printf("enter position");
                               scanf("%d",&pos);
                               delfrompos(pos);
                               break;
                        case 7: printf("enter element");
                                scanf("%d",&x);
                                search(x);
                                break;
                        case 8: forwarddisplay();
                                break;
			case 9: backwarddisplay();
				break;
                        default:exit(0);
		}
	}
}
void insertatbeg(int x)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=x;
	nn->next=NULL;
	nn->prev=NULL;
	if(first==NULL)
	{
		first=nn;
		last=nn;
		ls++;
	}
	else{
		nn->next=first;
		first->prev=nn;
		first=nn;
		ls++;
	}
}
void insertatend(int x)
{
        struct node *nn;
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=x;
        nn->next=NULL;
        nn->prev=NULL;
        if(first==NULL)
        {
                first=nn;
                last=nn;
                ls++;
        }  
        else{
         last->next=nn;
         nn->prev=last;
	 last=nn;
	 ls++;
	}
}
void insertatpos(int x,int pos)
{
        struct node *nn,*temp;
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=x;
        nn->next=NULL;
        nn->prev=NULL;
        if(pos<1||pos>(ls+1))
	{
		printf("invalid postion");
		return;
	}

	if(pos==1)
        {
             if(first==NULL)
	     {
		first=nn;
                last=nn;
                ls++;
        }
	     else{
		     nn->next=first;
		     first->prev=nn;
		     first=nn;
		     ls++;
	     }
	}
         else if(pos==(ls+1))
	 {
		 last->next=nn;
		 nn->prev=last;
		 last=nn;
		 ls++;
	 }
	else{
		if(pos<=(ls/2)){
			temp=first;
                        for(int i=1;i<pos-1;i++)
				temp=temp->next;
		nn->next=temp;
		temp->next->prev=nn;
		temp->next=nn;
		nn->prev=temp;
		ls++;
		}
		else{
			temp=last;
			for(int i=ls;i>pos-1;i--)
				temp=temp->prev;
		nn->next=temp->next;
		temp->next->prev=nn;				
		temp->next=nn;
		nn->prev=temp;
		ls++;
		}
	}
}
void delfrombeg()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("list is empty");
return;
	}
	if(first->next==NULL)
	{
		temp=first;
		first=last=NULL;
		free(temp);
		ls--;
	}
	else{
		temp=first;
		first=first->next;
		first->prev=NULL;
		free(temp);
		ls--;
	}
}
void delfromend(){
	struct node *temp;
        if(first==NULL)
        {
                printf("list is empty");
return;
        }
        if(first->next=NULL)
        {
                temp=first;
                first=last=NULL;
                free(temp);
                ls--;
        }
        else{
               temp=last;
	       last=last->prev;
	       last->next=NULL;
	       free(temp);
	       ls--;
	}
}
void forwarddisplay()
{
	struct node*temp;
	if(first==NULL)
	{
		printf("list is empty");
		return;
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void backwarddisplay()
{
        struct node*temp;
        if(first==NULL)
        {
                printf("list is empty");
                return;
        }
        temp=last;
        while(temp!=NULL)
        {
                printf("%d\t",temp->data);
                temp=temp->prev;
        }
}
void delfrompos(int pos)
{
	struct node*temp;
	if(pos<1||pos>ls)  
	{
		printf("invalid position");
		return;
	}
	if(pos==1)
	{
		temp=first;
		first=first->next;
		if(first==NULL)
		{
			last=NULL;
		}
			else{
				first->prev=NULL;
			free(temp);
			ls--;
			return;
		}
	}
	else if(pos==ls)
	{
			temp=last;
			last=last->prev;
			last->next=NULL;
			free(temp);
			ls--;
			return;
		}
		else{
			if(pos<=(ls/2))
			{
				temp=first;
				for(int i=1;i<pos;i++)
					temp=temp->next;
				temp->prev->next=temp->next;
	        		temp->next->prev=temp->prev;
                                free(temp);
				ls--;
			}
			else{
				temp=last;
				for(int i=ls;i>pos;i--)
					temp=temp->prev;
			 temp->prev->next=temp->next;
			 temp->next->prev=temp->prev;
			 free(temp);
			 ls--;
			}
		}
	}
	void search(int ele)
	{
		struct node*temp;
		int pos=1;
		if(first==NULL)
		{
			printf("List is empty");
			return;
		}
		else{
			temp=first;
			while(temp!=NULL)
			{
				if(temp->data==ele)
				{
					printf("element found at %d position",pos);
					break;
				}
				else{
					temp=temp->next;
					pos++;
				}
			}
			if(temp==NULL)
			{
				printf("element is not present");
			}
		}
	}
