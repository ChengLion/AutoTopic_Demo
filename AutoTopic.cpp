#include <iostream>  // 输入输出流
#include <fstream>   // 包含文件流库
#include <string>    // 包含字符串库
#include <vector>    // 调用vector库
#include <algorithm> // 用于 std::shuffle
#include <random>    // 用于 std::default_random_engine
#include <ctime>     // 用于 std::time
#include <sstream>   // 处理字符串流
using namespace std; // 声明使用标准命名空间

int main()
{
    // 打开文件
    ifstream Topic("TEST/TEST3_ANSI.txt"); 
    if (!Topic.is_open())// 检查文件是否成功打开
    {
        cerr << "无法打开题目文件！" << endl;
        return 1; // 返回错误代码
    }
    else cerr << "成功打开题目文件。" << endl;


    // 逐行读取文件内容保存至vector并报数
    string Line;
    vector<vector<string>> M_Contents;// 定义三个 vector 容器，分别保存 M、J、L 类型的内容
    vector<vector<string>> J_Contents;// 每个元素是一个 vector<string>，存储每行的属性信息
    vector<vector<string>> L_Contents;
    int TopicCount = 0;
    while (getline(Topic, Line)) 
    {
        if (!Line.empty()) // 检查当前行是否为空
        {
            stringstream ss(Line);// 使用 stringstream 解析每行内容
            char type;
            string content, page, attr;
            ss >> type;// 读取第一个字母
            if (ss.peek() == ',') 
            {
                ss.ignore(); // 忽略逗号
            }

            // 读取内容部分
            getline(ss, content, ','); // 读取内容到第一个逗号
            getline(ss, page, ',');    // 读取答案页码
            getline(ss, attr, ';');    // 读取属性

            // 将内容、页码、属性信息保存到 vector<string> 中
            vector<string> allContent = { content, page, attr };

            // 根据类型,将每一行保存到对应的 vector 中
            switch (type) 
            {
            case 'M':
                M_Contents.push_back(allContent);
                break;
            case 'J':
                J_Contents.push_back(allContent);
                break;
            case 'L':
                L_Contents.push_back(allContent);
                break;
            default:
                cerr << "未知类型: " << type << endl;
                break;
            }
        }
    }
    cout << "试题内容已加载，共有 " << M_Contents.size() + J_Contents.size() + L_Contents.size() << " 道题：" << endl;
    cout << "名词解释共有 " << M_Contents.size() << " 道题：" << endl;
    cout << "简答题共有 " << J_Contents.size() << " 道题：" << endl;
    cout << "论述题共有 " << L_Contents.size() << " 道题：" << endl ;
    cout <<  "--------------------------" << endl << endl;
    Topic.close(); // 关闭题目文件


    // 初始化随机数种子
    srand(static_cast<unsigned int>(time(0))); 
    // 打乱每个 vector 的顺序
    shuffle(M_Contents.begin(), M_Contents.end(), default_random_engine(time(0)));
    shuffle(J_Contents.begin(), J_Contents.end(), default_random_engine(time(0)));
    shuffle(L_Contents.begin(), L_Contents.end(), default_random_engine(time(0)));

    // M名词解释随机出题
    int M_numLinesToOutput = 6; // 设置需要随机输出的行数，假设随机输出 6 行
    cout << "一、名词解释" << endl << endl;
    for (int i = 0; i < M_numLinesToOutput && i < M_Contents.size(); ++i) // 输出前几行
    {
        if (M_Contents[i][2].empty())
        {
            cout << i + 1 << ". " << M_Contents[i][0] << endl;
        }
        else
        {
            cout << i + 1 << ". " << M_Contents[i][0] << " (" << M_Contents[i][2] << ")" << endl;
        }
    }cout << endl << "--------------------------" << endl;

    // J简答题随机出题
    int J_numLinesToOutput = 5; // 设置需要随机输出的行数，假设随机输出 5 行
    cout << "二、简答题" << endl << endl;
    for (int i = 0; i < J_numLinesToOutput && i < J_Contents.size(); ++i) // 输出前几行
    {
        if (J_Contents[i][2].empty())
        {
            cout << i + 1 << ". " << J_Contents[i][0] << endl;
        }
        else
        {
            cout << i + 1 << ". " << J_Contents[i][0] << " (" << J_Contents[i][2] << ")" << endl;
        }
    }cout << endl << "--------------------------" << endl;

    // L论述题随机出题
    int L_numLinesToOutput = 2; // 设置需要随机输出的行数，假设随机输出 2 行
    cout << "三、论述题" << endl << endl;
    for (int i = 0; i < L_numLinesToOutput && i < L_Contents.size(); ++i) // 输出前几行
    {
        if (L_Contents[i][2].empty())
        {
            cout << i + 1 << ". " << L_Contents[i][0] << endl;
        }
        else
        {
            cout << i + 1 << ". " << L_Contents[i][0] << " (" << L_Contents[i][2] << ")" << endl;
        }
    }cout << endl << "--------------------------" << endl;

    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件