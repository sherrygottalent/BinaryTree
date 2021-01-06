#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val;
    node *lnode;
    node *rnode;
};

void insert(int val, node *ptr);
void traverse_Level_Order(node *ptr);

int main(){
    node *root = new node;
    root-> val = 100;
    root-> lnode = NULL;
    root-> rnode = NULL;

    node *ptr = root;
    cout<< "ready go"<<endl;
    insert(200, ptr);
    insert(50, ptr);
    insert(20, ptr);
    insert(30, ptr);
    insert(200, ptr);
    insert(10, ptr);
    cout<< "insert done"<<endl;

    traverse_Level_Order(root);

    return 0;
}

void insert(int val, node *ptr){
    cout<<"--- Insert "<<val<<" ---"<<endl;
    node *newNode = new node;
    newNode->val = val;
    newNode->lnode = NULL;
    newNode->rnode = NULL;

    while(1){
        if(ptr->val==val){
            cout<< "!! Node noted !!"<<endl;
            break;

        }else if(val < ptr->val && ptr->lnode == NULL){
            cout<< "L null\n";
            ptr->lnode = newNode;
            break;

        }else if(val < ptr->val && ptr->lnode != NULL){
            cout<< "L not null\n";
            ptr = ptr->lnode;

        }else if(val > ptr->val && ptr->rnode == NULL){
            cout<< "R null\n";
            ptr->rnode = newNode;
            break;

        }else if(val > ptr->val && ptr->rnode != NULL){
            cout<< "R not null\n";
            ptr = ptr->rnode;

        }
    }
}

void traverse_Level_Order(node *ptr){
    vector<node *> stk;
    stk.push_back(ptr);
    node *current = ptr;

    cout<<"Traverse in order:"<<endl;
    while(stk.size()>0){
        current = stk.front();    
        cout<< current->val<<" ";
        if(current-> lnode!=NULL){
            stk.push_back(current->lnode);
        }
        if(current->rnode!=NULL){ 
            stk.push_back(current->rnode);
        }
        stk.erase(stk.begin());
    }
    cout<<endl;
}
