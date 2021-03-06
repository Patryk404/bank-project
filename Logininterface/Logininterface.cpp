#include "Logininterface.h"

Logininterface::Logininterface()
{
	;
}
void Logininterface::display_interface()
{
	get_accounts_from_db();
	while (actual_acc.Username == "")
	{
		std::cout << "Welcome in bank!" << std::endl;
		std::cout << "Username: ";
		std::cin >> username_from_log;
		std::cout << "Password: ";
		std::cin >> password_from_log;
		actual_acc = check_login_and_password();
		if (actual_acc.Username == "")
		{
		   std::cout << "Wrong password or username" << std::endl;
		   _getch();
		   system("cls");
		}
	}
}
Account Logininterface::check_login_and_password()
{
	Account temp;
	for (int i = 0; i < how_many_acc; i++)
	{
		if (username_from_log == accounts[i].Username&&password_from_log == accounts[i].Password)
		{
			temp.Username = accounts[i].Username;
			temp.Password = accounts[i].Password;
			accounts.clear();
			return temp;
		}
	}
	return temp;
}
void Logininterface::get_accounts_from_db()
{
	mysql_query(&Databasecontroller::mysql, "SELECT login FROM accounts ORDER BY id");
	std::vector<std::string> Username(0);// additional variable which get username from db
	MYSQL_RES *idquery = mysql_store_result(&Databasecontroller::mysql);
	MYSQL_ROW record;
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			Username.push_back(record[i]);
			how_many_acc++;
		}
	}
	mysql_query(&Databasecontroller::mysql, "SELECT haslo FROM accounts ORDER BY id");
	std::vector<std::string> Password;
	idquery = mysql_store_result(&Databasecontroller::mysql);
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			Password.push_back(record[i]);
		}
	}
	Account account_from_db;// additional variable which get accounts from my additional variables
	for (int i = 0; i < how_many_acc; i++)
	{
		account_from_db.Username = Username[i];//initialazing account_from_db only for one sec 
		account_from_db.Password = Password[i];
		accounts.push_back(account_from_db);//giving this to accounts ;P
	}
}
Account Logininterface::return_actual_acc()
{
	return actual_acc;
}
