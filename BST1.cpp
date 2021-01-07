#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val;
    node *lnode;
    node *rnode;
};

void insertNode(int val, node *ptr);
node* deleteNode(int val, node *ptr);
node* findMinNode(node *ptr);
node* searchNode(int val, node *ptr);
void traverse_Level_Order(node *ptr);

int main(){
    node *root = new node;
    root-> val = 100;
    root-> lnode = NULL;
    root-> rnode = NULL;

    node *ptr = root;
    cout<< "```Ready go"<<endl;
    insertNode(200, ptr);
    insertNode(50, ptr);
    insertNode(20, ptr);
    insertNode(30, ptr);
    insertNode(200, ptr);
    insertNode(10, ptr);
    cout<< "```Insert done"<<endl;

    traverse_Level_Order(root);
    
    node *search_node;
    search_node = searchNode(20, ptr);
    if(search_node)
        cout<<"Find node: "<<ptr->val<<endl;
    else
        cout<<"Node not find"<<endl;

    search_node = searchNode(70, ptr);
    if(search_node)
        cout<<"Find node: "<<ptr->val<<endl;
    else
        cout<<"Node not find"<<endl;
    

    node *delNode;
    cout<<endl<<"Delete node 5:"<<endl;
    delNode = deleteNode(5, ptr);
    if(delNode==NULL)
        cout<<"Delete: Node not find"<<endl;
    else
        traverse_Level_Order(ptr);


    cout<<endl<<"Delete node 50:"<<endl;
    delNode = deleteNode(50, ptr);
    if(delNode==NULL)
        cout<<"Delete: Node not find"<<endl;
    else
        traverse_Level_Order(ptr);

    cout<<endl<<"Delete node 20:"<<endl;
    delNode = deleteNode(20, ptr);
    if(delNode==NULL)
        cout<<"Delete: Node not find"<<endl;
    else
        traverse_Level_Order(ptr);

    return 0;
}

void insertNode(int val, node *ptr){
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

node* deleteNode(int val, node *ptr){
    node *findNode = searchNode(val, ptr);
    if(findNode==NULL){
        return NULL;
    }

    if(ptr==NULL)
        return ptr;
    else if(val < ptr->val)
        ptr->lnode = deleteNode(val, ptr->lnode);
    else if(val > ptr->val)
        ptr->rnode = deleteNode(val, ptr->rnode);
    else{
        // 1. ptr with no child
        if(ptr->lnode==NULL && ptr->rnode==NULL){
            ptr = NULL;
            return ptr;
        }
        // 2. ptr with 1 child
        else if(ptr->lnode==NULL){
            node *tmpNode = ptr;
            ptr = ptr->rnode;
            delete tmpNode;
            return ptr;
        }
        else if(ptr->rnode==NULL){
            node *tmpNode = ptr;
            ptr = ptr->lnode;
            delete tmpNode;
            return ptr;
        }
        // 3. ptr with 2 children: 
        //      change ptr to right-tree's node with smallest val
        //      link rnode with tree with that node deleted.
        else{
            node *minNode = findMinNode(ptr->rnode);
            ptr->val = minNode->val;
            ptr->rnode = deleteNode(minNode->val, ptr->rnode);
        }
    }
}

node* findMinNode(node *ptr){
    while(ptr->lnode != NULL){
        ptr = ptr->lnode;
    }
    return ptr;
}

node* searchNode(int val, node *ptr){
    while(ptr!=NULL){
        if(ptr-> val == val){
            return ptr;
        }else if(val < ptr-> val && ptr->lnode){
            ptr = ptr->lnode;
        }else if(val > ptr-> val && ptr->rnode){
            ptr = ptr->rnode;
        }else{
            return NULL;
        }
    }
    return NULL;
}

void traverse_Level_Order(node *ptr){
    vector<node *> stk;
    stk.push_back(ptr);
    node *current = ptr;

    cout<<"Traverse in order:"<<endl;
    cout<<"\t";
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
