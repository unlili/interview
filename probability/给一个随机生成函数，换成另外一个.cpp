#include<iostream>
#include<random>
#include<map>
#include<ctime>
#include<vector>
#include<string>

using namespace std;

/*
给你一个函数f等概率的生成1~5的整数，请扩展成等概率生成2~11的函数

衍生等概率生成字符串a~b  a~f

*/

//获得一个int类型的二进制长度
int getBinaryLength(int a)//10
{
	if (a <= 0) return 1;
	int tmp = 0;//8421  1010
	while (a)
	{
		a >>=  1;
		++tmp;
	}
	return tmp;
}


class RandomBox
{
private:
	int min;
	int max;
public:
	RandomBox(int min,int max)
	{
		this->min = min;//0  [0,5] 1~8  12~16
		this->max = max;//5
	}
	int Random()
	{
		static default_random_engine e((unsigned)time(0));
		static uniform_int_distribution<unsigned> u(min, max);
		return u(e);
	}
	int getMin()
	{
		return min;
	}
	int getMax()
	{
		return max;
	}
};



//利用RandomBox等概率返回0和1
static int rand01(RandomBox rb)
{
	int min = rb.getMin();
	int max = rb.getMax();
	int size = max - min + 1;  //范围

	/*判断size是不是奇数*/
	bool odd = (size & 1) != 0;

	int mid = size / 2;
	int ans = 0;

	do {
		ans = rb.Random() - min;
	} while (odd && ans == mid);//随机到中间的数重新roll

	return ans < mid ? 0 : 1;
}

static int rand02(int l,int r, RandomBox rb)//1~5  -> 2~11    
{
	if (r <= l) return 1;
	if ((rb.getMin() == l) && (rb.getMax() == r)) return rb.Random();

	int size = r - l + 1; //范围 11-2+1 = 10


	int length = getBinaryLength(size);//10  1010 4  
	/*
	1111~1010

	8421

	1011
	
	*/
	int fin;

	do {

		fin = 0;

		int tmp = 0;//用来存储生成的
		for (int i = 0; i < length; ++i)
		{
			int a = rand01(rb);
			tmp += a;
			tmp *= 10;
		}
		tmp /= 10;


		int fa = 1;
		//1010

		while (tmp)
		{
			fin += ((tmp % 10) * fa);
			fa *= 2;  // 2
			tmp /= 10;// 101
		}

	} while (fin > (r - l));


	cout << "fin = "<<fin << endl;


	return fin +l;

}




int main(void)
{

	RandomBox rb(5,20);


	for (int i = 0; i < 100; ++i)
	{
		 cout << "-------------" << endl;
		int a = rand02(2, 11, rb);
		if(a>=2 && a <=11) cout << "ok" << endl;
		else cout << "sbsbsbsbsbsbsbsbsbsb" << endl;
		cout << "-------------" << endl;

	}

	
	


	system("pause");
	return 0;
}
