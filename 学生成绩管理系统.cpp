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
    cout << "*****1.���ѧ����Ϣ*****" << endl;
    cout << "*****2.��ʾѧ����Ϣ*****" << endl;
    cout << "*****3.ɾ��ѧ����Ϣ*****" << endl;
    cout << "*****4.����ѧ����Ϣ*****" << endl;
    cout << "*****5.�޸�ѧ����Ϣ*****" << endl;
    cout << "*****6.���гɼ�ͳ��*****" << endl;
    cout << "*****0.�˳�����ϵͳ*****" << endl;
    cout << "************************" << endl;
}

void saveToFile (Adderssbooks *abs ) 
{
    ofstream outFile("student.txt");
    if (!outFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    for (int i = 0; i < abs->size; i++) {
        outFile << "����: " << abs->personArray[i].name << " ѧ��: " << abs->personArray[i].num << " �ɼ�: " << abs->personArray[i].score << endl;
    }

    outFile.close();  // �ر��ļ�
    cout << "ѧ����Ϣ�ѱ��浽 student.txt �ļ��У�" << endl;
}


void addPerson(Adderssbooks *abs )
{
    if (abs->size > Max){
        cout << "ѧ������������" << endl;
    } else{
        cout << "������ѧ������" <<endl;
        string Tname;
        cin >> Tname;
        abs->personArray[abs->size].name = Tname;
        cout << "������ѧ��ѧ��" <<endl;
        int Tnum;
        cin >> Tnum ;
        abs->personArray[abs->size].num = Tnum;
        cout << "������ѧ���ɼ�" <<endl;
        int Tscore;
        cin >> Tscore ;
        abs->personArray[abs->size].score = Tscore;
        abs->size++;
        cout << "��ӳɹ���" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }
}

void showPerson(Adderssbooks abs)
{
    if (abs.size == 0){
        cout << "��¼Ϊ�գ�"<< endl;
        system("pause");
        system("cls");
    }else{
        for(int i = 0 ; i < abs.size ; i++){
            cout << "������ "<< abs.personArray[i].name << "  ѧ�ţ� "<< abs.personArray[i].num << "  �ɼ��� " << abs.personArray[i].score<<endl;
        }
        printf("����%d��ѧ������ʾ��ϣ�",abs.size);
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
    cout << "������Ҫɾ��ѧ����ѧ��" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        for(int i = ret; i < abs->size ; i++){
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--;
        cout << "ɾ���ɹ���" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }else{
        cout << "������ѧ�������ڣ�����ѧ���Ƿ�������ȷ��"<< endl;
        system("pause");
        system("cls");
    }
}


void findPerson(Adderssbooks *abs )
{
    cout << "������Ҫ����ѧ����ѧ��" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        cout << "������ "<< abs->personArray[ret].name << "  ѧ�ţ� "<< abs->personArray[ret].num << "  �ɼ��� " << abs->personArray[ret].score<<endl;
    }else {
        cout << "������ѧ�������ڣ�����ѧ���Ƿ�������ȷ��"<< endl;
    }
    system("pause");
    system("cls");
}   


void modifyPerson(Adderssbooks * abs)
{
    cout << "��������Ҫ�޸�ѧ����ѧ��" << endl;
    int Tnum;
    cin >> Tnum ;
    int ret = isExist( abs, Tnum);
    if (isExist(abs, Tnum) != -1){
        cout << "ѧ��ԭ�ɼ�Ϊ�� " << abs->personArray[ret].score << "   �������޸ĺ�ĳɼ��� "<< endl;
        int Tscore;
        cin >> Tscore;
        abs->personArray[ret].score = Tscore;
        cout << "�޸ĳɹ���" << endl;
        saveToFile(abs);
        system("pause");
        system("cls");
    }else {
        cout << "������ѧ�������ڣ�����ѧ���Ƿ�������ȷ��"<< endl;
        system("pause");
        system("cls");
    }

}


void scoreCount(Adderssbooks abs)
{   
    
    cout << "��ѡ��ͳ�����ͣ� " << endl;
    cout << "***1.��߷�***" << endl;
    cout << "***2.��ͷ�***" << endl;
    cout << "***3.ƽ����***" << endl;
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
        cout << "��߷�Ϊ�� "<< max << endl;
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

        cout << "��ͷ�Ϊ�� "<< min << endl;
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
        cout << "ƽ����Ϊ�� "<< score_average << endl;
        system("pause");
        system("cls");
        break;
    }
    default:
        {
        cout << "������ѡ��"<<endl;
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
            cout << "��ӭ�´�ʹ��" << endl;
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