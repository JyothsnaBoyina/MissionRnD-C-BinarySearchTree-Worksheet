/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

static int i = 0, lh = 0, rh = 0;



int get_height1(struct node *root){


	if (root == NULL)
		return 0;

	int lh = get_height1(root->left);
	int rh = get_height1(root->right);

	if (lh >= rh)
		return lh + 1;
	else
		return rh + 1;
}

void BSTarray(struct node* root, int *arr,int h)
{
	if (root == NULL)
		return;
	if (h == 1)
	{
		arr[i] = root->data;
		i++;
	}
	else if (h > 1)
	{
		BSTarray(root->right,arr, h - 1);
		BSTarray(root->left, arr, h - 1);
	}
	
}




int* BSTRighttoLeftRows(struct node* root)
{
	
	if (root == NULL)
		return NULL; 
	
	int *arr;
	arr = (int*)malloc(20*sizeof(int));

	i = 0;

	int h = get_height1(root);

	for (int j = 1; j <= h;j++)
		BSTarray(root, arr,j);
   
	return arr;

}



