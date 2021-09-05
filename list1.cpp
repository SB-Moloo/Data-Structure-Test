#include <iostream>

//定义链表最大长度常量
const int LISTSIZE = 10;

//一次性修改链表里的数据类型
typedef int MyDataType;

//结构体来定义链表，length为当前链表长度
typedef struct listsimple
{
	MyDataType data[LISTSIZE];
	int length;
}LS;

//初始化
void init(LS *l)
{
	l->length = 0;
}

//空表头插法
bool headinsert(LS* l, MyDataType data)
{
	if (l->length >= LISTSIZE)
	{
		std::cout << "链表已经满了,该数据存入失败" << std::endl;
		return false;
	}
	else
	{
		//i是最后一个数据的脚标，将所有数据后移一位
		for (int i = l->length; i >= 0; i--)
		{
			l->data[i] = l->data[i - 1];
		}
		//将数据后移完，再在数组的头部加入数据
		l->data[0] = data;
		l->length++;
		return true;
	}
}

//空表的尾插法
int tailinsert(LS *l, MyDataType data)
{
	if (l->length >= LISTSIZE)
	{
		std::cout << "链表已经满了,该数据存入失败" << std::endl;
		return false;
	}
	else
	{
		l->data[l->length] = data;
		l->length++;
		return true;
	}

}

//在录入完成后的非空链表中间插入数据
void insert(LS *l, MyDataType data, int position)
{
	//先判断表是否已经满
	if (l->length >= LISTSIZE)
	{
		std::cout << "表已经满了，不能再插入了" << std::endl;
		return;
	}
	else
	{
		//i是从最后一个数据开始，到想插入的那个数据的位置，这段距离的所有数据后移
		for (int i = l->length; i >= position; i--)
		{
			l->data[i] = l->data[i - 1];
		}
		//插入数据
		l->data[position] = data;
		l->length++;
	}
}

//从头部删掉链表的一个数据
void HeadDelete(LS* l)
{
	if (l->length <= 0)
	{
		std::cout << "链表已经空了" << std::endl;
		return;
	}
	else
	{
		for (int i = 0; i < l->length; i++ )
		{
			l->data[i] = l->data[i + 1];
		}
		l->length--;
		return;
	}
}

//从尾部删掉链表的一个数据
void TailDelete(LS* l)
{
	if (l->length <= 0)
	{
		std::cout << "链表已经空了" << std::endl;
		return;
	}
	else
	{
		l->length--;
		return;
	}
}

//在录入完成后的非空链表中间查找，再删除数据
void SMidDelete(LS* l, MyDataType data)
{
	if (l->length <= 0)
	{
		std::cout << "链表已经空了" << std::endl;
		return;
	}
	for (int i = 0; i < l->length; i++)
	{
		if (l->data[i] == data)
		{
			for (; i < l->length; i++)
			{
				l->data[i] = l->data[i + 1];
			}
			l->length--;
			std::cout << "成功删除 " << data << " 在链表 " << l << std::endl;
			return;
		}
	}
	std::cout << "链表中没有找到要删除的数据 " << data << " 在链表 " << l << std::endl;
	return;
}

//在录入完成后的非空链表中间根据已知的下标，删除数据
void PMidDelete(LS* l, int position)
{

	if (l->length <= 0)
	{
		std::cout << "链表已经空了" << std::endl;
		return;
	}
	else if(position <= 0 || position >= l->length)
	{
		std::cout << "脚标超出范围" << std::endl;
	}
	else
	{
		for (int i = position; i < l->length; i++)
		{
			l->data[i] = l->data[i + 1];
		}
		l->length--;
		std::cout << "成功删除脚标 " << position << " 的数据在链表 " << l << std::endl;
	}
}

//打印链表
void print(LS* l)
{
	for (int i = 0; i < l->length; i++)
	{
		std::cout << l->data[i] << "\t";
	}
	std::cout << "\n";
	return;
}

bool main(void)
{
	//int size;
	MyDataType data;
	LS mytaillist;
	LS myheadlist;

	init(&mytaillist);
	init(&myheadlist);

	//所需数据输入
	//std::cout << "请输入所需链表长度：";
	//std::cin >> size;
	//std::cout << "\n";

	std::cout << "现在是头插法" << std::endl;
	for (int i = 0; i < LISTSIZE; i++)
	{
		bool Hjudge;
		std::cout << "请输入所需链表数据(输入-1结束插入)：";
		std::cin >> data;
		if (data == -1) break;
		Hjudge = headinsert(&myheadlist, data);
		if (!Hjudge) break;
	}

	std::cout << "\n" << "现在是尾插法" << std::endl;
	for (int i = 0; i < LISTSIZE; i++)
	{
		bool Tjudge;
		std::cout << "请输入所需链表数据(输入-1结束插入)：";
		std::cin >> data;
		if (data == -1) break;
		Tjudge = tailinsert(&mytaillist, data);
		if (!Tjudge) break;
	}

	std::cout << "\n";
	print(&myheadlist);
	print(&mytaillist);

	std::cout << "从头部删除一个数据结果：";
	HeadDelete(&myheadlist);
	print(&myheadlist);
	std::cout << "从尾部删除一个数据结果：";
	TailDelete(&mytaillist);
	print(&mytaillist);
	std::cout << "\n";

	std::cout << "请输入想要删除的数据：";
	std::cin >> data;
	SMidDelete(&myheadlist, data);
	print(&myheadlist);
	SMidDelete(&mytaillist, data);
	print(&mytaillist);
	std::cout << "\n";

	std::cout << "请输入想要删除的脚标：";
	int position;
	std::cin >> position;
	PMidDelete(&myheadlist, position);
	print(&myheadlist);
	PMidDelete(&mytaillist, position);
	print(&mytaillist);
	std::cout << "\n";
	return 0;
}