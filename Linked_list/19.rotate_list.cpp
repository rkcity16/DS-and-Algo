/*Given a linked list, rotate the list to the right by k places,
where k is non-negative.*/

#include <iostream>
using namespace std;

struct node {
  int data;
  node* link;
  node(int item){
    data=item;
    link=NULL;
  }
};
void insert_data(node* &head, int item) {
  if(head==NULL)
    head=new node(item);
  else{
    node* temp=head;
    while(temp->link!=NULL)
      temp=temp->link;
    temp->link=new node(item);
  }
}

void show_data(node* head) {
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->link;
  }
}

int list_size(node* h){
  int n=0;
  while(h!=NULL){
    n++;
    h=h->link;
  }
  return n;
}


node* rotate_list(node* head,int k){
    node* temp=head;
    int size=list_size(head);
    if(size!=0)
      k=k%size;
    if(k==0){
      return  head;
    }
    int m=size-k;
    if(m<=0)
      return head;
    while(m-1!=0){
      head=head->link;
      m--;
    }
    node* new_head=head->link;
    node* t=new_head;
    while(t->link!=NULL)
      t=t->link;
    t->link=temp;
    head->link=NULL;
    return new_head;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,44);
  insert_data(HEAD,15);
  insert_data(HEAD,23);
  insert_data(HEAD,19);
  insert_data(HEAD,43);
  insert_data(HEAD,18);
  cout<<"Linked list : ";
  show_data(HEAD);
  int k;
  cout<<"\nk :";
  cin>>k;
  cout<<"\nAfter "<<k<<" rotations, Linked list : ";
  HEAD=rotate_list(HEAD,k);
  show_data(HEAD);
  return 0;
}
