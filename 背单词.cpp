#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstdio>
#include <map>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <set>
#include <fstream>
using namespace std;
const int M = 9999999;
int choose, wordnumber = 0, mark = 1, score = 0, wrongWord = 0;
map<string, string> English;
map<string, string> chinese;
struct Node
{
    string wEnglish;
    string wchinese;
};
Node words[M];
typedef struct User_basicinfo
{
    char id[15];
    char paw[20];
    char name[15];
    char sex[5];
} Users;
typedef struct Day
{
    char id[15];
    int day_count;
} Day;
bool isLogin = false; //全局变量，用于记录是否登录
// 展示错题
int showWrongWords()
{
	system("cls");
    FILE *fp = fopen("错题词库.txt", "a+");
    for (int i = 0; i < wrongWord; i++)
    {
        string A, B;
        char a[100], b[100];
        fscanf(fp, "%s", a);
        fscanf(fp, "%s", b);
        printf("%s %s\n", a, b);
    }
    printf(" \n总共有%d个词汇！\n\n", wrongWord);
    printf("\n\n<回车键返回菜单>");
    getchar();
    getchar();
    return 1;
}
// 显示总成绩
int showScore()
{
     printf("\n\n                                                  本次总共得%d分!!!                                \n\n", score);
     system("pause");
    return 1;
}
//获取随机数
int random(int num)
{
    srand(time(NULL));
    int magic = rand() % num + 1;
    return magic;
}
//根据中文选择英文
int choosechinese()
{
    system("cls");
    if (English.size() < 4)
    {
        printf("\n\n                            单词不够请继续添加新的单词（最少四个）！！\n\n\n");
        printf("<按回车键返回菜单>");
        getchar();
        getchar();

        return 1;
    }
    while (1)
    {
        int book[4];
        int t = random(English.size()) - 1;
        book[0] = t;
        cout << "请选择单词“" << words[t].wchinese << "”的英文意思（输入m返回菜单）：";

        string wer = words[t].wEnglish; //存好答案;
        //依次顺序取下标
        int j = 1;
        t++;
        while (1)
        {
            if (t > English.size() - 1)
            {
                t = 0;
            }
            if (j >= 4)
            {
                break;
            }
            book[j++] = t++;
        }
        //将四个下标打乱
        if (t % 2)
        {
            swap(book[0], book[random(3)]);
            swap(book[random(3)], book[random(3)]);
            swap(book[random(2)], book[0]);
        }
        else
        {
            swap(book[0], book[random(1)]);
            swap(book[random(3)], book[random(3)]);
            swap(book[random(3)], book[0]);
        }

        cout << endl
             << endl;
        for (int i = 0; i < 4; i++)
        {
            printf("%c.", 'A' + i);
            cout << words[book[i]].wEnglish << "     ";
        }
        cout << endl
             << "答案：";
        //输入答案
        string answer;
        cin >> answer;
        if (answer == "m")
        {
            return 1;
        }
        if (answer == "q")
        {
            printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
            exit(0);
        }
        if (answer == "A")
        {
            if (words[book[0]].wEnglish == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[0]].wEnglish.c_str(), words[book[0]].wEnglish.length() + 1);
                strncpy(c, words[book[0]].wchinese.c_str(), words[book[0]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "B")
        {
            if (words[book[1]].wEnglish == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[1]].wEnglish.c_str(), words[book[1]].wEnglish.length() + 1);
                strncpy(c, words[book[1]].wchinese.c_str(), words[book[1]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "C")
        {
            if (words[book[2]].wEnglish == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[2]].wEnglish.c_str(), words[book[2]].wEnglish.length() + 1);
                strncpy(c, words[book[2]].wchinese.c_str(), words[book[2]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "D")
        {
            if (words[book[3]].wEnglish == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[3]].wEnglish.c_str(), words[book[3]].wEnglish.length() + 1);
                strncpy(c, words[book[3]].wchinese.c_str(), words[book[3]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else
        {
            printf("\n输入有误！！\n\n");
        }
        printf("\n<回车下一题>");
        getchar();
        getchar();
        system("cls");
    }
}
//添加新单词
int addwords()
{
    system("cls");
    int k = 0;
    printf("请分别输入单词中英文意思用空格隔开,输入m表示结束:\n\n");
    while (1)
    {
        string Englishword;
        string chineseword;
        //输入单英文
        cin >> Englishword;
        //退出程序
        if (Englishword == "q")
        {
            printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
            exit(0);
        }
        //打开菜单
        if (Englishword == "m")
        {
            system("cls");
            if (k >= 1)
            {
                printf("\n              单词导入词库成功，本次共导入%d个单词！！\n\n\n", k);
            }
            else
            {
                printf("\n               您没有导入任何单词！！\n\n\n");
            }
            printf("<回车键返回菜单>");
            getchar();
            getchar();
            return 1;
        }
        //输入单词中文
        cin >> chineseword;
        //退出程序
        if (Englishword == "q")
        {
            printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
            exit(0);
        }
        //打开菜单
        if (chineseword == "m")
        {
            system("cls");
            if (k >= 1)
            {
                printf("\n              单词导入词库成功，本次共导入%d个单词！！\n\n\n", k);
            }
            else
            {
                printf("\n              您没有导入任何单词！！\n\n\n");
            }
            printf("<回车键返回菜单>");
            getchar();
            getchar();
            return 1;
        }
        //单词添加到map中
        English[Englishword] = chineseword;
        chinese[chineseword] = Englishword;
        words[k].wchinese = chineseword;
        words[k++].wEnglish = Englishword;
        //单词加入词库
        FILE *fp = fopen("词库.txt", "a+");
        char e[100], c[100];
        //将字符串转为字符数组
        strncpy(e, Englishword.c_str(), Englishword.length() + 1);
        strncpy(c, chineseword.c_str(), chineseword.length() + 1);
        //判断是否为第一个单词控制换行
        if (English.size() <= 1)
        {
            fprintf(fp, "%s ", e);
            fprintf(fp, "%s", c);
        }
        else
        {
            fprintf(fp, "\n%s ", e);
            fprintf(fp, "%s", c);
        }
        fclose(fp);
        wordnumber++; //单词数统计
    }
}

//默写中文
int writechinese()
{
    system("cls");
    //保证有单词记
    if (English.size() == 0)
    {
        printf("\n                                   词库为空，请先添加单词！！！\n\n");
        printf("<按回车键返回菜单>");
        getchar();
        getchar();
        return 1;
    }
    while (1)
    {
        string answer;
        map<string, string>::iterator it = English.begin();
        int count = 0;
        int suji = random(English.size());
        //确定随机单词位置
        for (it = English.begin(); it != English.end(); ++it)
        {
            count++;
            if (count >= suji)
            {
                cout << "请输入单词“" << it->first << "”的中文意思（输入m返回菜单）：";
                cin >> answer;
                if (answer == "q")
                {
                    printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
                    exit(0);
                }
                if (answer == "m")
                {
                    return 1;
                }
                if (it->second == answer)
                {
                    score++;
                    printf("\n恭喜你答对了！！！,分数：%d\n\n", score);
                }
                else
                {
                    cout << endl
                         << "答错了“" << it->first << "”的中文意思是:" << it->second << endl
                         << endl;
                }
                break;
            }
        }
        printf("<回车下一题>");
        getchar();
        getchar();
        system("cls");
    }
}
//默写英文
int writeEnglish()
{
    system("cls");
    string answer;
    //保证有单词记
    if (English.size() == 0)
    {
        printf("\n                                   词库为空，请先添加单词！！！\n\n");
        printf("<按回车键返回菜单>");
        getchar();
        getchar();
        return 1;
    }
    while (1)
    {
        map<string, string>::iterator it = chinese.begin();
        int count = 0;
        int suiji = random(English.size());
        for (it = English.begin(); it != English.end(); ++it)
        {
            count++;
            if (count >= suiji)
            {
                cout << "请输入单词“" << it->second << "”的英文意思（输入m返回菜单）：";
                cin >> answer;
                if (answer == "q")
                {
                    printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
                    exit(0);
                }
                if (answer == "m")
                {
                    return 1;
                }
                if (it->first == answer)
                {
                    score++;
                    printf("\n恭喜你答对了！！！,分数：%d \n\n", score);
                }
                else
                {
                    cout << endl
                         << "答错了“" << it->second << "”的英文是:" << it->first << endl
                         << endl;
                }
                break;
            }
        }
        printf("<回车下一题>");
        getchar();
        getchar();
        system("cls");
    }
}
//查找单词
int findword()
{
    while (1)
    {
        system("cls");
        printf("\n\n     A.根据英文查找中文         ");
        printf("B.根据中文查找英文\n\n\n");
        printf("     请选择查找类型(输入A,B选项,m返回菜单)：");
        char r;
        cin >> r;
        if (r == 'm')
        {
            return 1;
        }
        else if (r == 'q')
        {
            exit(0);
        }
        else if (r == 'A')
        {
            system("cls");
            string t1;
            printf("   \n\n请输入英文：");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
             while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "的中文意思是“" << it->second << "”" << endl
                     << endl
                     << endl;
                cout << "<回车键返回上一步>";
            }
            else
            {
                printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
                cout << "<回车键返回上一步>";
            }
        }
        else if (r == 'B')
        {
            system("cls");
            string t2;
            printf("   \n\n请输入中文：");
            cin >> t2;
            map<string, string>::iterator it = chinese.begin();
             while(it!=English.end()&&it->first!=t2) {
            	it++;
			} 
            if (it != chinese.end())
            {
                cout << endl
                     << endl
                     << "    " << t2 << "的英文是“" << it->second << "”" << endl
                     << endl
                     << endl;
                cout << "<回车键返回上一步>";
            }
            else
            {
                printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
                cout << "<回车键返回上一步>";
            }
        }
        else
        {
            system("cls");
            printf("           输入错误！！\n\n\n");
            printf("<回车返回菜单>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//补充单词中文意思
int addWordChineseMeaning() {
		while (1)
    {
        system("cls");
        printf("\n\n     A.根据英文查找中文         ");
        printf("     请选择查找类型(输入A选项,m返回菜单)：");
        char r;
        cin >> r;
        if (r == 'm')
        {
            return 1;
        }
        else if (r == 'q')
        {
            exit(0);
        }
        else if (r == 'A')
        {
            system("cls");
            string t1;
            printf("   \n\n请输入英文：");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
            it = English.find(t1);
             while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "的中文意思是“" << it->second << "”" << endl
                     << endl
                     << endl;
                printf("   \n\n请输入补充的中文意思：");
                string t2;
				cin>>t2;
				English[it->first]=it->second+" "+t2; 
                cout<<"修改成功"<<endl; 
                cout << "<回车键返回上一步>";
            }
            else
            {
                printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
                cout << "<回车键返回上一步>";
            }
        }
        else
        {
            system("cls");
            printf("           输入错误！！\n\n\n");
            printf("<回车返回菜单>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//修改单词
int changeword() {
	while (1)
    {
        system("cls");
        printf("\n\n     A.根据英文查找中文         ");
        printf("     请选择查找类型(输入A选项,m返回菜单)：");
        char r;
        cin >> r;
        if (r == 'm')
        {
            return 1;
        }
        else if (r == 'q')
        {
            exit(0);
        }
        else if (r == 'A')
        {
            system("cls");
            string t1;
            printf("   \n\n请输入英文：");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
             while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "的中文意思是“" << it->second << "”" << endl
                     << endl
                     << endl;
                printf("   \n\n请输入修改后的中文意思：");
                string t2;
				cin>>t2;
				English[it->first]=t2; 
                cout<<"修改成功"<<endl; 
                cout << "<回车键返回上一步>";
            }
            else
            {
                printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
                cout << "<回车键返回上一步>";
            }
        }
        else
        {
            system("cls");
            printf("           输入错误！！\n\n\n");
            printf("<回车返回菜单>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
} 
//删除单词
 int deleteword()
{
    while (1)
    {
        system("cls");
        printf("\n\n     A.根据英文查找中文         ");
        printf("     请选择查找类型(输入A选项,m返回菜单)：");
        char r;
        cin >> r;
        if (r == 'm')
        {
            return 1;
        }
        else if (r == 'q')
        {
            exit(0);
        }
        else if (r == 'A')
        {
            system("cls");
            string t1;
            printf("   \n\n请输入英文：");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
            while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "的中文意思是“" << it->second << "”" << endl
                     << endl
                     << endl;
//                cout<<it->second<<endl;
                English.erase(it->first);
                chinese.erase(it->second);
                cout<<"  删除成功   "<<endl;
                cout << "<回车键返回上一步>";
            }
            else
            {
                printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
                cout << "<回车键返回上一步>";
            }
        }
        
        else
        {
            system("cls");
            printf("           输入错误！！\n\n\n");
            printf("<回车返回菜单>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//根据英文选择中文
int chooseEnglish()
{
    system("cls");
    if (English.size() < 4)
    {
        printf("\n\n                            单词不够请继续添加新的单词（最少四个）！！\n\n\n");
        printf("<按回车键返回菜单>");
        getchar();
        getchar();

        return 1;
    }
    while (1)
    {
        int book[4];
        int t = random(English.size()) - 1;
        book[0] = t;
        cout << "请输入单词“" << words[t].wEnglish << "”的中文意思（输入m返回菜单）：";

        string wer = words[t].wchinese; //存好答案;
        //依次顺序取下标
        int j = 1;
        t++;
        while (1)
        {
            if (t > English.size() - 1)
            {
                t = 0;
            }
            if (j >= 4)
            {
                break;
            }
            book[j++] = t++;
        }
        //将四个下标打乱
        if (t % 2)
        {
            swap(book[0], book[random(3)]);
            swap(book[random(3)], book[random(3)]);
            swap(book[random(2)], book[0]);
        }
        else
        {
            swap(book[0], book[random(1)]);
            swap(book[random(3)], book[random(3)]);
            swap(book[random(3)], book[0]);
        }

        cout << endl
             << endl;
        for (int i = 0; i < 4; i++)
        {
            printf("%c.", 'A' + i);
            cout << words[book[i]].wchinese << "     ";
        }
        cout << endl
             << "答案：";
        string answer;
        cin >> answer;
        if (answer == "m")
        {
            return 1;
        }
        if (answer == "q")
        {
            printf("\n\n                                本次总共得%d分!!!                                \n\n", score);
            exit(0);
        }
        if (answer == "A")
        {
            if (words[book[0]].wchinese == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[0]].wEnglish.c_str(), words[book[0]].wEnglish.length() + 1);
                strncpy(c, words[book[0]].wchinese.c_str(), words[book[0]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "B")
        {
            if (words[book[1]].wchinese == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[1]].wEnglish.c_str(), words[book[1]].wEnglish.length() + 1);
                strncpy(c, words[book[1]].wchinese.c_str(), words[book[1]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "C")
        {
            if (words[book[2]].wchinese == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[2]].wEnglish.c_str(), words[book[2]].wEnglish.length() + 1);
                strncpy(c, words[book[2]].wchinese.c_str(), words[book[2]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else if (answer == "D")
        {

            if (words[book[3]].wchinese == wer)
            {
                score += 10;
                printf("\n恭喜你答对了!!!,分数：%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("错题词库.txt", "a+");
                char e[100], c[100];
                //将字符串转为字符数组
                strncpy(e, words[book[3]].wEnglish.c_str(), words[book[3]].wEnglish.length() + 1);
                strncpy(c, words[book[3]].wchinese.c_str(), words[book[3]].wchinese.length() + 1);
                //判断是否为第一个单词控制换行
                if (English.size() <= 1)
                {
                    fprintf(fp, "%s ", e);
                    fprintf(fp, "%s", c);
                }
                else
                {
                    fprintf(fp, "\n%s ", e);
                    fprintf(fp, "%s", c);
                }
                wrongWord++;
                fclose(fp);
                printf("\n答案错误，正确答案是：");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n答错了,分数：%d\n\n", score);
            }
        }
        else
        {
            printf("\n\n输入有误！！\n\n");
        }
        printf("<回车下一题>");
        getchar();
        getchar();
        system("cls");
    }
}
void Login()
{
    Users a = {0}, b = {0};
    FILE *pf = fopen("users.txt", "r");
    if (pf == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    printf("欢迎来到登录界面!\n");
    printf("请输入账号->");
    scanf("%s", a.id);
    fread(&b, sizeof(Users), 1, pf);
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //未到文件尾
            {
                fread(&b, sizeof(Users), 1, pf);
            }
            else
            {
                printf("该账号不存在,请先注册\n");
                fclose(pf);
                pf = NULL;
                return;
            }
        }
        else //账号注册过->跳到输入密码
        {
            break; //退出无限循环，跳到输入密码
        }
    }
    //【输入密码】
    printf("请输入密码->");
    do
    {
        scanf("%s", a.paw);
        if (strcmp(a.paw, b.paw) != 0)
            printf("密码错误，请重新输入->");
        else
            break;
    } while (1);
    fclose(pf);
    pf = NULL;
    Day d = {0};
    FILE *pf2 = fopen("linshi.txt", "w+");
    pf = fopen("day.txt", "a+");

    while (fread(&d, sizeof(Day), 1, pf)) //从原文件读一个结点
    {
        if (strcmp(d.id, a.id) != 0) //不是要删除的内容
        {
            fwrite(&d, sizeof(Day), 1, pf2);
        }
    }
    Day d2 = {0};
    d2.day_count = d.day_count + 1;

    memcpy(d2.id, d.id, sizeof(d2.id));
    fwrite(&d2, sizeof(Day), 1, pf2);
    fclose(pf);
    fclose(pf2);
    remove("day.txt");
    rename("linshi.txt", "day.txt");
    pf = NULL;
    pf2 = NULL;
    printf("登录成功!\n");
    isLogin = true;
    pf = fopen("day.txt", "r");

    fread(&d, sizeof(Day), 1, pf);
    while (strcmp(d.id, b.id) != 0)
    {
        fread(&d, sizeof(Day), 1, pf);
    };
    printf("您已成功打卡%d次\n", d.day_count);
    fclose(pf);
    pf = NULL;
//    printf("6") ;
}
void Regist()
{
    Users a = {0}, b = {0};
    Day d = {0};
    char tmp[20] = {-1};
    FILE *pf = NULL;
    pf = fopen("users.txt", "r"); //用pf去指向文件
    if (pf == NULL)
    {
        printf("注册时打开文件失败\n");
        return;
    }
    printf("\t\t\t欢迎来到注册界面\n\n");
    printf("\t\t\t输入账号->");
    scanf("%s", a.id);
    //	printf("\t\t\t再次输入账号->");
    //	scanf("%s",d.id);
    printf("输入成功!\n");

    fread(&b, sizeof(Users), 1, pf);
    //【判断】有没有注册过-比较字符串是否相等
    //不相等->是否到文件尾
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //未到文件尾
                fread(&b, sizeof(Users), 1, pf);
            else //到了文件尾仍然没有相同的字符串-说明输入的账号使新的 可以去注册界面
            {
                printf("账号未注册过，将跳转到注册界面\n");
                memcpy(d.id, a.id, sizeof(d.id));
                d.day_count = 0;
                system("pause");
                break; //利用break来跳出无限循环
            }
        }
        else
        {
            printf("该账号已注册过\n");
            fclose(pf);
            pf = NULL;
            return;
        }
    }
    //【注册界面】
    printf("\t\t\t请输入姓名->");
    scanf("%s", a.name);
    printf("\t\t\t请输入性别:男/女->");
    do
    {
        getchar();
        scanf("%s", a.sex);
        if (strcmp(a.sex, "男") != 0 && strcmp(a.sex, "女") != 0)
            printf("\t\t\t输入错误，请重新输入->");
        else
            break;
    } while (1);

    printf("\t\t\t请输入密码->");
    scanf("%s", a.paw);
    printf("\t\t\t请再输入一次密码->");
    do
    {
        scanf("%s", tmp);
        if (strcmp(tmp, a.paw) != 0)
            printf("\t\t\t两次输入密码不一致，请再输入一次密码->");
        else
            break;
    } while (1);
    //两次密码一致
    fclose(pf);
    pf = NULL;
    pf = fopen("users.txt", "a");
    // fwrite会在当前文件指针的位置写入数据
    //"w" 打开，文件指针指到头，只写；"a" 打开，指向文件尾
    fwrite(&a, sizeof(Users), 1, pf);
    printf("\t\t\t注册成功!\n");
    fclose(pf);
    pf = NULL;
    pf = fopen("day.txt", "a");
    fwrite(&d, sizeof(Day), 1, pf);
    fclose(pf);
    pf = NULL;
    system("PAUSE");
    system("cls");
	Login(); 
    return;
}

void Clock_In()
{

    Users a = {0}, b = {0};
    char tmp[20] = {-1};
    FILE *pf = NULL;
    pf = fopen("users.txt", "r"); //用pf去指向文件
    if (pf == NULL)
    {
        printf("打开文件失败\n");
        return;
    }
    printf("\t\t\t欢迎来到打卡界面\n\n");
    printf("\t\t\t输入账号->");
    scanf("%s", a.id);
    printf("输入成功!\n");
    fread(&b, sizeof(Users), 1, pf);
    //【判断】有没有注册过-比较字符串是否相等
    //不相等->是否到文件尾
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //未到文件尾
                fread(&b, sizeof(Users), 1, pf);
            else //到了文件尾仍然没有相同的字符串-说明输入的账号使新的 可以去注册界面
            {
                printf("账号未注册过\n");
                system("pause");
                break; //利用break来跳出无限循环
            }
        }
        else
        {
            fclose(pf);
            pf = NULL;
            pf = fopen("day.txt", "r");
            Day d = {0};
            fread(&d, sizeof(Day), 1, pf);
            while (strcmp(d.id, b.id) != 0)
            {
                fread(&d, sizeof(Day), 1, pf);
            };
            printf("您已成功打卡%d次\n", d.day_count);
            fclose(pf);
            pf = NULL;
            //		 printf("%d",d.day_count);
            return;
        }
    }
}

void showLoginPage()
{
    int input = -1;
    if (!isLogin)
    {
        printf("\t\t\t----------------------------------\n");
        printf("\t\t\t|           1.登录               |\n");
        printf("\t\t\t|           2.注册               |\n");
        printf("\t\t\t|           3.打卡               |\n");
        printf("\t\t\t|           0.退出               |\n");
        printf("\t\t\t----------------------------------\n");
        printf("请选择功能->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Login();
            break;
        case 2:
            Regist();
            break;
        case 3:
            Clock_In();
            break;
        case 0:
            puts("退出成功");
        }
    }
}
//计算词库文件行数
int fileline()
{
    FILE *fp;
    int flag = 0, file_row = 0, count = 0;
    if ((fp = fopen("词库.txt", "r")) == NULL)
        return -1;
    char ch = fgetc(fp);
    if (ch == EOF)
        return 0;
    while (!feof(fp))
    {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count + 1; //加上最后一行
    fclose(fp);
    return file_row;
}
//计算错题词库文件行数
void wrongfileline()
{
    FILE *fp;
    int flag = 0, file_row = 0, count = 0;
    if ((fp = fopen("错题词库.txt", "r")) == NULL)
        return ;
    char ch = fgetc(fp);
    if (ch == EOF)
        return ;
    while (!feof(fp))
    {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count + 1; //加上最后一行
    fclose(fp);
//    printf("%d",file_row);
    wrongWord=  file_row;
}
//读入文件（词库中读入单词）
void readfile()
{
    FILE *fp = fopen("词库.txt", "r");
    int line = fileline();
    for (int i = 0; i < line; i++)
    {
        string A, B;
        char a[100], b[100];
        fscanf(fp, "%s", a);
        fscanf(fp, "%s", b);
        English[a] = b;
        chinese[b] = a;
        words[wordnumber].wEnglish = a;
        words[wordnumber++].wchinese = b;
    }
    fclose(fp);
}
//查看词库
int lookwordlist()
{
    system("cls");

    FILE *fp = fopen("词库.txt", "r");
    // int line=wordnumber;
    for (int i = 0; i < English.size(); i++)
    {
        string A, B;
        char a[100], b[100];
        fscanf(fp, "%s", a);
        fscanf(fp, "%s", b);
        printf("%s %s\n", a, b);
    }
    printf(" \n总共有%d个词汇！\n\n", English.size());
    printf("\n\n<回车键返回菜单>");
    getchar();
    getchar();
    return 1;
}
void list()
{
    system("cls");
    printf("             ||* * * * * * * * * * * * * * * * * * * * * *《菜单》 * * * * * * * * * * * * * *  * * * * * * * * *||\n             ||                                                                                                  ||\n             ");
    printf("||                   1.添加新单词             2.默写中文            3.默写英文                      ||\n             ||                                                                                                  ||\n ");
    printf("            ||                   4.根据中文选择英文       5.根据英文选择中文    6.查看词库列表                  ||\n             ||                                                                                                  ||\n             ||                   7.查找单词               8.查看总成绩            9.退出程序                    ||\n");
    printf("             ||                                                                                                  ||\n");
    printf("             ||                  10.显示错题集            11.删除单词            12.修改单词                     ||\n             ||                                                                                                  ||\n");
    printf("             ||                                                                                                  ||\n");
    printf("             ||                  13.补充单词中文意思                                                             ||\n             ||                                                                                                  ||\n");
    printf("             ######################################################################################################\n\n");
    printf("                                              请选择操作（输入相应序号）:");
}
int main()
{
    int n;
    char ch1, ch2;
    showLoginPage(); //显示菜单
    if (isLogin)
    {
        readfile();
        wrongfileline();
        system ("PAUSE");
        while (1)
        {
            if (mark == 1)
                list(); //打开菜单;
            scanf("%d", &choose);
            switch (choose)
            {
            case 1:
            {
                mark = addwords();
                break;
            }
            case 2:
            {
                mark = writechinese();
                break;
            }
            case 3:
            {
                mark = writeEnglish();
                break;
            }
            case 4:
            {
                mark = choosechinese();
                break;
            }
            case 5:
            {
                mark = chooseEnglish();
                break;
            }
            case 7:
            {
                mark = findword();
                break;
            }
            case 6:
            {
                mark = lookwordlist();
                break;
            }
            case 8:
            {
                showScore();
                break;
            }
            case 9:
            {
                printf("\n\n                                                  本次总共得%d分!!!                                \n\n", score);
                return 0;
                break;
            }
            case 10:
            {
                mark=showWrongWords();
                break;
            }
            case 0:
            {
                printf("\n                                            输入有误，请重新输入<按回车键继续>!!\n");
                getchar();
                getchar();
                getchar();
                break;
            }
                			case 11:{
                				mark=deleteword();
                				break;
                			}
                				case 12:{
                				mark=changeword();
                				break;
                			}
                				case 13:{
                				mark=addWordChineseMeaning();
                				break;
                			}
            default:
            {
                printf("\n                                            输入有误，请重新输入<按回车键继续>!!\n");
                getchar();
                getchar();
            }
            }
        }
    }
    return 0;
}

