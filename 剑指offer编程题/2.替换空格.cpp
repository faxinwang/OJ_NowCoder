/*
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.
�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/*
����˼·��
��pythonһ�д��뼴�ɸ㶨������û�����塣
����������һ����ʱ���飬Ȼ������ʱ��������װ�µ��ַ���Ȼ���ƻ�ԭ���顣
��Ч�ķ�����ֱ����ԭ�����в�����������Ҫ�ȼ�����������ַ����ܳ��ȣ� 
�µ��ܳ���Ϊԭ ��ĸ���� + 3���Ŀո�����Ȼ����ұ�����߿�ʼ��װ�´���
�����趨�������±�λ�ã��ȴ���ĩβ��ԭ����ĩβ�� Ȼ�������ɨ�裬
������ĸ���ߴ�������ֱ�Ӹ��Ƶ���Ӧλ�ã������ո��ת��Ϊ"%20",
ע���±�ı仯�� 
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


