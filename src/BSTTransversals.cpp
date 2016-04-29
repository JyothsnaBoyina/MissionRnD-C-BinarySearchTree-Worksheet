/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void in(struct node* , int*);
void pre(struct node*, int*);
void post(struct node*, int*);

static int i=0, j=0, k=0;


void inorder(struct node *root, int *arr){

	i = 0;
	if (root != NULL&& arr != NULL)
	  in(root, arr);

}

void preorder(struct node *root, int *arr){

	j= 0;
	if (root != NULL&& arr != NULL)
		pre(root, arr);

	
	
}
void postorder(struct node *root, int *arr){

	k = 0;
	if (root != NULL&& arr != NULL)
		post(root, arr);
}


void in(struct node  *root, int *arr){

	if (root != NULL&& arr != NULL)
	{
		in(root->left, arr);
		arr[i] = root->data;
		i++;
		in(root->right, arr);

	}
}

void pre(struct node  *root, int *arr){

	if (root != NULL&& arr != NULL)
	{
		arr[j] = root->data;
		j++;
		pre(root->left, arr);
		pre(root->right, arr);
	}
}


void post(struct node  *root, int *arr){

	if (root != NULL&& arr != NULL)
	{
		post(root->left, arr);
		post(root->right, arr);
		arr[k] = root->data;
		k++;
	}
}





