 /*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

static int lsum=0,rsum=0;

//**************************************************HELPER FUNCTIONS***********************************************//

void left_sum(struct node *root){

	if (root != NULL)
	{
		lsum = lsum + root->data;
		left_sum(root->left);
	}
	
}

void right_sum(struct node *root){

	if (root != NULL)
	{
		rsum = rsum + root->data;
		right_sum(root->right);
	}
	
}


//********************************************************************************************************************//



int get_height(struct node *root){


	if (root == NULL)
		return 0;
	
		int lh=get_height(root->left);
		int rh=get_height(root->right);
	
	if (lh >= rh)
		return lh+1;
	else
		return rh+1;
}


int get_left_subtree_sum(struct node *root){

	if (root == NULL)
		return -1;
	else if (root != NULL)
	{
		lsum = 0;
		left_sum(root->left);
	}
	return lsum;
}

int get_right_subtree_sum(struct node *root){
	
	if (root == NULL)
		return -1;
	else if (root != NULL)
	{
		rsum = 0;
		right_sum(root->right);
	}
	return rsum;
}

