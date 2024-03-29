/**
 * @file HashTable.hpp
 * @author Qingyu Chen (chen_qingyu@qq.com, https://chen-qingyu.github.io/)
 * @brief Hash table.
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

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <stdbool.h> // bool

/// A value of HashTableValue that indicates not found.
#define HASH_TABLE_NOT_FOUND (-1)

/// Hash Table Key.
typedef const char* HashTableKey;

/// Hash Table Value.
typedef int HashTableValue;

/// Hash Table.
typedef struct HashTable HashTable;

/**
 * @brief 创建一个空散列表
 *
 * @return 一个指向空散列表的指针
 */
HashTable* HashTable_Create(void);

/**
 * @brief 销毁一个散列表
 *
 * @param self 一个指向待销毁散列表的指针
 */
void HashTable_Destroy(HashTable* self);

/**
 * @brief 求散列表的元素个数
 *
 * @param self 一个指向散列表的指针
 * @return 散列表的元素个数
 */
int HashTable_Size(const HashTable* self);

/**
 * @brief 判断散列表是否为空
 *
 * @param self 一个指向散列表的指针
 * @return 如果散列表为空则返回 true ，否则返回 false
 */
bool HashTable_IsEmpty(const HashTable* self);

/**
 * @brief 在散列表中取 key 对应的 value
 *
 * @param self 一个指向散列表的指针
 * @param key 一个 key
 * @return key 对应的 value 或者 HASH_TABLE_NOT_FOUND
 */
HashTableValue HashTable_Get(const HashTable* self, HashTableKey key);

/**
 * @brief 在散列表中修改 key 对应的 value
 *
 * @param self 一个指向散列表的指针
 * @param key 一个 key
 * @param value 一个新的 value
 */
void HashTable_Modify(HashTable* self, HashTableKey key, HashTableValue value);

/**
 * @brief 在散列表中插入一个新的键值对
 *
 * @param self 一个指向散列表的指针
 * @param key 一个新的 key
 * @param value 一个新的 key 对应的 value
 */
void HashTable_Insert(HashTable* self, HashTableKey key, HashTableValue value);

/**
 * @brief 在散列表中删除 key 对应的键值对
 *
 * @param self 一个指向散列表的指针
 * @param key 待删除键值对的 key
 */
void HashTable_Remove(HashTable* self, HashTableKey key);

/**
 * @brief 清空散列表的内容
 *
 * @param self 一个指向散列表的指针
 */
void HashTable_Clear(HashTable* self);

#endif // HASHTABLE_HPP
