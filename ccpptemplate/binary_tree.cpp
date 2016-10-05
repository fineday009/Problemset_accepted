/*edit by tfans 2016-10-05*/
//refs:http://blog.csdn.net/hackbuteer1/article/details/6583988
#include<iostream>
#include<cstdio>
#include<cstdlib>  
#include<queue>  
#include<stack>  
#include<vector>
using namespace std; 

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preorder.size() == 0 || preStart > preEnd || inStart > inEnd) return NULL;
    
    TreeNode *root = new TreeNode(preorder[preStart]);
    int index;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == preorder[preStart]) {
            index = i;
            break;
        }
    }
    
    root->left = createTree(preorder, inorder, preStart + 1, preStart + index - inStart, inStart, index-1);
    root->right = createTree(preorder, inorder, preStart + index-inStart+1, preEnd, index+1, inEnd);
    
    return root;
}

TreeNode *buildTreeFromPreorderAndInorderSequence(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) return NULL;
    return createTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

void CreateBiTreeByAskingOneByOne(TreeNode** root)
{
	int ch; //要插入的数据  
    scanf("%d", &ch);
    if(ch==-1)
        *root = NULL;
    else
    {
		*root = new TreeNode(ch);
        printf("请输入%d的左孩子：",ch);
        CreateBiTreeByAskingOneByOne(&((*root)->left));
        printf("请输入%d的右孩子：",ch);
        CreateBiTreeByAskingOneByOne(&((*root)->right));
    }
}

void printTraversalAnswer(vector<int> ans)
{
	for(int i=0, size=ans.size(); i<size; i++) 
		printf("%d%c", ans[i], (i==size-1)?'\n':' ');
}

void printTraversalAnswer2D(vector<vector<int> > ans)
{
	if(ans.size()==0) return;
	for(int i=0, size=ans.size(); i<size; i++) 
		for(int j=0, sizej=ans[i].size(); j<sizej; j++)
			printf("%d%c", ans[i][j], j==sizej-1?'\n':' ');
}

vector<int> preOrderTraversal(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> st;
	
	st.push(root);
	while(!st.empty()){
		//访问根
		TreeNode* tp=st.top();
		ans.push_back(tp->val);
		st.pop();
		
		if(tp->right) st.push(tp->right);
		if(tp->left) st.push(tp->left);
	}
	return ans;
}

vector<int> inOrderTraversal(TreeNode* root)
{
	if(root==NULL) return vector<int>();
    vector<int> ans;
	stack<TreeNode*> st;
	TreeNode* q=root;
	
	//向左走到尽头
	while(q){
		st.push(q);
		q=q->left;	
	}	

	while(!st.empty()){
		//访问根
		TreeNode* tp=st.top();
		ans.push_back(tp->val);
		st.pop();
		
		//转向，继续向左走到尽头
		q=tp->right;
		while(q){
			st.push(q);
			q=q->left;	
		}
	}

	return ans;
}

vector<int> postOrderTraversal_1_stack(TreeNode* root)
{
	if(root==NULL) return vector<int>();
    vector<int> ans;
	stack<TreeNode*> s1; 
	TreeNode* q=root, *lastVisited=NULL;
	//类似中序，向左走到底
	while(q){
	    s1.push(q);
	    q=q->left;
	}
	
	while(!s1.empty()){
		TreeNode* tp=s1.top();
		if(tp->right && lastVisited!=tp->right){
		    //转向，继续向左走到底
		    q=tp->right;
		    while(q){
		        s1.push(q);
		        q=q->left;
		    }
		}else{
		    //real visit time
		    TreeNode* tp=s1.top();
		    ans.push_back(tp->val);
		    s1.pop();
		    lastVisited=tp;
		}
	}

	return ans;
}

vector<int> postOrderTraversal_2_stack(TreeNode* root)
{
	if(root==NULL) return vector<int>();
    vector<int> ans;
	stack<TreeNode*> s1, s2; s1.push(root);
	
	while(!s1.empty()){
		TreeNode* tp=s1.top(); s1.pop(); 
		s2.push(tp);
		if(tp->left) s1.push(tp->left);
		if(tp->right) s1.push(tp->right);
	}

	while(!s2.empty()){
		ans.push_back(s2.top()->val);
		s2.pop();	
	}

	return ans;
}

vector<vector<int> > levelOrder(TreeNode* root)
{
	if(root==NULL) return vector<vector<int> >();
	vector<vector<int> > ans;
	vector<int> perline;
	TreeNode* lastPerline=root;
	
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode* front=q.front();	
		perline.push_back(front->val);
		q.pop();

		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);
		
		if(front==lastPerline){
			ans.push_back(perline);
			perline.clear();
			lastPerline=q.back();
		}
	}
	
	return ans;
}

int depth(TreeNode* root)
{
	if(root==NULL) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

int CountNode(TreeNode* root)
{
	if(root==NULL) return 0;
	return CountNode(root->left) + CountNode(root->right) + 1;
}

int main(void)  
{  
    TreeNode *root=NULL; //定义一个根结点  
    int flag=1,k;  
	int pre[]={1,2,4,6,5,3};
	int in[]={4,6,2,5,1,3};
	vector<int> preorder(pre, pre+sizeof(pre)/sizeof(int)), inorder(in, in+sizeof(in)/sizeof(int));

    printf("                     本程序实现二叉树的基本操作。\n");  
    printf("可以进行建立二叉树，递归先序、中序、后序遍历，非递归先序、中序遍历及非递归层序遍历等操作。\n");  
  
    while(flag)  
    {  
        printf("\n");  
        printf("|--------------------------------------------------------------|\n");  
        printf("|                    二叉树的基本操作如下:                     |\n");  
        printf("|                        0.递归创建二叉树                          |\n");  
        printf("|                        1.非递归先序遍历                        |\n");  
        printf("|                        2.非递归中序遍历                        |\n");  
        printf("|                        3.非递归后序遍历                        |\n");  
        printf("|                        7.非递归层序遍历                      |\n");  
        printf("|                        8.二叉树的深度                        |\n");  
        printf("|                        9.二叉树的结点个数                    |\n");  
        printf("|                        10.退出程序                            |\n");  
        printf("|--------------------------------------------------------------|\n");  
        printf("                        请选择功能：");  
        scanf("%d",&k);
        switch(k)  
        {  
        case 0:  
            //printf("请建立二叉树并输入二叉树的根节点：");  
			//CreateBiTreeByAskingOneByOne(&root);  
			root=buildTreeFromPreorderAndInorderSequence(preorder, inorder);
			printf("二叉树新建完毕...\n");
            break;  
        case 1:  
            if(root)  
            {  
                printf("非递归先序遍历二叉树的结果为：");  
                printTraversalAnswer(preOrderTraversal(root));  
                printf("\n");  
            }  
            else  
                printf("          二叉树为空！\n");  
            break;  
        case 2:  
            if(root)  
            {  
                printf("非递归中序遍历二叉树的结果为：");  
                printTraversalAnswer(inOrderTraversal(root));  
                printf("\n");  
            }  
            else  
                printf("          二叉树为空！\n");  
            break;  
        case 3:  
            if(root)  
            {  
                printf("非递归后序遍历二叉树的结果(使用1个栈和一个变量)\n");  
                printTraversalAnswer(postOrderTraversal_1_stack(root));  
				printf("非递归后序遍历二叉树的结果((使用两个栈模拟遍历过程))\n"); 
				printTraversalAnswer(postOrderTraversal_2_stack(root)); 
                printf("\n");  
            }  
            else  
                printf("          二叉树为空！\n");  
            break;  
        case 7:  
            if(root)  
            {  
                printf("非递归层序遍历二叉树：\n");  
                //LeverTraverse(root);  
                printTraversalAnswer2D(levelOrder(root));  
                printf("\n");  
            }  
            else  
                printf("          二叉树为空！\n");  
            break;  
        case 8:  
            if(root)  
                printf("这棵二叉树的深度为：%d\n",depth(root));  
            else  
                printf("          二叉树为空！\n");  
            break;  
        case 9:  
            if(root)  
                printf("这棵二叉树的结点个数为：%d\n",CountNode(root));  
            else  
                printf("          二叉树为空！\n");  
            break;  
        default:  
            flag=0;  
            printf("程序运行结束，按任意键退出！\n");  
        }  
    }  
    system("pause");  
    return 0;  
}
