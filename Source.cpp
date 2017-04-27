#include <iostream>										// << Alper Yýlmaz>>
#include <stdlib.h>										//<< 25.12.2016 >>
#include <math.h>										
#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string.h>	
#include <string>
using namespace std;
struct Node {
	char* data;
	Node* next;
};
struct Stack {
	Node *head;
	void create();
	void makeEmpty();
	void push(char*);
	char* pop();
	bool isempty();
	void print();
	char* getHeadChar();
};


struct node{
	int data;
	node *next;
};
struct Queue{
	node *front;
	node *back;
	void create();
	void close();
	void enqueue(int);
	int dequeue();
	bool isempty();
};

typedef struct Stack stk;
struct postfx* writePostfix(struct prefx*);
int isNumeric(char *);
float e = 2.7182;
int toCalculate(struct postfx*, int);

int abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return n;
}
int sub(int a, int b)
{
	return a - b;
}
int exp(int n)
{
	return pow(e, n);
}
int exp(int x, int y)
{
	return pow(x, y);
}
int log (int x, int y)
{
	return log(y) / log(x);	
}
int mod(int a, int b)
{
	return b%a;
}
int mod(int a)
{
	return a%10;
}
struct prefx
{
	char data[50];
};
struct postfx
{
	char*data;
};

int main()
{
	struct prefx* prefix;
	prefix = new struct prefx[20];
	struct prefx* prefixByConsole;
	prefixByConsole = new struct prefx[20];
	
	struct postfx* postfix;
	postfix = new struct postfx[20];
	Queue ansQueue;
	ansQueue.create();
	int ans = 0;

	char secim;
	cout << "(A) -> Write From File(Only One Line)"<<endl;
	cout << "(B) -> Write To Console";
	cin>>secim;
	cout << "Default:"<<endl;
	switch (secim)
	{
	case 'A': case 'a':
	{
				  /*
				  FILE* data;
				  data = fopen("input.txt", "r");
				  char ch;
				  int k = 0;
				  int i = 0;
				  int countLine = 1;

				  while (!feof(data)) {
					  ch = fgetc(data);
					  if (ch == '\n')
						  countLine++;
				  }

				  prefxx* prefix = new prefxx[countLine];
				  rewind(data);

				  int i = 0;
				  int k = 0;
				  int m = 0;
				  do
				  {
					  if (ch == '\n') {
						  prefix[k].data[m][i - 1] = '\0';
						  k++;
						  m = 0;

				  }
					  i = 0;
					  prefix[k].data[m] = new char[25];
					  for (int x = 0; x < 20; x++) {
						  for (int y = 0; y < 50; y++) {
							  prefix[x].data[y] = '\0';
						  }
					  }
					  
					  
					  do {
						  if (feof(data))
							  break;
					  retry:
						  ch = fgetc(data);
						  if (ch == ' ') {
							  prefix[k].data[m][i] = '\0';
							  m++;
							  prefix[k].data[m] = new char[25];
							  for (int k = 0; k < 20; k++) {
								  for (int m = 0; m < 50; m++) {
									  prefix[k].data[m] = '\0';
								  }
							  i = 0;
							  goto retry;
						  }
						  prefix[k].data[m][i++] = ch;

					  } while (ch != '\n');
				  } while (!feof(data));

				  prefix[k].data[m][i - 1] = '\0';
*/
				  FILE* data;
				  data = fopen("input.txt", "r");
				  char ch;
				  int k = 0;
				  int i = 0;
				  int count = 1;

				  while (!feof(data))
				  {
					  ch = fgetc(data);
					  if (ch == ' ')
						  count++;
				  }
				  rewind(data);
				  for (int x = 0; x < 20; x++) {
					  for (int y = 0; y < 50; y++) {
						  prefix[x].data[y] = '\0';
					  }
				  }
				  for (int i = 0; i < count; i++)
				  {
					  while (!feof(data))
					  {
						  ch = fgetc(data);
						  prefix[i].data[k] = ch;
						  if (ch == ' ') {
							  prefix[i].data[k] = '\0';
							  break;
						  }
						  k++;
					  }
					  k = 0;
				  }
				  for (int i = 0; i < count; i++)
					  cout << prefix[i].data;
				  cout << endl;
				  postfix = writePostfix(prefix);
				  ans = toCalculate(postfix, ans);
				  ansQueue.enqueue(ans);
				  cout << ans;
				  fclose(data);

	}
	case 'B': case 'b':
	{


				  char* prefix2;
				  prefix2 = new char[50];

				  cout << " ----Write Exit For Answer Queue And Exit---";

				  while (strcasecmp(prefix2, "exit") != 0)
				  {

					  cout << endl << "Enter Prefix String With Space" << endl;
					  cin.getline(prefix2, 50);
					  int i = 0, k = 0;
					  int count = 1;
					  while (prefix2[i] != '\0')
					  {
						  if (prefix2[i] == ' ')
							  count++;
						  i++;
					  }

					  for (int x = 0; x < 20; x++) {
						  for (int y = 0; y < 50; y++) {
							  prefixByConsole[x].data[y] = '\0';
						  }
					  }
					  int j = 0;
					  char ch;

					  for (int i = 0; i < count; i++)
					  {
						  while (prefix2[j] != '\0')
						  {
							  prefixByConsole[i].data[k] = prefix2[j];
							  if (prefix2[j] == ' ') {
								  prefixByConsole[i].data[k] = '\0';
								  break;
							  }
							  k++;
							  j++;
						  }
						  j++;
						  k = 0;

					  }
					  i = 0;
					  /*while (prefixByConsole[i].data != '\0')
					  {

					  if (strcasecmp(prefixByConsole[i].data, "exit") != 0 && strcasecmp(prefixByConsole[i].data, "sum") != 0 && strcasecmp(prefixByConsole[i].data, "product") != 0 && strcasecmp(prefixByConsole[i].data, "div ") != 0 && strcasecmp(prefixByConsole[i].data, "sub") != 0 && strcasecmp(prefixByConsole[i].data, "log") != 0 && strcasecmp(prefixByConsole[i].data, "mod ") != 0 && strcasecmp(prefixByConsole[i].data, "max") != 0 && strcasecmp(prefixByConsole[i].data, "min") != 0 && strcasecmp(prefixByConsole[i].data, "exp") != 0 && strcasecmp(prefixByConsole[i].data, "ans") != 0 && strcasecmp(prefixByConsole[i].data, "sqrt") != 0 && strcasecmp(prefixByConsole[i].data, " ") != 0)
					  {
					  cout << "Wrong String !!";
					  break;
					  }
					  else
					  {
					  **/
					  postfix = writePostfix(prefixByConsole);
					  ans = toCalculate(postfix, ans);
					  ansQueue.enqueue(ans);
					  cout << "Answer :" << ans << endl;
				  }

	}
	default:{ cout << "Wrong Choice"; 
	
	}
	}
	
		cout << "Answer Queue: " <<endl;
		while (ansQueue.front->next != NULL)
		{
			cout << ansQueue.front->data<< " -> ";
			ansQueue.front = ansQueue.front->next;
		}
		ansQueue.close();
		system("PAUSE");

	}

int toCalculate(struct postfx* postfix,int answer)
{	
	int result = 0;
	stk stk1;
	stk1.create();
	int *op;
	op = new int[5];
	for (int k = 0; k < 5; k++)
	{
		op[k] =9999;
	}
	int p = 0,i=0;
	
	while ((postfix + p)->data != "\0")
	{
		while ((postfix + p)->data == " ")
		{
			p++;
		}
		
		
		if (isdigit((postfix + p)->data[0]) || isdigit((postfix + p)->data[1]))
		{
			stk1.push((postfix + p)->data);
		}
		else if (strcasecmp((postfix + p)->data, "ans") == 0)
		{
			
			char*d = new char[10];
			sprintf(d, "%d", answer);
			stk1.push(d);
		}
		else
		{
			while (!stk1.isempty())
			{	
				op[i] = atoi(stk1.pop());
				i++;
			}
			if (strcasecmp((postfix + p)->data, "sum") == 0)
			{
				int j = 0;
				result = 0;
				while (op[j] != 9999)
				{
					result += op[j];
					j++;
				}
			}
			if (strcasecmp((postfix + p)->data, "product") == 0)
			{
				int j = 0;
				result = 1;

				while (op[j]!=9999)
				{
					result *= op[j];
					j++;
				}
			}

			if (strcasecmp((postfix + p)->data, "sub") == 0)
			{
				result = op[1] - op[0];
			}
			if (strcasecmp((postfix + p)->data, "div") == 0)
			{
				if (op[0]== 0)
					cout << "Syntax Error!!";
				else
					result = op[1]/op[0];
				
			}
			if (strcasecmp((postfix + p)->data, "exp") == 0)
			{
				if (op[1] == 9999)
					result = exp(op[0]);

				else
					result = exp(op[1], op[0]);
			
			}
			if (strcasecmp((postfix + p)->data, "sqrt") == 0)
			{
				if (op[0] < 0)
					cout << "Syntax Error!!";
				else
				result = sqrt(op[0]);
			
			}
			if (strcasecmp((postfix + p)->data, "mod") == 0)
			{
				if (op[1] == 9999)
					result = mod(op[0]);

				else
					result = mod(op[1],op[0]);

			}
			if (strcasecmp((postfix + p)->data, "abs") == 0)
			{
				result = abs(op[0]);

			}

			if (strcasecmp((postfix + p)->data, "max") == 0)
			{
				int x=0,max=0;
				while (op[x] != 9999)
				{
					
					if (op[x] > max)
						max = op[x];
					x++;
				}
				result = max;
			}
			if (strcasecmp((postfix + p)->data, "min") == 0)
			{
				int x = 0, min = op[0];
				while (op[x] != 9999)
				{

					if (op[x] < min)
						min = op[x];
					x++;
				}
				result = min;
			}
			if (strcasecmp((postfix + p)->data, "log") == 0)
			{
				if (op[1] == 9999)
				{
					if (op[0]>0)
						result = log(op[0]);
					else
						cout << "Syntax Error";
				}
				else
				{
					if (op[1] > 0 && op[0] > 0 && op[0] != 1)
					{
						result = log(op[1], op[0]);
					}
					else
						cout << "Syntax Error";
					
				}
			}
			
			i = 0;
			char*c = new char[10];
			sprintf(c, "%d", result);
			stk1.push(c);
			
		    
		}
		p++;
	}
	result = atoi(stk1.pop());

	return result;
}
struct postfx* writePostfix(struct prefx*prefix ){

	struct postfx* postfix;
	postfix = new struct postfx[20];
	postfix->data = new char[50];
	int postfixindex = 0;
	stk oprStack;
	oprStack.create();
	int y = 0;
	
	for (int i = 0; strcasecmp(prefix[i].data, "\0") != 0; i++)
	{
		
			if (strcasecmp(prefix[i].data, "(") == 0)
			{
				oprStack.push(prefix[i].data);
			}
			else if (strcasecmp(prefix[i].data, "product") == 0)
				oprStack.push(prefix[i].data);
			else if (strcasecmp(prefix[i].data, "div") == 0)
			{
				if (!oprStack.isempty())
				while (strcasecmp(oprStack.getHeadChar(), "product") == 0)
				{
					postfix[postfixindex].data = oprStack.pop();
					postfixindex++;
					if (oprStack.isempty())
						break;

				}
				oprStack.push(prefix[i].data);
			}
			else if (strcasecmp(prefix[i].data, "sum") == 0)
			{
				if (!oprStack.isempty())
				while (strcasecmp(oprStack.getHeadChar(), "product") == 0 || strcasecmp(oprStack.getHeadChar(), "div") == 0)
				{
					postfix[postfixindex].data = oprStack.pop();
					postfixindex++;
					if (oprStack.isempty())
						break;
				}
				oprStack.push(prefix[i].data);
			}
			else if (strcasecmp(prefix[i].data, "sub") == 0)
			{
				if (!oprStack.isempty())
				while (strcasecmp(oprStack.getHeadChar(), "product") == 0 || strcasecmp(oprStack.getHeadChar(), "div") == 0 || strcasecmp(oprStack.getHeadChar(), "sum") == 0)
				{
					postfix[postfixindex].data = oprStack.pop();
					postfixindex++;
					if (oprStack.isempty())
						break;
				}
				oprStack.push(prefix[i].data);
			}
			else if (strcasecmp(prefix[i].data, "sqrt") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "exp") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "abs") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "mod") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "max") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "min") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "log") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, "ans") == 0)
				oprStack.push(prefix[i].data);

			else if (strcasecmp(prefix[i].data, ")") == 0)
			{
				while (strcasecmp(oprStack.getHeadChar(), "(") != 0)
				{
					postfix[postfixindex].data = oprStack.pop();
					postfixindex++;
				}
				char* buffer = oprStack.pop();
			}

			else
			{
				postfix[postfixindex].data = prefix[i].data;
				postfixindex++;
			}
			postfix[postfixindex].data = "\0";
		}
	
	while (!oprStack.isempty())
	{
		postfix[postfixindex].data = oprStack.pop();
		postfixindex++;
	}
	postfix[postfixindex].data= "\0";

	cout << endl <<endl<< "Postfix string:";

	for (int i = 0; i < postfixindex; i++)
		cout << postfix[i].data<<" ";
	cout << endl;
	
	
	oprStack.makeEmpty();

	return postfix;

}
int isNumeric(char *p){    // sayi olup olmadýgýný kontrol
		if (isdigit(p[0]) || isdigit(p[1]))
		{      // ilk karakteri veya ikinci karakteri sayiysa return 1
			return 1;
		}
		else return 0;
	}


void Stack::create() {
	head = NULL;
}
void Stack::makeEmpty() {
	Node *p;
	while (head) {
		p = head;
		head = head->next;
		delete p;
	}
}
char* Stack::getHeadChar()
{
	if (head == NULL)
		return "\0";
	return head->data;
}
void Stack::push(char* a) {
	Node *newNode = new Node;
	newNode->data = a;
	newNode->next = head;
	head = newNode;
}
char* Stack::pop() {
	if (head == NULL)
		return "\0";
	Node *topStack;
	char* toReturn;
	toReturn = new char;
	topStack = head;
	head = head->next;
	toReturn = topStack->data;
	delete topStack;
	return toReturn;
}
bool Stack::isempty() {
	return head == NULL;
}
void Stack::print()
{
	cout << "Stack contents : ";
	Node *p = head;
	while (p) {
		cout<< p->data<<" ";
		p = p->next;
	}
	cout << endl;
}

void Queue::create(){
	front = NULL; back = NULL;
}
void Queue::close(){
	node *p;
	while (front){
		p = front;
		front = front->next;
		delete p;
	}
}
void Queue::enqueue(int newdata){
	node *newnode = new node;
	newnode->data = newdata;
	newnode->next = NULL;
	if (isempty()){// first element?
		back = newnode;
		front = back;
	}
	else{
		back->next = newnode;
		back = newnode;
	}
}
int Queue::dequeue(){
	node *topnode;
	int temp;
	topnode = front;
	front = front->next;
	temp = topnode->data;
	delete topnode;
	return temp;
}
bool Queue::isempty(){
	return front == NULL;
}
