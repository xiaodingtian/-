#include <stdio.h>
#include <string.h>
/*

完成项目1：家庭收支记账软件 ---完成阶段1：整体框架的搭建

*/
int main()
{
    int loop = 1; // 控制整体收支的循环

    int hasRecord = 0; // 默认情况下，没有收入或支出的登记

    char details[3000] = "---------------当前收支明细---------------\n收支\t收支金额\t\t账户金额\t\t说明\n";
    ; // 用来存储收支的记录信息

    double initBalance = 1000; // 初始金额
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
            if (!hasRecord)
            {
                printf("当前没有收支明细....来一笔吧！\n");
            }
            else
            {
                printf("%s", details);
            }
            break;
        case 2:
            printf("本次收入金额：");
            double addMoney;
            scanf("%lf", &addMoney);
            printf("本次收入说明：");
            char addDetail[100];
            scanf("%s", addDetail);

            initBalance += addMoney;
            // 将用户的输入的信息拼接为一个完整的字符串
            char addDetails[300];
            sprintf(addDetails, "收入\t%f\t\t%f\t\t%s\n", addMoney, initBalance, addDetail);

            // 将用户完整收入的信息添加到当前整体用户收支明细里
            strcat(details, addDetails);

            hasRecord = 1; // 表示有过收入登记
            printf("登记收入完成\n");
            break;
        case 3:
            printf("本次支出金额：");
            double minusMoney;
            scanf("%lf", &minusMoney);
            if (minusMoney > initBalance)
            {
                printf("余额不足\n");
                break;
            }
            else
            {
                initBalance -= minusMoney;
                printf("本次支出说明:");
                // 将用户的信息拼接为完整的一个字符串
                char minusDetail[100];
                scanf("%s", minusDetail);
                char minusDetails[300];
                sprintf(minusDetails, "支出\t%f\t\t%f\t\t%s\n", minusMoney, initBalance, minusDetail);

                // 将用户完整收入的信息添加到当前整体用户收支明细里
                strcat(details, minusDetails);
                hasRecord = 1;
                printf("登记支出完成\n");
            }
            break;
        case 4:
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
            
            break;
        }
    } while (loop);

    printf("你退出了家庭财务软件~~~~\n");
    getchar();
    getchar();
    return 0;
}