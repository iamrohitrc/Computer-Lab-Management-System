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
public:
    void inputStudentData()
    {
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
        cout<<"Enter Duration : "; cin>>duration;
    }
    void displayS()
    {
        cout<<"\nRoll Number : "<<rno;
        cout<<"\nYear of Study : "<<year;
        cout<<"\nName : "<<name;
        if(purpose==1)
        cout<<"\nPurpose of Entering Lab : Practical";
        else cout<<"\nPurpose of Entering Lab : Other";
        cout<<"\nDuration : "<<duration<<" Hrs";
        cout<<endl;
    }
    int operator + ()
    {
        
        return 1;
    }
    int operator - ()
    {
        return 0;
    }
};

int main()
{
    int opt;
    lab oLab;
    oLab.inputLabCount();
    //oLab.display();
    int mc,pc;
    mc=oLab.returnMiniCount();
    pc=oLab.returnpgCount();
    //
    student *miniS= new student[mc];
    student *pgS= new student[pc];
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
        if(opt>4) break;
        switch (opt)
        {
            case 1:
            cout<<"\nEnter which Lab student enters : \n1)Mini CCF\t2)PG Lab : ";
                cin>>labID;
                if(labID==1)
                {
                    //stu enters mini ccf
                    if(miniC<mc)
                    {
                    cout<<"\nEnter Sr.No. of Student Entering : ";
                    cin>>numSminil;
                    miniS[numSminil-1].inputStudentData();
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
                        pgS[numSpg-1].inputStudentData();
                        pgC++;
                    }
                    else cout<<"\nAll PCs are occupied.Cant Take More Entries!";
                }
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
                    miniS[i].displayS();
                }
                else cout<<"\nEmpty List";
                break;
            case 4:
                if(pgC!=0)
                {
                for(int j=0;j<numSpg;j++)
                    pgS[j].displayS();
                }
                else cout<<"\nEmpty List";
                break;
                
        }
    }
    //STUDENT ENTRY END
    cout<<endl<<endl;
}
/*
Output : 
 
 Enter Number of PC in Mini CCF 2
 
 Enter Number of PC in PG Lab 1
 
 Enter Mini CCF Machine Information
 
 Condition check for MINI CCF PC : 1
 
 Is the PC properly Working ?
 
 1)YES 2)No : 1
 
 Which OS the PC has ?
 
 1)Windows	2)Ubuntu	3)Both : 1
 
 Is the PC is having Internet Connection ?
 
 1)YES 2)No : 2
 
 Is the PC is having all the Accessories ?
 
 1)YES 2)No : 2
 
 Condition check for MINI CCF PC : 2
 
 Is the PC properly Working ?
 
 1)YES 2)No : 1
 
 Which OS the PC has ?
 
 1)Windows	2)Ubuntu	3)Both : 1
 
 Is the PC is having Internet Connection ?
 
 1)YES 2)No : 1
 
 Is the PC is having all the Accessories ?
 
 1)YES 2)No : 1
 
 Mini CCF Machine Information :
 
 Condition of PC 1
 Working Condition : GOOD
 PC OS : Windows
 Internet Connectivity : NO
 All Accessories Present : NO
 
 Condition of PC 2
 Working Condition : GOOD
 PC OS : Windows
 Internet Connectivity : YES
 All Accessories Present : YES
 
 Do You want to Update the Info for Machines ?
 
 1)Yes	2)No2
 
 Do you want to Update the Info for more Machines ?
 
 1)Yes	2)No2
 
 
 Enter PG Lab Machine Information
 
 Condition check for PG LAB PC : 1
 
 Is the PC properly Working ?
 
 1)YES 2)No : 1
 
 Which OS the PC has ?
 
 1)Windows	2)Ubuntu	3)Both : 1
 
 Is the PC is having Internet Connection ?
 
 1)YES 2)No : 1
 1
 Is the PC is having all the Accessories ?
 
 1)YES 2)No : 1
 
 PG Lab Machine Information :
 
 Condition of PC 1
 Working Condition : GOOD
 PC OS : Windows
 Internet Connectivity : YES
 All Accessories Present : NO
 
 Do You want to Update the Info for Machines ?
 
 1)Yes	2)No2
 
 Do you want to Update the Info for more Machines ?
 
 1)Yes	2)No2
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit1
 
 Enter which Lab student enters :
 1)Mini CCF	2)PG Lab : 1
 
 Enter Sr.No. of Student Entering : 1
 
 Enter Roll Number : 11
 
 Enter Year of Study : 1
 
 Enter Name : Rohit
 
 Enter Purpose of Entering Lab : 1)Practical 2)Other1
 
 Lab Courses :
 1)C++	2)DS	3)PA	4)SE
 Your Option : 2
 Enter Duration : 2
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit1
 
 Enter which Lab student enters :
 1)Mini CCF	2)PG Lab : 2
 
 Enter Sr.No. of Student Entering : 1
 
 Enter Roll Number : 4
 
 Enter Year of Study : 3
 
 Enter Name : Rajat
 
 Enter Purpose of Entering Lab : 1)Practical 2)Other2
 Enter Duration : 2
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit1
 
 Enter which Lab student enters :
 1)Mini CCF	2)PG Lab : 1
 
 Enter Sr.No. of Student Entering : 2
 
 Enter Roll Number : 5
 
 Enter Year of Study : 2
 
 Enter Name : Gagan
 
 Enter Purpose of Entering Lab : 1)Practical 2)Other1
 
 Lab Courses :
 1)C++	2)DS	3)PA	4)SE
 Your Option : 2
 Enter Duration : 3
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit3
 
 Roll Number : 11
 Year of Study : 1
 Name : Rohit
 Purpose of Entering Lab : Practical
 Duration : 2 Hrs
 
 Roll Number : 5
 Year of Study : 2
 Name : Gagan
 Purpose of Entering Lab : Practical
 Duration : 3 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit4
 
 Roll Number : 4
 Year of Study : 3
 Name : Rajat
 Purpose of Entering Lab : Other
 Duration : 2 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit2
 
 Enter which Lab student leaves :
 1)Mini CCF	2)PG Lab : 1
 
 Enter Sr.No. of Student Leaving : 1
 
 Roll Number : 5
 Year of Study : 2
 Name : Gagan
 Purpose of Entering Lab : Practical
 Duration : 3 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit3
 
 Roll Number : 5
 Year of Study : 2
 Name : Gagan
 Purpose of Entering Lab : Practical
 Duration : 3 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit2
 
 Enter which Lab student leaves :
 1)Mini CCF	2)PG Lab : 2
 
 Enter Sr.No. of Student Leaving : 1
 
 Roll Number : 5
 Year of Study : 2
 Name : Gagan
 Purpose of Entering Lab : Practical
 Duration : 3 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit4
 
 Empty List
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit3
 
 Roll Number : 5
 Year of Study : 2
 Name : Gagan
 Purpose of Entering Lab : Practical
 Duration : 3 Hrs
 
 Menu :
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit2
 
 Enter which Lab student leaves :
 1)Mini CCF	2)PG Lab : 1
 
 Enter Sr.No. of Student Leaving : 2
 
 Empty List
 Menu : 
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit3
 
 Empty List
 Menu : 
 1)Add Student Entry
 2)Remove Student Entry
 3)Display Mini CCF Entry List
 4)Display PG Lab Entry List
 5)Exit5
 
 
 Program ended with exit code: 0
 
 */
