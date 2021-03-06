/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

static int i = 0;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void checkBST(struct node *root, struct node **first, struct node **mid, struct node **last, struct node **prev)
{

	if (root!=NULL)
	{
		
		checkBST(root->left, first, mid, last, prev);

		if (*prev!=NULL && root->data < (*prev)->data)
		{
			if (*first==NULL)
			{
				*first = *prev;
				*mid = root;
			}

	    	else
				*last = root;
		}
		*prev = root;
		checkBST(root->right, first, mid, last, prev);
	}
}
	

void fix_bst(struct node *root)
{


	struct node *first, *mid, *last, *prev;
	first = NULL;
	mid = NULL;
	last = NULL;
	prev = NULL;

	
	checkBST(root, &first, &mid, &last, &prev);

	if (first != NULL && last != NULL)
		swap(&(first->data), &(last->data));

	else if (first!=NULL && mid!=NULL) 
		swap(&(first->data), &(mid->data));

}
	