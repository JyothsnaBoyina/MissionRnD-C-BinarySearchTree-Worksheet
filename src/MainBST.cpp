/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}


int get_distance2(struct node *root, struct node *temp,int level) {

	if (root != NULL)
	{
		int x = 0;

		if (root->data == temp->data)
			return level;

		x = get_distance2(root->left, temp,level+1);
		x = get_distance2(root->right, temp,level+1);
			
	}
	else
	{
		return -1;
	}
}


int main(){

	//Use it for testing ,Creating BST etc


	struct node *root = NULL;
	int nums[20] = { 50, 25, 75, 15, 35,
		90, 5, 17, 45, 120,
		1, 7, 19, 39, 49,
		100, 20, 21, 22, 23
	};

	for (int i = 0; i < 20; i++){
		root = add_node_spec(root, nums[i]);
	}

	int results[20];
	inorder(root, results);

	for (int i = 0; i < 20; i++)
		printf(" in order element is : %d \n", results[i]);


	int ans = 3;
	int dist = get_closest_leaf_distance(root, root->left->left->right);

	printf("distance is : \t %d\t", dist);

	/*struct node *root = NULL;
	int nums[20] = { 50, 25, 75, 15, 35,
		90, 5, 17, 45, 120,
		1, 7, 19, 39, 49,
		100, 20, 21, 22, 23 };

	for (int i = 0; i < 20; i++){
		root = add_node_spec(root, nums[i]);
	}
	struct node *temp = root->left->left->right;
	int ans = 2;

	int results[20];
	inorder(root, results);

	for (int i = 0; i < 20; i++)
		printf(" in order element is : %d \n", results[i]);

	int results2[20];
	preorder(root, results2);

	for (int i = 0; i < 20; i++)
		printf(" in order element 2 is : %d \n", results2[i]);


	int dist = get_closest_leaf_distance(root, temp);

	int dist1 = get_distance2(root, temp, 0);


	printf("dist is : %d \n \t : %d\t ", dist, dist1); */

}