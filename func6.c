#include<stdio.h>
#include<string.h>
//栈区：局部变量，函数参数，调用函数时返回值等临时的变量

int my_strlen(char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

void reverse_string(char*str) //str是地址，*str是取str里面的值
{
    int left = 0;
    int right =my_strlen(str) - 1;
    while (left < right)
    {
        char temp = str[left]; //str[left] = *(str+left)
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

//递归:a移出，f移进，\0移入f原来位置，如果a过早移入不方便识别中间位置
void reverse_string2(char* str)
{
    char temp = *str; //*str->a
    int len = my_strlen(str); //如果用strlen函数，不用-1，因为字符串大小已经发生改变(待定)
    *str = *(str + len - 1);//len-1是下标 str + len - 1是f的地址
    *(str + len - 1) = '\0';
    //判断条件
    if (my_strlen(str + 1) > 1)
    {
        reverse_string2(str + 1);
    }
    *(str + len - 1) = temp;

}

int DightSum(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 + DightSum(n / 10);
    //1729/10=172 1729%10=9 9+DightSum(172)
}

double Pow(int n, int k)
{
    if (k == 0)
        return 1.0;
    else if (k == 1)
        return n * Pow(n, k - 1);
    else
        return 1.0 / Pow(n, -k);
}

int main()
{
    //1.字符串逆序 函数reverse_string(char* string)(递归)
    //内容反过来了，不要单纯逆序打印 不能用C库函数
    char arr[] = "abcdef";
    reverse_string(arr);
    printf("%s\n", arr);

//58行业

    //2.递归函数DightSum(),输入一个非负整数，返回组成它的数字之和
    int num = 1729;
    int sum = DightSum(num);
    printf("%d\n", sum);

    //3. 递归函数实现n^k
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    double ret = Pow(n, k);
    printf("%lf\n", ret);













    return 0;
}