/*
解题思路：
递归建立二叉树，边读取数据边建立结点，当读取到的数据是'#'时表示当前是一个空结点，直接返回0
否则就用读取到的数据建立当前节点，然后递归建立左右子树。
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct Node{
    char ch;
    Node *LC,*RC;
    Node(char ch,Node* lc=0,Node* rc=0):ch(ch),LC(lc),RC(rc){}
};

Node* BuildTree(){
    char ch;
    cin>>ch;
    if(ch == '#') return 0;
    Node* node = new Node(ch);
    node->LC = BuildTree();
    node->RC = BuildTree();
    return node;
}

void inOrder(Node* rt){
    if(rt==0) return;
    inOrder(rt->LC);
    cout<<rt->ch<<" ";
    inOrder(rt->RC);
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    Node * rt = BuildTree();
    inOrder(rt);

    return 0;
}