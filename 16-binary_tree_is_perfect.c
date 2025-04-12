#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect(tree, binary_tree_height(tree)));
}
/**
 * is_perfect - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @height: Height of the tree
 *
 * Return: 1 if the subtree is perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, int height)
{
	if (tree == NULL)
		return (height == 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, height - 1) &&
			is_perfect(tree->right, height - 1));
}
/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

