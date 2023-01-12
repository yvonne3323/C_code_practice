//读取文件并设定坐标
#include<stdio.h>
#include<stdbool.h>
#include<graphics.h>

int main()
{
    
    FILE *fp;
    fp=fopen("D:\\Code\\TEST\\XYZ.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        return 0;
    }
    double x;
    double y;
    double z;
    //读取txt文件中的数据
    while(true)
    {
        int ret = fscanf(fp,"%lf %lf %lf",&x,&y,&z);
        if (ret==EOF)
        {
            break;
        }
        printf("%0.7f %0.7f %0.7f\n",x,y,z);
    }
    fclose(fp);
    return 0;
}