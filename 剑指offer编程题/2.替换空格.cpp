/*
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
解题思路：
用python一行代码即可搞定，但这没有意义。
可以先申请一个临时数组，然后在临时数组中组装新的字符串然后复制回原数组。
高效的方法是直接在原数组中操作，不过需要先计算出编码后的字符串总长度， 
新的总长度为原 字母个数 + 3倍的空格数，然后从右边往左边开始组装新串，
首先设定好两个下标位置：先串的末尾和原串的末尾， 然后往左边扫描，
遇到字母或者串结束符直接复制到相应位置，遇到空格就转换为"%20",
注意下标的变化。 
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		int character=0, cntSpace=0;
        for(int i=0; str[i]; ++i) str[i]==' '? ++cntSpace : ++character;
        int oldLen = character + cntSpace;
        int newLen = character + cntSpace * 3;
        int idx1 = oldLen;
        int idx2 = newLen;
        while(0 <= idx1 && idx1 <= idx2){
            if(str[idx1] != ' '){  
                str[idx2--] = str[idx1--];  //copy characters and '\0' 
            }else{
                str[idx2--] = '0';
                str[idx2--] = '2';
                str[idx2--] = '%';
                --idx1; //idx1 should also decrease
            }
        }
	}
};


