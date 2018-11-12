// iamrohitrc
//CSE LAB MANAGEMENT SYSTEM

/*
    Rohit Rajesh Chougule
    Second Year B.Tech. CSE (Semester - I)
    Walchand College of Engineering, Sangli.
*/

#include <iostream>
using namespace std;
class lab
{
    int miniCount;
    int pgCount;
public:
    void inputLabCount()
    {
        cout<<"\nEnter Number of PC in Mini CCF ";
        cin>>miniCount;
        cout<<"\nEnter Number of PC in PG Lab ";
        cin>>pgCount;
    }
    void display()
    {
        cout<<"\nNumber of PC in Mini CCF is  : "<<miniCount<<endl;
        cout<<"\nNumber of PC in PG Lab is : "<<pgCount<<endl;
    }
    int returnMiniCount()
    {
        return miniCount;
    }
    int returnpgCount()
    {
        return pgCount;
    }
};
class machine : public lab
{
    int working;
    int os;
    int internet;
    int accessories;
public:
    void inputMachineCondition()
    {
        cout<<"\nIs the PC properly Working ?\n\n1)YES 2)No : ";
        cin>>working;
        cout<<"\nWhich OS the PC has ?\n\n1)Windows\t2)Ubuntu\t3)Both : ";
        cin>>os;
        cout<<"\nIs the PC is having Internet Connection ?\n\n1)YES 2)No : ";
        cin>>internet;
        cout<<"\nIs the PC is having all the Accessories ?\n\n1)YES 2)No : ";
        cin>>accessories;
    }
    void displayM()
    {
        if(working==1) cout<<"\nWorking Condition : GOOD";
        else cout<<"\nWorking Condition : NOT GOOD";
        
        if(os==1) cout<<"\nPC OS : Windows";
        else if(os==2) cout<<"\nPC OS : Ubuntu";
        else cout<<"\nPS OS : Both(Windows & Ubuntu)";
        
        if(internet==1) cout<<"\nInternet Connectivity : YES";
        else cout<<"\nInternet Connectivity : NO";
        
        if(accessories==1) cout<<"\nAll Accessories Present : YES";
        else cout<<"\nAll Accessories Present : NO";
        cout<<endl;
    }
};
class student : public lab
{
    int rno;
    int year;
    string name;
    int purpose;
    int course;
    int duration;
    int srno;
public:
    void operator+(int x)
    {
        srno=x;
        cout<<"\nEnter Roll Number : ";
        cin>>rno;
        cout<<"\nEnter Year of Study : ";
        cin>>year;
        cout<<"\nEnter Name : ";
        cin>>name;
        cout<<"\nEnter Purpose of Entering Lab : 1)Practical 2)Other";
        cin>>purpose;
        if(purpose==1)
        {
            cout<<"\nLab Courses : \n1)C++\t2)DS\t3)PA\t4)SE\nYour Option : ";
            cin>>course;
        }
        cout<<"\nEnter Duration in Hrs. (Approx.): "; cin>>duration;
    }
    void displayS(int s)
    {
        if(s==1) cout<<"\n MINI CCF : \n";
        if(s==2) cout<<"\n PG LAB : \n";
        cout<<"\nSerial Number : "<<srno;
        cout<<"\nRoll Number : "<<rno;
        cout<<"\nYear of Study : "<<year;
        cout<<"\nName : "<<name;
        if(purpose==1)
            cout<<"\nPurpose of Entering Lab : Practical";
        else cout<<"\nPurpose of Entering Lab : Other";
        cout<<"\nDuration : "<<duration<<" Hrs";
        cout<<endl;
    }
};

int main()
{
    int opt;
    lab oLab;
    oLab.inputLabCount();
    //oLab.display();
    int mc,pc;
    mc=oLab.returnMiniCount(); //num of pc in mini
    pc=oLab.returnpgCount(); // num of pc in pg
    //
    student *miniS= new student[mc]; // object miniS
    student *pgS= new student[pc];  //object pgS
    // LAB DATA START
    {
        machine miniCond[mc];
        machine pgCond[pc];
        //input for condition of pcs
        if(mc==0) cout<<"\nNo PC in MINI CCF ";
        else
        {
            cout<<"\nEnter Mini CCF Machine Information\n";
            for(int i=0;i<mc;i++)
            {
                cout<<"\nCondition check for MINI CCF PC : "<<i+1<<endl;
                miniCond[i].inputMachineCondition();
            }
            cout<<"\nMini CCF Machine Information : \n";
            for(int i=0;i<mc;i++)
            {
                cout<<"\nCondition of PC "<<i+1;
                miniCond[i].displayM();
            }
            //update info of machine
            int update;
            cout<<"\nDo You want to Update the Info for Machines ?\n\n1)Yes\t2)No";
            cin>>update;
            if(update==1)
            {
            up:
                int upn;
                cout<<"\nEnter Number of PC whose data is to be Updated";
                cin>>upn;
                if(upn>mc || upn<1)
                {cout<<"\nError ! Enter PC Number Between 1 and "<<mc<<" only";
                    goto up;
                }
                upn--;
                miniCond[upn].inputMachineCondition();
                cout<<"\nModified Info of Machine : "<<upn+1<<endl;
                miniCond[upn].displayM();
            }
            int upn2;
            cout<<"\nDo you want to Update the Info for more Machines ?\n\n1)Yes\t2)No";
            cin>>upn2;
            if(upn2==1) goto up;
        }
        
        if(pc==0) cout<<"\nNo PC in PG LAB ";
        else
        {
            cout<<"\n\nEnter PG Lab Machine Information\n";
            for(int i=0;i<pc;i++)
            {
                cout<<"\nCondition check for PG LAB PC : "<<i+1<<endl;
                pgCond[i].inputMachineCondition();
            }
            cout<<"\nPG Lab Machine Information : \n";
            for(int i=0;i<pc;i++)
            {
                cout<<"\nCondition of PC "<<i+1;
                pgCond[i].displayM();
            }
            //update info of machine
            int update1;
            cout<<"\nDo You want to Update the Info for Machines ?\n\n1)Yes\t2)No";
            cin>>update1;
            if(update1==1)
            {
            up1:
                int upn1;
                cout<<"\nEnter Number of PC whose data is to be Updated";
                cin>>upn1;
                if(upn1>pc || upn1<1)
                {cout<<"\nError ! Enter PC Number Between 1 and "<<pc<<" only";
                    goto up1;
                }
                
                upn1--;
                miniCond[upn1].inputMachineCondition();
                cout<<"\nModified Info of Machine : "<<upn1+1<<endl;
                miniCond[upn1].displayM();
            }
            int upn3;
            cout<<"\nDo you want to Update the Info for more Machines ?\n\n1)Yes\t2)No";
            cin>>upn3;
            if(upn3==1) goto up1;
        }
    }
    //LAB DATA END
    
    //STUDENT ENTRY START
    int labID;
    int numSminil;
    int numSpg;
    int miniC=0;
    int pgC=0;
    while(1)
    {
        cout<<"\nMenu : \n1)Add Student Entry\n2)Remove Student Entry\n3)Display Mini CCF Entry List\n4)Display PG Lab Entry List\n5)Exit";
        cin>>opt;
        if(opt>5)
        {
            cout<<"\nInavalid Option !!!\n";
            continue;
        }
        if(opt==5) break;
        switch (opt)
        {
            case 1:
                int branch;
                cout<<"\nEnter the Branch of the student : \n1)CSE\t2)IT\t3)ELN\n4)MECH\t5)ELE\t6)CVL\n";
                cin>>branch;
                if(branch==1)
                    
                {
                    cout<<"\nEnter which Lab student enters : \n1)Mini CCF\t2)PG Lab : ";
                    cin>>labID;
                    if(labID==1)
                    {
                        //stu enters mini ccf
                        if(miniC<mc)
                        {
                            cout<<"\nEnter Sr.No. of Student Entering : ";
                            cin>>numSminil;
                            miniS[numSminil-1]+numSminil;
                            miniC++;
                        }
                        else cout<<"\nAll PCs are occupied.Cant Take More Entries!";
                    }
                    else
                    {
                        //stu enters pg las
                        if(pgC<pc)
                        {
                            cout<<"\nEnter Sr.No. of Student Entering : ";
                            cin>>numSpg;
                            pgS[numSpg-1]+numSpg;
                            pgC++;
                        }
                        else cout<<"\nAll PCs are occupied.Cant Take More Entries!";
                    }
                }
                else cout<<"\nOnly CSE Students are allowed !!!\n";
                break;
            case 2:
                cout<<"\nEnter which Lab student leaves : \n1)Mini CCF\t2)PG Lab : ";
                cin>>labID;
                if(labID==1)
                {
                    if(miniC!=0)
                    {
                        cout<<"\nEnter Sr.No. of Student Leaving : ";
                        cin>>numSminil;
                        for(int i=numSminil;i<mc;i++)
                        {
                            miniS[numSminil-1]=miniS[numSminil];
                        }
                        miniC--;
                    }
                    else cout<<"\nError! List Already Empty !";
                }
                if(labID==2)
                {
                    if(pgC!=0)
                    {
                        cout<<"\nEnter Sr.No. of Student Leaving : ";
                        cin>>numSpg;
                        for(int i=numSpg;i<pc;i++)
                        {
                            pgS[numSpg-1]=pgS[numSpg];
                        }
                        pgC--;
                    }
                    else cout<<"\nError! List Already Empty !";
                }
            case 3:
                if(miniC!=0)
                {
                    for(int i=0;i<numSminil;i++)
                        miniS[i].displayS(1);
                }
                else cout<<"\nEmpty List";
                break;
            case 4:
                if(pgC!=0)
                {
                    for(int j=0;j<numSpg;j++)
                        pgS[j].displayS(2);
                }
                else cout<<"\nEmpty List";
                break;
        }
    }
    //STUDENT ENTRY END
    cout<<endl<<endl;
}
