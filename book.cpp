#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//姓名nianling\手机号、QQ、电子邮箱、地址
struct Person
        {
    string name;
    int age;
    string phone;
    string qq;
    string email;
    string address;
};
//联系人数组、通讯录当前记录个数
#define MAX 1000 //设置通讯录可容下的最大人数
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
    cout<<"|--------菜单---------|"<<'\n';
    cout<<"|----1、添加联系人----|"<<'\n';
    cout<<"|----2、显示联系人----|"<<'\n';
    cout<<"|----3、删除联系人----|"<<'\n';
    cout<<"|----4、查找联系人----|"<<'\n';
    cout<<"|----5、修改联系人----|"<<'\n';
    cout<<"|----6、清空联系人----|"<<'\n';
    cout<<"|----0、退出此程序----|"<<'\n';
}
void addPerson(AddressBook *book)
{
    if(book->size==MAX){
        cout<<"您的通讯录容量已满，请扩充容量或删除记录再试！"<<'\n';
        return;
    }

        //姓名nianling\手机号、QQ、电子邮箱、地址
    else{
        Person temp;
        cout<<"请输入姓名"<<'\n';
        cin>>temp.name;

        cout<<"请输入年龄"<<'\n';
        cin>>temp.age;

        cout<<"请输入电话号码"<<'\n';
        cin>>temp.phone;

        cout<<"请输入QQ号码"<<'\n';
        cin>>temp.qq;

        cout<<"请输入电子邮箱"<<'\n';
        cin>>temp.email;

        cout<<"请输入地址"<<'\n';
        cin>>temp.address;


        book->namemap[temp.name]=temp;
        book->phonemap[temp.phone]=temp;
        book->size++;
    }
}
void ShowAll(AddressBook *book)
{
    cout<<"通讯录的全部记录"<<'\n';
    //姓名nianling\手机号、QQ、电子邮箱、地址
    for(const auto &pair:book->namemap){
          out(pair.second);
    }
}
void Delete(AddressBook *book)
{
    cout<<"请输入要删除的联系人姓名"<<'\n';
    string name;
    cin>>name;
    if(book->namemap.find(name)==book->namemap.end()){
        cout<<"您要删除的人不存在！"<<'\n';
    }
    else{
        book->namemap.erase(name);
        cout<<"删除成功！"<<'\n';
        book->size--;
    }
}
void Search(AddressBook *book)
{
    cout<<"请选择您要依照什么查找，名字查找请按1，号码查找请按2"<<'\n';
    int action=0;
    cin>>action;
    if(action==1){
        string name;
        cin>>name;
        //姓名nianling\手机号、QQ、电子邮箱、地址
        if(book->namemap.find(name)==book->namemap.end())
            cout<<"查无此人"<<'\n';
        else
            out(book->namemap[name]);
//        printf("%s %d %s %s %s %s\n",&name,book->namemap[name].age,&book->namemap[name].phone,&book->namemap[name].qq,&book->namemap[name].email,&book->namemap[name].address);
    }
    else if(action==2){
        string phone;
        cin>>phone;
        //姓名nianling\手机号、QQ、电子邮箱、地址
        if(book->phonemap.find(phone)==book->phonemap.end())
            cout<<"查无此号"<<'\n';
        else
            out(book->phonemap[phone]);
//        printf("%s %d %s %s %s %s\n",&book->namemap[phone].name,book->namemap[phone].age,&book->namemap[phone].phone,&book->namemap[phone].qq,&book->namemap[phone].email,&book->namemap[phone].address);
    }
    else{
        cout<<"无效操作，请重试！"<<endl;
        return;
    }
}
void Update(AddressBook *book)
{
    Person temp;
    cout<<"请输入要修改的姓名"<<'\n';
    cin>>temp.name;

    string p=book->namemap[temp.name].phone;
    book->phonemap.erase(p);

    cout<<"请输入要修改的年龄"<<'\n';
    cin>>temp.age;

    cout<<"请输入要修改的电话号码"<<'\n';
    cin>>temp.phone;

    cout<<"请输入要修改的QQ号码"<<'\n';
    cin>>temp.qq;

    cout<<"请输入要修改的电子邮箱"<<'\n';
    cin>>temp.email;

    cout<<"请输入要修改的地址"<<'\n';
    cin>>temp.address;


    book->namemap[temp.name]=temp;
    book->phonemap[temp.phone]=temp;
    cout<<"修改完成"<<'\n';
}
void Reset(AddressBook *book)
{
    book->size=0;
    book->namemap.clear();
    book->phonemap.clear();
    cout<<"重置完成"<<endl;
}
int main()
{
    AddressBook addressBook;
    addressBook.size=0;

    int select=0;
    while(true)
    {
        //菜单调用
        ShowMenu();
        cin>>select;
        switch (select)
        {
            case 1:
                addPerson(&addressBook);//用地址传递
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
                cout<<"再见，欢迎您下次再使用！"<<'\n';
                system("pause");
                return 0;
            default:
                break;
        }
    }
}