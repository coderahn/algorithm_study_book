#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData) {
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void BST_DestroyNode(BSTNode* Node) {
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree) {
	if (Tree->Right != NULL) {
		BST_DestroyTree(Tree->Right);
	}

	if (Tree->Left != NULL) {
		BST_DestroyTree(Tree->Left);
	}

	Tree->Left = NULL;
	Tree->Right = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target) {
	if (Tree == NULL) {
		return NULL;
	}

	if (Tree->Data < Target) {
		return BST_SearchNode(Tree->Right, Target);
	} else if (Tree->Data > Target) {
		return BST_SearchNode(Tree->Left, Target);
	}
	else {
		return Tree;
	}
}

BSTNode* BST_SearchMinNode(BSTNode* Tree) {
	if (Tree == NULL) {
		return NULL;
	} 

	if (Tree->Left == NULL) {
		return Tree;
	}
	else {
		return BST_SearchMinNode(Tree->Left);
	}
}

