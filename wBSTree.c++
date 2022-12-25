// Impliment Binary tree  
#include<iostream>
using namespace std;
class Node 
{
    public:
    int Data;
    Node *preL;
    Node *nextR;
    Node(int v)
    {
        Data = v;
        preL = NULL;
        nextR = NULL;
    }
    Node()
    {
        Data = 0;
        preL = NULL;
        nextR = NULL;
    }
    void Preorder()
    {
        if(this!=NULL)
        {
            cout<<Data<<" ";
            preL->Preorder();
            nextR->Preorder();
        }
    }
   
    void InOrder()
    {
        if(this!=NULL)
        {
            preL->InOrder();
            cout<<Data<<" ";
            nextR->InOrder();
        }
    }
    Node * Insert(int value)
    {
        if(this==NULL)
        Node *Root = new Node(value);
        else if(this->Data<value)
        this->nextR = this->nextR->Insert(value);
        else if(this->Data>value)
        this->preL = this->preL-> Insert(value);
    }
    Node * Minimum_()
    { 
       if(this==NULL)
       return NULL;
       else if(this->preL == NULL)
       return this;
       else
       this->preL->Minimum_();
       
       return this;

    }
     Node * Miximum_()
    { 
       if(this==NULL)
       return NULL;
       else if(this->nextR == NULL)
       return this;
       else
       this->nextR->Minimum_();

    }
    Node * Deletction(int value)
    {
        Node *temp;
        if(this==NULL)
        return NULL;
        else if(this->Data<value)
        this->nextR = this->nextR->Deletction(value);
        else if(this->Data >  value)
        this->preL = this->preL-> Deletction(value);
        else {
            if((this->preL==NULL)&&(this->nextR==NULL))  // Zero child Left and right both are NULL
            {
                delete this;
                return NULL;
            }
            if(this->preL==NULL) // Left NULL yani right mye element hai
            {
                Node *temp = this->nextR;   // jo delete karna hai uske next block ka address  save kr liya 
                delete this;  // ab Node delete kr diya 
                return temp;     // jo node save kiya tha vo temp mya ab vo return kr diya parent k pass   
            }
                 // Right NULL
            if(this->nextR== NULL) // jo node delete karna hai vo this mye hai to uska right node null hai ya nehi  vo check kr reha hai 
            {
                Node *temp = this->preL;  // jo delete kerna hai uske next block ka address save krna hai to vo temp mya save kr liya 
                delete this;  // then delete 
                return temp;   //  jo delete karna hai use next block ka address save kiya the to bo ab return kr diya parent k pass  
            }
            else {                                // Nothing is NULL Both side are Element ✨
                Node *temp= this->nextR->Minimum_(); // 😉find out preorder succeser  of current Node jo ki uske right ka subse minimum element hoga or usko temp mye save kerage  
                this->Data= temp ->Data;    // temp ki value copy kerni hai root ke data mai jo ki ab ye root ka right( ya left ) bn jyaga
                this->nextR = this->nextR->Deletction(temp->Data); // to ab hume temp ka data delete krna hai 
                // jo hmera root node tha uske right mye sye delete krna hai kuki humne vahi sye data liya tha (successer k lya ) 
                // to vo duplicate na ho jay eslya delete krna hai jo delete function return krega use current root ke right child bna denge 
            }
            return temp;
        }
    }
};
int main()
{
    Node *R = new Node(20);
    R->Insert(23);
    R->Insert(15);
    R->Insert(10);
    R->Insert(18);
    R->Insert(16);
    R->Insert(19);
    R->Insert(25);
    R->Insert(24);
    R->Insert(28);
    R->Insert(30);
    R->Insert(40);
   
    cout<<"\n";
    R->Deletction(16);
    R->Preorder();
    cout<<"\n";
   
}

