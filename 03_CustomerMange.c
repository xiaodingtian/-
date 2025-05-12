/*

编写项目2：客户信息管理系统


*/
#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 30

int loop = 1;

// 声明结构体：客户
struct Customer
{
    int id;
    char name[10];
    char gender;
    int age;
    char phone[20];
    char email[40];
};

// 声明结构体的数组
struct Customer customers[MAX_CAPACITY];

int total; // 记录添加客户个数

/*
删除索引位置的客户
删除成功，返回0
不成功，非0
*/
int removeCustomer(int index)
{
    if(index<0||index>=total)
    {
        return -1;
    }
    //通过循环遍历的方式将index后续位置依次前移
    for(int i = index;i<total - 1;i++)
    {
        customers[i] = customers[i+1];
        //如果需要修改编号
        customers[i].id=index+1;
    }
    total--;
    return 1;
}

/*
判断编号是否存在

如果客户不存在 返回-1
如果存在，返回编号的索引位置
*/
int getCustomerIndex(int id)
{
    for(int i =0;i<total;i++)
    {
        if(customers[i].id==id)
        {
            return i;
        }
    }
    return -1;
}
/*
删除客户的功能实现
*/
void deleteView()
{
    printf("-------------删除客户-------------\n");
    printf("请选择待删除客户编号(-1退出):");
    int deleteId;
    scanf("%d",&deleteId); 
    if(deleteId ==-1)
    {
        return;
    }
    //判断给定的客户编号是否存在
    int deleteIndex = getCustomerIndex(deleteId);
    if(deleteIndex == -1)
    {
        printf("不存在指定编号的客户！\n");
        return ;
    }
    //如果代码能执行，表示指定的编号用户存在
    //判断是否要删除
    getchar();
    printf("确认是否删除(Y/N):");
    char isDelete;
    scanf("%c",&isDelete);
    if(isDelete == 'N')
    {
        return ;
    }
    else if(isDelete == 'Y')
    {
        //确定删除
        if(removeCustomer(deleteIndex))
        {
            printf("-------------删除成功-------------\n");
        }
        else
        {
            printf("-------------删除失败-------------\n");
        }
    }
    else
    {
        printf("你输入的选择有误！\n");  
    }
}
/*
修改客户信息的功能实现
*/
void modifyView()
{
    printf("-------------修改客户-------------\n");
    printf("请选择修改客户的编号(-1退出):");
    int modifyId;
    scanf("%d",&modifyId);
    if(modifyId == -1)
    {
        return;
    }
    int modifyIndex = getCustomerIndex(modifyId);
    if(modifyIndex == -1)
    {
        printf("该用户不存在!\n");
        return;
    }
    //代码能执行到此位置，表示存在要修改的客户
    struct Customer *custPtr = &customers[modifyIndex];
    printf("-------------修改客户-------------\n");
    
    //声明一个通用的字符串，用于存储可能要修改的数据
    char info[30];
    getchar();
    printf("姓名(%s):",custPtr->name);
    //scanf("%s",info);
    fgets(info,sizeof(info),stdin);
    if(!(info[0]=='\n'))
    {
        //strcpy(custPtr->name,info);
        sscanf(info,"%s",custPtr->name);
    }

    printf("性别(%c):",custPtr->gender);
    fgets(info,sizeof(info),stdin);
    if(!(info[0]=='\n'))
    {
        sscanf(info,"%c",&custPtr->gender);
    }
    printf("年龄(%d):",custPtr->age);
    fgets(info,sizeof(info),stdin);
    if(!(info[0]=='\n'))
    {
        sscanf(info,"%d",&custPtr->age);
    }
    printf("电话(%s):",custPtr->phone);
    fgets(info,sizeof(info),stdin);
    if(!(info[0]=='\n'))
    {
        sscanf(info,"%s",custPtr->phone);
    }
    printf("邮箱(%s):",custPtr->email);
    fgets(info,sizeof(info),stdin);
    if(!(info[0]=='\n'))
    {
        sscanf(info,"%s",custPtr->email);
    }
    printf("-------------修改完成-------------\n");
}
/*
添加客户的功能实现
*/
void addView()
{
    if(total<MAX_CAPACITY)
            {
                printf("-------------添加客户-------------\n");
                //写法2
                // struct Customer *custPtr = &customers[total];
                // custPtr->
                //编号id自动累加
                customers[total].id = total + 1;

                printf("姓名:");
                char name[10];
                scanf("%s",name); 
                strcpy(customers[total].name,name);

                getchar();
                printf("性别:");
                char gender;
                scanf("%c",&gender);
                customers[total].gender=gender;


                printf("年龄:");
                int age;
                scanf("%d",&age);
                customers[total].age = age;

                printf("电话:");
                char phone[20];
                scanf("%s",phone);
                strcpy(customers[total].phone,phone);

                printf("邮箱:");
                char email[20];
                scanf("%s",email);
                strcpy(customers[total].email,email);
                total++;
                printf("-------------添加完成-------------\n");
            }
            else
            {
                printf("客户列表已满，添加失败");
            }
}
/*
显示某个具体客户信息
*/
void showCustomer(struct Customer *custPtr)
{
    printf("%d\t%s\t%c\t%d\t%s\t\t%s\t\n",custPtr->id,custPtr->name,custPtr->gender,custPtr->age,custPtr->phone,custPtr->email);
}

/*
显示课后列表功能
*/
void showView()
{
    if(total == 0)
            {
                printf("系统中没有任何客户信息!请先添加\n");
            }
            else
            {
                printf("----------客户列表-----------\n");
                printf("编号\t姓名\t性别\t年龄\t电话\t\t邮箱\n");
                //遍历数组元素
                for(int i = 0; i<total;i++)
                {
                    showCustomer(&customers[i]);
                }
            }
}
/*
退出功能实现
*/
void exitView()
{
    printf("确认是否退出(Y/N):"); 

    char isExit;

    while (1)
    {
        getchar();
        scanf("%c", &isExit);
        if (isExit == 'Y' || isExit == 'N')
        {
            break;
        }
        else
        {
            printf("输入有误，请重新输入(Y/N):");
        }
    }
    if (isExit == 'Y')
    {
        loop = 0;
    }
}

/*
显示客户管理软件的界面
*/
void menu()
{
    while (loop)
    {
        printf("--------------客户信息管理软件----------------\n");
        printf("              1 添加客户\n");
        printf("              2 修改客户\n");
        printf("              3 删除客户\n");
        printf("              4 客户列表\n");
        printf("              5 退    出\n");
        printf("              请选择（1-5）:");

        int selection;
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            addView();
            break;
        case 2:
            modifyView();
            break;
        case 3:
            deleteView();
            break;
        case 4:
            showView();
            break;
        case 5:
            exitView();
            break;
        }
    }
    printf("退出客户信息管理系统，欢迎下次光临哈哈^_^");
}

int main()
{
    menu();

    getchar();
    getchar();

    return 0;
}