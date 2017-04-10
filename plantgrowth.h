#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include "Topology.h"
using namespace std;


struct branchInfo
{
	vector<int> nodelist;
	int funValue;          //objective function
	float pro;              // growth probablity
	float  base;               //statue base

};

class PG
{
public:
	Topology T;			//ͼ
	vector<branchInfo> cur;
	int fmin;
	int finit;
	vector<vector<int>> res;   //���н�
	vector<vector<int>> tested;  //�Ѳ���ֵ
	double start, stop;	
	
	
	PG(Topology T, double start){
		this->T = T;
		this->start = start;
	};

	void init(vector<int> nodes);	


	void curPro(vector<branchInfo> &brIn);          	//����������,״̬�ռ�
	void curbase(vector<branchInfo> &brIn);  
	int chooseNewbase(vector<branchInfo>  brIn);    		//���������ѡȡ�µĻ���
	vector<branchInfo> setnewbrgroup(vector<int> node,unordered_map<int, vector<int>> cluster_map);             //���ܱ���ɢ
	vector<branchInfo> setngroup(vector<int> node,unordered_map<int, vector<int>> cluster_map);             //���ܱ���ɢ
	bool hastested(vector<int> nodes);
	void clear(vector<branchInfo> &brIn);
	vector<int> getexistnodes();
	vector<vector<int>> getMinCost(vector<int> nodes,int &mincost, int time_threshold,	unordered_map<int, vector<int>> cluster_map);
	branchInfo lessthanfmin(vector<int> node);
	int havepath(vector<int> nodes);
};