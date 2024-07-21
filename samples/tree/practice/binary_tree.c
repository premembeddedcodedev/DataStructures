#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *next;
}TreeNode;

typedef struct queue {
	int front;
	int rear;
	int bound;
	TreeNode *node[MAX];
}qdata;

void queue_init(qdata *q)
{
	q->front = 0;
	q->rear = 0;
	printf("Enter the number of nodes: ");
	scanf("%d", &q->bound);
}

void pre_order_trav(TreeNode *root)
{
	if(!root)
		return;

	printf("%d ", root->data);
	pre_order_trav(root->left);
	pre_order_trav(root->right);
}

void enqueue(qdata *q, TreeNode *node)
{
	if(q->rear >= q->bound) // compating with maximum value instead of lessthan to front
		return;

	q->node[++q->rear] = node;
}

bool qempty(qdata *q)
{
	if(q->rear == q->front)
		return true;

	return false;
}

TreeNode* dequeue(qdata *q)
{
	q->front++;
	return q->node[q->front];
}

void bfs(TreeNode *root, qdata *q)
{
	printf("\nBFS : ");
	enqueue(q, root);

	while(!qempty(q)) {
		TreeNode *temp = dequeue(q);
		printf("%d ", temp->data);

		if(temp->left)
			enqueue(q, temp->left);
		if(temp->right)
			enqueue(q, temp->right);
	}
	printf("\n");
}

TreeNode* create_tree()
{
	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
	if(!root)
		return NULL;

	printf("Enter Node value: ");
	scanf("%d",&root->data);

	if(root->data == 0) {
		free(root);
		return NULL;
	}

	root->left = create_tree();
	root->right = create_tree();

	return root;
}

//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
//TODO: need to reverse the created arrays below mentioned <<== here
int** levelOrderBottom(TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	qdata q;

	if(!root)
		return NULL;

	queue_init(&q);

	int **result = (int **) malloc (sizeof(int *) * q.bound);
	*returnColumnSizes = (int *) malloc (sizeof(int) * q.bound);

	if(!result)
		return NULL;

	enqueue(&q, root);

	while(!qempty(&q)) {
		int levelSize = q.rear - q.front;
		result[*returnSize] = (int *) malloc (sizeof(int) * levelSize);
		(*returnColumnSizes)[*returnSize] = levelSize;
		for(int i = 0; i<levelSize; i++) {
			TreeNode *temp = dequeue(&q);
			result[*returnSize][i] = temp->data; //TODO : <<== reverse the array
			if(temp->left)
				enqueue(&q, temp->left);

			if(temp->right)
				enqueue(&q, temp->right);
		}
		(*returnSize)++;
	}

	return result;
}

//https://leetcode.com/problems/average-of-levels-in-binary-tree/
double* averageOfLevels(TreeNode* root, int* returnSize)
{
	if(!root)
		return NULL;

	qdata q;

	queue_init(&q);

	double *retArray = (double *) malloc (sizeof(double) * q.bound);
	if(!retArray)
		return NULL;

	enqueue(&q, root);

	double avg;

	while(!qempty(&q)) {
		int levelSize = q.rear - q.front;
		for(int i = 0; i<levelSize; i++) { // each level we will get elements just dividing with levelsize will give avg of the level
			TreeNode *temp = dequeue(&q);
			avg += temp->data;
			if(temp->left)
				enqueue(&q, temp->left);
			if(temp->right)
				enqueue(&q, temp->right);
		}
		avg /= levelSize; //here we are dividing
		retArray[*returnSize] = avg;
		printf("avg : %f", avg);
		avg = 0; // dont forgot to keep 0 here
		(*returnSize)++; 
	}

	return retArray;
}

TreeNode* connect_withoutq(TreeNode* root)
{
	if(!root)
		return NULL;
	
	TreeNode *leftMost = root;

	while(leftMost->left) {
		TreeNode *curr = leftMost;
		while(curr) {
			curr->left->next = curr->right;
			if(curr->next != NULL)
				curr->right->next = curr->next->left;
			curr = curr->next;
		}
		leftMost = leftMost->left;
	}
	return root;
}

int** zigzagLevelOrderWithQ(TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if(!root)
		return NULL;

	qdata q;

	queue_init(&q);

	int **result = (int **) malloc (sizeof(int *) * q.bound);
	if(!result)
		return NULL;
	*returnColumnSizes = (int *) malloc (sizeof(int) * q.bound);
	if(!(*returnColumnSizes))
		return NULL;

	enqueue(&q, root);
	bool reverse = false;
	while(!qempty(&q)) {
		int levelSize = q.rear - q.front;
		(*returnColumnSizes)[*returnSize] = levelSize;
		result[*returnSize] = (int *) malloc (sizeof(int) * levelSize);
		for(int i =0; i<levelSize; i++) {
			TreeNode *temp = dequeue(&q);
			if(reverse) { // alternative level reverse so keeping condition here.
				if(temp->left)
					enqueue(&q, temp->left);
				if(temp->right)
					enqueue(&q, temp->right);
			} else {
				if(temp->right)
					enqueue(&q, temp->right);
				if(temp->left)
					enqueue(&q, temp->left);
			}
			result[*returnSize][i] = temp->data;
		}
		reverse = !reverse; // toggling if and else condition in above.
		(*returnSize)++;
	}
	return result;
}

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
TreeNode* connect(TreeNode* root)
{
	if(!root)
		return NULL;

	qdata q;
	queue_init(&q);

	enqueue(&q, root);
	while(!qempty(&q)) {
		int levelSize = q.rear - q.front;
		TreeNode *head = NULL, *curr;
		for(int i =0; i<levelSize; i++) {
			TreeNode *temp = dequeue(&q);				
			if(temp->left)
				enqueue(&q, temp->left);
			if(temp->right)
				enqueue(&q, temp->right);
			temp->next = NULL; // every level making NULL remaind this is next not left or right
			if(!head) {
				head = temp;
				curr = head; //this is the main logic
			} else {
				curr->next = temp;
				curr = temp;
			}
		}
	}
	return root;	
}

//https://leetcode.com/problems/binary-tree-right-side-view/
int* rightSideView(TreeNode* root, int* returnSize) 
{
	if(!root)
		return NULL;


	qdata q;
	queue_init(&q);

	int *result = (int *) malloc(sizeof(int) * q.bound);
	enqueue(&q, root);
	while(!qempty(&q)) {
		int levelSize = q.rear - q.front;
		for(int i =0; i<levelSize; i++) {
			TreeNode *temp = dequeue(&q);

			if(i == levelSize - 1) // this is the main logic levelsize-1 always gives rightside view
				result[*returnSize] = temp->data;

			if(temp->left)
				enqueue(&q, temp->left);
			if(temp->right)
				enqueue(&q, temp->right);
		}
		(*returnSize)++;
	}
	return result;

}

TreeNode *findnode(TreeNode *root, int x)
{
	if(!root) //exit condition traverse till end
		return NULL;
	if(root->data == x) // exit when current node finds the value till finds
		return root;

	TreeNode *Node = findnode(root->left, x);
	if(!Node)
		return Node;

	return findnode(root->right, x);
}

bool isSiblings(TreeNode *root, TreeNode *NodeX, TreeNode *NodeY)
{
	if(!root)
		return false;
	return (root->left == NodeX && root->right == NodeY) || (root->left == NodeY && root->right == NodeX) || isSiblings(root->left, NodeX, NodeY) || isSiblings(root->right, NodeX, NodeY);
}

int level(TreeNode *root, TreeNode *NodeX, int Currentlevel)
{
	// same logic as find node -- instead printing integer
	if(!root) // root node always at level 0 and using for exiting the recursion as well
		return 0;

	if(root == NodeX)
		return Currentlevel;

	int clevel = level(root->left, NodeX, Currentlevel+1); // every level  + 1, starts from 0
	if(clevel != 0)
		return clevel;

	return level(root->right, NodeX, Currentlevel+1);
}

//https://leetcode.com/problems/cousins-in-binary-tree/description/
bool isCousins(TreeNode* root, int x, int y)
{
	/* Logic: 
	 * 1. find the nodes because we got integers in the function
	 * 2. check the levels are same and with different parents
	 * 3. above condition holds true then cousins otherwise No.
	 * 
	 * */

	TreeNode *NodeX = findnode(root, x);
	TreeNode *NodeY = findnode(root, y);

	return ((level(root, NodeX, 0) == level(root, NodeY, 0)) && (!isSiblings(root, NodeX, NodeY)));
}

int main()
{
	TreeNode *root = create_tree();		
	if(!root)
		return -1;
#if 1
	int x, y;

	printf(" enter nodes for sibling check : \n");
	scanf("%d %d", &x, &y);

	printf("iscousins : %s\n", isCousins(root, x, y) ? "yes": "no");
#endif 
#if rightSideView	
	int returnSize = 0;

	int *result = rightSideView(root, &returnSize);

	for(int i = 0; i<returnSize; i++)
		printf("%d, ", result[i]);
#endif

#if linkedlist
	TreeNode *curr, *list = connect_withoutq(root);

	curr = list;
	printf("Linked list : ");
	while(curr) {
		TreeNode *temp;
		temp = curr;
		printf("Node @%d : [", curr->data);
		while(temp) {
			printf("%d, ", temp->data);
			temp = temp->next;
		}
		printf("]\n");
		curr = curr->left;
	}
#endif
#if connect
	TreeNode *curr, *list = connect(root);

	curr = list;
	printf("Linked list : ");
	while(curr) {
		TreeNode *temp;
		temp = curr;
		printf("Node @%d : [", curr->data);
		while(temp) {
			printf("%d, ", temp->data);
			temp = temp->next;
		}
		printf("]\n");
		curr = curr->left;
	}
#endif
#if zigzagLevelOrderWithQ
	int returnSize = 0, *returnColumnSizes[10];

	int **result = zigzagLevelOrderWithQ(root, &returnSize, returnColumnSizes);
	if(!result)
		return -1;

	printf("level order bottom : [");
	for(int i = 0; i<returnSize; i++) {
		printf("[");
		for(int j = 0; j<(*returnColumnSizes)[i]; j++) {
			printf("%d, ", result[i][j]);
		}
		printf("]");
	}
	printf("]\n");

	free(*returnColumnSizes);
	free(result);
#endif

#if levelOrderBottom //TODO: need to write from reverse but nt from stright
	int returnSize = 0, *returnColumnSizes[10];
	int **result = levelOrderBottom(root, &returnSize, returnColumnSizes);
	if(!result)
		return -1;
	printf("level order bottom : [");
	for(int i = 0; i<returnSize; i++) {
		printf("[");
		for(int j = 0; j<(*returnColumnSizes)[i]; j++) {
			printf("%d, ", result[i][j]);
		}
		printf("]");
	}
	printf("]\n");

	free(*returnColumnSizes);
	free(result);
#endif

#if averageOfLevels
	int returnSize = 0;
	double *result = averageOfLevels(root, &returnSize);
	if(!result)
		return -1;

	printf("avg level : [");
	for(int i=0; i<returnSize; i++) {
		printf("%f, ", result[i]);
	}
	printf("]\n");
	free(result);
#endif

#if bfs
	qdata q;

	queue_init(&q);

	printf("Printing pre order traversal: ");
	pre_order_trav(root);

	bfs(root, &q);
#endif
	return 0;
}
