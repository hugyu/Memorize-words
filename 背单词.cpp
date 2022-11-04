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
bool isLogin = false; //ȫ�ֱ��������ڼ�¼�Ƿ��¼
// չʾ����
int showWrongWords()
{
	system("cls");
    FILE *fp = fopen("����ʿ�.txt", "a+");
    for (int i = 0; i < wrongWord; i++)
    {
        string A, B;
        char a[100], b[100];
        fscanf(fp, "%s", a);
        fscanf(fp, "%s", b);
        printf("%s %s\n", a, b);
    }
    printf(" \n�ܹ���%d���ʻ㣡\n\n", wrongWord);
    printf("\n\n<�س������ز˵�>");
    getchar();
    getchar();
    return 1;
}
// ��ʾ�ܳɼ�
int showScore()
{
     printf("\n\n                                                  �����ܹ���%d��!!!                                \n\n", score);
     system("pause");
    return 1;
}
//��ȡ�����
int random(int num)
{
    srand(time(NULL));
    int magic = rand() % num + 1;
    return magic;
}
//��������ѡ��Ӣ��
int choosechinese()
{
    system("cls");
    if (English.size() < 4)
    {
        printf("\n\n                            ���ʲ������������µĵ��ʣ������ĸ�������\n\n\n");
        printf("<���س������ز˵�>");
        getchar();
        getchar();

        return 1;
    }
    while (1)
    {
        int book[4];
        int t = random(English.size()) - 1;
        book[0] = t;
        cout << "��ѡ�񵥴ʡ�" << words[t].wchinese << "����Ӣ����˼������m���ز˵�����";

        string wer = words[t].wEnglish; //��ô�;
        //����˳��ȡ�±�
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
        //���ĸ��±����
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
             << "�𰸣�";
        //�����
        string answer;
        cin >> answer;
        if (answer == "m")
        {
            return 1;
        }
        if (answer == "q")
        {
            printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
            exit(0);
        }
        if (answer == "A")
        {
            if (words[book[0]].wEnglish == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[0]].wEnglish.c_str(), words[book[0]].wEnglish.length() + 1);
                strncpy(c, words[book[0]].wchinese.c_str(), words[book[0]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "B")
        {
            if (words[book[1]].wEnglish == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[1]].wEnglish.c_str(), words[book[1]].wEnglish.length() + 1);
                strncpy(c, words[book[1]].wchinese.c_str(), words[book[1]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "C")
        {
            if (words[book[2]].wEnglish == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[2]].wEnglish.c_str(), words[book[2]].wEnglish.length() + 1);
                strncpy(c, words[book[2]].wchinese.c_str(), words[book[2]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "D")
        {
            if (words[book[3]].wEnglish == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[3]].wEnglish.c_str(), words[book[3]].wEnglish.length() + 1);
                strncpy(c, words[book[3]].wchinese.c_str(), words[book[3]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else
        {
            printf("\n�������󣡣�\n\n");
        }
        printf("\n<�س���һ��>");
        getchar();
        getchar();
        system("cls");
    }
}
//����µ���
int addwords()
{
    system("cls");
    int k = 0;
    printf("��ֱ����뵥����Ӣ����˼�ÿո����,����m��ʾ����:\n\n");
    while (1)
    {
        string Englishword;
        string chineseword;
        //���뵥Ӣ��
        cin >> Englishword;
        //�˳�����
        if (Englishword == "q")
        {
            printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
            exit(0);
        }
        //�򿪲˵�
        if (Englishword == "m")
        {
            system("cls");
            if (k >= 1)
            {
                printf("\n              ���ʵ���ʿ�ɹ������ι�����%d�����ʣ���\n\n\n", k);
            }
            else
            {
                printf("\n               ��û�е����κε��ʣ���\n\n\n");
            }
            printf("<�س������ز˵�>");
            getchar();
            getchar();
            return 1;
        }
        //���뵥������
        cin >> chineseword;
        //�˳�����
        if (Englishword == "q")
        {
            printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
            exit(0);
        }
        //�򿪲˵�
        if (chineseword == "m")
        {
            system("cls");
            if (k >= 1)
            {
                printf("\n              ���ʵ���ʿ�ɹ������ι�����%d�����ʣ���\n\n\n", k);
            }
            else
            {
                printf("\n              ��û�е����κε��ʣ���\n\n\n");
            }
            printf("<�س������ز˵�>");
            getchar();
            getchar();
            return 1;
        }
        //������ӵ�map��
        English[Englishword] = chineseword;
        chinese[chineseword] = Englishword;
        words[k].wchinese = chineseword;
        words[k++].wEnglish = Englishword;
        //���ʼ���ʿ�
        FILE *fp = fopen("�ʿ�.txt", "a+");
        char e[100], c[100];
        //���ַ���תΪ�ַ�����
        strncpy(e, Englishword.c_str(), Englishword.length() + 1);
        strncpy(c, chineseword.c_str(), chineseword.length() + 1);
        //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
        wordnumber++; //������ͳ��
    }
}

//Ĭд����
int writechinese()
{
    system("cls");
    //��֤�е��ʼ�
    if (English.size() == 0)
    {
        printf("\n                                   �ʿ�Ϊ�գ�������ӵ��ʣ�����\n\n");
        printf("<���س������ز˵�>");
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
        //ȷ���������λ��
        for (it = English.begin(); it != English.end(); ++it)
        {
            count++;
            if (count >= suji)
            {
                cout << "�����뵥�ʡ�" << it->first << "����������˼������m���ز˵�����";
                cin >> answer;
                if (answer == "q")
                {
                    printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
                    exit(0);
                }
                if (answer == "m")
                {
                    return 1;
                }
                if (it->second == answer)
                {
                    score++;
                    printf("\n��ϲ�����ˣ�����,������%d\n\n", score);
                }
                else
                {
                    cout << endl
                         << "����ˡ�" << it->first << "����������˼��:" << it->second << endl
                         << endl;
                }
                break;
            }
        }
        printf("<�س���һ��>");
        getchar();
        getchar();
        system("cls");
    }
}
//ĬдӢ��
int writeEnglish()
{
    system("cls");
    string answer;
    //��֤�е��ʼ�
    if (English.size() == 0)
    {
        printf("\n                                   �ʿ�Ϊ�գ�������ӵ��ʣ�����\n\n");
        printf("<���س������ز˵�>");
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
                cout << "�����뵥�ʡ�" << it->second << "����Ӣ����˼������m���ز˵�����";
                cin >> answer;
                if (answer == "q")
                {
                    printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
                    exit(0);
                }
                if (answer == "m")
                {
                    return 1;
                }
                if (it->first == answer)
                {
                    score++;
                    printf("\n��ϲ�����ˣ�����,������%d \n\n", score);
                }
                else
                {
                    cout << endl
                         << "����ˡ�" << it->second << "����Ӣ����:" << it->first << endl
                         << endl;
                }
                break;
            }
        }
        printf("<�س���һ��>");
        getchar();
        getchar();
        system("cls");
    }
}
//���ҵ���
int findword()
{
    while (1)
    {
        system("cls");
        printf("\n\n     A.����Ӣ�Ĳ�������         ");
        printf("B.�������Ĳ���Ӣ��\n\n\n");
        printf("     ��ѡ���������(����A,Bѡ��,m���ز˵�)��");
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
            printf("   \n\n������Ӣ�ģ�");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
             while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "��������˼�ǡ�" << it->second << "��" << endl
                     << endl
                     << endl;
                cout << "<�س���������һ��>";
            }
            else
            {
                printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
                cout << "<�س���������һ��>";
            }
        }
        else if (r == 'B')
        {
            system("cls");
            string t2;
            printf("   \n\n���������ģ�");
            cin >> t2;
            map<string, string>::iterator it = chinese.begin();
             while(it!=English.end()&&it->first!=t2) {
            	it++;
			} 
            if (it != chinese.end())
            {
                cout << endl
                     << endl
                     << "    " << t2 << "��Ӣ���ǡ�" << it->second << "��" << endl
                     << endl
                     << endl;
                cout << "<�س���������һ��>";
            }
            else
            {
                printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
                cout << "<�س���������һ��>";
            }
        }
        else
        {
            system("cls");
            printf("           ������󣡣�\n\n\n");
            printf("<�س����ز˵�>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//���䵥��������˼
int addWordChineseMeaning() {
		while (1)
    {
        system("cls");
        printf("\n\n     A.����Ӣ�Ĳ�������         ");
        printf("     ��ѡ���������(����Aѡ��,m���ز˵�)��");
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
            printf("   \n\n������Ӣ�ģ�");
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
                     << "    " << t1 << "��������˼�ǡ�" << it->second << "��" << endl
                     << endl
                     << endl;
                printf("   \n\n�����벹���������˼��");
                string t2;
				cin>>t2;
				English[it->first]=it->second+" "+t2; 
                cout<<"�޸ĳɹ�"<<endl; 
                cout << "<�س���������һ��>";
            }
            else
            {
                printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
                cout << "<�س���������һ��>";
            }
        }
        else
        {
            system("cls");
            printf("           ������󣡣�\n\n\n");
            printf("<�س����ز˵�>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//�޸ĵ���
int changeword() {
	while (1)
    {
        system("cls");
        printf("\n\n     A.����Ӣ�Ĳ�������         ");
        printf("     ��ѡ���������(����Aѡ��,m���ز˵�)��");
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
            printf("   \n\n������Ӣ�ģ�");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
             while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "��������˼�ǡ�" << it->second << "��" << endl
                     << endl
                     << endl;
                printf("   \n\n�������޸ĺ��������˼��");
                string t2;
				cin>>t2;
				English[it->first]=t2; 
                cout<<"�޸ĳɹ�"<<endl; 
                cout << "<�س���������һ��>";
            }
            else
            {
                printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
                cout << "<�س���������һ��>";
            }
        }
        else
        {
            system("cls");
            printf("           ������󣡣�\n\n\n");
            printf("<�س����ز˵�>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
} 
//ɾ������
 int deleteword()
{
    while (1)
    {
        system("cls");
        printf("\n\n     A.����Ӣ�Ĳ�������         ");
        printf("     ��ѡ���������(����Aѡ��,m���ز˵�)��");
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
            printf("   \n\n������Ӣ�ģ�");
            cin >> t1;
            map<string, string>::iterator it = English.begin();
            while(it!=English.end()&&it->first!=t1) {
            	it++;
			} 
            if (it != English.end())
            {
                cout << endl
                     << endl
                     << "    " << t1 << "��������˼�ǡ�" << it->second << "��" << endl
                     << endl
                     << endl;
//                cout<<it->second<<endl;
                English.erase(it->first);
                chinese.erase(it->second);
                cout<<"  ɾ���ɹ�   "<<endl;
                cout << "<�س���������һ��>";
            }
            else
            {
                printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
                cout << "<�س���������һ��>";
            }
        }
        
        else
        {
            system("cls");
            printf("           ������󣡣�\n\n\n");
            printf("<�س����ز˵�>");
            getchar();
            getchar();
            return 1;
        }

        getchar();
        getchar();
    }
}
//����Ӣ��ѡ������
int chooseEnglish()
{
    system("cls");
    if (English.size() < 4)
    {
        printf("\n\n                            ���ʲ������������µĵ��ʣ������ĸ�������\n\n\n");
        printf("<���س������ز˵�>");
        getchar();
        getchar();

        return 1;
    }
    while (1)
    {
        int book[4];
        int t = random(English.size()) - 1;
        book[0] = t;
        cout << "�����뵥�ʡ�" << words[t].wEnglish << "����������˼������m���ز˵�����";

        string wer = words[t].wchinese; //��ô�;
        //����˳��ȡ�±�
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
        //���ĸ��±����
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
             << "�𰸣�";
        string answer;
        cin >> answer;
        if (answer == "m")
        {
            return 1;
        }
        if (answer == "q")
        {
            printf("\n\n                                �����ܹ���%d��!!!                                \n\n", score);
            exit(0);
        }
        if (answer == "A")
        {
            if (words[book[0]].wchinese == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[0]].wEnglish.c_str(), words[book[0]].wEnglish.length() + 1);
                strncpy(c, words[book[0]].wchinese.c_str(), words[book[0]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "B")
        {
            if (words[book[1]].wchinese == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[1]].wEnglish.c_str(), words[book[1]].wEnglish.length() + 1);
                strncpy(c, words[book[1]].wchinese.c_str(), words[book[1]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "C")
        {
            if (words[book[2]].wchinese == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[2]].wEnglish.c_str(), words[book[2]].wEnglish.length() + 1);
                strncpy(c, words[book[2]].wchinese.c_str(), words[book[2]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else if (answer == "D")
        {

            if (words[book[3]].wchinese == wer)
            {
                score += 10;
                printf("\n��ϲ������!!!,������%d\n\n", score);
            }
            else
            {
                FILE *fp = fopen("����ʿ�.txt", "a+");
                char e[100], c[100];
                //���ַ���תΪ�ַ�����
                strncpy(e, words[book[3]].wEnglish.c_str(), words[book[3]].wEnglish.length() + 1);
                strncpy(c, words[book[3]].wchinese.c_str(), words[book[3]].wchinese.length() + 1);
                //�ж��Ƿ�Ϊ��һ�����ʿ��ƻ���
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
                printf("\n�𰸴�����ȷ���ǣ�");
                cout << wer << endl
                     << endl;
                score -= 10;
                printf("\n�����,������%d\n\n", score);
            }
        }
        else
        {
            printf("\n\n�������󣡣�\n\n");
        }
        printf("<�س���һ��>");
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
        printf("�ļ���ʧ��\n");
        return;
    }
    printf("��ӭ������¼����!\n");
    printf("�������˺�->");
    scanf("%s", a.id);
    fread(&b, sizeof(Users), 1, pf);
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //δ���ļ�β
            {
                fread(&b, sizeof(Users), 1, pf);
            }
            else
            {
                printf("���˺Ų�����,����ע��\n");
                fclose(pf);
                pf = NULL;
                return;
            }
        }
        else //�˺�ע���->������������
        {
            break; //�˳�����ѭ����������������
        }
    }
    //���������롿
    printf("����������->");
    do
    {
        scanf("%s", a.paw);
        if (strcmp(a.paw, b.paw) != 0)
            printf("�����������������->");
        else
            break;
    } while (1);
    fclose(pf);
    pf = NULL;
    Day d = {0};
    FILE *pf2 = fopen("linshi.txt", "w+");
    pf = fopen("day.txt", "a+");

    while (fread(&d, sizeof(Day), 1, pf)) //��ԭ�ļ���һ�����
    {
        if (strcmp(d.id, a.id) != 0) //����Ҫɾ��������
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
    printf("��¼�ɹ�!\n");
    isLogin = true;
    pf = fopen("day.txt", "r");

    fread(&d, sizeof(Day), 1, pf);
    while (strcmp(d.id, b.id) != 0)
    {
        fread(&d, sizeof(Day), 1, pf);
    };
    printf("���ѳɹ���%d��\n", d.day_count);
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
    pf = fopen("users.txt", "r"); //��pfȥָ���ļ�
    if (pf == NULL)
    {
        printf("ע��ʱ���ļ�ʧ��\n");
        return;
    }
    printf("\t\t\t��ӭ����ע�����\n\n");
    printf("\t\t\t�����˺�->");
    scanf("%s", a.id);
    //	printf("\t\t\t�ٴ������˺�->");
    //	scanf("%s",d.id);
    printf("����ɹ�!\n");

    fread(&b, sizeof(Users), 1, pf);
    //���жϡ���û��ע���-�Ƚ��ַ����Ƿ����
    //�����->�Ƿ��ļ�β
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //δ���ļ�β
                fread(&b, sizeof(Users), 1, pf);
            else //�����ļ�β��Ȼû����ͬ���ַ���-˵��������˺�ʹ�µ� ����ȥע�����
            {
                printf("�˺�δע���������ת��ע�����\n");
                memcpy(d.id, a.id, sizeof(d.id));
                d.day_count = 0;
                system("pause");
                break; //����break����������ѭ��
            }
        }
        else
        {
            printf("���˺���ע���\n");
            fclose(pf);
            pf = NULL;
            return;
        }
    }
    //��ע����桿
    printf("\t\t\t����������->");
    scanf("%s", a.name);
    printf("\t\t\t�������Ա�:��/Ů->");
    do
    {
        getchar();
        scanf("%s", a.sex);
        if (strcmp(a.sex, "��") != 0 && strcmp(a.sex, "Ů") != 0)
            printf("\t\t\t�����������������->");
        else
            break;
    } while (1);

    printf("\t\t\t����������->");
    scanf("%s", a.paw);
    printf("\t\t\t��������һ������->");
    do
    {
        scanf("%s", tmp);
        if (strcmp(tmp, a.paw) != 0)
            printf("\t\t\t�����������벻һ�£���������һ������->");
        else
            break;
    } while (1);
    //��������һ��
    fclose(pf);
    pf = NULL;
    pf = fopen("users.txt", "a");
    // fwrite���ڵ�ǰ�ļ�ָ���λ��д������
    //"w" �򿪣��ļ�ָ��ָ��ͷ��ֻд��"a" �򿪣�ָ���ļ�β
    fwrite(&a, sizeof(Users), 1, pf);
    printf("\t\t\tע��ɹ�!\n");
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
    pf = fopen("users.txt", "r"); //��pfȥָ���ļ�
    if (pf == NULL)
    {
        printf("���ļ�ʧ��\n");
        return;
    }
    printf("\t\t\t��ӭ�����򿨽���\n\n");
    printf("\t\t\t�����˺�->");
    scanf("%s", a.id);
    printf("����ɹ�!\n");
    fread(&b, sizeof(Users), 1, pf);
    //���жϡ���û��ע���-�Ƚ��ַ����Ƿ����
    //�����->�Ƿ��ļ�β
    while (1)
    {
        if (strcmp(a.id, b.id) != 0)
        {
            if (feof(pf) == 0) //δ���ļ�β
                fread(&b, sizeof(Users), 1, pf);
            else //�����ļ�β��Ȼû����ͬ���ַ���-˵��������˺�ʹ�µ� ����ȥע�����
            {
                printf("�˺�δע���\n");
                system("pause");
                break; //����break����������ѭ��
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
            printf("���ѳɹ���%d��\n", d.day_count);
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
        printf("\t\t\t|           1.��¼               |\n");
        printf("\t\t\t|           2.ע��               |\n");
        printf("\t\t\t|           3.��               |\n");
        printf("\t\t\t|           0.�˳�               |\n");
        printf("\t\t\t----------------------------------\n");
        printf("��ѡ����->");
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
            puts("�˳��ɹ�");
        }
    }
}
//����ʿ��ļ�����
int fileline()
{
    FILE *fp;
    int flag = 0, file_row = 0, count = 0;
    if ((fp = fopen("�ʿ�.txt", "r")) == NULL)
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
    file_row = count + 1; //�������һ��
    fclose(fp);
    return file_row;
}
//�������ʿ��ļ�����
void wrongfileline()
{
    FILE *fp;
    int flag = 0, file_row = 0, count = 0;
    if ((fp = fopen("����ʿ�.txt", "r")) == NULL)
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
    file_row = count + 1; //�������һ��
    fclose(fp);
//    printf("%d",file_row);
    wrongWord=  file_row;
}
//�����ļ����ʿ��ж��뵥�ʣ�
void readfile()
{
    FILE *fp = fopen("�ʿ�.txt", "r");
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
//�鿴�ʿ�
int lookwordlist()
{
    system("cls");

    FILE *fp = fopen("�ʿ�.txt", "r");
    // int line=wordnumber;
    for (int i = 0; i < English.size(); i++)
    {
        string A, B;
        char a[100], b[100];
        fscanf(fp, "%s", a);
        fscanf(fp, "%s", b);
        printf("%s %s\n", a, b);
    }
    printf(" \n�ܹ���%d���ʻ㣡\n\n", English.size());
    printf("\n\n<�س������ز˵�>");
    getchar();
    getchar();
    return 1;
}
void list()
{
    system("cls");
    printf("             ||* * * * * * * * * * * * * * * * * * * * * *���˵��� * * * * * * * * * * * * * *  * * * * * * * * *||\n             ||                                                                                                  ||\n             ");
    printf("||                   1.����µ���             2.Ĭд����            3.ĬдӢ��                      ||\n             ||                                                                                                  ||\n ");
    printf("            ||                   4.��������ѡ��Ӣ��       5.����Ӣ��ѡ������    6.�鿴�ʿ��б�                  ||\n             ||                                                                                                  ||\n             ||                   7.���ҵ���               8.�鿴�ܳɼ�            9.�˳�����                    ||\n");
    printf("             ||                                                                                                  ||\n");
    printf("             ||                  10.��ʾ���⼯            11.ɾ������            12.�޸ĵ���                     ||\n             ||                                                                                                  ||\n");
    printf("             ||                                                                                                  ||\n");
    printf("             ||                  13.���䵥��������˼                                                             ||\n             ||                                                                                                  ||\n");
    printf("             ######################################################################################################\n\n");
    printf("                                              ��ѡ�������������Ӧ��ţ�:");
}
int main()
{
    int n;
    char ch1, ch2;
    showLoginPage(); //��ʾ�˵�
    if (isLogin)
    {
        readfile();
        wrongfileline();
        system ("PAUSE");
        while (1)
        {
            if (mark == 1)
                list(); //�򿪲˵�;
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
                printf("\n\n                                                  �����ܹ���%d��!!!                                \n\n", score);
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
                printf("\n                                            ������������������<���س�������>!!\n");
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
                printf("\n                                            ������������������<���س�������>!!\n");
                getchar();
                getchar();
            }
            }
        }
    }
    return 0;
}

