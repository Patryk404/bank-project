#include "Account.h"
Account::Account()
{
	Name = "";
	Surname = "";
	Username = "";
	Password = "";
	how_many_dates = 0;
	cash = "";
	bill = "";
	account_id = "";
}
Account &Account::operator=(Account &acc)
{
	this->Name = acc.Name;
	this->Surname = acc.Surname;
	this->Username = acc.Username;
	this->Password = acc.Password;
	this->cash = acc.cash;
	this->how_many_dates = acc.how_many_dates;
	this->bill = acc.bill;
	this->account_id = acc.account_id;
	for (int i = 0; i < acc.date.size(); i++)
	{
		this->date.push_back(acc.date[i]);
	}
}