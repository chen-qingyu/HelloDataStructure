/**
 * @file BinarySearchTree.hpp
 * @author Qingyu Chen (chen_qingyu@qq.com, https://chen-qingyu.github.io/)
 * @brief Binary search tree.
 * @date 2022.01.29
 *
 * @copyright Copyright (C) 2022
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <stdbool.h> // bool

/// A value of BinarySearchTreeItem that indicates not found.
#define BINARY_SEARCH_TREE_NOT_FOUND (-1)

/// Traverse Option.
enum TraverseOption
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    LEVEL_ORDER
};

/// Binary Search Tree Item.
typedef int BinarySearchTreeItem;

/// Binary Search Tree.
typedef struct BinarySearchTree BinarySearchTree;

/**
 * @brief 创建一个空二叉搜索树
 *
 * @return 一个指向空二叉搜索树的指针
 */
BinarySearchTree* BinarySearchTree_Create(void);

/**
 * @brief 销毁一个二叉搜索树
 *
 * @param self 一个指向待销毁二叉搜索树的指针
 */
void BinarySearchTree_Destroy(BinarySearchTree* self);

/**
 * @brief 求二叉搜索树的元素个数
 *
 * @param self 一个指向二叉搜索树的指针
 * @return 二叉搜索树的元素个数
 */
int BinarySearchTree_Size(const BinarySearchTree* self);

/**
 * @brief 判断二叉搜索树是否为空
 *
 * @param self 一个指向二叉搜索树的指针
 * @return 如果二叉搜索树为空则返回 true ，否则返回 false
 */
bool BinarySearchTree_IsEmpty(const BinarySearchTree* self);

/**
 * @brief 遍历一个二叉搜索树
 *
 * @param self 一个指向二叉搜索树的指针
 * @param order 一个枚举遍历类型
 *              - PRE_ORDER   先序遍历
 *              - IN_ORDER    中序遍历
 *              - POST_ORDER  后序遍历
 *              - LEVEL_ORDER 层次遍历
 * @param p_trav 一个对遍历到的每个元素进行操作的函数的指针
 */
void BinarySearchTree_Traverse(BinarySearchTree* self, enum TraverseOption order, void (*p_trav)(const BinarySearchTreeItem data));

/**
 * @brief 在一个二叉搜索树中寻找元素 data
 *
 * @param self 一个指向二叉搜索树的指针
 * @param data 一个待寻找元素
 * @return 元素 data 或者 BINARY_SEARCH_TREE_NOT_FOUND
 */
BinarySearchTreeItem BinarySearchTree_Find(const BinarySearchTree* self, BinarySearchTreeItem data);

/**
 * @brief 在一个二叉搜索树中寻找最小元素
 *
 * @param self 一个指向二叉搜索树的指针
 * @return 最小的元素或者 BINARY_SEARCH_TREE_NOT_FOUND
 */
BinarySearchTreeItem BinarySearchTree_FindMin(const BinarySearchTree* self);

/**
 * @brief 在一个二叉搜索树中寻找最大元素
 *
 * @param self 一个指向二叉搜索树的指针
 * @return 最大的元素或者 BINARY_SEARCH_TREE_NOT_FOUND
 */
BinarySearchTreeItem BinarySearchTree_FindMax(const BinarySearchTree* self);

/**
 * @brief 在一个二叉搜索树中插入元素 data
 *
 * @param self 一个指向二叉搜索树的指针
 * @param data 一个待插入元素
 */
void BinarySearchTree_Insert(BinarySearchTree* self, BinarySearchTreeItem data);

/**
 * @brief 在一个二叉搜索树中删除元素 data
 *
 * @param self 一个指向二叉搜索树的指针
 * @param data 一个待删除元素
 */
void BinarySearchTree_Remove(BinarySearchTree* self, BinarySearchTreeItem data);

/**
 * @brief 求二叉搜索树的最大深度，空树深度为0
 *
 * @param self 一个指向二叉搜索树的指针
 * @return 二叉搜索树的最大深度
 */
int BinarySearchTree_Depth(const BinarySearchTree* self);

/**
 * @brief 清空二叉搜索树的内容
 *
 * @param self 一个指向二叉搜索树的指针
 */
void BinarySearchTree_Clear(BinarySearchTree* self);

#endif // BINARYSEARCHTREE_HPP
