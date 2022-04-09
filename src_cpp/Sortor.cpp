#include "Sortor.h"
#include<iostream>
#include<vector>
void swap(Row* &a, Row* &b)
{
    auto temp = a;
    a = b;
    b = temp;
}
void adjust(std::vector<Row *> &arr, int len, int index)
{
    int left = 2*index + 1; // index的左子节点
    int right = 2*index + 2;// index的右子节点
 
    int maxIdx = index;
    if(left<len && arr[maxIdx] < arr[left])     maxIdx = left;
    if(right<len && arr[maxIdx] < arr[right])     maxIdx = right;
 
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
// 堆排序
void heapSort(std::vector<Row*> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}
void Sortor1::sort(std::list<Row *> &rows) {
    //降序，*a<*b则为升序
    rows.sort([](Row *a, Row *b) -> bool { return (*b < *a); });
}

void Sortor2::sort(std::list<Row *> &rows) {
    std::list<Row *>::iterator it = rows.begin();
    std::vector<Row *> v;
    for (; it != rows.end(); it++) {
        v.push_back(*it);
    }
    heapSort(v, v.size());
}