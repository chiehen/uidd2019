#include <stdio.h>
#include <string.h>
#define RED "\x1B[31m"//顯示紅色
#define RESET "\x1B[0m"//顯示原色
#define YEL "\x1B[33m"//顯示黃色

int main(void)
{
    char code[12][4]={"A-1","A-2","A-3","B-1","B-2","B-3","C-1","C-2","C-3","C-4","D-1","D-2"};//各項餐點編碼
    int price[12]={25,30,40,30,40,45,10,10,20,25,40,60};//餐點價錢
    char name[12][20]={"火腿吐司","法式吐司","豬排吐司","培根漢堡","雞肉漢堡","牛肉起司漢堡","豆漿","紅茶","熱可可","咖啡","超值早餐","活力套餐"};//餐點名稱 
    /*welcome & menu*/
    printf("歡迎使用點餐系統\n");
    printf("菜單\n");
    printf("===========================\n");
    printf("編號  餐點          價錢\n");
    printf("===========================\n");
    int i;
    for(i=0;i<12;i++)//顯示菜單
    {
        printf("%s   %-18s %d元\n",code[i],name[i],price[i]);
    }
    printf("===========================\n");
    int keep=1;//控制系統結束
    do//整個系統
    {
        int num[12]={0};//各餐點所點數量
        char input[20];//輸入
        float total = 0;//總價錢
        printf("請輸入系統指令\n離開系統請輸入"RED"0"RESET" 開始點餐請輸入"RED"1"RESET"\n");
        printf("請輸入:");
        scanf("%s",&input);
        if(strcmp(input,"0") == 0) break;//離開系統
        else if(strcmp(input,"1") == 0)//開始點餐
        {
            int keep1 = 1;//控制點餐迴圈
            do
            {
                printf("請輸入餐點編號(ex:"RED"A-1"RESET"):");
                char codein[20];
                scanf("%s",codein);
                int correct = 0;//輸入正確為1   
                for(i=0;i<12;i++)
                {
                    if(strcmp(code[i],codein) == 0)//選取餐點
                    {
                        printf("選取:%s %s\n",codein,name[i]);
                        total += price[i];
                        num[i] += 1;
                        correct = 1;
                        break;
                    }
                }   
                if(correct == 0 )
                {
                    printf(YEL "輸入錯誤 請重新輸入\n"RESET);
                    continue;
                }
                else 
                {
                    int keep2 = 1;
                    do 
                    {
                        printf("進行結帳請輸入"RED"0"RESET" 繼續點餐請輸入"RED"1"RESET"\n");//選擇結帳OR點餐
                        printf("請輸入:");
                        char input2[20];
                        scanf("%s",&input2);
                        if(strcmp(input2,"1") == 0)
                        {
                            printf("---繼續點餐---\n");
                            keep1 = 1;
                            break;
                        } 
                        else if(strcmp(input2,"0") == 0)
                        {
                            while(num[2]>0 && num[7]>0)//符合D-1套餐
                            {
                                num[2]--;
                                num[7]--;
                                num[10]++;
                                total -= 10;
                            }
                            while(num[1]>0 && num[3]>0 && num[6]>0)//符合D-2套餐
                            {
                                num[1]--;
                                num[3]--;
                                num[6]--;
                                num[11]++;
                                total -= 10;
                            }
                            printf("點選餐點:\n\n");//顯示所選餐點
                            for(i=0;i<12;i++)
                            {
                                if(num[i]>0)
                                {
                                    printf("%s %-14s *%d\n",code[i],name[i],num[i]);
                                }
                            }
                            if(total >= 100)//符合95折條件
                            {
                                total *= 0.95;
                                printf(RED "\n總金額:%.2f元(限時95折優惠)\n"RESET ,total);
                            }
                            else//不符合95折條件
                            {
                               printf(RED "\n總金額:%.2f元\n" RESET,total);
                            }
                            keep1 = 0;
                            break;
                        }
                        else 
                        {
                            printf(YEL "輸入錯誤 請重新輸入\n"RESET);
                            continue; 
                        }
                    }while(keep2 == 1);    
                }
            }while(keep1 == 1);
        }
        else
        {
            printf(YEL "輸入錯誤 請重新輸入\n"RESET);
            continue;
        }
    }while(keep == 1);
    printf("感謝您使用本系統\n");
    return 0;
}
