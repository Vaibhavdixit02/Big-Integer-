#include <bits/stdc++.h>

using namespace std;

class bigg{
	 public:
	 	std::vector< int > value;
	 	long long int ji=0;
	 	void create(int);
	 	void print(void);

};

void bigg::create(int j){
	value.push_back(j);
	ji++;

}

void bigg::print(void){
	vector <int>::iterator It;
	
	for(It = value.begin(); It != value.end(); It++){
		cout<< *It;
	}
	cout<<"\n";
}

bigg addition(bigg a, bigg b){
	bigg n;
	int carry=0;
	std::vector<int>:: iterator itend;
	vector <int>::iterator It1;
	vector <int>::iterator It2;

	if(a.value.size() < b.value.size()){
		
		return addition(b,a);
	}
	else if(a.value.size() > b.value.size()){
		itend = a.value.begin();
		for(It1 = prev(a.value.end()), It2 = prev(b.value.end()) ;It1 != itend, It2 != prev(b.value.begin()); It1--,It2-- ){
		n.create(((*It1 + *It2) + carry) % 10);
		carry = ((*It1 + *It2) + carry) /10;
		}
		for(;It1 != prev(itend); It1--){
			n.create((*It1 + carry)%10);
			carry = (*It1 + carry)/10;
		}
	reverse(n.value.begin(), n.value.end());
	return n;
	}
	else{
		itend = b.value.begin();
		for(It1 = prev(a.value.end()), It2 = prev(b.value.end()) ;It2 != prev(itend); It1--,It2-- ){
		n.create(((*It1 + *It2) + carry)%10);
		carry = (((*It1 + *It2) + carry)) /10;
	}
	if(carry > 0){
		n.create(carry);
	}
	reverse(n.value.begin(), n.value.end());
	return n;
	}
}
bigg neg(bigg c){
	std::vector<int>:: iterator itend;
	itend =c.value.begin();
	for (itend = c.value.begin(); itend != c.value.end() ; itend++)
	{
		/* code */
		*itend = (*itend)*(-1);
	}
	return c;
}

bool checkneg(bigg d){
	if (neg(d).value[0] > 0)
	{
		/* code */
		return true;
	}
	else{
		return false;
	}
}

bigg subtraction(bigg a, bigg b){
	bigg n;
	std::vector<int>:: iterator itend;
	vector <int>::iterator It1;
	vector <int>::iterator It2;
	if (checkneg(a) && checkneg(b))
	{
		/* code */
		if (neg(a).value.size() < neg(b).value.size())
		{
			/* code */
			return subtraction(neg(b), neg(a));
		}
		else if (neg(a).value.size() == neg(b).value.size() && neg(a).value[neg(a).value.size()-1] < neg(b).value[neg(a).value.size()-1])
		{
			/* code */
			return subtraction(neg(b), neg(a));

		}
		else if (neg(a).value.size() == neg(b).value.size() && neg(a).value[neg(a).value.size()-1] > neg(b).value[neg(a).value.size()-1])
		{
			/* code */
			return neg(subtraction(neg(a), neg(b)));

		}
		else if (neg(a).value.size() > neg(b).value.size())
		{
			/* code */
			return neg(subtraction(neg(a), neg(b)));

		}
	}
	else if (checkneg(a))
	{	
		/* code */
		return neg(addition(neg(a), b));
	}

	else if (checkneg(b))
	{
		/* code */
		return (addition(neg(b), a));
	}
	else{
		if (a.value.size() < b.value.size()){
			return neg(subtraction(b,a));
		}
		else if (a.value.size() == b.value.size() && a.value[0] < b.value[0])
		{
			return neg(subtraction(b,a));	
		}
		else if (a.value.size() == b.value.size() && a.value[0] > b.value[0])
		{
			/* code */

			for(It1 = prev(a.value.end()), It2 = prev(b.value.end()) ;It2 != prev(b.value.begin()); It1--,It2-- ){
				if(*It1 > *It2){
					n.create(*It1 - *It2);
				}
				else if(*It1 == *It2){
					n.create(0);
	
				}
				else{
					*prev(It1) = *prev(It1) - 1;
					*It1 = *It1 + 10;
					n.create(*It1 - *It2);
				}

			}
			reverse(n.value.begin(), n.value.end());
			return n;

		}
		else if (a.value.size() > b.value.size()){
			for(It1 = prev(a.value.end()), It2 = prev(b.value.end()) ;It2 != prev(b.value.begin()); It1--, It2-- ){
				if(*It1 > *It2){
					n.create(*It1 - *It2);
				}
				else if(*It1 == *It2){
					n.create(0);
					
				}
				else{
					*prev(It1) = *prev(It1) - 1;
					*It1 = *It1 + 10;
					n.create(*It1 - *It2);
				}

			}
			for(itend = It1; itend != prev(a.value.begin()); itend--){
				n.create(*itend);
			}
			reverse(n.value.begin(), n.value.end());
			return n;

		}

		}
	
}

bigg multiplication(bigg a, bigg b){
	std::vector<int> v;
	std::vector<int>:: iterator it1;
	std::vector<int>:: iterator it2;
	std::vector<int>:: iterator it;
	if (checkneg(a) && checkneg(b))
	{
		/* code */
		return multiplication(neg(a), neg(b));

	}
	else if (checkneg(a))
	{
		/* code */
		return neg(multiplication(neg(a),b));
	}
	else if (checkneg(b))
	{
		/* code */
		return neg(multiplication(a,neg(b)));
	}
	else
	{
		if (a.value.size() < b.value.size())
		{
			/* code */
			return multiplication(b,a);
		}
		else
		{
			for(it2 = prev(b.value.end()); it2 != prev(b.value.begin()); it2--){
				for(it1 = prev(a.value.end()); it1 != prev(a.value.begin()); it1--){
					v.push_back(*it2 * *it1);
					cout << *it2 * *it1<<"\n";
				}
				v.push_back(-1);
				v.push_back(-1);
			}
			int i=0,j=0;
			bigg arr[b.value.size()];
			for(it = v.begin(); it != v.end(); it++){
				if(*it > 0 && *next(it) != -1){
					arr[i].create(*it%10);
					*next(it) = *next(it) + *it/10;
				}
				else if(*it > 0 && *next(it) == -1){
					arr[i].create(*it%10);
					if(*it >= 10)
					arr[i].create(*it/10);
				}
				else{
					i++;
					it++;
				}
				
				//arr[i].print();
			}
			
			
			for(i=0;i<b.value.size();i++){
				reverse(arr[i].value.begin(),arr[i].value.end());
				arr[i].print();
			}
			for(i=0;i<b.value.size();i++){
				for(j=0;j<i;j++){
					arr[i].create(0);
				}
				arr[i].print();
			}
			bigg d = arr[0];
			for(i=1;i<b.value.size();i++){
				d = addition(d,arr[i]);
			}
			return d;
		}
	}
}


int main(){
	bigg t1,t2;
	int l=0,j =0;
	while(l != -1){
		cin >>l;
		if(l != -1)
			t1.create(l);
	}
	while(j != -1){
		cin >>j;
		if(j != -1)
			t2.create(j);
	}
	t1.print();
	t2.print();
	multiplication(t1,t2).print();
	
}