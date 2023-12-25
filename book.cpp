#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//����nianling\�ֻ��š�QQ���������䡢��ַ
struct Person
        {
    string name;
    int age;
    string phone;
    string qq;
    string email;
    string address;
};
//��ϵ�����顢ͨѶ¼��ǰ��¼����
#define MAX 1000 //����ͨѶ¼�����µ��������
struct AddressBook
        {
    unordered_map<string,Person> namemap;
    unordered_map<string,Person> phonemap;
    int size;
};
void out(Person it)
{
    string name=it.name;
    int age=it.age;
    string phone=it.phone;
    string qq=it.qq;
    string email=it.email;
    string address=it.address;
    cout<<name<<" "<<age<<" "<<phone<<" "<<qq<<" "<<email<<" "<<address<<'\n';
}
void ShowMenu()
{
    cout<<"-----------------------"<<'\n';
    cout<<"|--------�˵�---------|"<<'\n';
    cout<<"|----1�������ϵ��----|"<<'\n';
    cout<<"|----2����ʾ��ϵ��----|"<<'\n';
    cout<<"|----3��ɾ����ϵ��----|"<<'\n';
    cout<<"|----4��������ϵ��----|"<<'\n';
    cout<<"|----5���޸���ϵ��----|"<<'\n';
    cout<<"|----6�������ϵ��----|"<<'\n';
    cout<<"|----0���˳��˳���----|"<<'\n';
}
void addPerson(AddressBook *book)
{
    if(book->size==MAX){
        cout<<"����ͨѶ¼����������������������ɾ����¼���ԣ�"<<'\n';
        return;
    }

        //����nianling\�ֻ��š�QQ���������䡢��ַ
    else{
        Person temp;
        cout<<"����������"<<'\n';
        cin>>temp.name;

        cout<<"����������"<<'\n';
        cin>>temp.age;

        cout<<"������绰����"<<'\n';
        cin>>temp.phone;

        cout<<"������QQ����"<<'\n';
        cin>>temp.qq;

        cout<<"�������������"<<'\n';
        cin>>temp.email;

        cout<<"�������ַ"<<'\n';
        cin>>temp.address;


        book->namemap[temp.name]=temp;
        book->phonemap[temp.phone]=temp;
        book->size++;
    }
}
void ShowAll(AddressBook *book)
{
    cout<<"ͨѶ¼��ȫ����¼"<<'\n';
    //����nianling\�ֻ��š�QQ���������䡢��ַ
    for(const auto &pair:book->namemap){
          out(pair.second);
    }
}
void Delete(AddressBook *book)
{
    cout<<"������Ҫɾ������ϵ������"<<'\n';
    string name;
    cin>>name;
    if(book->namemap.find(name)==book->namemap.end()){
        cout<<"��Ҫɾ�����˲����ڣ�"<<'\n';
    }
    else{
        book->namemap.erase(name);
        cout<<"ɾ���ɹ���"<<'\n';
        book->size--;
    }
}
void Search(AddressBook *book)
{
    cout<<"��ѡ����Ҫ����ʲô���ң����ֲ����밴1����������밴2"<<'\n';
    int action=0;
    cin>>action;
    if(action==1){
        string name;
        cin>>name;
        //����nianling\�ֻ��š�QQ���������䡢��ַ
        if(book->namemap.find(name)==book->namemap.end())
            cout<<"���޴���"<<'\n';
        else
            out(book->namemap[name]);
//        printf("%s %d %s %s %s %s\n",&name,book->namemap[name].age,&book->namemap[name].phone,&book->namemap[name].qq,&book->namemap[name].email,&book->namemap[name].address);
    }
    else if(action==2){
        string phone;
        cin>>phone;
        //����nianling\�ֻ��š�QQ���������䡢��ַ
        if(book->phonemap.find(phone)==book->phonemap.end())
            cout<<"���޴˺�"<<'\n';
        else
            out(book->phonemap[phone]);
//        printf("%s %d %s %s %s %s\n",&book->namemap[phone].name,book->namemap[phone].age,&book->namemap[phone].phone,&book->namemap[phone].qq,&book->namemap[phone].email,&book->namemap[phone].address);
    }
    else{
        cout<<"��Ч�����������ԣ�"<<endl;
        return;
    }
}
void Update(AddressBook *book)
{
    Person temp;
    cout<<"������Ҫ�޸ĵ�����"<<'\n';
    cin>>temp.name;

    string p=book->namemap[temp.name].phone;
    book->phonemap.erase(p);

    cout<<"������Ҫ�޸ĵ�����"<<'\n';
    cin>>temp.age;

    cout<<"������Ҫ�޸ĵĵ绰����"<<'\n';
    cin>>temp.phone;

    cout<<"������Ҫ�޸ĵ�QQ����"<<'\n';
    cin>>temp.qq;

    cout<<"������Ҫ�޸ĵĵ�������"<<'\n';
    cin>>temp.email;

    cout<<"������Ҫ�޸ĵĵ�ַ"<<'\n';
    cin>>temp.address;


    book->namemap[temp.name]=temp;
    book->phonemap[temp.phone]=temp;
    cout<<"�޸����"<<'\n';
}
void Reset(AddressBook *book)
{
    book->size=0;
    book->namemap.clear();
    book->phonemap.clear();
    cout<<"�������"<<endl;
}
int main()
{
    AddressBook addressBook;
    addressBook.size=0;

    int select=0;
    while(true)
    {
        //�˵�����
        ShowMenu();
        cin>>select;
        switch (select)
        {
            case 1:
                addPerson(&addressBook);//�õ�ַ����
                break;
            case 2:
                ShowAll(&addressBook);
                break;
            case 3:
                Delete(&addressBook);
                break;
            case 4:
                Search(&addressBook);
                break;
            case 5:
                Update(&addressBook);
                break;
            case 6:
                Reset(&addressBook);
                break;
            case 0:
                cout<<"�ټ�����ӭ���´���ʹ�ã�"<<'\n';
                system("pause");
                return 0;
            default:
                break;
        }
    }
}