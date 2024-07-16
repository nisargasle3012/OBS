#include<iostream>
#include<vector>

using namespace std;

class user
{
	public:
		string userName;
		string passWord;
        int balance;
        vector<pair<string, pair<char, int>>> th;
	user()
	{
		userName="";
		passWord="";
        balance = 0;
	}
	void InputData()
	{
		cout<<"\t\t\tENTER UNIQUE USER-NAME : ";
		cin>>userName;
		cout<<"\t\t\tENTER UNIQUE PASS-WORD : ";
		cin>>passWord;
	}
	void DisplayData()
	{
		cout<<"\t\t\tUSER-NAME : "<<userName<<endl;
		cout<<"\t\t\tPASS-WORD : "<<passWord<<endl;
	}
};
class signUp_page
{
	public:
		user UD;
		signUp_page *Left;
		signUp_page *Right;

	signUp_page(user U)
	{
		UD=U;
		Left=NULL;
		Right=NULL;
	}
};
class creatingTree
{
	public:
		signUp_page *Root;

		creatingTree()
		{
			Root=NULL;
		}
		void Insertion()
		{
			home:
			user U1;
			U1.InputData();
			if(U1.userName=="" && U1.passWord=="")
			{
				cout<<endl;
				cout<<"\t\t\tNO INPUT DETECTED !! "<<endl;
				return;
			}
			signUp_page *New = new signUp_page(U1);
			
			if(Root==NULL)
			{
				Root=New;
			}
			else
			{
				signUp_page *Temp=Root;
				while(true)
				{
					if(New->UD.userName==Temp->UD.userName)
					{
						cout<<endl;
						cout<<"\t\t\tUSER-NAME MUST BE UNIQUE !! "<<endl;
						cout<<endl;
						cout<<"\t\t\t============================"<<endl;
						cout<<"\t\t\tPRESS 1) TO GO BACK "<<endl;
						cout<<"\t\t\tPRESS 2) TO RETRY   "<<endl;
						int Ask;
						cout<<"\t\t\tCHOICE > ";
						cin>>Ask;
						cin.ignore();
						if(Ask==2)
						{
							system("cls");
							cout<<"\t\t\t============================"<<endl;
							cout<<"\t\t\t           SIGN-UP          "<<endl;
							cout<<"\t\t\t============================"<<endl;
							cout<<endl;
							goto home;
						}
						else
						{
							return;
						}
					}
					if(New->UD.userName>Temp->UD.userName)
					{
						if(Temp->Right==NULL)
						{
							Temp->Right=New;
							break;
						}
						else
						{
							Temp=Temp->Right;
						}
					}
					else
					{
						if(Temp->Left==NULL)
						{
							Temp->Left=New;
							break;
						}
						else
						{
							Temp=Temp->Left;
						}
					}
				}
			}
			cout<<endl;
			cout<<"\t\t\t==============================="<<endl;
			cout<<"\t\t\tACCOUNT IS SUCCESSFULLY CREATED "<<endl;
			cout<<"\t\t\t==============================="<<endl;
		}
};

class login_page
{
	public:
		signUp_page *SuRoot;
		signUp_page *currentUser;
		signUp_page *requestedUser;
		login_page()
		{
			SuRoot=NULL;
			currentUser=NULL;
			requestedUser=NULL;
		}
		int Authenticate_User(signUp_page *Temp)
		{
			SuRoot=Temp;
			if(SuRoot==NULL)
			{
				cout<<"\t\t\tYOU NEED TO SIGN-UP FIRST !! "<<endl;
				return -1;
			}
			else
			{
				cout<<"\t\t\tENTER USER-NAME : ";
				string Uname;
				cin>>Uname;
				cout<<"\t\t\tENTER PASS-WORD : ";
				string Upass;
				cin>>Upass;
				bool Found=Search_User(Uname , Upass , SuRoot);
				if(Found==1)
				{
					cout<<endl;
					cout<<"\t\t\t============================"<<endl;
					cout<<"\t\t\tWELCOME !! LOG-IN SUCCESS !!"<<endl;
					cout<<"\t\t\t============================"<<endl;
					return 1;
				}
				else
				{
					return 0;
				}
			}	
		}
		bool Search_User(string Name , string Pass , signUp_page *Temp)
		{
			while(Temp!=NULL)
			{
				if(Temp->UD.userName==Name && Temp->UD.passWord==Pass)
				{
					currentUser=Temp;
					return 1;
				}
				if(Name>Temp->UD.userName)
				{
					Temp=Temp->Right;
				}
				else
				{
					Temp=Temp->Left;
				}
			}
			return 0;
		}
		bool searchUser(string Name)
		{
			signUp_page *Temp = SuRoot;
			while(Temp!=NULL)
			{
				if(Temp->UD.userName==Name)
				{
					requestedUser=Temp;
					return 1;
				}
				if(Name>Temp->UD.userName)
				{
					Temp=Temp->Right;
				}
				else
				{
					Temp=Temp->Left;
				}
			}
			return 0;
		}
		void balance_enquiry()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t      BALANCE ENQUIRY       "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
            cout<<"\t\t\tYOUR BALANCE IS : "<<currentUser->UD.balance<<" Rs."<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\tENTER -1 TO RETURN BACK TO DASHBOARD"<<endl;
            int Select;
            cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
            if(Select==-1)
            {
                return;
            }
			else
			{
				goto Menu;
			}
		}
        void depositing_funds()
		{
			Menu:
            int amount;
            int Select=1;
            while(Select==1)
            {
                system("cls");
                cout<<"\t\t\t============================"<<endl;
                cout<<"\t\t\t       DEPOSIT FUNDS        "<<endl;
                cout<<"\t\t\t============================"<<endl;
                cout<<endl;
                cout<<"\t\t\tENTER THE AMOUNT YOU WANT TO DEPOSIT : ";
                cin>>amount;
                currentUser->UD.balance = currentUser->UD.balance + amount;
                currentUser->UD.th.push_back(make_pair("PERSONAL",make_pair('d', amount)));
                cout<<"\t\t\tYOUR FUND IS SUCCESSFULLY DEPOSITED "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\tPRESS -1)BACK TO DASHBOARD"<<endl;
                cout<<"\t\t\tPRESS  1)DEPOSIT MORE FUNDS"<<endl;
                cout<<endl;
                cout<<"\t\t\tENTER YOUR CHOICE : ";
                cin>>Select;
            }
			if(Select==-1)
			{
				return;
			}
			else
			{
				goto Menu;
			}
		}
		void withdrawing_funds()
		{
			Menu:
            int amount;
            int Select=1;
            while(Select==1)
            {
                system("cls");
                cout<<"\t\t\t============================"<<endl;
                cout<<"\t\t\t       WITHDRAW FUNDS       "<<endl;
                cout<<"\t\t\t============================"<<endl;
                cout<<endl;
                cout<<"\t\t\tENTER THE AMOUNT YOU WANT TO WITHDRAW: ";
                cin>>amount;
                if(currentUser->UD.balance - amount>=0)
                {
                    currentUser->UD.balance = currentUser->UD.balance - amount;
                    currentUser->UD.th.push_back(make_pair("PERSONAL",make_pair('w', amount)));
                }
                else
                {
                    cout<<"\t\t\t!! YOU DONT HAVE SUFFICIENT FUNDS "<<endl;
                }
                cout<<"\t\t\tYOUR FUND IS SUCCESSFULLY WITHDRAWN "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\t\t\tPRESS -1)BACK TO DASHBOARD"<<endl;
                cout<<"\t\t\tPRESS  1)WITHDRAW MORE FUNDS"<<endl;
                cout<<endl;
                cout<<"\t\t\tENTER YOUR CHOICE : ";
                cin>>Select;
                if(Select==-1)
                {
                    return;
                }
                else
                {
                    goto Menu;
                }
            }
        }
        void transferring_funds()
		{
			Menu:
            int Select=1;
            while(Select==1)
            {
                system("cls");
                cout<<"\t\t\t============================"<<endl;
                cout<<"\t\t\t      TRANSFER FUNDS        "<<endl;
                cout<<"\t\t\t============================"<<endl;
                cout<<endl;
                string tf;
                cout<<"\t\t\tUSER YOU WANT TO TRANSFER FUNDS : ";
                cin>>tf;
                if(currentUser->UD.userName==tf)
                {
                    cout<<endl;
                    cout<<"\t\t\tTRANSFERING FUNDS TO YOURSELF IS PROHIBITED"<<endl;
                    cout<<endl;
                    cout<<"\t\t\t";
                    system("pause");
                    goto Menu;
                }
                if(searchUser(tf))
                {
                    int amount;
                    cout<<"t\t\tAMOUNT YOU WANT TO TRANSFER : ";
                    cin>>amount;
                    if(currentUser->UD.balance - amount>=0)
                    {
                        currentUser->UD.balance = currentUser->UD.balance - amount;
                        currentUser->UD.th.push_back(make_pair(requestedUser->UD.userName,make_pair('w',amount)));
                        requestedUser->UD.balance = requestedUser->UD.balance + amount;
                        requestedUser->UD.th.push_back(make_pair(currentUser->UD.userName,make_pair('d',amount)));
                        cout<<"t\t\tTRANFER IS SUCCESFULLY DONE : "<<endl;
                    }
                    else
                    {
                        cout<<"\t\t\tYOU DONT HAVE SUFFICENT FUNDS !!"<<endl;
                    }
                    
                    cout<<endl;
                }
                else
                {
                    cout<<"\t\t\tUSER NOT FOUND !!"<<endl;
                    cout<<endl;
                }
                cout<<"\t\t\tPRESS -1)BACK TO DASHBOARD"<<endl;
                cout<<"\t\t\tPRESS  1)TRANSFER MORE FUNDS"<<endl;
                
                cout<<endl;
                cout<<"\t\t\tENTER YOUR CHOICE : ";
                cin>>Select;
                if(Select==-1)
                {
                    return;
                }
                else
                {
                    goto Menu;
                }
            }
        }

        void transaction_history()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t     TRANSACTION HISTORY    "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
            cout<<endl;
            for(int i = 0; i<currentUser->UD.th.size(); i++)
            {
                if(currentUser->UD.th[i].second.first=='d')
                {
                    cout<<"\t\t\tCREDITED : "<<currentUser->UD.th[i].second.second<<" FROM "<<currentUser->UD.th[i].first<<endl;
                }
                if(currentUser->UD.th[i].second.first=='w')
                {
                    cout<<"\t\t\tDEBITED : "<<currentUser->UD.th[i].second.second<<" TO "<<currentUser->UD.th[i].first<<endl;
                }
            }
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\tENTER -1 TO RETURN BACK TO DASHBOARD"<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==-1)
			{
				return;
            }
            else
            {
                goto Menu;
            }
        }
		void personal_info()
		{
			Menu:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t       PERSONAL-INFO        "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
            cout<<endl;
            currentUser->UD.DisplayData();
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\tENTER -1 TO RETURN BACK TO DASHBOARD"<<endl;
			int Select;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			cin>>Select;
			if(Select==-1)
			{
				return;
            }
            else
            {
                goto Menu;
            }	
		}
};
int main()
{
    creatingTree peoples;
    login_page customers;
    home:
	system("cls");
	cout<<"\t\t\t============================"<<endl;
	cout<<"\t\t\t       WELCOME TO OBS       "<<endl;
	cout<<"\t\t\t============================"<<endl;
	cout<<endl;
	int func;
    cout<<"\t\t\tPRESS 1) CREATE NEW ACCOUNT"<<endl;
	cout<<"\t\t\tPRESS 2) LOG IN THE ACCOUNT"<<endl;
	cout<<endl;
	cout<<"\t\t\tENTER YOUR CHOCIE : ";
	cin>>func;
	cin.ignore();
    if(func==1)
	{
		system("cls");
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t         NEW ACCOUNT        "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
        peoples.Insertion();
		cout<<endl;
		cout<<"\t\t\t";
		system("pause");
		goto home;
    }
	if(func==2)
	{
		system("cls");
		cout<<"\t\t\t============================"<<endl;
		cout<<"\t\t\t           LOG-IN           "<<endl;
		cout<<"\t\t\t============================"<<endl;
		cout<<endl;
		int Check=customers.Authenticate_User(peoples.Root);
		if(Check!=0)
		{
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
		}
		if(Check==1)
		{
			dashboard:
			system("cls");
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\t          LOG-IN MENU       "<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\tPRESS 1) FOR BALANCE ENQUIRY"<<endl;
			cout<<"\t\t\tPRESS 2) FOR DEPSOTING FUNDS "<<endl;
			cout<<"\t\t\tPRESS 3) FOR WITHDRAWING FUNDS "<<endl;
			cout<<"\t\t\tPRESS 4) FOR TRANSFERING FUNDS "<<endl;
            cout<<"\t\t\tPRESS 5) TO VIEW TRANSACTION HISTORY "<<endl;
			cout<<"\t\t\tPRESS 6) TO VIEW PERSONAL INFO "<<endl;
			cout<<"\t\t\tPRESS 7) TO LOG-OUT "<<endl;
			cout<<endl;
			cout<<"\t\t\tENTER YOUR CHOCIE : ";
			int Key;
			cin>>Key;
			if(Key==1)
			{
				customers.balance_enquiry();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
			if(Key==2)
			{
				customers.depositing_funds();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
			if(Key==3)
			{
				customers.withdrawing_funds();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
			if(Key==4)
			{
				customers.transferring_funds();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
            if(Key==5)
			{
				customers.transaction_history();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
			if(Key==6)
			{
				customers.personal_info();
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto dashboard;
			}
			if(Key==7)
			{
				cout<<endl;
				cout<<"\t\t\t";
				system("pause");
				goto home;
			}
			else
			{
				goto dashboard;
			}
		}
		if(Check==0)
		{
			cout<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<"\t\t\tACCOUNT DO NOT EXIST !! RETRY"<<endl;
			cout<<"\t\t\t============================"<<endl;
			cout<<endl;
			cout<<"\t\t\t";
			system("pause");
			goto home;
		}
		if(Check==-1)
		{
			goto home;
		}
	}
    
    return 0;
}