//C99标准中引用一个概念：变长数组
//支持数组创建的时候，用变量指定大小的，但是数组不能初始化

#include <stdio.h>


int main()
{
    
    int a = 10;
    int arr[a];  //int arr[10]={0};不可

    //顺序结构 选择结构 循环结构
    //由一个分号隔开的就是一条语句


    //分支语句(选择结构) if switch
    //if
    int age = 19;
    if(age > 18)
        printf("成年人\n");
    else
        printf("未成年\n");
        printf("不能谈恋爱\n");
    // 答案会是 成年人 不能谈恋爱 if else 不加括号 只能控制一条语句 不和语句分开格式有关
    
    if (age <18)
        printf("未成年\n");
    else if (age < 30)  // age >= 18 && age < 30
        printf("青年\n");
    else if (age < 50)
        printf("中年\n");
    else
        printf("老年\n");

    // else 离最近的 if 配对

    // if (condition){
    //     return x;
    // }
    // return y; 容易造成误会 实际若if成立 则不会执行return y

    //if(5 == num) 推荐数字写前面 出错会报错 num == 5 若漏写= 则不会报错

    //输出1-100之间的奇数 
    int i = 1;
    while(i <= 100)
    {
        if(i % 2 == 1)
            printf("%d ", i);
        i++;
    }
    
    for(int i = 1; i <= 100; i++) // int i 在C99中可以 c++标准
    {
        if(i % 2 == 1)
            printf("%d ", i);
    }

    for(int i=1;i<=100;i+=2)
        printf("%d ", i);
    
    //switch
    //基本格式 switch(整型表达式)
    //        {
    //            case 整型常量表达式1:
    //                语句1;
    //        }

    int day = 0;
    scanf("%d", &day);
    switch (day) // 强调过 整型(字符属于整型：运用ASCII码)
    {
    case 1 : //强调过：整型常量
        printf("星期一\n");
        break; //break 语句可以跳出switch语句
        // 没有break 会继续执行下面的语句
    case 2 :
        printf("星期二\n");
        break;
    case 3 :
        printf("星期三\n");
        break;
    case 4 :        
        printf("星期四\n");
        break;
    case 5 :
        printf("星期五\n");
        break;
    case 6 :
        printf("星期六\n");
        break;
    case 7 :
        printf("星期日\n");
        break;
    }

    //1-5工作日 6-7周末
    int day2 = 0;
    scanf("%d", &day2);
    switch (day2)
    {
    case 1 : 
    case 2 :
    case 3 :
    case 4 :
    case 5 :
        printf("工作日\n");
        break;
    case 6 :
    case 7 :
        printf("周末\n");
        break;
    default:
        printf("输入错误\n");
        break; //最后一个break可以省略 习惯不省略 便于修改
    } //习惯上default放在最后

    //switch 允许嵌套

    //循环语句 while do-while for
    //while
    //基本格式
        //while(条件表达式)
        //     循环语句;

    //打印1-10之间的所有整数
    int c = 1; //初始化
    while(c <= 10) //判断条件
    { 
        if(c==5)
            break; //break 跳出循环
        printf("%d ", c);
        c++; //调整部分
    }

    int d = 1;
    while(d <= 10)
    {
        if(d==5)
            continue; //continue 跳过本次循环continue之后的语句
            //if 所在的范围不是整个循环
            //直接去判断部分，看是否进行下一次循环
        printf("%d ", d);
        d++;
    } //死循环 跳过了d++ 无法退出



//EOF end of file 文件结束标志 本质是-1
//getchar 返回值是int类型
    int ch1 = getchar(); //读取一个字符
    //printf("%d\n", ch1);
    putchar(ch1); //输出一个字符



    int ch = 0;
    while((ch = getchar()) != EOF) //获取失败返回EOF
        putchar(ch);
    //ctrl+z 读取结束
    //过程：getchar() -> 缓冲区 -> 键盘 当缓冲区输入A\n时，getchar()读取A\n \n代表换行


    char password[20] = {0};
    printf("请输入密码：");
    scanf("%s", password); //数组的名字代表数组的首地址
    printf("请确认密码(Y/N):>");

    //清理缓冲区
    //getchar(); //处理'\n' 密码后面所带的\n
    //但是如果密码中间出现空格，就会出现问题
    
    int temp = 0;
    while((temp = getchar()) != '\n' )
        ; //清理缓冲区中多个字符 密码只有空格前面的

    int ch2 = getchar();
    if(ch2 == 'Y')
        printf("密码设置成功\n");
    else
        printf("密码设置失败\n");


    int ch3 = 0;
    while((ch3 = getchar()) != EOF)
    {
        if(ch3<'0' || ch3>'9')
            continue;
        putchar(ch3);
    } //只打印数字字符



    return 0;
}
