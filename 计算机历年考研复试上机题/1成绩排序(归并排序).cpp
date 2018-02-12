/*
解题思路：
排序题目要求是稳定排序，成绩相同时，先输入的先输出，题目描述与测试数据不相符。
在归并排序的时候，如果要实现稳定排序， 需要根据合并算法具体判断比较的时候需要用
'<'运算符还是'<='运算符. 
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;


struct Stu{
    string name;
    int score;
}s[100000];

bool LessEqualThen(Stu& s1, Stu& s2){ return s1.score <= s2.score; }

bool GreaterEqualThen(Stu& s1, Stu& s2){ return s1.score >= s2.score; }


void merge(int low, int mid, int high, bool (*cmp)(Stu& s1, Stu& s2)){
    Stu *L = new Stu[(high-low)/2+1];
    Stu *R = s+mid ,*a=s+low;
    copy(s+low, s+mid, L);
    int i=0,j=0, k=0, la=mid-low,lb=high-mid;
    //注意，当比较条件结果为真时，并入的是前半部分中的元素
    //所以要实现稳定排序，就需要用<=或者>=号来保证排序的稳定性。
    while(i<la && j<lb) a[k++] = (cmp(L[i], R[j])? L[i++] : R[j++]);
    while(i<la) a[k++] = L[i++];

    delete []L;
}

void mergeSort(int L,int R, bool (*cmp)(Stu& s1, Stu& s2)){
    if(R - L < 2) return;
    int mid = L + (R - L) / 2;
    mergeSort(L,mid, cmp);
    mergeSort(mid, R, cmp);
    merge(L,mid,R, cmp);
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,op;
    while(~scanf("%d%d",&n,&op)){
        for(int i=0; i < n; ++i) cin>>s[i].name>>s[i].score;
        if(op==1){ //升序
            mergeSort(0,n, LessEqualThen);
        }
        else{ //降序
            mergeSort(0,n, GreaterEqualThen);
        }
        for(int i=0;i<n;++i) cout<<s[i].name<<" "<<s[i].score<<endl;
    }

    return 0;
}
