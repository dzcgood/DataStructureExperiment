#ifndef STUDENT_H
#define STUDENT_H
#include<QString>
using namespace std;
class student
{
private:
    QString name;
    QString number;
    QString gender;
    QString birthday;
    QString healthCondition;
public:
    student * next;
    QString getName(){return name;}
    QString getNumber(){return number;}
    QString getGender(){return gender;}
    QString getBirthday(){return birthday;}
    QString getHealthCondition(){return healthCondition;}
    void setName(QString n){name=n;}
    void setNumber(QString n){number=n;}
    void setGender(QString n){gender=n;}
    void setBirthday(QString n){birthday=n;}
    void setHealthCondition(QString n){healthCondition=n;}
    void exchange(student& w2)
    {
        QString temp1;
        temp1 = this->name;//交换姓名
        this->name = w2.name;
        w2.name = temp1;
        temp1 = this->number;//交换学号
        this->number = w2.number;
        w2.number = temp1;
        temp1 = this->gender;//交换性别
        this->gender = w2.gender;
        w2.gender = temp1;
        temp1 = this->birthday;//交换出生日期
        this->birthday = w2.birthday;
        w2.birthday = temp1;
        temp1 = this->healthCondition;//交换健康状况
        this->healthCondition = w2.healthCondition;
        w2.healthCondition = temp1;
    }
};

#endif // STUDENT_H
