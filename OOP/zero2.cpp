#include<iostream>
#include<stdio.h>

using namespace std;
int fehrenheit  (int x);
int main()
{
	int temp;
	cout<<"enter temprature in °c :::      ";
cin>>temp;

cout<<"\n\ntemprature  is     ::"<<fehrenheit(temp)<<"°F"<<"\n\n";
      }
int fehrenheit (int x)
{
	int temp;
	temp=x*1.8+32;
	return temp;}