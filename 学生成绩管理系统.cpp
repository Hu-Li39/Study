#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
#define Max 1000

struct person
{
    string name;
    int num;
    int score ;

};

struct Adderssbooks  
{
    person personArray[Max];
    int size;
};

void showMenu()
{
    cout << "************************" << endl;
    cout << "*****1.添加学生信息*****" << endl;
    cout << "*****2.显示学生信息*****" << endl;
    cout << "*****3.删除学生信息*****" << endl;
    cout << "*****4.查找学生信息*****" << endl;
    cout << "*****5.修改学生信息*****" << endl;
    cout << "*****6.进行成绩统计*****" << endl;
    cout << "*****0.退出管理系统*****" << endl;
    cout << "************************" << endl;
}

void saveToFile (Adderssbooks *abs ) 
{
    ofstream outFile("student.txt");
    if (!outFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return;
    }
    for (int i = 0; i < abs->size; i++) {
        outFile << "姓名: " << abs->personArray[i].name << " 学号: " << abs->personArray[i].num << " 成绩: " << abs->personArray[i].score << endl;
    }

    outFile.close();  // 关闭文件
    cout << "学生信息已保存到 student.txt 文件中！" << endl;
}


void addPerson(Adderssbooks *abs )
{
    if (abs->size > Max){
        cout << "学生名单已满！" << endl;
    } else{
        cout << "请输入学生姓名" <<endl;
        string Tname;
        cin >> Tname;
        abs->personArray[abs->size].name = Tname;
        cout << "请输入学生学号" <<endl;
        int Tnum;
        cin >> Tnum ;
        abs->personArray[abs->size].num = Tnum;
        cout << "请输入学生成绩" <<endl;
        int Tscore;
        cin >> Tscore ;
        abs->personArray[abs->size].score = Tscore;
        abs->size++;
        cout << "添加成功！" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }
}

void showPerson(Adderssbooks abs)
{
    if (abs.size == 0){
        cout << "记录为空！"<< endl;
        system("pause");
        system("cls");
    }else{
        for(int i = 0 ; i < abs.size ; i++){
            cout << "姓名： "<< abs.personArray[i].name << "  学号： "<< abs.personArray[i].num << "  成绩： " << abs.personArray[i].score<<endl;
        }
        printf("共有%d个学生，显示完毕！",abs.size);
        system("pause");
        system("cls");
    }
}


int isExist(Adderssbooks* abs , int Tnum)
{
    for(int i = 0 ; i < abs->size ; i ++){
        if(abs->personArray[i].num == Tnum ){          
            return i;
        }    
    }
    return -1; 
}

void deletePerson(Adderssbooks * abs)
{
    cout << "请输入要删除学生的学号" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        for(int i = ret; i < abs->size ; i++){
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--;
        cout << "删除成功！" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }else{
        cout << "所查找学生不存在，请检查学号是否输入正确。"<< endl;
        system("pause");
        system("cls");
    }
}


void findPerson(Adderssbooks *abs )
{
    cout << "请输入要查找学生的学号" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        cout << "姓名： "<< abs->personArray[ret].name << "  学号： "<< abs->personArray[ret].num << "  成绩： " << abs->personArray[ret].score<<endl;
    }else {
        cout << "所查找学生不存在，请检查学号是否输入正确。"<< endl;
    }
    system("pause");
    system("cls");
}   


void modifyPerson(Adderssbooks * abs)
{
    cout << "请输入所要修改学生的学号" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        cout << "学生原成绩为： " << abs->personArray[ret].score << "   请输入修改后的成绩： "<< endl;
        int Tscore;
        cin >> Tscore;
        abs->personArray[ret].score = Tscore;
        cout << "修改成功！" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }else {
        cout << "所查找学生不存在，请检查学号是否输入正确。"<< endl;
        system("pause");
        system("cls");
    }

}


void scoreCount(Adderssbooks abs)
{   
    
    cout << "请选择统计类型： " << endl;
    cout << "***1.最高分***" << endl;
    cout << "***2.最低分***" << endl;
    cout << "***3.平均分***" << endl;
    int mode = 0;
    cin >> mode;
    switch (mode)
    {
    case 1: {
        float max = 0;
        for( int i = 0; i < abs.size ; i++){
            if(abs.personArray[i].score > max){
                max = abs.personArray[i].score;
            }
        }
        cout << "最高分为： "<< max << endl;
        system("pause");
        system("cls");
        break;
    }
         
    case 2:{
        float min = 100 ;
        for( int i = 0; i < abs.size ; i++){
            if(abs.personArray[i].score < min){
                min = abs.personArray[i].score;
            }
        } 

        cout << "最低分为： "<< min << endl;
        system("pause");
        system("cls");
        break;
        
    }    
    case 3:
    {
        float score_total = 0;
        for( int i = 0; i < abs.size ; i++){
            score_total += abs.personArray[i].score;   
        }
        float score_average = round((score_total / abs.size)*100 / 100);
        cout << "平均分为： "<< score_average << endl;
        system("pause");
        system("cls");
        break;
    }
    default:
        {
        cout << "请重新选择！"<<endl;
        system("pause");
        system("cls");
        break;
        }
    }
};
int main() {   
    Adderssbooks book1;
    book1.size = 0;

    int slecet = 0;
     
    while(1) {
        showMenu();
        cin >> slecet ;
        switch (slecet)
        {
        case 1:
            addPerson(&book1);
            break;
        case 2:
            showPerson(book1);
            break;
        case 3:
            deletePerson(&book1);
            break;
        case 4:
            findPerson(&book1);
            break;
        case 5:
            modifyPerson(&book1);
            break;
        case 6:
            scoreCount(book1);
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0 ;  
            break;
            
        default:
            break;
        }
    }
    system("pause");
    return 0;
}