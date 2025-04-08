#include<iostream>
using namespace std;
int main()
{
	int score=0;
	char answer;
	cout<<"-->Welcome to Quiz Game<--\n\n";
	
	//Question 1:
	cout<<"What is '5+9'?\n";
	cout<<"a)8\n b)12\n c)14\n d)13\n";
	cout<<"Enter your answer:";
	cin>>answer;
	if(answer=='c'||answer=='C')
	 {  cout<<"Correct!\n";
	    score+=10;
	 }
	else
	{
     	cout<<"Wrong! The correct answer is c)14\n try again!!";
		score-=5;    
    }
	//Question 2:
	cout<<" Who is known as the father of computers?";
	cout<<"a) Alan Turing\n b) Charles Babbage\n c) Bill Gates\n d) Steve Jobs?\n";
	cout<<"Enter your answer:";
	cin>>answer;
	if(answer=='b'||answer=='B')
	 {  cout<<"Correct!\n";
	    score+=10;
	 }
	else
	{   
	    cout<<"Wrong! The correct answer is b)Charles Babbage\n try again!!";
		score-=5; 
    }
	//display score
	cout<<"\nTotal Score:"<<score<<"points\n";
	if(score>=20)
	   cout<<"Excellent!!";
	else if(score>=10)
	   cout<<"Good Job!!";
	else
	   cout<<"Better Luck Next Time!!";
	 return 0;   	   
}

