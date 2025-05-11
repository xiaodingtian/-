/*

针对1.0的升级迭代

主要考虑将main()相关功能代码抽取为具体函数，在main()函数中进行调用；将账户抽取为结构体变量

*/
#include <stdio.h>
#include <string.h>

int loop = 1; // 控制整体收支的循环
//声明结构体
struct FamilyAccout
{
    //声明结构体成员
    
    int hasRecord; // 默认情况下，没有收入或支出的登记

    char details[3000];

    double initBalance; // 初始金额
};

/*
显示收支明细
*/
void showDetails(struct FamilyAccout *fAccount)
{
    if (!fAccount->hasRecord)
    {
        printf("当前没有收支明细....来一笔吧！\n");
    }
    else
    {
        printf("%s", fAccount->details);
    }
}

/*
登记收入功能
*/
void income(struct FamilyAccout *fAccount)
{
    printf("本次收入金额：");
    double addMoney;
    scanf("%lf", &addMoney);
    printf("本次收入说明：");
    char addDetail[100];
    scanf("%s", addDetail);

    fAccount->initBalance += addMoney;
    // 将用户的输入的信息拼接为一个完整的字符串
    char addDetails[300];
    sprintf(addDetails, "收入\t%f\t\t%f\t\t%s\n", addMoney, fAccount->initBalance, addDetail);

    // 将用户完整收入的信息添加到当前整体用户收支明细里
    strcat(fAccount->details, addDetails);

    fAccount->hasRecord = 1; // 表示有过收入登记
    printf("登记收入完成\n");
}
/*
登记支出功能
*/
void pay(struct FamilyAccout *fAccount)
{
    printf("本次支出金额：");
    double minusMoney;
    scanf("%lf", &minusMoney);
    if (minusMoney > fAccount->initBalance)
    {
        printf("余额不足\n");
    }
    else
    {
        fAccount->initBalance -= minusMoney;
        printf("本次支出说明:");
        // 将用户的信息拼接为完整的一个字符串
        char minusDetail[100];
        scanf("%s", minusDetail);
        char minusDetails[300];
        sprintf(minusDetails, "支出\t%f\t\t%f\t\t%s\n", minusMoney, fAccount->initBalance, minusDetail);

        // 将用户完整收入的信息添加到当前整体用户收支明细里
        strcat(fAccount->details, minusDetails);
        fAccount->hasRecord = 1;
        printf("登记支出完成\n");
    }
}

/*
退出功能
*/
void goExit()
{
    printf("你确定要退出吗(y/n):");
            char isExit;
            while (1)
            {
                scanf("%c", &isExit);
                scanf("%c", &isExit);
                if (isExit == 'y' || isExit == 'n')
                {
                    break;
                }

                else
                {
                    printf("你输入的有误，请重新输入(y/n):");
                }
            }
            if(isExit =='y')
            {
                loop = 0;
                printf("欢迎再次来到家庭记账软件^_^\n");
            }
}

void menu(struct FamilyAccout *fAccount)
{

    // char *info = "---------------当前收支明细---------------\n收支\t收支金额\t\t账户金额\t\t说明\n";
    // sprintf(details,info);

    do
    {
        printf("---------------家庭收支记账软件---------------\n");
        printf("               1 收支明细\n");
        printf("               2 登记收入\n");
        printf("               3 登记支出\n");
        printf("               4 退    出\n");
        printf("               请选择(1-4):");

        int selection; // 用户选择
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            showDetails(fAccount);
            break;
        case 2:
            income(fAccount);
            break;
        case 3:
            pay(fAccount);
            break;
        case 4:
            goExit();
            break;
        }
    } while (loop);

    printf("你退出了家庭财务软件~~~~\n");
}
int main()
{
    //声明结构体变量并且赋值
    struct FamilyAccout fAccount;
    fAccount.hasRecord=0;   // 默认情况下，没有收入或支出的登记
    strcpy(fAccount.details,"---------------当前收支明细---------------\n收支\t收支金额\t\t账户金额\t\t说明\n"); // 用来存储收支的记录信息
    fAccount.initBalance = 1000;
    //显示界面 
    menu(&fAccount);
    getchar();
    getchar();
    return 0;
}