/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};



int getMin(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int count(struct node *root)
{
	if (root == NULL)
		return INT_MAX;
	if (root->left == NULL && root->right == NULL)
		return 0;

	return 1 + getMin(count(root->left), count(root->right));
}

int get_dist(struct node *root, int k, struct node *nodes[],int index)
{
	
	if (root == NULL)
		return INT_MAX;

	
	if (root->data == k)
	{
		int res = count(root);

		
		for (int i = index - 1; i >= 0; i--)
			res = getMin(res, index - i + count(nodes[i]));
		return res;
	}

	
	nodes[index] = root;
	return getMin(get_dist(root->left, k, nodes, index + 1),get_dist(root->right, k, nodes, index + 1));

}


int find(struct node *root, int k)
{
	struct node *nodes[100];

	return get_dist(root, k, nodes, 0);
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL||temp==NULL)
      return -1;

	return find(root, temp->data);
}