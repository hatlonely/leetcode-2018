#!/usr/bin/env python3

import random


def insert_sort(ia):
    for i in range(len(ia)):
        for j in range(i, 0, -1):
            if ia[j] < ia[j - 1]:
                ia[j], ia[j-1] = ia[j-1], ia[j]


def bubble_sort(ia):
    for i in range(len(ia)):
        for j in range(i + 1, len(ia)):
            if ia[j] < ia[i]:
                ia[i], ia[j] = ia[j], ia[i]


def merge_sort_recursive(ia, s, e):
    if s + 1 >= e:
        return
    m = (s + e) // 2
    merge_sort_recursive(ia, s, m)
    merge_sort_recursive(ia, m, e)
    i = s
    j = m
    ib = []
    while i < m and j < e:
        if ia[i] < ia[j]:
            ib.append(ia[i])
            i += 1
        else:
            ib.append(ia[j])
            j += 1
    while i < m:
        ib.append(ia[i])
        i += 1
    while j < e:
        ib.append(ia[j])
        j += 1
    ia[s:e] = ib


def merge_sort(ia):
    merge_sort_recursive(ia, 0, len(ia))


def quick_sort_recursive(ia, s, e):
    if s + 1 >= e:
        return
    l = s
    r = e - 1
    while l < r:
        while l < r and ia[l] < ia[e]:
            l += 1
        while l < r and ia[r] >= ia[e]:
            r -= 1
        ia[l], ia[r] = ia[r], ia[l]
    ia[l], ia[e] = ia[e], ia[l]
    quick_sort_recursive(ia, s, l - 1)
    quick_sort_recursive(ia, l + 1, e)


def quick_sort(ia):
    quick_sort_recursive(ia, 0, len(ia) - 1)


if __name__ == '__main__':
    for sort in [bubble_sort, insert_sort, merge_sort, quick_sort]:
        ia = [4, 2, 3, 1, 5, 9, 4, 3, 8]
        ia = list(range(9)) + list(range(9))
        random.shuffle(ia)
        sort(ia)
        print(ia)
