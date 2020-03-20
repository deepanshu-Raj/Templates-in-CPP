#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Book
{
public:
	ll bno;
	string bname;

	Book(ll n,string s)
	{
		bno=n;
		bname=s;
	}
	void print()
	{
		cout<<"Book number is:"<<bno<<endl;
		cout<<"Book name is:"<<bname<<endl;
	}
};


//comparator class-used to get rid of custom comparisons.
class compare
{
public:
	bool operator()(Book A,Book B)
	{
		if(A.bname==B.bname)
			return true;
		else
			return false;
	}
};

//fit-forward iterator(independence of the container).
//t-data type of the data stored(independence of the data type).
//c-for comparison(custom,(here) on the basis of name).
template<class fit,class t,class c>
fit search(fit start,fit end,t key,c C)
{
	while(start!=end)
	{
		if(C(*start,key))
			return start;
		start++;
	}
	return end;
}

int main()
{
	Book A(1,"ML");
	Book B(2,"C++");
	Book C(3,"C");

	list<Book> l;
	l.push_back(A);
	l.push_back(B);
	l.push_back(C);

	Book key(1,"C++");
	compare cmp;
	list<Book>:: iterator it=search(l.begin(),l.end(),key,cmp);

	if(it!=l.end())
	{
		cout<<"successfully found the Book!!"<<endl;
		(*it).print();
	}
	else
		cout<<"the Book you searched for is not present!!"<<endl;
	return 0;
}