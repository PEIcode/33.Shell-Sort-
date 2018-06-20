//
//  main.c
//  33.Shell Sort(希尔排序)
//
//  Created by sunny&pei on 2018/6/20.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//

#include <stdio.h>
/**
 希尔排序：是对直接插入排序的一种改进。
 将相距某个“增量”的记录组成一个子序列，这样才能保证在子序列内分别进行直接插入排序后得到的结果是基本有序而不是局部有序。
 */
#define MAXSIZE 10
typedef struct{
    int r[MAXSIZE+1];
    int length;
}Sqlist;
//
void ShellSort(Sqlist *L){
    int i,j;
    int increment = L->length;// 9
    do {
        increment = increment/3+1;//增量排序
        for (i= increment+1; i<=L->length; i++) {
            if (L->r[i]<L->r[i-increment]) {//需要将L->r[i]插入有序增量子表
                L->r[0] = L->r[i];//暂存在L->r[0]
                for (j = i-increment; j>0 && L->r[0]<L->r[j]; j-=increment) {
                    L->r[j+increment] = L->r[j];//记录后移，查找插入位置
                }
                L->r[j+increment] = L->r[0];//插入
            }
        }
    } while (increment>1);
}

/**
 总结：希尔排序  是对直接插入排序的优化
     增量的选取非常关键，不过如何选取增量，至今是个难题，时间复杂度为O(n^3/2)
     增量序列的最后一个增量必须等于1才行。
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    Sqlist L;
    L.length = 10;
    L.r[1] = 9;
    L.r[2] = 1;
    L.r[3] = 5;
    L.r[4] = 8;
    L.r[5] = 3;
    L.r[6] = 7;
    L.r[7] = 4;
    L.r[8] = 6;
    L.r[9] = 2;
    ShellSort(&L);
    for (int i = 1; i<L.length; i++) {
        printf("%d\n",L.r[i]);
    }
    printf("r[0]=%d\n",L.r[0]);
    return 0;
}
