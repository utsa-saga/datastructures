#include <iostream>
#define ARR_SIZE 80
using namespace std;

void insert_in_array(int* arr, int* size, int value);
int search_in_array(int* arr, int size, int value);
void delete_in_array(int* arr, int* size, int value);
void insert_in_sorted_array(int* arr, int* size, int value);
int search_in_sorted_array(int* arr, int low, int high, int value);
void delete_in_sorted_array(int* arr, int* size, int value);
void insertion_sort(int* arr, int size);
void print_array(int* arr, int size);

typedef struct Node { 
	int value; 
	struct Node* next; 
} Node;

typedef struct
{
    Node* head;
} List;

typedef struct TreeNode { 
	int value; 
	struct TreeNode* leftchild; 
	struct TreeNode* rightchild;
} TreeNode;

typedef struct BinarySearchTree
{
    TreeNode* root;
} BinarySearchTree;

Node* allocateNode(int value);
void insert_in_linkedlist(List* list, int value);
void search_in_linkedlist(List* list, int value);
void delete_in_linkedlist(List* list, int value);
void print_linkedlist(List* list);


TreeNode* allocateBSTNode(int value);
TreeNode* insert_in_bst(TreeNode* node, int value);
void search_in_bst(TreeNode* node, int value);
TreeNode* delete_in_bst(TreeNode* node, int value);
void inorder_bst(TreeNode* node);

int main()
{
	int arr[ARR_SIZE] = {3, 2, 5, 4, 1}; // initialize the array
	int size = 5; // current array size

	// Inserting an element in array at the given index
	insert_in_array(arr, &size, 7);

	// Searching an element in array by the value and return its index
	if (search_in_array(arr, size, 5) >= 0)
	{
		cout << "Found element 5 in the array. " << endl;
	}
	else
	{
		cout << "Could not find the element 5 in the array. " << endl;
	}
	
	// Deleting an element in array at the given index
	delete_in_array(arr, &size, 5);
	
	// Sort Array
	insertion_sort(arr, size);

	// Inserting an element in sorted array at the given index
	insert_in_sorted_array(arr, &size, 5);

	// Searching an element in sorted array by the value
	if (search_in_sorted_array(arr, 0, size-1, 1) >= 0)
	{
		cout << "Found element 1 in the sorted array. " << endl;
	}
	else
	{
		cout << "Could not find the element 1 in the sorted array. " << endl;
	}

	// Deleting an element in sorted array at the given index
	delete_in_sorted_array(arr, &size, 2);

	// Print array
	print_array(arr, size);

	List* l = new List;
	l->head = NULL;
	insert_in_linkedlist(l, 1);
	insert_in_linkedlist(l, 4);
	insert_in_linkedlist(l, 6);
	insert_in_linkedlist(l, 5);
	insert_in_linkedlist(l, 2);
	insert_in_linkedlist(l, 3);
	search_in_linkedlist(l, 5);
	delete_in_linkedlist(l, 6);
	print_linkedlist(l);

	BinarySearchTree* t = new BinarySearchTree;
	t->root = NULL;
	t->root = insert_in_bst(t->root, 3);
	t->root = insert_in_bst(t->root, 2);
	t->root = insert_in_bst(t->root, 5);
	t->root = insert_in_bst(t->root, 1);
	t->root = insert_in_bst(t->root, 4);
	t->root = insert_in_bst(t->root, 6);	
	search_in_bst(t->root, 1);
	delete_in_bst(t->root, 6);
	inorder_bst(t->root);
	cout << endl;

	return 0;
}

void insert_in_array(int* arr, int* size, int value) {
    if ((*size) >= ARR_SIZE)
    {
		cout << "Error: array is full! " << endl;
		return;
    }
    arr[(*size)] = value;
    (*size)++;
}

int search_in_array(int* arr, int size, int value) {
    for (int i = 0; i < size; i++)
    {
    	if (arr[i] == value)
    	{
    		return i;
    	}
    }
	return -1;
}

void delete_in_array(int* arr, int* size, int value) {
    int index = search_in_array(arr, (*size), value);
    if (index == -1)
    {
    	cout << "Could not find the element in the array. " << endl;
    }
    else
    {
    	for (int i = index; i < (*size)-1; i++)
    	{
    		arr[i] = arr[i+1];
    	}
    }
    (*size)--;
}

void insert_in_sorted_array(int* arr, int* size, int value) {
    if ((*size) >= ARR_SIZE)
    {
		cout << "Error: array is full! " << endl;
		return;
    }
    if ((*size) == 0)
    {
    	arr[0] = value;
    }
    else if (value <= arr[0])
    {
    	for (int i = 0; i < (*size); i++)
    	{
    		arr[i+1] = arr[i];
    	}
    	arr[0] = value;
    }
    else if (value > arr[(*size)-1])
    {
    	arr[(*size)] = value;
    }
    else
    {
    	int index;
    	for (int i = 0; i < (*size)-1; i++)
	    {
	    	if ((arr[i] <= value) && (value < arr[i+1]))
	    	{
	    		index = i+1;
	    		break;
	    	}
	    }
	    for (int i = index; i < (*size); i++)
	    {
	    	arr[i+1] = arr[i];
	    }
	    arr[index] = value;
    }
    (*size)++;
}

int search_in_sorted_array(int* arr, int low, int high, int value) {
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2;
    if (value == arr[mid]) 
        return mid; 
    if (value > arr[mid]) 
        return search_in_sorted_array(arr, (mid + 1), high, value); 
    return search_in_sorted_array(arr, low, (mid - 1), value); 
}

void delete_in_sorted_array(int* arr, int* size, int value) {
    int index = search_in_sorted_array(arr, 0, (*size)-1, value);
    if (index == -1)
    {
    	cout << "Could not find the element in the array. " << endl;
    }
    else
    {
    	for (int i = index; i < (*size)-1; i++)
    	{
    		arr[i] = arr[i+1];
    	}
    }
    (*size)--;
}

void insertion_sort(int* arr, int size) {
	int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

Node* allocateNode(int value)
{
	Node* newnode = new Node;
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

void insert_in_linkedlist(List* list, int value)
{
	Node* newnode = allocateNode(value);
	if (list->head == NULL)
	{
		list->head = newnode;
	}
	else
	{
        newnode->next = list->head;
        list->head = newnode;
	}
}

void search_in_linkedlist(List* list, int value)
{
	Node* p = list->head;
	while (p != NULL)
	{
		if (p->value == value)
		{
			cout << "Found the element in the array. " << endl;
		}
		p = p->next;
	}
	cout << "Could not find the element in the array. " << endl;
}

void delete_in_linkedlist(List* list, int value)
{
	Node* p = list->head;
	if (p->value == value)
	{
		list->head = list->head->next;
		free(p);
	}
	else
	{
		while (p->next != NULL)
		{
			if (p->next->value == value)
			{
				Node* temp = p->next;
				p->next = temp->next;
				free(temp);
				break;
			}
			else
			{
				p = p->next;
			}
		}
	}
}

void print_linkedlist(List* list)
{
	Node* p = list->head;
	if (p == NULL)
	{
		return;
	}
	while (p->next != NULL)
	{
		cout << p->value << "->";
		p = p->next;
	}
	cout << p->value << endl;
}


TreeNode* allocateBSTNode(int value)
{
	TreeNode* node = new TreeNode;
    node->value = value;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}

TreeNode* insert_in_bst(TreeNode* node, int value)
{
	if (node == NULL) 
    {
        return allocateBSTNode(value);
    }
    if (node->value > value)
    {
        node->leftchild = insert_in_bst(node->leftchild, value);
    }
    else if (node->value < value)
    {
        node->rightchild = insert_in_bst(node->rightchild, value);
    }
    else
    {
        cout << "Error: key already exist" << endl;
    }
    return node;
}

void search_in_bst(TreeNode* node, int value)
{
	if (node->value == value)
	{
		cout << "Found the element. " << endl;
		return;
	}
	if (node == NULL)
	{
		cout << "Couldn't find the element. " << endl;
		return;
	}
	if (node->value > value)
	{
		search_in_bst(node->leftchild, value);
	}
	else 
	{
		search_in_bst(node->rightchild, value);
	}
}

TreeNode* delete_in_bst(TreeNode* node, int value)
{
	if (node == NULL) 
		{
			return node;
		}
      	if (value < node->value)
      	{
      		node->leftchild = delete_in_bst(node->leftchild, value);
      	}
      	else if (value > node->value)
      	{
      		node->rightchild = delete_in_bst(node->rightchild, value);
      	}
      	else
      	{
      		if (node->leftchild == NULL)
      		{
      			TreeNode* temp = node->rightchild;
      			free(node);
      			return temp;
      		}
      		else if (node->rightchild == NULL)
      		{
      			TreeNode* temp = node->leftchild;
      			free(node);
      			return temp;
      		}
      		TreeNode* p = node->rightchild;
      		while ((p != NULL) && (p->leftchild != NULL))
      		{
      			p = p->leftchild;
      		}
      		node->value = p->value;
      		node->rightchild = delete_in_bst(node->rightchild, p->value);
      	}
   	return node;
}

void inorder_bst(TreeNode* node)
{
	if (node == NULL)
    {
        return;
    }
    inorder_bst(node->leftchild);
    cout << node->value << " ";
    inorder_bst(node->rightchild);
}


